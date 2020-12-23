#include "Pack.h"
#include <iostream>
#include <cstdio>
#include <cstring>

std::string getFileNameFromPath(const std::string &path)
{
    fs::path p(path);
    return p.filename().string();
}

// subFiles 包含目录、文件的信息结构体
// 顺序呢
void GetAllSubFiles(const fs::path &directoryPath, std::vector<SubFileInfo> &subFiles)
{
    subFiles.emplace_back(false, fs::absolute(directoryPath).string());
    for (auto &entry : fs::directory_iterator(directoryPath))
    {
        if (entry.is_directory())
        {
            GetAllSubFiles(entry.path(), subFiles);
        }
        else
        {
            subFiles.emplace_back(true, entry.file_size(), fs::absolute(entry.path()).string());
        }
    }
}

bool packFileAndFolder(const std::vector<std::string> &Files,
                       const std::vector<std::string> &Folders,
                       const std::string &OutputFile)
{
    //打包格式:多少个文件 然后每个文件的名称存储，然后是文件的内容
    FILE *output = fopen(OutputFile.c_str(), "wb+");
    if (output == nullptr)
    {
        std::cout << "Open OutputFile Error!" << std::endl;
        return false;
    }
    else
    {
        //文件打包部分
        int fileNumber = Files.size();                      //统计文件个数
        fwrite(&fileNumber, sizeof(fileNumber), 1, output); //将有多少个文件个数写入
        printf("pack files:\n");
        for (auto &file : Files)
        {
            auto fileSize = fs::file_size(file);
            FileInfo info(getFileNameFromPath(file), fileSize);
            //FIleInfo写如文件
            info.writeToFile(output); // NOLINT(bugprone-sizeof-expression)
            //把文件具体内容写如
            if (fileSize != 0)
            {
                FILE *input = fopen(file.c_str(), "rb+"); //打开输入文件
                if (input != nullptr)
                {
                    auto *fileBuffer = new unsigned char[fileSize];
                    fread(fileBuffer, fileSize, 1, input);
                    fwrite(fileBuffer, fileSize, 1, output);
                    delete[] fileBuffer;
                    fclose(input);
                }
            }
        }
        //文件夹打包部分
        printf("pack folders\n");

        int totalFolderFileNum = 0;
        for (auto &Folder : Folders)
        { //Folders是绝对路径
            std::vector<SubFileInfo> SubFiles;
            GetAllSubFiles(Folder, SubFiles);
            totalFolderFileNum += SubFiles.size(); //所有文件总个数
        }

        fwrite(&totalFolderFileNum, sizeof(totalFolderFileNum), 1, output); //将有多少个文件和文件夹写入
        for (auto &folder : Folders)
        {
            std::vector<SubFileInfo> AllSubFiles;
            GetAllSubFiles(folder, AllSubFiles);

            //
            //获取文件名字
            //  C:/users/xhy/  b/c/a.txt
            std::string subDirectory = getFileNameFromPath(folder); //输入C:/a/c/b  输出 /b
            std::cout << subDirectory << std::endl;
            unsigned long pos = folder.length() - subDirectory.length(); //定位前面字符串最后的位置
            for (auto SubFile : AllSubFiles)
            {
                std::string absolutePath = SubFile.filename;
                SubFile.filename = SubFile.filename.erase(0, pos); //删除绝对路径部分 C:/a/c
                //std::cout<<AllSubFile.filename<<std::endl;
                if (SubFile.IsTypeFile)
                {
                    // std::cout << absolutePath << std::endl;
                    unsigned long long int fileSize = fs::file_size(absolutePath); //获取文件大小
                    SubFile.fileSize = fileSize;
                    SubFile.writeToFile(output); //fwrite(&SubFile, sizeof(SubFileInfo), 1, output);
                    assert(fileSize != 0);
                    FILE *input = fopen(absolutePath.c_str(), "rb+"); //打开输入文件
                    assert(input != nullptr);
                    std::unique_ptr<unsigned char> fileBuffer(new unsigned char[fileSize]);
                    fread(fileBuffer.get(), fileSize, 1, input);
                    fwrite(fileBuffer.get(), fileSize, 1, output);
                    fclose(input);
                }
                else
                {
                    SubFile.writeToFile(output); //fwrite(&SubFile, sizeof(SubFileInfo), 1, output);
                }
            }
        }
    }
    fclose(output);
    return true;
}

bool unPackFileAndFolder(const std::string &inputFilePath, const std::string &OutputPath)
{
    FILE *input = fopen(inputFilePath.c_str(), "rb+");
    fs::create_directory(OutputPath);
    if (input == nullptr)
    {
        std::cout << "Input file Path Error! Unpack Failure!" << std::endl;
        return false;
    }
    //文件解包部分
    int fileNumber;
    fread(&fileNumber, sizeof(fileNumber), 1, input);
    for (auto i = 0; i < fileNumber; i++)
    {
        struct FileInfo fileInformation; //用于保存文件信息
        fileInformation.readFromFile(
            input); //fread(&fileInformation, sizeof(fileInfo), 1, input); // NOLINT(bugprone-sizeof-expression)
        std::string fileOutputPath = OutputPath + "/" + fileInformation.fileName;
        FILE *output = fopen(fileOutputPath.c_str(), "wb+");
        if (output == nullptr)
        {
            std::cout << "Open file Error!" << std::endl;
            return false;
        }
        auto *fileBuffer = new unsigned char[fileInformation.fileSize];
        fread(fileBuffer, fileInformation.fileSize, 1, input);
        fwrite(fileBuffer, fileInformation.fileSize, 1, output);
        delete[] fileBuffer;
        fclose(output);
    }
    //文件夹解包部分
    int totalFolderFileNum;
    fread(&totalFolderFileNum, sizeof(totalFolderFileNum), 1, input); //将有多少个文件和文件夹写入
    for (auto i = 0; i < totalFolderFileNum; i++)
    {
        struct SubFileInfo subFileInfo;
        subFileInfo.readFromFile(input); //fread(&subFileInfo, sizeof(SubFileInfo), 1, input);
        std::string path = OutputPath + "/" + subFileInfo.filename;
        std::cout << "Unpack " << subFileInfo.filename << " to " << path << std::endl;
        std::cout << subFileInfo.IsTypeFile << std::endl;
        if (!subFileInfo.IsTypeFile)
        { //如果是文件夹
            fs::create_directory(fs::path(path));
        }
        else
        {
            FILE *output = fopen(path.c_str(), "wb+");
            if (!output)
            {
                std::cout << "Open file(" << path << ") Error!" << std::endl;
                return false;
            }
            std::unique_ptr<unsigned char> fileBuffer(new unsigned char[subFileInfo.fileSize]);
            fread(fileBuffer.get(), subFileInfo.fileSize, 1, input);
            fwrite(fileBuffer.get(), subFileInfo.fileSize, 1, output);
            fclose(output);
        }
    }

    fclose(input);

    return true;
}

//#endif

void FileInfo::writeToFile(FILE *file)
{
    assert(file != nullptr);
    auto serialization(serialize());
    std::unique_ptr<char> data(serialization.first);
    auto *len_ptr(&serialization.second);
    fwrite(len_ptr, sizeof(*len_ptr), 1, file);
    fwrite(data.get(), *len_ptr, 1, file);
}

void FileInfo::readFromFile(FILE *file)
{
    assert(file != nullptr);
    std::unique_ptr<int> len_ptr(new int);
    fread(len_ptr.get(), sizeof(*len_ptr), 1, file);
    std::unique_ptr<char> data(new char[*len_ptr]);
    fread(data.get(), *len_ptr, 1, file);
    deserialize(data.get(), *len_ptr);
}

std::pair<char *, int> FileInfo::serialize()
{
    size_t len(fileName.size() + sizeof(fileSize));
    char *data(new char[len]);
    memcpy(data, &fileSize, sizeof(fileSize));
    memcpy(data + sizeof(fileSize), fileName.c_str(), fileName.size());
    return std::pair<char *, int>(data, len);
}

void FileInfo::deserialize(char *data, int len)
{
    memcpy(&fileSize, data, sizeof(fileSize));
    fileName = std::string(data + sizeof(fileSize), len - sizeof(fileSize));
}

void SubFileInfo::writeToFile(FILE *file)
{
    assert(file != nullptr);
    auto serialization(serialize());
    std::unique_ptr<char> data(serialization.first);
    auto *len_ptr(&serialization.second);
    fwrite(len_ptr, sizeof(*len_ptr), 1, file);
    fwrite(data.get(), *len_ptr, 1, file);
}

void SubFileInfo::readFromFile(FILE *file)
{
    assert(file != nullptr);
    std::unique_ptr<int> len_ptr(new int);
    fread(len_ptr.get(), sizeof(*len_ptr), 1, file);
    std::unique_ptr<char> data(new char[*len_ptr]);
    fread(data.get(), *len_ptr, 1, file);
    deserialize(data.get(), *len_ptr);
}

std::pair<char *, int> SubFileInfo::serialize()
{
    size_t len(filename.size() + sizeof(IsTypeFile) + sizeof(fileSize));
    char *data(new char[len]);
    memcpy(data, &IsTypeFile, sizeof(IsTypeFile));
    memcpy(data + sizeof(IsTypeFile), &fileSize, sizeof(fileSize));
    memcpy(data + sizeof(IsTypeFile) + sizeof(fileSize), filename.c_str(), filename.size());
    return std::pair<char *, int>(data, len);
}

void SubFileInfo::deserialize(char *data, int len)
{
    memcpy(&IsTypeFile, data, sizeof(IsTypeFile));
    memcpy(&fileSize, data + sizeof(IsTypeFile), sizeof(fileSize));
    filename = std::string(data + sizeof(IsTypeFile) + sizeof(fileSize),
                           len - sizeof(IsTypeFile) - sizeof(fileSize));
}

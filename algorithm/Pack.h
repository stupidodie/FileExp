#ifndef FILEPACK_PACK_H
#define FILEPACK_PACK_H

#include <string>
#include <utility>
#include <vector>
#include <cstring>
#include <cassert>
#include <memory>
#include <filesystem>

namespace fs = std::filesystem;

struct FileInfo {
    std::string fileName;  //绝对路径
    unsigned long long int fileSize{}; //B
    FileInfo() = default;

    FileInfo(std::string fileName, unsigned long long int size) : fileName(std::move(fileName)), fileSize(size) {}

    // 确保file指针有效
    void writeToFile(FILE *file);

    void readFromFile(FILE *file);

private:
    // 不考虑大小端
    // 记得释放内存
    std::pair<char *, int> serialize();

    void deserialize(char *data, int len);
};

struct SubFileInfo {
    ~SubFileInfo() = default;

    SubFileInfo(bool isFile, unsigned long long int size, std::string name)
            : IsTypeFile(isFile), fileSize(size), filename(std::move(name)) {}

    SubFileInfo() = default;

    SubFileInfo(bool isFile, std::string name) : SubFileInfo(isFile, 0, std::move(name)) {}

    bool IsTypeFile;//纪录类型是文件夹还是文件 true是文件 false是文件夹
    unsigned long long int fileSize;//如果是文件的话，则存储大小
    std::string filename;

    // 确保file指针有效
    void writeToFile(FILE *file);

    void readFromFile(FILE *file);

private:
    // 不考虑大小端
    // 记得释放内存
    std::pair<char *, int> serialize();

    void deserialize(char *data, int len);
};

//给定一个文件夹的路径，获取其下面所有子文件
void GetAllSubFiles(const fs::path &directoryPath, std::vector<SubFileInfo> &subFiles);

//打包文件和文件夹
bool packFileAndFolder(const std::vector<std::string> &Files, const std::vector<std::string> &Folders,
                       const std::string &OutputFile);

bool unPackFileAndFolder(const std::string &inputFilePath, const std::string &OutputPath);

std::string getFileNameFromPath(const std::string &path);

#endif //FILEPACK_PACK_H

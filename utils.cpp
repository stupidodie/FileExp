#include "utils.h"
#include <cstdlib>
#include <QFile>
#include <QString>
#include <QCryptographicHash>

bool qCopyDirectory(const QDir &fromDir, const QDir &toDir, bool bCoverIfFileExists)
{
    QDir formDir_ = fromDir;
    QDir toDir_ = toDir;
    if(!toDir_.exists()){
        if(!toDir_.mkdir(toDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = formDir_.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;
        //拷贝子目录
        if(fileInfo.isDir()){
            //递归调用拷贝
            if(!qCopyDirectory(fileInfo.filePath(), toDir_.filePath(fileInfo.fileName()),bCoverIfFileExists))
                return false;
        }else{
            if(bCoverIfFileExists && toDir_.exists(fileInfo.fileName()))
            {
                toDir_.remove(fileInfo.fileName());
            }
            if(!QFile::copy(fileInfo.filePath(), toDir_.filePath(fileInfo.fileName())))
            {
                return false;
            }
        }
    }
    return true;
}


QString getSha1sum(const QString& fullFIleName){
            QFile theFile(fullFIleName);
            theFile.open(QIODevice::ReadOnly);
           QByteArray ba = QCryptographicHash::hash(theFile.readAll(), QCryptographicHash::Sha1);
                theFile.close();
                return  ba.toHex().constData();
}




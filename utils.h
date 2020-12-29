#ifndef UTILS_H
#define UTILS_H


#include <QDir>
#include <QFileInfoList>


bool qCopyDirectory(const QDir& fromDir, const QDir& toDir, bool bCoverIfFileExists);

QString getSha1sum(const QString& fullFIleName);
#endif // UTILS_H

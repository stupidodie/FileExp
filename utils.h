#ifndef UTILS_H
#define UTILS_H


#include <QDir>
#include <QFileInfoList>


bool qCopyDirectory(const QDir& fromDir, const QDir& toDir, bool bCoverIfFileExists);
#endif // UTILS_H

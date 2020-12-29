#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFutureWatcher>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static bool  zipFiles();

private slots:
    void on_addFileBtn_clicked();

    void on_addFolderBtn_clicked();

    void on_removeFileBtn_clicked();

    void on_removeFolderBtn_clicked();

    void on_packFileBtn_clicked();

    void on_compressFileBtn_clicked();

    static QString packAndCompress(const std::vector<std::string> &fileList,const std::vector<std::string> &folderList, const std::string &targetFileName,const std::string &password, bool compress);
    static bool unComprssAndunPack(const std::string& fileName, const std::string & folderName,const std::string& password,bool onlyUnComprss);
    static QString buildSCP(const QString& ip,const QString& userName, const QString& password, const QString& cloudPath,const QString& localFile,bool push);
    static int scp(const QString& cmd);

    void on_openZipFileBtn_clicked();

    void on_unpackBtn_clicked();

    void on_chooseLocalFolderBtn_clicked();

    void on_chooseBackupFolderBtn_clicked();

    void on_restoreBtn_clicked();

    void bakupFolder();
    void on_sha1checkBtn_clicked();

    void on_pushToCloudBtn_clicked();

    void on_fetchFromCloudBtn_clicked();

private:
    Ui::MainWindow *ui;
    QFutureWatcher<QString> zipWatcher;
    QFutureWatcher<bool> unzipWatcher;
    QFutureWatcher<int> scpWatcher;
    QTimer *backupTimer;
    QThread *backupThread;
    void unzipFinishedCallback();
    void zipFinishedCallback();
    void scpFinishedCallback();

};
#endif // MAINWINDOW_H

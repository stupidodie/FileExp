#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "algorithm/Pack.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <set>
#include <QtConcurrent/QtConcurrent>
#include <QDir>
#include "utils.h"
#include "algorithm/Huffman.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fileList->setSelectionMode(QAbstractItemView::ExtendedSelection);
     ui->folderList->setSelectionMode(QAbstractItemView::ExtendedSelection);

     //set future watcher
     connect(&unzipWatcher, &QFutureWatcher<int>::finished, this, &MainWindow::unzipFinishedCallback);
     connect(&zipWatcher, &QFutureWatcher<int>::finished, this, &MainWindow::zipFinishedCallback);


     //backup thread
     this->backupThread = new QThread(this);
     this->backupTimer = new QTimer(0); //parent must be null
     backupTimer->setInterval(10000);
     backupTimer->moveToThread(backupThread);
     connect(backupTimer,SIGNAL(timeout()),this,SLOT(bakupFolder()));
     connect(backupThread, SIGNAL(started()), backupTimer, SLOT(start()));
     backupThread->start();
}

MainWindow::~MainWindow()
{
    backupThread->exit();
    backupTimer->stop();
    delete ui;
}


void MainWindow::on_addFileBtn_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
                               this,
                               "Select one or more files to open",
                               QDir::homePath(),
                               "All files (*.*)");
       ui->fileList->addItems(files);

}

void MainWindow::on_addFolderBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          QDir::homePath(),
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    ui->folderList->addItem(dir);
}




//remove file from fileList;
void MainWindow::on_removeFileBtn_clicked()
{

    auto items = ui->fileList ->selectedItems();
        for(auto &item :items){
               ui->fileList->takeItem(ui->fileList->row(item));
        }
}

void MainWindow::on_removeFolderBtn_clicked()
{
    auto items = ui->folderList ->selectedItems();
        for(auto &item :items){
               ui->folderList->takeItem(ui->folderList->row(item));
        }
}

void MainWindow::on_packFileBtn_clicked()
{


    if(ui->fileList->count() ==0 && ui->folderList->count() ==0){
    QMessageBox::information(this, tr("warning"),tr("both file and folder list is empty"));
    }else{
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                       "untitled.tgr",
                                                        tr("Zip file (*.tgr)"));

        const int fileCount = ui->fileList->count();
        const int foldersCount = ui->folderList->count();

        //   remove same files;
        std::vector<std::string> filesToPack;
        std::cout<<ui->fileList->count()<<std::endl;
        for(int i = 0;i < fileCount;i++){
          filesToPack.push_back(ui->fileList->item(i)->text().toStdString());
        }


        std::vector<std::string> foldersToPack;
        printf("vector size is %zu",filesToPack.size());
        for(int i = 0;i < foldersCount;i++){
            foldersToPack.push_back(ui->folderList->item(i)->text().toStdString());
        }
        QFuture<bool> future =  QtConcurrent::run(
                    &packFileAndFolder,
                    filesToPack,
                    foldersToPack,
                    fileName.toStdString());
        this->zipWatcher.setFuture(future);
    }
}

void MainWindow::unzipFinishedCallback()
{
    if(this->unzipWatcher.result()){
        QMessageBox::information(this, tr("info"),tr("finish"));
    }else {
        QMessageBox::information(this, tr("error"),tr("password is error"));
    }
}

void MainWindow::zipFinishedCallback()
{
    QMessageBox::information(this, tr("info"),tr("finish"));
}


void MainWindow::on_compressFileBtn_clicked()
{

    if(ui->fileList->count() ==0 && ui->folderList->count() ==0){
    QMessageBox::information(this, tr("warning"),tr("both file and folder list is empty"));
    }else if(ui->compressPasswordEdit->text().isEmpty() || ui->compressPasswordEdit->text().size() > 128){
        QMessageBox::information(this, tr("warning"),tr("password is valid"));
    }else {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                       "untitled.tgr",
                                       tr("Zip file (*.tgr)"));
        //remove same files;

        const int fileCount = ui->fileList->count();
        const int foldersCount = ui->folderList->count();

        //   remove same files;
        std::vector<std::string> filesToPack;
        std::cout<<ui->fileList->count()<<std::endl;
        for(int i = 0;i < fileCount;i++){
          filesToPack.push_back(ui->fileList->item(i)->text().toStdString());
        }


        std::vector<std::string> foldersToPack;
        printf("vector size is %zu",filesToPack.size());
        for(int i = 0;i < foldersCount;i++){
            foldersToPack.push_back(ui->folderList->item(i)->text().toStdString());
        }

        auto password = ui->compressPasswordEdit->text().toStdString();
        QFuture<bool> future =  QtConcurrent::run(
                    &MainWindow::packAndCompress,
                    filesToPack,
                    foldersToPack,
                    fileName.toStdString(),password,true);
        this->zipWatcher.setFuture(future);
    }
}


bool MainWindow::packAndCompress(const std::vector<std::string> &fileList, const std::vector<std::string> &folderList, const std::string &targetFileName,const std::string &password ,bool compress)
{
    packFileAndFolder(fileList,folderList,targetFileName);
    auto zipFileName = targetFileName + ".hz";
    compressFile(targetFileName.c_str(), zipFileName.c_str(),password.size(),password.c_str());
    return true;
}


bool MainWindow::unComprssAndunPack(const std::string &fileName, const std::string &folderName,const std::string & password ,bool onlyUnCompress)
{
    QString fullFileName(fileName.c_str());
    auto onlyFileName =  fullFileName.remove(0,fullFileName.lastIndexOf(QChar('/')));
    onlyFileName.chop(3);

    const  std::string packFileName = folderName + onlyFileName.toStdString();
    std::cout<<"extract "<<fileName<<" to "<<packFileName;
    std::cout.flush();
    bool result =  extract(fileName.c_str(),packFileName.c_str(),password.c_str());
    if(!result){
        return false;
    }
    if(!onlyUnCompress){
        unPackFileAndFolder(packFileName,folderName);
    }
    return true;
}


void MainWindow::on_openZipFileBtn_clicked()
{
    auto file = QFileDialog::getOpenFileName(
                               this,
                               "open .tgr.hz file",
                               QDir::homePath(),
                               ".tgr.hz files (*.tgr.hz)");
    ui->targetFileEdit->setText(file);
    //ui->targetFileEdit;
}



void MainWindow::on_unpackBtn_clicked()
{

    if(ui->targetFileEdit->text().trimmed().isEmpty()){
    QMessageBox::information(this, tr("warning"),tr("target file is empty"));
        return;
    }

    auto password = ui->extractPasswordEdit->text().trimmed();
    if(password.isEmpty() || password.size() >128){
        QMessageBox::information(this, tr("warning"),tr("invalid password"));
            return;
    }

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          QDir::homePath(),
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);

    const std::string folder = dir.toStdString();
    const std::string fileName =  ui->targetFileEdit->text().toStdString();
    std::cout<<folder<<"  "<<fileName<<"\n";
    std::cout.flush();
    QFuture<bool> future =  QtConcurrent::run(
                &MainWindow::unComprssAndunPack,
               fileName,folder ,ui->extractPasswordEdit->text().toStdString(),false);
    this->unzipWatcher.setFuture(future);
}





void MainWindow::on_chooseLocalFolderBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          QDir::homePath(),
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    ui->localBackupFolderEdit->setText(dir);
}

void MainWindow::on_chooseBackupFolderBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          QDir::homePath(),
                                                          QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    ui->targetBackupFolderEdit->setText(dir);
}


void MainWindow::bakupFolder()
{
    if(ui->localBackupFolderEdit->text().isEmpty() || ui->targetBackupFolderEdit->text().isEmpty())return;
    auto source = ui->localBackupFolderEdit->text();
    auto desc = ui->targetBackupFolderEdit->text() + "/" +QTime::currentTime().toString();
   //std::cout<<source.toStdString()<<"\n"<<desc.toStdString()<<std::endl;
    QtConcurrent::run(qCopyDirectory,source,desc,false);;
    auto diff = ui->backupTimer->time().secsTo(QTime::currentTime());
    if(diff > 0 && diff < 10){
        std::cout<<"this time show backup\n";
    }
    printf("%d\n",diff);
    fflush(stdout);
   // QString str = ui->localBackupFolderEdit->text() + " ==> "+ui->targetBackupFolderEdit->text() + "  "+ui->backupTimer->text();
   // std::cout<<str.toStdString()<<std::endl;
   // std::cout.flush();
    // printf("backup \n");
}

void MainWindow::on_restoreBtn_clicked()
{
    if(ui->localBackupFolderEdit->text().isEmpty() || ui->targetBackupFolderEdit->text().isEmpty()){
    QMessageBox::information(this, tr("warning"),tr("target file is empty"));
     return;
 }

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          ui->targetBackupFolderEdit->text(),
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    QMessageBox::information(this, tr("warning"), dir + " is restoring");
    auto restoreFolder = ui->localBackupFolderEdit->text() +"_restore";
    QtConcurrent::run(
                &qCopyDirectory,
                dir,
                restoreFolder,false);
}

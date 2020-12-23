/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *coppressTab;
    QListWidget *fileList;
    QPushButton *addFileBtn;
    QPushButton *removeFileBtn;
    QPushButton *packFileBtn;
    QPushButton *compressFileBtn;
    QListWidget *folderList;
    QPushButton *addFolderBtn;
    QPushButton *removeFolderBtn;
    QLineEdit *compressPasswordEdit;
    QLabel *label_2;
    QWidget *extractTab;
    QLineEdit *targetFileEdit;
    QPushButton *openZipFileBtn;
    QPushButton *unpackBtn;
    QLineEdit *extractPasswordEdit;
    QLabel *label_3;
    QWidget *tab;
    QLineEdit *localBackupFolderEdit;
    QLineEdit *targetBackupFolderEdit;
    QPushButton *chooseLocalFolderBtn;
    QPushButton *chooseBackupFolderBtn;
    QTimeEdit *backupTimer;
    QLabel *label;
    QPushButton *restoreBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(821, 614);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 571));
        coppressTab = new QWidget();
        coppressTab->setObjectName(QStringLiteral("coppressTab"));
        fileList = new QListWidget(coppressTab);
        fileList->setObjectName(QStringLiteral("fileList"));
        fileList->setGeometry(QRect(40, 30, 341, 331));
        addFileBtn = new QPushButton(coppressTab);
        addFileBtn->setObjectName(QStringLiteral("addFileBtn"));
        addFileBtn->setGeometry(QRect(20, 400, 131, 41));
        removeFileBtn = new QPushButton(coppressTab);
        removeFileBtn->setObjectName(QStringLiteral("removeFileBtn"));
        removeFileBtn->setGeometry(QRect(160, 400, 131, 41));
        packFileBtn = new QPushButton(coppressTab);
        packFileBtn->setObjectName(QStringLiteral("packFileBtn"));
        packFileBtn->setGeometry(QRect(400, 460, 121, 41));
        compressFileBtn = new QPushButton(coppressTab);
        compressFileBtn->setObjectName(QStringLiteral("compressFileBtn"));
        compressFileBtn->setGeometry(QRect(540, 460, 121, 41));
        folderList = new QListWidget(coppressTab);
        folderList->setObjectName(QStringLiteral("folderList"));
        folderList->setGeometry(QRect(400, 30, 361, 331));
        addFolderBtn = new QPushButton(coppressTab);
        addFolderBtn->setObjectName(QStringLiteral("addFolderBtn"));
        addFolderBtn->setGeometry(QRect(400, 400, 131, 41));
        removeFolderBtn = new QPushButton(coppressTab);
        removeFolderBtn->setObjectName(QStringLiteral("removeFolderBtn"));
        removeFolderBtn->setGeometry(QRect(540, 400, 121, 41));
        compressPasswordEdit = new QLineEdit(coppressTab);
        compressPasswordEdit->setObjectName(QStringLiteral("compressPasswordEdit"));
        compressPasswordEdit->setGeometry(QRect(160, 460, 131, 41));
        label_2 = new QLabel(coppressTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 457, 141, 41));
        tabWidget->addTab(coppressTab, QString());
        extractTab = new QWidget();
        extractTab->setObjectName(QStringLiteral("extractTab"));
        targetFileEdit = new QLineEdit(extractTab);
        targetFileEdit->setObjectName(QStringLiteral("targetFileEdit"));
        targetFileEdit->setGeometry(QRect(40, 110, 481, 51));
        openZipFileBtn = new QPushButton(extractTab);
        openZipFileBtn->setObjectName(QStringLiteral("openZipFileBtn"));
        openZipFileBtn->setGeometry(QRect(550, 110, 141, 51));
        unpackBtn = new QPushButton(extractTab);
        unpackBtn->setObjectName(QStringLiteral("unpackBtn"));
        unpackBtn->setGeometry(QRect(450, 220, 241, 51));
        extractPasswordEdit = new QLineEdit(extractTab);
        extractPasswordEdit->setObjectName(QStringLiteral("extractPasswordEdit"));
        extractPasswordEdit->setGeometry(QRect(240, 220, 151, 51));
        label_3 = new QLabel(extractTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 230, 131, 31));
        tabWidget->addTab(extractTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        localBackupFolderEdit = new QLineEdit(tab);
        localBackupFolderEdit->setObjectName(QStringLiteral("localBackupFolderEdit"));
        localBackupFolderEdit->setGeometry(QRect(120, 80, 341, 51));
        targetBackupFolderEdit = new QLineEdit(tab);
        targetBackupFolderEdit->setObjectName(QStringLiteral("targetBackupFolderEdit"));
        targetBackupFolderEdit->setGeometry(QRect(120, 160, 341, 51));
        chooseLocalFolderBtn = new QPushButton(tab);
        chooseLocalFolderBtn->setObjectName(QStringLiteral("chooseLocalFolderBtn"));
        chooseLocalFolderBtn->setGeometry(QRect(510, 80, 171, 51));
        chooseBackupFolderBtn = new QPushButton(tab);
        chooseBackupFolderBtn->setObjectName(QStringLiteral("chooseBackupFolderBtn"));
        chooseBackupFolderBtn->setGeometry(QRect(510, 160, 171, 51));
        backupTimer = new QTimeEdit(tab);
        backupTimer->setObjectName(QStringLiteral("backupTimer"));
        backupTimer->setGeometry(QRect(290, 250, 171, 51));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 250, 151, 51));
        restoreBtn = new QPushButton(tab);
        restoreBtn->setObjectName(QStringLiteral("restoreBtn"));
        restoreBtn->setGeometry(QRect(510, 250, 171, 51));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 821, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        addFileBtn->setText(QApplication::translate("MainWindow", "add file", Q_NULLPTR));
        removeFileBtn->setText(QApplication::translate("MainWindow", "remove file(s)", Q_NULLPTR));
        packFileBtn->setText(QApplication::translate("MainWindow", "pack", Q_NULLPTR));
        compressFileBtn->setText(QApplication::translate("MainWindow", "compress", Q_NULLPTR));
        addFolderBtn->setText(QApplication::translate("MainWindow", "add folders", Q_NULLPTR));
        removeFolderBtn->setText(QApplication::translate("MainWindow", "remove folders", Q_NULLPTR));
        compressPasswordEdit->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "setPassword here", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(coppressTab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        openZipFileBtn->setText(QApplication::translate("MainWindow", "open file", Q_NULLPTR));
        unpackBtn->setText(QApplication::translate("MainWindow", "unzip", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "set password here", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(extractTab), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        chooseLocalFolderBtn->setText(QApplication::translate("MainWindow", "choose local folder", Q_NULLPTR));
        chooseBackupFolderBtn->setText(QApplication::translate("MainWindow", "choose backup foder", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "select every  backup time", Q_NULLPTR));
        restoreBtn->setText(QApplication::translate("MainWindow", "restore", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

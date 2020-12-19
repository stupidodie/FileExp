#include "mainwindow.h"

#include <QApplication>
#include "utils.h"
#include <QDir>
#include <iostream>
int main(int argc, char *argv[])
{

        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("MagicCube");
    QCoreApplication::setOrganizationDomain("MagicCube.com");
    QCoreApplication::setApplicationName("MagicCube");

    MainWindow w;
    w.show();

    return a.exec();
}

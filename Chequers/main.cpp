#include "mainwindow.h"
#include <QApplication>
#include "webmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    CWebManager::GetInstance()->Connect("127.0.0.1");

    return a.exec();
}

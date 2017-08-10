#include "mainwindow.h"
#include <QApplication>
#include "webmanager.h"
#include "game.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    CWebManager::GetInstance()->Connect("127.0.0.1");
    CGame::GetInstance()->RegisterUser("k", "123");

//    CGame::GetInstance()->Login("konrad", "123");
    return a.exec();
}

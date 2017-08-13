#include "mainwindow.h"
#include <QApplication>
#include "webmanager.h"
#include "game.h"
#include "loginform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CLoginForm loginForm;
    CWebManager::GetInstance()->Connect("127.0.0.1");

    loginForm.SetMainWindow(&w);
    loginForm.show();


    //CGame::GetInstance()->RegisterUser("k", "123");

//    CGame::GetInstance()->Login("konrad", "123");
    return a.exec();
}

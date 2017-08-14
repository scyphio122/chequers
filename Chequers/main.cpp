#include "mainwindow.h"
#include <QApplication>
#include "webmanager.h"
#include "game.h"
#include "loginform.h"
#include <QList>
#include "player.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType< QList<CPlayer> >("QList<CPlayer>");
    qRegisterMetaType< CGame::E_GameState >("CGame::E_GameState");
    qRegisterMetaType< std::string >("std::string");
    //qRegisterMetaType< char[8][8] >("char[8][8]");

    QApplication a(argc, argv);
    MainWindow w;
    CLoginForm loginForm;
    if (!CWebManager::GetInstance()->Connect("127.0.0.1"))
    {
        LOG_CRITICAL("Could not connect. Aborting...");
        exit(0);
    }

    loginForm.SetMainWindow(&w);
    w.SetLoginForm(&loginForm);
    loginForm.show();


    //CGame::GetInstance()->RegisterUser("k", "123");

//    CGame::GetInstance()->Login("konrad", "123");
    return a.exec();
}

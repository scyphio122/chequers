#include "mainwindow.h"
#include <QApplication>
#include "webmanager.h"
#include "game.h"
#include "loginform.h"
#include <QList>
#include "player.h"
#include "logger.h"
#include "serverconnectform.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType< QList<CPlayer> >("QList<CPlayer>");
    qRegisterMetaType< CGame::E_GameState >("CGame::E_GameState");
    qRegisterMetaType< std::string >("std::string");
    //qRegisterMetaType< char[8][8] >("char[8][8]");

    QApplication a(argc, argv);
    MainWindow w;
    CLoginForm loginForm;
    CServerConnectForm connectForm;

    connectForm.SetLoginForm(&loginForm);
    loginForm.SetMainWindow(&w);
    w.SetLoginForm(&loginForm);
    connectForm.show();


    //CGame::GetInstance()->RegisterUser("k", "123");

//    CGame::GetInstance()->Login("konrad", "123");
    return a.exec();
}

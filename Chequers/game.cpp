#include "game.h"
#include <QThread>
#include "lock.h"
#include "webprotocolframe.h"
#include "webmanager.h"

CGame::CGame()
{
    m_userColor = E_SideColor::E_INVALID;
    m_state = E_GameState::E_NOT_INITIALIZED;

    m_pThread = new QThread();
    m_pMutex = new QMutex(QMutex::Recursive);

    connect(this, SIGNAL(destroyed(QObject*)), m_pThread, SLOT(deleteLater()));

    this->moveToThread(m_pThread);
    m_pThread->start();
}

CGame::~CGame()
{
    delete m_pMutex;
}

CGame* CGame::GetInstance()
{
    static CGame s_game;
    return &s_game;
}

bool CGame::Login(std::string username, std::string password)
{
    QByteArray serverResponse;
    CWebProtocolFrame frame;
    std::string params = username + "#" + password;

    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_LOGIN), params);

    CWebManager* webMan = CWebManager::GetInstance();
    webMan->SendData(frame.GetRawFrame(), frame.GetFrameSize());
    webMan->ReadDataSynchroneous(serverResponse);

    return true;
}

bool CGame::RegisterUser(std::string username, std::string password)
{
    QByteArray serverResponse;
    CWebProtocolFrame frame;
    std::string params = username + "#" + password;

    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_REGISTER_USER), params);

    CWebManager* webMan = CWebManager::GetInstance();
    webMan->SendData(frame.GetRawFrame(), frame.GetFrameSize());
    webMan->ReadDataSynchroneous(serverResponse);

    return true;
}


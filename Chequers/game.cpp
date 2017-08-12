#include "game.h"
#include <QThread>
#include "lock.h"
#include "webprotocolframe.h"
#include "webmanager.h"

CGame::CGame()
{
    m_userColor = E_SideColor::E_INVALID;
    m_state = E_GameState::E_NOT_INITIALIZED;

    m_pParser = CProtocolFrameParser::GetInstance();
    connect(CWebManager::GetInstance(), SIGNAL(signalDataAvailable(QByteArray)), m_pParser, SLOT(Parse(QByteArray)));

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

    return m_SendFrame(frame);
}

bool CGame::RegisterUser(std::string username, std::string password)
{
    CWebProtocolFrame frame;
    std::string params = username + "#" + password;

    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_REGISTER_USER), params);

    return m_SendFrame(frame);
}

bool CGame::StartNewGame(std::string secondPlayerName)
{
    CWebProtocolFrame frame;
    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_START_NEW_GAME), secondPlayerName);

    return m_SendFrame(frame);
}

bool CGame::Logout()
{
    CWebProtocolFrame frame;
    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_LOGOUT));

    bool retval = m_SendFrame(frame);
    if (retval)
        m_loggedIn = false;

    return retval;
}

bool CGame::Resign()
{
    CWebProtocolFrame frame;
    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_RESIGN));

    return m_SendFrame(frame);
}


void CGame::onLoginResponse(bool response)
{
    if (response == 1)
    {
        m_loggedIn = true;
        m_state = E_GameState::E_LOGGED_IN;
    }
    else
    {
        m_loggedIn = false;
        m_state = E_GameState::E_NOT_INITIALIZED;
    }
}

void CGame::onUserRegistrationResponse(bool response)
{

}

void CGame::onGetPlayersListResponse(QList<CPlayer> playersList)
{
    m_playersList = playersList;
}

void CGame::onBoardReceived(char board[][])
{
    memcpy(m_board, board, 64);
}

void CGame::onGameEnded(std::__cxx11::string result, std::__cxx11::string reason)
{

}

void CGame::onGameInitialization(char playerColor)
{
    m_userColor = playerColor;
}

bool CGame::m_SendFrame(CWebProtocolFrame &frame)
{
    int size = frame.GetFrameSize();
    int ret = CWebManager::GetInstance()->SendData(frame.GetRawFrame(), size);

    if (ret == size)
        return true;

    return false;
}

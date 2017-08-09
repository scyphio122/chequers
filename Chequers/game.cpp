#include "game.h"
#include <QThread>
#include "lock.h"
#include "webprotocolframe.h"
#include "webmanager.h"

std::map<CGame::E_ServerCommands, std::string>CGame::s_commandsMap =
{
    {CGame::E_ServerCommands::E_LOGIN, "LGN"},
    {CGame::E_ServerCommands::E_REGISTER_USER, "CRA"},
    {CGame::E_ServerCommands::E_GET_PLAYERS_LIST, "LSP"},
    {CGame::E_ServerCommands::E_START_NEW_GAME, "RFP"},
    {CGame::E_ServerCommands::E_NEW_GAME_REQUESTED, "RP1"},
    {CGame::E_ServerCommands::E_NEW_GAME_REQUEST_RESPONSE, "RP2"},
    {CGame::E_ServerCommands::E_GAME_INITIALIZATION, "INI"},
    {CGame::E_ServerCommands::E_BOARD, "CHB"},
    {CGame::E_ServerCommands::E_YOUR_MOVE, "YMV"},
    {CGame::E_ServerCommands::E_RESIGN, "GVU"},
    {CGame::E_ServerCommands::E_END_GAME, "EOG"},
    {CGame::E_ServerCommands::E_LOGOUT, "LGO"},
    {CGame::E_ServerCommands::E_ERROR, "ERR"},
    {CGame::E_ServerCommands::E_INCONSISTENCY, "ERS"},
};

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

bool CGame::Login(std::__cxx11::string username, std::__cxx11::string password)
{
    QByteArray serverResponse;
    CWebProtocolFrame frame;
    std::string params = username + "#" + password;

    frame.FormFrame(E_ServerCommands::E_LOGIN, params);

    CWebManager* webMan = CWebManager::GetInstance();
    webMan->SendData(frame.GetRawFrame(), frame.GetFrameSize());
    webMan->ReadDataSynchroneous(serverResponse);

    return true;
}

bool CGame::RegisterUser(std::__cxx11::string username, std::__cxx11::string password)
{
    QByteArray serverResponse;
    CWebProtocolFrame frame;
    std::string params = username + "#" + password;

    frame.FormFrame(E_ServerCommands::E_REGISTER_USER, params);

    CWebManager* webMan = CWebManager::GetInstance();
    webMan->SendData(frame.GetRawFrame(), frame.GetFrameSize());
    webMan->ReadDataSynchroneous(serverResponse);

    return true;
}

std::string CGame::m_getCommandString(CGame::E_ServerCommands command)
{
    return s_commandsMap[command];
}

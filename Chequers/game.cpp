#include "game.h"
#include <QThread>
#include "lock.h"
#include "webprotocolframe.h"
#include "webmanager.h"
#include "logger.h"

std::map<CGame::E_GameState, const char*> CGame::s_stateMap =
{
    {CGame::E_GameState::E_NOT_INITIALIZED, "NOT_INITIALIZED"},
    {CGame::E_GameState::E_LOGGED_IN, "LOGGED_IN"},
    {CGame::E_GameState::E_WAITING_FOR_ACCEPT, "WAITING_FOR_ACCEPT"},
    {CGame::E_GameState::E_GAME_REQUEST, "GAME_REQUEST"},
    {CGame::E_GameState::E_PLAYING_GAME, "PLAYING_GAME"}
};


CGame::CGame()
{
    m_userColor = E_SideColor::E_INVALID;
    m_state = E_GameState::E_NOT_INITIALIZED;

    m_pParser = CProtocolFrameParser::GetInstance();

    connect(m_pParser, SIGNAL(signalLoginRetval(bool)), this, SLOT(onLoginResponse(bool)));
    connect(m_pParser, SIGNAL(signalRegisterRetval(bool)), this, SLOT(onUserRegistrationResponse(bool)));
    connect(m_pParser, SIGNAL(signalListOfPlayersReceived(QList<CPlayer>)), this, SLOT(onGetPlayersListResponse(QList<CPlayer>)));
    connect(m_pParser, SIGNAL(signalNewGameRequestPassed(int)), this, SLOT(onStartNewGameServerResponse(int)));
    connect(m_pParser, SIGNAL(signalNewGameRequestResponse(int)), this, SLOT(onNewGameRequestPlayerResponse(int)));
    connect(m_pParser, SIGNAL(signalNewGameRequested(std::string)), this, SLOT(onNewGameRequested(std::string)));
    connect(m_pParser, SIGNAL(signalGameInitialization(char)), this, SLOT(onGameInitialization(char)));
    connect(m_pParser, SIGNAL(signalBoardReceived(char[8][8])), this, SLOT(onBoardReceived(char[8][8])));
    connect(m_pParser, SIGNAL(signalYourMove(bool)), this, SLOT(onYourMove(bool)));
    connect(m_pParser, SIGNAL(signalGameEnded(std::string,std::string)), this, SLOT(onGameEnded(std::string,std::string)));

    connect(CWebManager::GetInstance(), SIGNAL(signalDataAvailable(QByteArray)), m_pParser, SLOT(Parse(QByteArray)));

    m_pMutex = new QMutex(QMutex::Recursive);

    m_pThread = new QThread();
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

char* CGame::GetBoard()
{
    return &m_board[0][0];
}

std::string CGame::GetUserName()
{
    return m_userName;
}
/*
 *  ###############################################
 *   ################  GAME API  ###################
 *  ###############################################
*/

bool CGame::Login(std::string username, std::string password)
{
    if (m_state != E_GameState::E_NOT_INITIALIZED)
    {
        LOG_CRITICAL("Unexpected state. Is %s, should be %s", s_stateMap[m_state], s_stateMap[E_GameState::E_NOT_INITIALIZED]);
        return false;
    }

    CWebProtocolFrame frame;
    std::string params = username + "#" + password;

    m_userName = username;
    frame.FormFrame(CWebProtocolFrame::E_ServerCommands::E_LOGIN, params);

    return m_SendFrame(frame);
}

bool CGame::RegisterUser(std::string username, std::string password)
{
    if (m_state != E_GameState::E_NOT_INITIALIZED)
    {
        LOG_CRITICAL("Unexpected state. Is %s, should be %s", s_stateMap[m_state], s_stateMap[E_GameState::E_NOT_INITIALIZED]);
        return false;
    }

    CWebProtocolFrame frame;
    std::string params = username + "#" + password;

    frame.FormFrame(CWebProtocolFrame::E_ServerCommands::E_REGISTER_USER, params);

    return m_SendFrame(frame);
}

bool CGame::GetPlayersList()
{
    if (m_state != E_GameState::E_LOGGED_IN)
    {
        LOG_CRITICAL("Unexpected state. Is %s, should be %s", s_stateMap[m_state], s_stateMap[E_GameState::E_LOGGED_IN]);
        return false;
    }

    CWebProtocolFrame frame;
    frame.FormFrame(CWebProtocolFrame::E_ServerCommands::E_GET_PLAYERS_LIST);

    return m_SendFrame(frame);
}

bool CGame::StartNewGame(std::string secondPlayerName)
{
    if (m_state != E_GameState::E_LOGGED_IN)
    {
        LOG_CRITICAL("Unexpected state. Is %s, should be %s", s_stateMap[m_state], s_stateMap[E_GameState::E_LOGGED_IN]);
        return false;
    }

    CWebProtocolFrame frame;
    frame.FormFrame(CWebProtocolFrame::E_ServerCommands::E_START_NEW_GAME, secondPlayerName);

    return m_SendFrame(frame);
}

bool CGame::RespondToGameInvitation(bool accept)
{
    CWebProtocolFrame frame;
    std::string param;

    if (accept)
    {
        param = "1";
    }
    else
    {
        param = "0";
    }

    frame.FormFrame(CWebProtocolFrame::E_ServerCommands::E_NEW_GAME_REQUEST_RESPONSE, param);

    bool retval = m_SendFrame(frame);

    if (retval)
    {
        m_changeState(E_GameState::E_GAME_REQUEST);
    }
    else
    {
        m_changeState(E_GameState::E_LOGGED_IN);
    }

    return retval;
}

bool CGame::Logout()
{
    if (m_state != E_GameState::E_WAITING_FOR_ACCEPT && m_state != E_GameState::E_LOGGED_IN)
    {
        LOG_CRITICAL("Unexpected state. Is %s, should be %s or %s", s_stateMap[m_state], s_stateMap[E_GameState::E_WAITING_FOR_ACCEPT], s_stateMap[E_GameState::E_LOGGED_IN]);
        return false;
    }

    CWebProtocolFrame frame;
    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_LOGOUT));

    bool retval = m_SendFrame(frame);
    if (retval)
    {
        m_loggedIn = false;
        m_userName = "";
        m_changeState(E_GameState::E_NOT_INITIALIZED);
        emit signalLogout();
    }

    return retval;
}

bool CGame::Resign()
{
    if (m_state != E_GameState::E_PLAYING_GAME)
    {
        LOG_CRITICAL("Unexpected state. Is %s, should be %s", s_stateMap[m_state], s_stateMap[E_GameState::E_PLAYING_GAME]);
        return false;
    }

    CWebProtocolFrame frame;
    frame.FormFrame(CWebProtocolFrame::GetCommandFromMap(CWebProtocolFrame::E_ServerCommands::E_RESIGN));

    return m_SendFrame(frame);
}


/*
 *  ###############################################
 *   ################  CALLBACKS ###################
 *  ###############################################
*/

void CGame::onLoginResponse(bool response)
{
    if (response == 1)
    {
        m_loggedIn = true;
        m_changeState(E_GameState::E_LOGGED_IN);
        GetPlayersList();
    }
    else
    {
        m_userName = "";
        m_loggedIn = false;
        m_changeState(E_GameState::E_NOT_INITIALIZED);
    }
}

void CGame::onUserRegistrationResponse(bool response)
{
    // Probably this signal is useful for GUI only
}

void CGame::onGetPlayersListResponse(QList<CPlayer> playersList)
{
    m_playersList = playersList;
}

void CGame::onStartNewGameServerResponse(int result)
{
    //   If request was successfully passed to the player
    if (result > 0)
        m_changeState(E_GameState::E_WAITING_FOR_ACCEPT);
    else   // If player is no longer available
        LOG_CRITICAL("Player not available");
}

void CGame::onNewGameRequested(std::__cxx11::string hostPlayerName)
{
    LOG_DBG("Received new game request from player: %s", hostPlayerName.c_str());
}

void CGame::onNewGameRequestPlayerResponse(int response)
{
    LOG_DBG("Player has %s the invitation", response? "accepted" : "declined");

    if (response > 0)
    {
        m_changeState(E_GameState::E_GAME_REQUEST);
    }
    else
    {
        m_changeState(E_GameState::E_LOGGED_IN);
    }
}

void CGame::onGameInitialization(char playerColor)
{
    m_userColor = (E_SideColor)playerColor;
    m_changeState(E_GameState::E_PLAYING_GAME);
}

void CGame::onBoardReceived(char board[8][8])
{
    memcpy(m_board, board, 64);

    emit signalRedrawBoard();
}

void CGame::onYourMove(bool status)
{
    // TODO: TO FILL
}

void CGame::onGameEnded(std::__cxx11::string result, std::__cxx11::string reason)
{
    LOG_DBG("Game has ended. You %s! Reason for game end is %s", result.c_str(), reason.c_str());
    m_changeState(E_GameState::E_LOGGED_IN);
    GetPlayersList();
}


/*
 *  #######################################################
 *   ################  PRIVATE FUNCTIONS ###################
 *  #######################################################
*/

bool CGame::m_SendFrame(CWebProtocolFrame &frame)
{
    int size = frame.GetFrameSize();
    int ret = CWebManager::GetInstance()->SendData(frame.GetRawFrame(), size);

    if (ret == size)
        return true;

    return false;
}

bool CGame::m_changeState(E_GameState newState)
{
    LOG_DBG("Changing state from %s to %s", s_stateMap[m_state], s_stateMap[newState]);

    m_state = newState;
    emit signalStateChanged(newState);

    return true;
}

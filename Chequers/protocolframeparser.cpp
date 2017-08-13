#include "protocolframeparser.h"
#include <QList>
#include <QByteArray>
#include "webprotocolframe.h"
#include "logger.h"
#include "player.h"

CProtocolFrameParser::CProtocolFrameParser()
{

}

CProtocolFrameParser* CProtocolFrameParser::GetInstance()
{
    static CProtocolFrameParser s_instance;
    return &s_instance;
}

void CProtocolFrameParser::Parse(QByteArray receivedData)
{
        QList<QByteArray> listOfFrames = m_getFrames(receivedData);

        for (int i=0; i<listOfFrames.size(); ++i)
        {
            CWebProtocolFrame frame = m_formFrame(listOfFrames[i]);

            m_parseFrame(frame);
        }
}

QList<QByteArray> CProtocolFrameParser::m_getFrames(QByteArray receivedBuffer)
{
    QList<QByteArray> packets = receivedBuffer.split('\n');

    // Remove the '\r' char if included
    for(int i=0; i<packets.size(); ++i)
    {
        packets[i] = packets[i].split('\r')[0];
    }

    for (int i=0; i<packets.size(); ++i)
    {
        if (packets[i].size() == 0)
        {
            packets.removeAt(i);
        }
    }
    return packets;
}

CWebProtocolFrame CProtocolFrameParser::m_formFrame(QByteArray& singleFrame)
{
    CWebProtocolFrame frame;
    frame.FormFrameFromReceivedData(singleFrame.toStdString());
    return frame;
}

void CProtocolFrameParser::m_parseFrame(CWebProtocolFrame& frame)
{

    std::string cmd = frame.GetCommand().toStdString();
    QList<QByteArray> params = frame.GetParameters();
    LOG_DBG("CMD: %s, paramsSize: %d", cmd.c_str(), params.size());

    CWebProtocolFrame::E_ServerCommands commandEnum = CWebProtocolFrame::GetCommandFromMap(cmd);

    switch (commandEnum)
    {
        case CWebProtocolFrame::E_ServerCommands::E_LOGIN:
            {
                if (params.size() == 1)
                {
                    int loginSuccess = params[0].toUShort();
                    LOG_DBG("Login %s", loginSuccess? "success" : "fail");

                    emit signalLoginRetval(loginSuccess);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_REGISTER_USER:
            {
                if (params.size() == 1)
                {
                    int registerSuccess = params[0].toUShort();
                    LOG_DBG("Register %s", registerSuccess? "success" : "fail");

                    emit signalRegisterRetval((bool)registerSuccess);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_BOARD:
            {
                if (params.size() == 1)
                {
                    char board[8][8];
                    memcpy(board, params[0].data(), sizeof(board));
                    emit signalBoardReceived(board);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_GAME_ENDED:
            {
                if (params.size() == 2)
                {
                    emit signalGameEnded(params[0].toStdString(), params[1].toStdString());
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_GAME_INITIALIZATION:
            {
                if (params.size() == 1)
                {
                    char playerColor = static_cast<char>(params[0].toInt());

                    emit signalGameInitialization(playerColor);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_GET_PLAYERS_LIST:
            {
                QList<CPlayer> playersList;
                LOG_DBG("Number of players available ond server: %d", params.size());
                for (int i=0; i< params.size(); i+=2)
                {
                    playersList.append(CPlayer(params[i].toStdString(), (CPlayer::E_PlayerStatus)(params[i+1].toStdString()[0])));
                }

                emit signalListOfPlayersReceived(playersList);
            }break;


        case CWebProtocolFrame::E_ServerCommands::E_INCONSISTENCY:
            {
                if (params.size() == 1)
                {
                    LOG_FATAL("Error inconsistency: %s", params[0].toStdString());
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_LOGOUT:
            {
                LOG_WARNING("UNEXPECTED FRAME TYPE");
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_NEW_GAME_REQUESTED:
            {
                if (params.size() == 1)
                {
                    std::string newGamePlayerName = params[0].toStdString();
                    LOG_DBG("PLayer: '%s' has requested new game", newGamePlayerName.c_str());

                    emit signalNewGameRequested(newGamePlayerName);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_NEW_GAME_REQUEST_RESPONSE:
            {
                if (params.size() == 1)
                {
                    int requestStatus = params[0].toInt();
                    LOG_DBG("Response from player: %s", requestStatus? "Invitation accepted" : "Invitation declined");
                    emit signalNewGameRequestResponse(requestStatus);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_RESIGN:
            {
                LOG_WARNING("UNEXPECTED FRAME TYPE");
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_START_NEW_GAME:
            {
                if (params.size() == 1)
                {
                    int requestStatus = params[0].toInt();
                    LOG_DBG("Response from server to starting new game: %s", requestStatus? "Request passed to player" : "Player does not exist");
                    emit signalNewGameRequestPassed(requestStatus);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_YOUR_MOVE:
            {

            }break;

        case CWebProtocolFrame::E_ServerCommands::E_ERROR:
        {
            if (params.size() == 1)
            {
                LOG_FATAL("Error command: %s", params[0].toStdString());
            }
            else
            {
                LOG_FATAL("Wrong number of parameters");
            }
        }break;

        default:
        {
            LOG_CRITICAL("Unknown command. Returning...");
        }break;
    }
}

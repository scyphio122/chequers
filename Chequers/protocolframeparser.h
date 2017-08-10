#ifndef PROTOCOLFRAMEPARSER_H
#define PROTOCOLFRAMEPARSER_H

#include <QObject>
#include <QList>
#include <QByteArray>
#include "webprotocolframe.h"

class CProtocolFrameParser : public QObject
{
    Q_OBJECT
public:
    static CProtocolFrameParser* GetInstance();

signals:
    void signalLoginRetval(bool success);

    void signalRegisterRetval(bool success);

    void signalListOfPlayersReceived(QList<QByteArray> playersList);

    void signalNewGameRequested(std::string playerName);

public slots:
    void Parse(QByteArray receivedData);

private:
    CProtocolFrameParser();

    QList<QByteArray> m_getFrames(QByteArray receivedBuffer);

    CWebProtocolFrame m_formFrame(QByteArray& singleFrame);

    void m_parseFrame(CWebProtocolFrame& frame);

    /// Buffer containing data which could not be parsed into full protocol packets/messages
    QByteArray m_partialData;
};

#endif // PROTOCOLFRAMEPARSER_H

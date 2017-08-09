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
    CProtocolFrameParser* GetInstance();


signals:

public slots:

private:
    CProtocolFrameParser();

    QList<QByteArray> m_getFrames(QByteArray receivedBuffer);

    CWebProtocolFrame m_getSingleFrame(QByteArray& singleFrame);

    void m_parseFrame(CWebProtocolFrame& frame);

    /// Buffer containing data which could not be parsed into full protocol packets/messages
    QByteArray m_partialData;
};

#endif // PROTOCOLFRAMEPARSER_H

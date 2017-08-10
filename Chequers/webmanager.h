#ifndef WEBMANAGER_H
#define WEBMANAGER_H

#include <string>
#include <QThread>
#include <QMutex>
#include <QByteArray>
#include <QTimer>

class CWebManager : public QObject
{
    Q_OBJECT
public:
    static CWebManager* GetInstance();

    bool Connect(std::string ip);

    bool Disconnect();

    int SendData(void* data, int dataSize);

    void ReadDataSynchroneous(QByteArray& response);

    static QMutex* s_pWebMutex;

signals:
    void signalDataAvailable(QByteArray data);

private:
    CWebManager();

    ~CWebManager();

    bool m_connect();

    bool m_startCyclicReceiveCheck();

    void m_cancelCyclicReceiveCheck();

    const int M_SERVER_PORT = 4000;

    static const int M_RECEIVE_DATA_BUFFER_SIZE = 1024;

    const int M_RECEIVE_TIMEOUT_MS = 100;

    std::string m_serverIpAddress;

    bool m_isConnected;

    int m_socketDescriptor;

    QThread* m_networkThread;

    QTimer* m_pReceiveTimer;

    bool m_serverResponseTimeout;

    char m_receiveBuf[M_RECEIVE_DATA_BUFFER_SIZE];

private slots:
    void m_getDataIfAvailable();
};

#endif // WEBMANAGER_H

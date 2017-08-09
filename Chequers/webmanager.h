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
    void signalDataAvailable(QByteArray* data, int dataSize);

private:
    CWebManager();

    ~CWebManager();

    bool m_connect();



    bool m_startReceiveTimeout();

    void m_cancelReceiveTimeout();

    const int M_SERVER_PORT = 4000;

    const int M_RECEIVE_DATA_BUFFER_SIZE = 1024;

    const int M_RECEIVE_TIMEOUT_MS = 400;

    std::string m_serverIpAddress;

    bool m_isConnected;

    int m_socketDescriptor;

    QThread* m_networkThread;

    QByteArray m_receiveDataArray;

    QTimer* m_pReceiveTimer;

    bool m_serverResponseTimeout;

private slots:
    void m_receiveTimerTimeoutCallback();

    void m_getDataIfAvailable();
};

#endif // WEBMANAGER_H

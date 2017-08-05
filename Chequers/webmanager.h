#ifndef WEBMANAGER_H
#define WEBMANAGER_H

#include <string>
#include <QThread>
#include <QMutex>

class CWebManager : public QObject
{
    Q_OBJECT
public:
    static CWebManager* GetInstance();

    bool Connect(std::string ip);

    bool Disconnect();

    int SendData(void* data, int dataSize);


private:
    CWebManager();

    ~CWebManager();

    bool m_connect();

    const int M_SERVER_PORT = 8088;

    std::string m_serverIpAddress;

    bool m_isConnected;

    int m_socketDescriptor;

    QThread* m_networkThread;

    QMutex m_sendMutex;

    QMutex m_readMutex;
};

#endif // WEBMANAGER_H

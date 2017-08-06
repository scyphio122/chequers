#ifndef WEBMANAGER_H
#define WEBMANAGER_H

#include <string>
#include <QThread>
#include <QMutex>
#include <QByteArray>
class CWebManager : public QObject
{
    Q_OBJECT
public:
    static CWebManager* GetInstance();

    bool Connect(std::string ip);

    bool Disconnect();

    int SendData(void* data, int dataSize);

signals:
    void signalDataAvailable(QByteArray* data, int dataSize);

private:
    CWebManager();

    ~CWebManager();

    bool m_connect();

    void m_getDataIfAvailable();

    const int M_SERVER_PORT = 8088;

    const int M_RECEIVE_DATA_BUFFER_SIZE = 1024;

    std::string m_serverIpAddress;

    bool m_isConnected;

    int m_socketDescriptor;

    QThread* m_networkThread;

    QByteArray m_receiveDataArray;

    QMutex* m_pWebMutex;
};

#endif // WEBMANAGER_H

#include "webmanager.h"
#include "logger.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "lock.h"
#include <QMutex>


#define NET_MUTEX_LOCK CLock(m_pWebMutex)

CWebManager::CWebManager()
{
    m_networkThread = new QThread(this);
    this->moveToThread(m_networkThread);

    connect(this, SIGNAL(destroyed(QObject*)), m_networkThread, SLOT(deleteLater()));

    m_isConnected = false;
    m_socketDescriptor = -1;
    m_pWebMutex = new QMutex();

    m_receiveDataArray.resize(M_RECEIVE_DATA_BUFFER_SIZE);

    m_networkThread->start();
}

CWebManager* CWebManager::GetInstance()
{
    static CWebManager s_instance;
    return &s_instance;
}

CWebManager::~CWebManager()
{
    delete m_pWebMutex;
}

bool CWebManager::Connect(std::__cxx11::string ip)
{
    if (m_isConnected)
    {
        LOG_WARNING("Already connected: m_socketDescriptor: %d", m_socketDescriptor);
        return false;
    }
    m_socketDescriptor = socket(AF_INET , SOCK_STREAM , 0);

    if (m_socketDescriptor == -1)
    {
        LOG_CRITICAL("Could not create socket. m_socketDescriptror: %d", m_socketDescriptor);
        return false;
    }

    m_serverIpAddress = ip;
    LOG_DBG("Trying to connect to IP: \'%s\', socketDescriptor: %d", ip.c_str(), m_socketDescriptor);

    if (!m_connect())
    {
        LOG_CRITICAL("Connecting failed.");
    }

    LOG_DBG("Connected successfully");
    m_isConnected = true;

    return true;
}

bool CWebManager::Disconnect()
{
    NET_MUTEX_LOCK;
    LOG_DBG(" ");
    // Close the socket
    close(m_socketDescriptor);
    m_socketDescriptor = -1;
    m_isConnected = false;

    return true;
}

int CWebManager::SendData(void *data, int dataSize)
{
    NET_MUTEX_LOCK;
    if (!m_isConnected)
    {
        LOG_CRITICAL("Not connected. Returning");
        return 0;
    }

   int size = send(m_socketDescriptor, data, dataSize, 0);
   return size;
}

void CWebManager::m_getDataIfAvailable()
{
    NET_MUTEX_LOCK;
    int size = recv(m_socketDescriptor, m_receiveDataArray.data(), M_RECEIVE_DATA_BUFFER_SIZE, MSG_DONTWAIT);

    if (size == -1)
    {
        if (errno == EWOULDBLOCK || errno == EAGAIN)
        {
            return;
        }
        else
        {
            LOG_ERRNO();
        }
    }

    emit signalDataAvailable(&m_receiveDataArray, size);
}

bool CWebManager::m_connect()
{
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(m_serverIpAddress.c_str());
    server.sin_port = htons(M_SERVER_PORT);

    if (::connect(m_socketDescriptor, (sockaddr*)&server, sizeof(server)) == -1)
    {
        LOG_CRITICAL("Could not connect to server.");
        return false;
    }

    return true;
}

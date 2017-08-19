#ifndef WEBMANAGER_H
#define WEBMANAGER_H

#include <string>
#include <QThread>
#include <QMutex>
#include <QByteArray>
#include <QTimer>

/**
 * @brief The CWebManager class - Class managing the Network communication
 */
class CWebManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief GetInstance - Return the instance of the web manager
     * @return
     */
    static CWebManager* GetInstance();

    /**
     * @brief Connect - Function connecting to the server
     * @param ip - ip of the server ot connect to
     * @return true if connected, false otherwise
     */
    bool Connect(std::string ip);

    /**
     * @brief Disconnect - Function for disconnecting from the server
     * @return true if disconnected, false otherwise
     */
    bool Disconnect();

    /**
     * @brief SendData - Function to send some data via network
     * @param data [in]- data to be sent
     * @param dataSize [in] - size of data to send
     * @return size of data actually sent
     */
    int SendData(void* data, int dataSize);

    /**
     * @brief ReadDataSynchroneous - Function for synchroneous read of data
     * @param response - pointer to the bufer in which the received data is to be put
     */
    void ReadDataSynchroneous(QByteArray& response);


signals:
    /**
     * @brief signalDataAvailable - signal emitted when the data is available
     * @param data [out] - data which were read. To be parsed
     */
    void signalDataAvailable(QByteArray data);

private:
    CWebManager();

    ~CWebManager();

    /**
     * @brief m_connect - server connection worker
     * @return  true if connected, false otherwise
     */
    bool m_connect();

    /**
     * @brief m_startCyclicReceiveCheck - start the timer which does cyclic data available to read check
     * @return true if timer started
     */
    bool m_startCyclicReceiveCheck();

    /**
     * @brief m_cancelCyclicReceiveCheck - stop the timer which does cyclic data available to read check
     */
    void m_cancelCyclicReceiveCheck();

    /**
     * @brief M_SERVER_PORT - port number for the server to listen to
     */
    const int M_SERVER_PORT = 4000;

    /**
     * @brief M_RECEIVE_DATA_BUFFER_SIZE - size of the receive buffer
     */
    static const int M_RECEIVE_DATA_BUFFER_SIZE = 1024;

    /**
     * @brief M_RECEIVE_TIMEOUT_MS - time between two available data to read data checks
     */
    const int M_RECEIVE_TIMEOUT_MS = 100;

    /**
     * @brief m_serverIpAddress - ip of the server application is connected to
     */
    std::string m_serverIpAddress;

    /**
     * @brief m_isConnected - true if connected
     */
    bool m_isConnected;

    /**
     * @brief m_socketDescriptor - descriptor of the data socket
     */
    int m_socketDescriptor;

    /**
     * @brief m_networkThread - pointer to the thread in which the object runs
     */
    QThread* m_networkThread;

    /**
     * @brief m_pReceiveTimer - pointer to the timer which does cyclic data to read check
     */
    QTimer* m_pReceiveTimer;

    /**
     * @brief m_receiveBuf - buffer for receive data
     */
    char m_receiveBuf[M_RECEIVE_DATA_BUFFER_SIZE];

    /**
     * @brief s_pWebMutex - pointer to the mutex
     */
    static QMutex* s_pWebMutex;

private slots:
    /**
     * @brief m_getDataIfAvailable - function which does cyclic ready to read data
     */
    void m_getDataIfAvailable();
};

#endif // WEBMANAGER_H

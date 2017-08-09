#ifndef CGAME_H
#define CGAME_H

#include <QObject>
#include <QMutex>
#include "webprotocolframe.h"

class CGame : public QObject
{
    Q_OBJECT
public:

    enum class E_SideColor : char
    {
        E_INVALID,
        E_WHITE = 'B',
        E_BLACK = 'C'
    };

    ~CGame();

    static CGame* GetInstance();

    bool Login(std::string username, std::string password);

    bool RegisterUser(std::string username, std::string password);

    bool MakeMove();
signals:

public slots:

private:

    enum class E_GameState : unsigned char
    {
        E_NOT_INITIALIZED,
    };


    CGame();

    E_GameState m_state;

    E_SideColor m_userColor;

    char m_board[8][8];

    QThread* m_pThread;

    QMutex* m_pMutex;
};

#endif // CGAME_H

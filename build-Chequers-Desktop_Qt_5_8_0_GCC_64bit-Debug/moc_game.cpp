/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Chequers/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGame_t {
    QByteArrayData data[30];
    char stringdata0[440];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGame_t qt_meta_stringdata_CGame = {
    {
QT_MOC_LITERAL(0, 0, 5), // "CGame"
QT_MOC_LITERAL(1, 6, 18), // "signalStateChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "CGame::E_GameState"
QT_MOC_LITERAL(4, 45, 8), // "newState"
QT_MOC_LITERAL(5, 54, 17), // "signalRedrawBoard"
QT_MOC_LITERAL(6, 72, 12), // "signalLogout"
QT_MOC_LITERAL(7, 85, 14), // "signalMoveMade"
QT_MOC_LITERAL(8, 100, 15), // "onLoginResponse"
QT_MOC_LITERAL(9, 116, 8), // "response"
QT_MOC_LITERAL(10, 125, 26), // "onUserRegistrationResponse"
QT_MOC_LITERAL(11, 152, 24), // "onGetPlayersListResponse"
QT_MOC_LITERAL(12, 177, 14), // "QList<CPlayer>"
QT_MOC_LITERAL(13, 192, 11), // "playersList"
QT_MOC_LITERAL(14, 204, 28), // "onStartNewGameServerResponse"
QT_MOC_LITERAL(15, 233, 6), // "result"
QT_MOC_LITERAL(16, 240, 18), // "onNewGameRequested"
QT_MOC_LITERAL(17, 259, 11), // "std::string"
QT_MOC_LITERAL(18, 271, 14), // "hostPlayerName"
QT_MOC_LITERAL(19, 286, 30), // "onNewGameRequestPlayerResponse"
QT_MOC_LITERAL(20, 317, 20), // "onGameInitialization"
QT_MOC_LITERAL(21, 338, 11), // "playerColor"
QT_MOC_LITERAL(22, 350, 15), // "onBoardReceived"
QT_MOC_LITERAL(23, 366, 5), // "char*"
QT_MOC_LITERAL(24, 372, 5), // "board"
QT_MOC_LITERAL(25, 378, 10), // "onYourMove"
QT_MOC_LITERAL(26, 389, 6), // "status"
QT_MOC_LITERAL(27, 396, 11), // "onGameEnded"
QT_MOC_LITERAL(28, 408, 6), // "reason"
QT_MOC_LITERAL(29, 415, 24) // "onMakeMoveServerResponse"

    },
    "CGame\0signalStateChanged\0\0CGame::E_GameState\0"
    "newState\0signalRedrawBoard\0signalLogout\0"
    "signalMoveMade\0onLoginResponse\0response\0"
    "onUserRegistrationResponse\0"
    "onGetPlayersListResponse\0QList<CPlayer>\0"
    "playersList\0onStartNewGameServerResponse\0"
    "result\0onNewGameRequested\0std::string\0"
    "hostPlayerName\0onNewGameRequestPlayerResponse\0"
    "onGameInitialization\0playerColor\0"
    "onBoardReceived\0char*\0board\0onYourMove\0"
    "status\0onGameEnded\0reason\0"
    "onMakeMoveServerResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   95,    2, 0x0a /* Public */,
      10,    1,   98,    2, 0x0a /* Public */,
      11,    1,  101,    2, 0x0a /* Public */,
      14,    1,  104,    2, 0x0a /* Public */,
      16,    1,  107,    2, 0x0a /* Public */,
      19,    1,  110,    2, 0x0a /* Public */,
      20,    1,  113,    2, 0x0a /* Public */,
      22,    1,  116,    2, 0x0a /* Public */,
      25,    1,  119,    2, 0x0a /* Public */,
      27,    2,  122,    2, 0x0a /* Public */,
      29,    1,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Char,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17,   15,   28,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void CGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGame *_t = static_cast<CGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalStateChanged((*reinterpret_cast< CGame::E_GameState(*)>(_a[1]))); break;
        case 1: _t->signalRedrawBoard(); break;
        case 2: _t->signalLogout(); break;
        case 3: _t->signalMoveMade(); break;
        case 4: _t->onLoginResponse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onUserRegistrationResponse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onGetPlayersListResponse((*reinterpret_cast< QList<CPlayer>(*)>(_a[1]))); break;
        case 7: _t->onStartNewGameServerResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onNewGameRequested((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->onNewGameRequestPlayerResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onGameInitialization((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 11: _t->onBoardReceived((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 12: _t->onYourMove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->onGameEnded((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 14: _t->onMakeMoveServerResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CGame::*_t)(CGame::E_GameState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CGame::signalStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CGame::signalRedrawBoard)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CGame::signalLogout)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CGame::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CGame::signalMoveMade)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject CGame::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CGame.data,
      qt_meta_data_CGame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CGame.stringdata0))
        return static_cast<void*>(const_cast< CGame*>(this));
    return QObject::qt_metacast(_clname);
}

int CGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void CGame::signalStateChanged(CGame::E_GameState _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGame::signalRedrawBoard()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CGame::signalLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CGame::signalMoveMade()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

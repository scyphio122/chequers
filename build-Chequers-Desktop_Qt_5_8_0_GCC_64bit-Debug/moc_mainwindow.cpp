/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Chequers/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[38];
    char stringdata0[599];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "onLogin"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 6), // "result"
QT_MOC_LITERAL(4, 27, 24), // "onGetPlayersListResponse"
QT_MOC_LITERAL(5, 52, 14), // "QList<CPlayer>"
QT_MOC_LITERAL(6, 67, 16), // "availablePlayers"
QT_MOC_LITERAL(7, 84, 28), // "onStartNewGameServerResponse"
QT_MOC_LITERAL(8, 113, 18), // "onNewGameRequested"
QT_MOC_LITERAL(9, 132, 11), // "std::string"
QT_MOC_LITERAL(10, 144, 14), // "hostPlayerName"
QT_MOC_LITERAL(11, 159, 30), // "onNewGameRequestPlayerResponse"
QT_MOC_LITERAL(12, 190, 8), // "response"
QT_MOC_LITERAL(13, 199, 20), // "onGameInitialization"
QT_MOC_LITERAL(14, 220, 11), // "playerColor"
QT_MOC_LITERAL(15, 232, 15), // "onBoardReceived"
QT_MOC_LITERAL(16, 248, 5), // "char*"
QT_MOC_LITERAL(17, 254, 5), // "board"
QT_MOC_LITERAL(18, 260, 11), // "onGameEnded"
QT_MOC_LITERAL(19, 272, 6), // "reason"
QT_MOC_LITERAL(20, 279, 8), // "onLogout"
QT_MOC_LITERAL(21, 288, 10), // "onYourMove"
QT_MOC_LITERAL(22, 299, 18), // "onGameStateChanged"
QT_MOC_LITERAL(23, 318, 18), // "CGame::E_GameState"
QT_MOC_LITERAL(24, 337, 8), // "newState"
QT_MOC_LITERAL(25, 346, 15), // "onRedrawRequest"
QT_MOC_LITERAL(26, 362, 14), // "onMoveAccepted"
QT_MOC_LITERAL(27, 377, 17), // "onMoveNotAccepted"
QT_MOC_LITERAL(28, 395, 36), // "on_tW_availablePlayers_double..."
QT_MOC_LITERAL(29, 432, 5), // "index"
QT_MOC_LITERAL(30, 438, 20), // "on_pB_logout_pressed"
QT_MOC_LITERAL(31, 459, 20), // "on_pB_resign_pressed"
QT_MOC_LITERAL(32, 480, 28), // "on_pB_requestNewGame_pressed"
QT_MOC_LITERAL(33, 509, 23), // "on_tW_board_itemClicked"
QT_MOC_LITERAL(34, 533, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(35, 551, 4), // "item"
QT_MOC_LITERAL(36, 556, 18), // "onMoveTimerTimeout"
QT_MOC_LITERAL(37, 575, 23) // "onRefreshPlayersTimeout"

    },
    "MainWindow\0onLogin\0\0result\0"
    "onGetPlayersListResponse\0QList<CPlayer>\0"
    "availablePlayers\0onStartNewGameServerResponse\0"
    "onNewGameRequested\0std::string\0"
    "hostPlayerName\0onNewGameRequestPlayerResponse\0"
    "response\0onGameInitialization\0playerColor\0"
    "onBoardReceived\0char*\0board\0onGameEnded\0"
    "reason\0onLogout\0onYourMove\0"
    "onGameStateChanged\0CGame::E_GameState\0"
    "newState\0onRedrawRequest\0onMoveAccepted\0"
    "onMoveNotAccepted\0"
    "on_tW_availablePlayers_doubleClicked\0"
    "index\0on_pB_logout_pressed\0"
    "on_pB_resign_pressed\0on_pB_requestNewGame_pressed\0"
    "on_tW_board_itemClicked\0QTableWidgetItem*\0"
    "item\0onMoveTimerTimeout\0onRefreshPlayersTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x0a /* Public */,
       4,    1,  122,    2, 0x0a /* Public */,
       7,    1,  125,    2, 0x0a /* Public */,
       8,    1,  128,    2, 0x0a /* Public */,
      11,    1,  131,    2, 0x0a /* Public */,
      13,    1,  134,    2, 0x0a /* Public */,
      15,    1,  137,    2, 0x0a /* Public */,
      18,    2,  140,    2, 0x0a /* Public */,
      20,    0,  145,    2, 0x0a /* Public */,
      21,    1,  146,    2, 0x0a /* Public */,
      22,    1,  149,    2, 0x0a /* Public */,
      25,    0,  152,    2, 0x0a /* Public */,
      26,    0,  153,    2, 0x0a /* Public */,
      27,    0,  154,    2, 0x0a /* Public */,
      28,    1,  155,    2, 0x08 /* Private */,
      30,    0,  158,    2, 0x08 /* Private */,
      31,    0,  159,    2, 0x08 /* Private */,
      32,    0,  160,    2, 0x08 /* Private */,
      33,    1,  161,    2, 0x08 /* Private */,
      36,    0,  164,    2, 0x08 /* Private */,
      37,    0,  165,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Char,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,    3,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLogin((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onGetPlayersListResponse((*reinterpret_cast< QList<CPlayer>(*)>(_a[1]))); break;
        case 2: _t->onStartNewGameServerResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onNewGameRequested((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->onNewGameRequestPlayerResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onGameInitialization((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 6: _t->onBoardReceived((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 7: _t->onGameEnded((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 8: _t->onLogout(); break;
        case 9: _t->onYourMove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onGameStateChanged((*reinterpret_cast< CGame::E_GameState(*)>(_a[1]))); break;
        case 11: _t->onRedrawRequest(); break;
        case 12: _t->onMoveAccepted(); break;
        case 13: _t->onMoveNotAccepted(); break;
        case 14: _t->on_tW_availablePlayers_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->on_pB_logout_pressed(); break;
        case 16: _t->on_pB_resign_pressed(); break;
        case 17: _t->on_pB_requestNewGame_pressed(); break;
        case 18: _t->on_tW_board_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 19: _t->onMoveTimerTimeout(); break;
        case 20: _t->onRefreshPlayersTimeout(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

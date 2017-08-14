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
    QByteArrayData data[26];
    char stringdata0[391];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "onGetPlayersListResponse"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "QList<CPlayer>"
QT_MOC_LITERAL(4, 52, 16), // "availablePlayers"
QT_MOC_LITERAL(5, 69, 28), // "onStartNewGameServerResponse"
QT_MOC_LITERAL(6, 98, 6), // "result"
QT_MOC_LITERAL(7, 105, 18), // "onNewGameRequested"
QT_MOC_LITERAL(8, 124, 11), // "std::string"
QT_MOC_LITERAL(9, 136, 14), // "hostPlayerName"
QT_MOC_LITERAL(10, 151, 30), // "onNewGameRequestPlayerResponse"
QT_MOC_LITERAL(11, 182, 8), // "response"
QT_MOC_LITERAL(12, 191, 20), // "onGameInitialization"
QT_MOC_LITERAL(13, 212, 11), // "playerColor"
QT_MOC_LITERAL(14, 224, 15), // "onBoardReceived"
QT_MOC_LITERAL(15, 240, 5), // "char*"
QT_MOC_LITERAL(16, 246, 5), // "board"
QT_MOC_LITERAL(17, 252, 11), // "onGameEnded"
QT_MOC_LITERAL(18, 264, 6), // "reason"
QT_MOC_LITERAL(19, 271, 8), // "onLogout"
QT_MOC_LITERAL(20, 280, 18), // "onGameStateChanged"
QT_MOC_LITERAL(21, 299, 18), // "CGame::E_GameState"
QT_MOC_LITERAL(22, 318, 8), // "newState"
QT_MOC_LITERAL(23, 327, 36), // "on_tW_availablePlayers_double..."
QT_MOC_LITERAL(24, 364, 5), // "index"
QT_MOC_LITERAL(25, 370, 20) // "on_pB_logout_pressed"

    },
    "MainWindow\0onGetPlayersListResponse\0"
    "\0QList<CPlayer>\0availablePlayers\0"
    "onStartNewGameServerResponse\0result\0"
    "onNewGameRequested\0std::string\0"
    "hostPlayerName\0onNewGameRequestPlayerResponse\0"
    "response\0onGameInitialization\0playerColor\0"
    "onBoardReceived\0char*\0board\0onGameEnded\0"
    "reason\0onLogout\0onGameStateChanged\0"
    "CGame::E_GameState\0newState\0"
    "on_tW_availablePlayers_doubleClicked\0"
    "index\0on_pB_logout_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       5,    1,   72,    2, 0x0a /* Public */,
       7,    1,   75,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      12,    1,   81,    2, 0x0a /* Public */,
      14,    1,   84,    2, 0x0a /* Public */,
      17,    2,   87,    2, 0x0a /* Public */,
      19,    0,   92,    2, 0x0a /* Public */,
      20,    1,   93,    2, 0x0a /* Public */,
      23,    1,   96,    2, 0x08 /* Private */,
      25,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Char,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    6,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::QModelIndex,   24,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onGetPlayersListResponse((*reinterpret_cast< QList<CPlayer>(*)>(_a[1]))); break;
        case 1: _t->onStartNewGameServerResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onNewGameRequested((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->onNewGameRequestPlayerResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onGameInitialization((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 5: _t->onBoardReceived((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 6: _t->onGameEnded((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 7: _t->onLogout(); break;
        case 8: _t->onGameStateChanged((*reinterpret_cast< CGame::E_GameState(*)>(_a[1]))); break;
        case 9: _t->on_tW_availablePlayers_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_pB_logout_pressed(); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

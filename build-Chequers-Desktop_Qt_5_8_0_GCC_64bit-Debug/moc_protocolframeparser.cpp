/****************************************************************************
** Meta object code from reading C++ file 'protocolframeparser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Chequers/protocolframeparser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocolframeparser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CProtocolFrameParser_t {
    QByteArrayData data[25];
    char stringdata0[370];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CProtocolFrameParser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CProtocolFrameParser_t qt_meta_stringdata_CProtocolFrameParser = {
    {
QT_MOC_LITERAL(0, 0, 20), // "CProtocolFrameParser"
QT_MOC_LITERAL(1, 21, 17), // "signalLoginRetval"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 7), // "success"
QT_MOC_LITERAL(4, 48, 20), // "signalRegisterRetval"
QT_MOC_LITERAL(5, 69, 27), // "signalListOfPlayersReceived"
QT_MOC_LITERAL(6, 97, 14), // "QList<CPlayer>"
QT_MOC_LITERAL(7, 112, 11), // "playersList"
QT_MOC_LITERAL(8, 124, 26), // "signalNewGameRequestPassed"
QT_MOC_LITERAL(9, 151, 6), // "result"
QT_MOC_LITERAL(10, 158, 22), // "signalNewGameRequested"
QT_MOC_LITERAL(11, 181, 11), // "std::string"
QT_MOC_LITERAL(12, 193, 14), // "hostPlayerName"
QT_MOC_LITERAL(13, 208, 28), // "signalNewGameRequestResponse"
QT_MOC_LITERAL(14, 237, 24), // "signalGameInitialization"
QT_MOC_LITERAL(15, 262, 11), // "playerColor"
QT_MOC_LITERAL(16, 274, 19), // "signalBoardReceived"
QT_MOC_LITERAL(17, 294, 5), // "char*"
QT_MOC_LITERAL(18, 300, 5), // "board"
QT_MOC_LITERAL(19, 306, 14), // "signalYourMove"
QT_MOC_LITERAL(20, 321, 6), // "status"
QT_MOC_LITERAL(21, 328, 15), // "signalGameEnded"
QT_MOC_LITERAL(22, 344, 6), // "reason"
QT_MOC_LITERAL(23, 351, 5), // "Parse"
QT_MOC_LITERAL(24, 357, 12) // "receivedData"

    },
    "CProtocolFrameParser\0signalLoginRetval\0"
    "\0success\0signalRegisterRetval\0"
    "signalListOfPlayersReceived\0QList<CPlayer>\0"
    "playersList\0signalNewGameRequestPassed\0"
    "result\0signalNewGameRequested\0std::string\0"
    "hostPlayerName\0signalNewGameRequestResponse\0"
    "signalGameInitialization\0playerColor\0"
    "signalBoardReceived\0char*\0board\0"
    "signalYourMove\0status\0signalGameEnded\0"
    "reason\0Parse\0receivedData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CProtocolFrameParser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    1,   75,    2, 0x06 /* Public */,
       8,    1,   78,    2, 0x06 /* Public */,
      10,    1,   81,    2, 0x06 /* Public */,
      13,    1,   84,    2, 0x06 /* Public */,
      14,    1,   87,    2, 0x06 /* Public */,
      16,    1,   90,    2, 0x06 /* Public */,
      19,    1,   93,    2, 0x06 /* Public */,
      21,    2,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Char,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,    9,   22,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   24,

       0        // eod
};

void CProtocolFrameParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CProtocolFrameParser *_t = static_cast<CProtocolFrameParser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalLoginRetval((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signalRegisterRetval((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->signalListOfPlayersReceived((*reinterpret_cast< QList<CPlayer>(*)>(_a[1]))); break;
        case 3: _t->signalNewGameRequestPassed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signalNewGameRequested((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 5: _t->signalNewGameRequestResponse((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signalGameInitialization((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 7: _t->signalBoardReceived((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 8: _t->signalYourMove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->signalGameEnded((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 10: _t->Parse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CProtocolFrameParser::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalLoginRetval)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalRegisterRetval)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(QList<CPlayer> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalListOfPlayersReceived)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalNewGameRequestPassed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalNewGameRequested)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalNewGameRequestResponse)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(char );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalGameInitialization)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalBoardReceived)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalYourMove)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (CProtocolFrameParser::*_t)(std::string , std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CProtocolFrameParser::signalGameEnded)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject CProtocolFrameParser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CProtocolFrameParser.data,
      qt_meta_data_CProtocolFrameParser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CProtocolFrameParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CProtocolFrameParser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CProtocolFrameParser.stringdata0))
        return static_cast<void*>(const_cast< CProtocolFrameParser*>(this));
    return QObject::qt_metacast(_clname);
}

int CProtocolFrameParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CProtocolFrameParser::signalLoginRetval(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CProtocolFrameParser::signalRegisterRetval(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CProtocolFrameParser::signalListOfPlayersReceived(QList<CPlayer> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CProtocolFrameParser::signalNewGameRequestPassed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CProtocolFrameParser::signalNewGameRequested(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CProtocolFrameParser::signalNewGameRequestResponse(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CProtocolFrameParser::signalGameInitialization(char _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CProtocolFrameParser::signalBoardReceived(char * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CProtocolFrameParser::signalYourMove(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CProtocolFrameParser::signalGameEnded(std::string _t1, std::string _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

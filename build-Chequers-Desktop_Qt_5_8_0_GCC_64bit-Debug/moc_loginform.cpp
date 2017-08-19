/****************************************************************************
** Meta object code from reading C++ file 'loginform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Chequers/GUI_Forms/loginform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CLoginForm_t {
    QByteArrayData data[12];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLoginForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLoginForm_t qt_meta_stringdata_CLoginForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CLoginForm"
QT_MOC_LITERAL(1, 11, 15), // "onLoginResponse"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "response"
QT_MOC_LITERAL(4, 37, 16), // "onUserRegistered"
QT_MOC_LITERAL(5, 54, 11), // "std::string"
QT_MOC_LITERAL(6, 66, 8), // "userName"
QT_MOC_LITERAL(7, 75, 8), // "password"
QT_MOC_LITERAL(8, 84, 28), // "on_lE_userName_returnPressed"
QT_MOC_LITERAL(9, 113, 28), // "on_lE_password_returnPressed"
QT_MOC_LITERAL(10, 142, 19), // "on_pB_login_clicked"
QT_MOC_LITERAL(11, 162, 26) // "on_pB_registerUser_pressed"

    },
    "CLoginForm\0onLoginResponse\0\0response\0"
    "onUserRegistered\0std::string\0userName\0"
    "password\0on_lE_userName_returnPressed\0"
    "on_lE_password_returnPressed\0"
    "on_pB_login_clicked\0on_pB_registerUser_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLoginForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    2,   47,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,
      10,    0,   54,    2, 0x08 /* Private */,
      11,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CLoginForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CLoginForm *_t = static_cast<CLoginForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLoginResponse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onUserRegistered((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 2: _t->on_lE_userName_returnPressed(); break;
        case 3: _t->on_lE_password_returnPressed(); break;
        case 4: _t->on_pB_login_clicked(); break;
        case 5: _t->on_pB_registerUser_pressed(); break;
        default: ;
        }
    }
}

const QMetaObject CLoginForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CLoginForm.data,
      qt_meta_data_CLoginForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CLoginForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLoginForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CLoginForm.stringdata0))
        return static_cast<void*>(const_cast< CLoginForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int CLoginForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

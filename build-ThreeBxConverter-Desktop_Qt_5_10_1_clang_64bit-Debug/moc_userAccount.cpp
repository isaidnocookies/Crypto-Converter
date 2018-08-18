/****************************************************************************
** Meta object code from reading C++ file 'userAccount.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ThreeBxConverter/userAccount.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userAccount.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserAccount_t {
    QByteArrayData data[15];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserAccount_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserAccount_t qt_meta_stringdata_UserAccount = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UserAccount"
QT_MOC_LITERAL(1, 12, 18), // "marketValueChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "valueChanged"
QT_MOC_LITERAL(4, 45, 19), // "marketValuesUpdated"
QT_MOC_LITERAL(5, 65, 6), // "iNames"
QT_MOC_LITERAL(6, 72, 7), // "iValues"
QT_MOC_LITERAL(7, 80, 21), // "downloaderErrorString"
QT_MOC_LITERAL(8, 102, 6), // "iError"
QT_MOC_LITERAL(9, 109, 14), // "getMarketValue"
QT_MOC_LITERAL(10, 124, 10), // "iShortname"
QT_MOC_LITERAL(11, 135, 9), // "iCurrency"
QT_MOC_LITERAL(12, 145, 8), // "getValue"
QT_MOC_LITERAL(13, 154, 8), // "setValue"
QT_MOC_LITERAL(14, 163, 16) // "iValueInCurrency"

    },
    "UserAccount\0marketValueChanged\0\0"
    "valueChanged\0marketValuesUpdated\0"
    "iNames\0iValues\0downloaderErrorString\0"
    "iError\0getMarketValue\0iShortname\0"
    "iCurrency\0getValue\0setValue\0"
    "iValueInCurrency"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserAccount[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   61,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    2,   69,    2, 0x02 /* Public */,
       9,    1,   74,    2, 0x22 /* Public | MethodCloned */,
      12,    2,   77,    2, 0x02 /* Public */,
      12,    1,   82,    2, 0x22 /* Public | MethodCloned */,
      13,    2,   85,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // methods: parameters
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::QString, QMetaType::QString,   10,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::QString, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   14,

       0        // eod
};

void UserAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserAccount *_t = static_cast<UserAccount *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->marketValueChanged(); break;
        case 1: _t->valueChanged(); break;
        case 2: _t->marketValuesUpdated((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 3: _t->downloaderErrorString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { QString _r = _t->getMarketValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getMarketValue((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getValue((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (UserAccount::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccount::marketValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UserAccount::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserAccount::valueChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserAccount::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UserAccount.data,
      qt_meta_data_UserAccount,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserAccount.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void UserAccount::marketValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UserAccount::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

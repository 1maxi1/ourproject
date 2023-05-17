/****************************************************************************
** Meta object code from reading C++ file 'singleton.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../client/singleton.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'singleton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_singleton_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[13];
    char stringdata5[5];
    char stringdata6[5];
    char stringdata7[12];
    char stringdata8[18];
    char stringdata9[21];
    char stringdata10[18];
    char stringdata11[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_singleton_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_singleton_t qt_meta_stringdata_singleton = {
    {
        QT_MOC_LITERAL(0, 9),  // "singleton"
        QT_MOC_LITERAL(10, 6),  // "authOk"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 10),  // "registerOk"
        QT_MOC_LITERAL(29, 12),  // "incomingTask"
        QT_MOC_LITERAL(42, 4),  // "name"
        QT_MOC_LITERAL(47, 4),  // "body"
        QT_MOC_LITERAL(52, 11),  // "onReadyRead"
        QT_MOC_LITERAL(64, 17),  // "onClientConnected"
        QT_MOC_LITERAL(82, 20),  // "onClientDisconnected"
        QT_MOC_LITERAL(103, 17),  // "onSokDisplayError"
        QT_MOC_LITERAL(121, 28)   // "QAbstractSocket::SocketError"
    },
    "singleton",
    "authOk",
    "",
    "registerOk",
    "incomingTask",
    "name",
    "body",
    "onReadyRead",
    "onClientConnected",
    "onClientDisconnected",
    "onSokDisplayError",
    "QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_singleton[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    2,   58,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   63,    2, 0x0a,    6 /* Public */,
       8,    0,   64,    2, 0x0a,    7 /* Public */,
       9,    0,   65,    2, 0x0a,    8 /* Public */,
      10,    1,   66,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject singleton::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_singleton.offsetsAndSizes,
    qt_meta_data_singleton,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_singleton_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<singleton, std::true_type>,
        // method 'authOk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registerOk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'incomingTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClientConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClientDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSokDisplayError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>
    >,
    nullptr
} };

void singleton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<singleton *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->authOk(); break;
        case 1: _t->registerOk(); break;
        case 2: _t->incomingTask((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->onReadyRead(); break;
        case 4: _t->onClientConnected(); break;
        case 5: _t->onClientDisconnected(); break;
        case 6: _t->onSokDisplayError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (singleton::*)();
            if (_t _q_method = &singleton::authOk; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (singleton::*)();
            if (_t _q_method = &singleton::registerOk; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (singleton::*)(QString , QString );
            if (_t _q_method = &singleton::incomingTask; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *singleton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *singleton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_singleton.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int singleton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void singleton::authOk()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void singleton::registerOk()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void singleton::incomingTask(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

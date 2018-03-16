/****************************************************************************
** Meta object code from reading C++ file 'CommandProcessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CommandProcessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommandProcessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CommandProcessor_t {
    QByteArrayData data[11];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandProcessor_t qt_meta_stringdata_CommandProcessor = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CommandProcessor"
QT_MOC_LITERAL(1, 17, 28), // "SignalOutputTextEditFinished"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 25), // "SignalOutputTextEditError"
QT_MOC_LITERAL(4, 73, 16), // "SignalLoadMesh_1"
QT_MOC_LITERAL(5, 90, 16), // "SignalLoadMesh_2"
QT_MOC_LITERAL(6, 107, 16), // "SignalLoadMesh_3"
QT_MOC_LITERAL(7, 124, 16), // "SignalLoadMesh_4"
QT_MOC_LITERAL(8, 141, 22), // "SignalChangeToLayout_1"
QT_MOC_LITERAL(9, 164, 22), // "SignalChangeToLayout_2"
QT_MOC_LITERAL(10, 187, 22) // "SignalChangeToLayout_4"

    },
    "CommandProcessor\0SignalOutputTextEditFinished\0"
    "\0SignalOutputTextEditError\0SignalLoadMesh_1\0"
    "SignalLoadMesh_2\0SignalLoadMesh_3\0"
    "SignalLoadMesh_4\0SignalChangeToLayout_1\0"
    "SignalChangeToLayout_2\0SignalChangeToLayout_4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    0,   65,    2, 0x06 /* Public */,
       5,    0,   66,    2, 0x06 /* Public */,
       6,    0,   67,    2, 0x06 /* Public */,
       7,    0,   68,    2, 0x06 /* Public */,
       8,    0,   69,    2, 0x06 /* Public */,
       9,    0,   70,    2, 0x06 /* Public */,
      10,    0,   71,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CommandProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommandProcessor *_t = static_cast<CommandProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalOutputTextEditFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SignalOutputTextEditError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SignalLoadMesh_1(); break;
        case 3: _t->SignalLoadMesh_2(); break;
        case 4: _t->SignalLoadMesh_3(); break;
        case 5: _t->SignalLoadMesh_4(); break;
        case 6: _t->SignalChangeToLayout_1(); break;
        case 7: _t->SignalChangeToLayout_2(); break;
        case 8: _t->SignalChangeToLayout_4(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CommandProcessor::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalOutputTextEditFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalOutputTextEditError)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_1)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_2)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_3)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_4)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalChangeToLayout_1)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalChangeToLayout_2)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalChangeToLayout_4)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject CommandProcessor::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CommandProcessor.data,
      qt_meta_data_CommandProcessor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CommandProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CommandProcessor.stringdata0))
        return static_cast<void*>(const_cast< CommandProcessor*>(this));
    return QThread::qt_metacast(_clname);
}

int CommandProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void CommandProcessor::SignalOutputTextEditFinished(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommandProcessor::SignalOutputTextEditError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommandProcessor::SignalLoadMesh_1()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CommandProcessor::SignalLoadMesh_2()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CommandProcessor::SignalLoadMesh_3()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CommandProcessor::SignalLoadMesh_4()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void CommandProcessor::SignalChangeToLayout_1()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void CommandProcessor::SignalChangeToLayout_2()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void CommandProcessor::SignalChangeToLayout_4()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

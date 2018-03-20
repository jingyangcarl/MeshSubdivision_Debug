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
    QByteArrayData data[20];
    char stringdata0[375];
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
QT_MOC_LITERAL(4, 73, 24), // "SignalOutputTextEditHelp"
QT_MOC_LITERAL(5, 98, 16), // "SignalLoadMesh_1"
QT_MOC_LITERAL(6, 115, 16), // "SignalLoadMesh_2"
QT_MOC_LITERAL(7, 132, 16), // "SignalLoadMesh_3"
QT_MOC_LITERAL(8, 149, 16), // "SignalLoadMesh_4"
QT_MOC_LITERAL(9, 166, 16), // "SignalShowMesh_1"
QT_MOC_LITERAL(10, 183, 16), // "SignalShowMesh_2"
QT_MOC_LITERAL(11, 200, 16), // "SignalShowMesh_3"
QT_MOC_LITERAL(12, 217, 16), // "SignalShowMesh_4"
QT_MOC_LITERAL(13, 234, 17), // "SignalClearMesh_1"
QT_MOC_LITERAL(14, 252, 17), // "SignalClearMesh_2"
QT_MOC_LITERAL(15, 270, 17), // "SignalClearMesh_3"
QT_MOC_LITERAL(16, 288, 17), // "SignalClearMesh_4"
QT_MOC_LITERAL(17, 306, 22), // "SignalChangeToLayout_1"
QT_MOC_LITERAL(18, 329, 22), // "SignalChangeToLayout_2"
QT_MOC_LITERAL(19, 352, 22) // "SignalChangeToLayout_4"

    },
    "CommandProcessor\0SignalOutputTextEditFinished\0"
    "\0SignalOutputTextEditError\0"
    "SignalOutputTextEditHelp\0SignalLoadMesh_1\0"
    "SignalLoadMesh_2\0SignalLoadMesh_3\0"
    "SignalLoadMesh_4\0SignalShowMesh_1\0"
    "SignalShowMesh_2\0SignalShowMesh_3\0"
    "SignalShowMesh_4\0SignalClearMesh_1\0"
    "SignalClearMesh_2\0SignalClearMesh_3\0"
    "SignalClearMesh_4\0SignalChangeToLayout_1\0"
    "SignalChangeToLayout_2\0SignalChangeToLayout_4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       3,    1,  107,    2, 0x06 /* Public */,
       4,    1,  110,    2, 0x06 /* Public */,
       5,    0,  113,    2, 0x06 /* Public */,
       6,    0,  114,    2, 0x06 /* Public */,
       7,    0,  115,    2, 0x06 /* Public */,
       8,    0,  116,    2, 0x06 /* Public */,
       9,    0,  117,    2, 0x06 /* Public */,
      10,    0,  118,    2, 0x06 /* Public */,
      11,    0,  119,    2, 0x06 /* Public */,
      12,    0,  120,    2, 0x06 /* Public */,
      13,    0,  121,    2, 0x06 /* Public */,
      14,    0,  122,    2, 0x06 /* Public */,
      15,    0,  123,    2, 0x06 /* Public */,
      16,    0,  124,    2, 0x06 /* Public */,
      17,    0,  125,    2, 0x06 /* Public */,
      18,    0,  126,    2, 0x06 /* Public */,
      19,    0,  127,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 2: _t->SignalOutputTextEditHelp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SignalLoadMesh_1(); break;
        case 4: _t->SignalLoadMesh_2(); break;
        case 5: _t->SignalLoadMesh_3(); break;
        case 6: _t->SignalLoadMesh_4(); break;
        case 7: _t->SignalShowMesh_1(); break;
        case 8: _t->SignalShowMesh_2(); break;
        case 9: _t->SignalShowMesh_3(); break;
        case 10: _t->SignalShowMesh_4(); break;
        case 11: _t->SignalClearMesh_1(); break;
        case 12: _t->SignalClearMesh_2(); break;
        case 13: _t->SignalClearMesh_3(); break;
        case 14: _t->SignalClearMesh_4(); break;
        case 15: _t->SignalChangeToLayout_1(); break;
        case 16: _t->SignalChangeToLayout_2(); break;
        case 17: _t->SignalChangeToLayout_4(); break;
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
            typedef void (CommandProcessor::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalOutputTextEditHelp)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_1)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_2)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_3)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalLoadMesh_4)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalShowMesh_1)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalShowMesh_2)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalShowMesh_3)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalShowMesh_4)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalClearMesh_1)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalClearMesh_2)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalClearMesh_3)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalClearMesh_4)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalChangeToLayout_1)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalChangeToLayout_2)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (CommandProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandProcessor::SignalChangeToLayout_4)) {
                *result = 17;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
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
void CommandProcessor::SignalOutputTextEditHelp(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommandProcessor::SignalLoadMesh_1()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CommandProcessor::SignalLoadMesh_2()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CommandProcessor::SignalLoadMesh_3()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void CommandProcessor::SignalLoadMesh_4()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void CommandProcessor::SignalShowMesh_1()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void CommandProcessor::SignalShowMesh_2()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void CommandProcessor::SignalShowMesh_3()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void CommandProcessor::SignalShowMesh_4()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void CommandProcessor::SignalClearMesh_1()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void CommandProcessor::SignalClearMesh_2()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void CommandProcessor::SignalClearMesh_3()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void CommandProcessor::SignalClearMesh_4()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void CommandProcessor::SignalChangeToLayout_1()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void CommandProcessor::SignalChangeToLayout_2()
{
    QMetaObject::activate(this, &staticMetaObject, 16, Q_NULLPTR);
}

// SIGNAL 17
void CommandProcessor::SignalChangeToLayout_4()
{
    QMetaObject::activate(this, &staticMetaObject, 17, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

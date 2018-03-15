/****************************************************************************
** Meta object code from reading C++ file 'MeshSubdivision_Debug.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MeshSubdivision_Debug.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshSubdivision_Debug.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeshSubdivision_Debug_t {
    QByteArrayData data[8];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshSubdivision_Debug_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshSubdivision_Debug_t qt_meta_stringdata_MeshSubdivision_Debug = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MeshSubdivision_Debug"
QT_MOC_LITERAL(1, 22, 22), // "OutputTextEditFinished"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 24), // "OutputTextEditProcessing"
QT_MOC_LITERAL(4, 71, 20), // "OutputTextEditNotice"
QT_MOC_LITERAL(5, 92, 21), // "OutputTextEditWarning"
QT_MOC_LITERAL(6, 114, 19), // "OutputTextEditError"
QT_MOC_LITERAL(7, 134, 27) // "OutputTextEditColoredString"

    },
    "MeshSubdivision_Debug\0OutputTextEditFinished\0"
    "\0OutputTextEditProcessing\0"
    "OutputTextEditNotice\0OutputTextEditWarning\0"
    "OutputTextEditError\0OutputTextEditColoredString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshSubdivision_Debug[] = {

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
       1,    1,   44,    2, 0x08 /* Private */,
       3,    1,   47,    2, 0x08 /* Private */,
       4,    1,   50,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       6,    1,   56,    2, 0x08 /* Private */,
       7,    2,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QColor, QMetaType::QString,    2,    2,

       0        // eod
};

void MeshSubdivision_Debug::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshSubdivision_Debug *_t = static_cast<MeshSubdivision_Debug *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OutputTextEditFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OutputTextEditProcessing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->OutputTextEditNotice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->OutputTextEditWarning((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->OutputTextEditError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->OutputTextEditColoredString((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MeshSubdivision_Debug::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MeshSubdivision_Debug.data,
      qt_meta_data_MeshSubdivision_Debug,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshSubdivision_Debug::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshSubdivision_Debug::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshSubdivision_Debug.stringdata0))
        return static_cast<void*>(const_cast< MeshSubdivision_Debug*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MeshSubdivision_Debug::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

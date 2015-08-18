/****************************************************************************
** Meta object code from reading C++ file 'theremin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../theremin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'theremin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_theremin_t {
    QByteArrayData data[19];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_theremin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_theremin_t qt_meta_stringdata_theremin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "theremin"
QT_MOC_LITERAL(1, 9, 6), // "soundS"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "soundQ"
QT_MOC_LITERAL(4, 24, 6), // "soundT"
QT_MOC_LITERAL(5, 31, 6), // "soundD"
QT_MOC_LITERAL(6, 38, 9), // "soundPlay"
QT_MOC_LITERAL(7, 48, 9), // "stopSound"
QT_MOC_LITERAL(8, 58, 10), // "modAfinado"
QT_MOC_LITERAL(9, 69, 12), // "mostrarPiano"
QT_MOC_LITERAL(10, 82, 7), // "vconfig"
QT_MOC_LITERAL(11, 90, 11), // "aboutButton"
QT_MOC_LITERAL(12, 102, 5), // "salir"
QT_MOC_LITERAL(13, 108, 23), // "on_actionPlay_triggered"
QT_MOC_LITERAL(14, 132, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(15, 156, 24), // "on_actionSinus_triggered"
QT_MOC_LITERAL(16, 181, 23), // "on_actionQuad_triggered"
QT_MOC_LITERAL(17, 205, 22), // "on_actionSaw_triggered"
QT_MOC_LITERAL(18, 228, 27) // "on_actionTriangle_triggered"

    },
    "theremin\0soundS\0\0soundQ\0soundT\0soundD\0"
    "soundPlay\0stopSound\0modAfinado\0"
    "mostrarPiano\0vconfig\0aboutButton\0salir\0"
    "on_actionPlay_triggered\0on_actionStop_triggered\0"
    "on_actionSinus_triggered\0"
    "on_actionQuad_triggered\0on_actionSaw_triggered\0"
    "on_actionTriangle_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_theremin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void theremin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        theremin *_t = static_cast<theremin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->soundS(); break;
        case 1: _t->soundQ(); break;
        case 2: _t->soundT(); break;
        case 3: _t->soundD(); break;
        case 4: _t->soundPlay(); break;
        case 5: _t->stopSound(); break;
        case 6: _t->modAfinado(); break;
        case 7: _t->mostrarPiano(); break;
        case 8: _t->vconfig(); break;
        case 9: _t->aboutButton(); break;
        case 10: _t->salir(); break;
        case 11: _t->on_actionPlay_triggered(); break;
        case 12: _t->on_actionStop_triggered(); break;
        case 13: _t->on_actionSinus_triggered(); break;
        case 14: _t->on_actionQuad_triggered(); break;
        case 15: _t->on_actionSaw_triggered(); break;
        case 16: _t->on_actionTriangle_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject theremin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_theremin.data,
      qt_meta_data_theremin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *theremin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *theremin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_theremin.stringdata0))
        return static_cast<void*>(const_cast< theremin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int theremin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

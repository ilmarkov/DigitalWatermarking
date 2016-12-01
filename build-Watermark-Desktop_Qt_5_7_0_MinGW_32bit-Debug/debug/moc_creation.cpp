/****************************************************************************
** Meta object code from reading C++ file 'creation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Watermark/creation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_creation_t {
    QByteArrayData data[8];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_creation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_creation_t qt_meta_stringdata_creation = {
    {
QT_MOC_LITERAL(0, 0, 8), // "creation"
QT_MOC_LITERAL(1, 9, 19), // "on_createWM_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 22), // "on_browseImage_clicked"
QT_MOC_LITERAL(4, 53, 21), // "on_browseMark_clicked"
QT_MOC_LITERAL(5, 75, 25), // "on_browseNewImage_clicked"
QT_MOC_LITERAL(6, 101, 13), // "on_ok_clicked"
QT_MOC_LITERAL(7, 115, 17) // "on_cancel_clicked"

    },
    "creation\0on_createWM_clicked\0\0"
    "on_browseImage_clicked\0on_browseMark_clicked\0"
    "on_browseNewImage_clicked\0on_ok_clicked\0"
    "on_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_creation[] = {

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
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void creation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        creation *_t = static_cast<creation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_createWM_clicked(); break;
        case 1: _t->on_browseImage_clicked(); break;
        case 2: _t->on_browseMark_clicked(); break;
        case 3: _t->on_browseNewImage_clicked(); break;
        case 4: _t->on_ok_clicked(); break;
        case 5: _t->on_cancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject creation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_creation.data,
      qt_meta_data_creation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *creation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *creation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_creation.stringdata0))
        return static_cast<void*>(const_cast< creation*>(this));
    return QDialog::qt_metacast(_clname);
}

int creation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'validation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Watermark/validation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'validation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_validation_t {
    QByteArrayData data[6];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_validation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_validation_t qt_meta_stringdata_validation = {
    {
QT_MOC_LITERAL(0, 0, 10), // "validation"
QT_MOC_LITERAL(1, 11, 24), // "on_browseImage_2_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 23), // "on_browseMark_2_clicked"
QT_MOC_LITERAL(4, 61, 13), // "on_ok_clicked"
QT_MOC_LITERAL(5, 75, 17) // "on_cancel_clicked"

    },
    "validation\0on_browseImage_2_clicked\0"
    "\0on_browseMark_2_clicked\0on_ok_clicked\0"
    "on_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_validation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void validation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        validation *_t = static_cast<validation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_browseImage_2_clicked(); break;
        case 1: _t->on_browseMark_2_clicked(); break;
        case 2: _t->on_ok_clicked(); break;
        case 3: _t->on_cancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject validation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_validation.data,
      qt_meta_data_validation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *validation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *validation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_validation.stringdata0))
        return static_cast<void*>(const_cast< validation*>(this));
    return QDialog::qt_metacast(_clname);
}

int validation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

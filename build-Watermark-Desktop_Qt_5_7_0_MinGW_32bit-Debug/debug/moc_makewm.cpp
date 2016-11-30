/****************************************************************************
** Meta object code from reading C++ file 'makewm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Watermark/makewm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'makewm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_makeWM_t {
    QByteArrayData data[6];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_makeWM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_makeWM_t qt_meta_stringdata_makeWM = {
    {
QT_MOC_LITERAL(0, 0, 6), // "makeWM"
QT_MOC_LITERAL(1, 7, 20), // "on_browseKey_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "on_ok_clicked"
QT_MOC_LITERAL(4, 43, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(5, 61, 24) // "on_browseNewMark_clicked"

    },
    "makeWM\0on_browseKey_clicked\0\0on_ok_clicked\0"
    "on_cancel_clicked\0on_browseNewMark_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_makeWM[] = {

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

void makeWM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        makeWM *_t = static_cast<makeWM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_browseKey_clicked(); break;
        case 1: _t->on_ok_clicked(); break;
        case 2: _t->on_cancel_clicked(); break;
        case 3: _t->on_browseNewMark_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject makeWM::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_makeWM.data,
      qt_meta_data_makeWM,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *makeWM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *makeWM::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_makeWM.stringdata0))
        return static_cast<void*>(const_cast< makeWM*>(this));
    return QDialog::qt_metacast(_clname);
}

int makeWM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

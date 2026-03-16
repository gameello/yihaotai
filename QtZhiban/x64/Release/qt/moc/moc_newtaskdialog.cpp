/****************************************************************************
** Meta object code from reading C++ file 'newtaskdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Todo/newtaskdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newtaskdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewTaskDialog_t {
    QByteArrayData data[12];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewTaskDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewTaskDialog_t qt_meta_stringdata_NewTaskDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NewTaskDialog"
QT_MOC_LITERAL(1, 14, 18), // "on_savebtn_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 22), // "on_slider_valueChanged"
QT_MOC_LITERAL(4, 57, 5), // "value"
QT_MOC_LITERAL(5, 63, 29), // "on_description_ed_textChanged"
QT_MOC_LITERAL(6, 93, 23), // "on_title_et_textChanged"
QT_MOC_LITERAL(7, 117, 4), // "arg1"
QT_MOC_LITERAL(8, 122, 29), // "on_datepicker_userDateChanged"
QT_MOC_LITERAL(9, 152, 4), // "date"
QT_MOC_LITERAL(10, 157, 20), // "on_cancelbtn_clicked"
QT_MOC_LITERAL(11, 178, 20) // "on_deletebtn_clicked"

    },
    "NewTaskDialog\0on_savebtn_clicked\0\0"
    "on_slider_valueChanged\0value\0"
    "on_description_ed_textChanged\0"
    "on_title_et_textChanged\0arg1\0"
    "on_datepicker_userDateChanged\0date\0"
    "on_cancelbtn_clicked\0on_deletebtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewTaskDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
      10,    0,   60,    2, 0x08 /* Private */,
      11,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QDate,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewTaskDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewTaskDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_savebtn_clicked(); break;
        case 1: _t->on_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_description_ed_textChanged(); break;
        case 3: _t->on_title_et_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_datepicker_userDateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 5: _t->on_cancelbtn_clicked(); break;
        case 6: _t->on_deletebtn_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NewTaskDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_NewTaskDialog.data,
    qt_meta_data_NewTaskDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewTaskDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewTaskDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewTaskDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NewTaskDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

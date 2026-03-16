/****************************************************************************
** Meta object code from reading C++ file 'calandarWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Calandar/calandarWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calandarWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calandarWidget_t {
    QByteArrayData data[9];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calandarWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calandarWidget_t qt_meta_stringdata_calandarWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "calandarWidget"
QT_MOC_LITERAL(1, 15, 16), // "DateSelectSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "date"
QT_MOC_LITERAL(4, 38, 14), // "HaveDateSelect"
QT_MOC_LITERAL(5, 53, 12), // "JumpLastYear"
QT_MOC_LITERAL(6, 66, 13), // "JumpLastMonth"
QT_MOC_LITERAL(7, 80, 13), // "JumpNextMonth"
QT_MOC_LITERAL(8, 94, 12) // "JumpNextYear"

    },
    "calandarWidget\0DateSelectSignal\0\0date\0"
    "HaveDateSelect\0JumpLastYear\0JumpLastMonth\0"
    "JumpNextMonth\0JumpNextYear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calandarWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       5,    0,   50,    2, 0x0a /* Public */,
       6,    0,   51,    2, 0x0a /* Public */,
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void calandarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<calandarWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DateSelectSignal((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 1: _t->HaveDateSelect((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: _t->JumpLastYear(); break;
        case 3: _t->JumpLastMonth(); break;
        case 4: _t->JumpNextMonth(); break;
        case 5: _t->JumpNextYear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (calandarWidget::*)(QDate );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&calandarWidget::DateSelectSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject calandarWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_calandarWidget.data,
    qt_meta_data_calandarWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *calandarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calandarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_calandarWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int calandarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void calandarWidget::DateSelectSignal(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

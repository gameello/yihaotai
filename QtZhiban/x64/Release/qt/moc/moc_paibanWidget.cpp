/****************************************************************************
** Meta object code from reading C++ file 'paibanWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Paiban/paibanWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paibanWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_paibanWidget_t {
    QByteArrayData data[7];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_paibanWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_paibanWidget_t qt_meta_stringdata_paibanWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "paibanWidget"
QT_MOC_LITERAL(1, 13, 20), // "backToCalandarWidget"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 24), // "comboxZhiwu_indexchanged"
QT_MOC_LITERAL(4, 60, 4), // "text"
QT_MOC_LITERAL(5, 65, 23), // "comboxName_indexchanged"
QT_MOC_LITERAL(6, 89, 14) // "button_clicked"

    },
    "paibanWidget\0backToCalandarWidget\0\0"
    "comboxZhiwu_indexchanged\0text\0"
    "comboxName_indexchanged\0button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_paibanWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void paibanWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<paibanWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backToCalandarWidget(); break;
        case 1: _t->comboxZhiwu_indexchanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->comboxName_indexchanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (paibanWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paibanWidget::backToCalandarWidget)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject paibanWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_paibanWidget.data,
    qt_meta_data_paibanWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *paibanWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *paibanWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_paibanWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int paibanWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void paibanWidget::backToCalandarWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

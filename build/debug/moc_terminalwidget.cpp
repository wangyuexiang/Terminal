/****************************************************************************
** Meta object code from reading C++ file 'terminalwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../terminalwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terminalwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TerminalWidget_t {
    QByteArrayData data[19];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TerminalWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TerminalWidget_t qt_meta_stringdata_TerminalWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TerminalWidget"
QT_MOC_LITERAL(1, 15, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "QItemSelection"
QT_MOC_LITERAL(4, 48, 8), // "selected"
QT_MOC_LITERAL(5, 57, 8), // "addEntry"
QT_MOC_LITERAL(6, 66, 4), // "name"
QT_MOC_LITERAL(7, 71, 7), // "address"
QT_MOC_LITERAL(8, 79, 9), // "editEntry"
QT_MOC_LITERAL(9, 89, 11), // "removeEntry"
QT_MOC_LITERAL(10, 101, 10), // "addProduct"
QT_MOC_LITERAL(11, 112, 1), // "i"
QT_MOC_LITERAL(12, 114, 1), // "c"
QT_MOC_LITERAL(13, 116, 1), // "w"
QT_MOC_LITERAL(14, 118, 7), // "number1"
QT_MOC_LITERAL(15, 126, 7), // "number2"
QT_MOC_LITERAL(16, 134, 7), // "number3"
QT_MOC_LITERAL(17, 142, 11), // "editProduct"
QT_MOC_LITERAL(18, 154, 13) // "removeProduct"

    },
    "TerminalWidget\0selectionChanged\0\0"
    "QItemSelection\0selected\0addEntry\0name\0"
    "address\0editEntry\0removeEntry\0addProduct\0"
    "i\0c\0w\0number1\0number2\0number3\0editProduct\0"
    "removeProduct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TerminalWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a /* Public */,
       5,    2,   63,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      10,    6,   71,    2, 0x0a /* Public */,
      17,    0,   84,    2, 0x0a /* Public */,
      18,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TerminalWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TerminalWidget *_t = static_cast<TerminalWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 1: _t->addEntry(); break;
        case 2: _t->addEntry((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->editEntry(); break;
        case 4: _t->removeEntry(); break;
        case 5: _t->addProduct(); break;
        case 6: _t->addProduct((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 7: _t->editProduct(); break;
        case 8: _t->removeProduct(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TerminalWidget::*_t)(const QItemSelection & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TerminalWidget::selectionChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TerminalWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_TerminalWidget.data,
      qt_meta_data_TerminalWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TerminalWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TerminalWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TerminalWidget.stringdata0))
        return static_cast<void*>(const_cast< TerminalWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int TerminalWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TerminalWidget::selectionChanged(const QItemSelection & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'veellipse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vector-editor_changed/src/veellipse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'veellipse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VEEllipse_t {
    QByteArrayData data[13];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VEEllipse_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VEEllipse_t qt_meta_stringdata_VEEllipse = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 11),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 10),
QT_MOC_LITERAL(4, 34, 4),
QT_MOC_LITERAL(5, 39, 23),
QT_MOC_LITERAL(6, 63, 7),
QT_MOC_LITERAL(7, 71, 10),
QT_MOC_LITERAL(8, 82, 14),
QT_MOC_LITERAL(9, 97, 4),
QT_MOC_LITERAL(10, 102, 2),
QT_MOC_LITERAL(11, 105, 2),
QT_MOC_LITERAL(12, 108, 16)
    },
    "VEEllipse\0elliChanged\0\0VEEllipse*\0"
    "rect\0previousPositionChanged\0clicked\0"
    "signalMove\0QGraphicsItem*\0item\0dx\0dy\0"
    "previousPosition\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VEEllipse[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,
       5,    0,   37,    2, 0x06,
       6,    1,   38,    2, 0x06,
       7,    3,   41,    2, 0x06,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QReal, QMetaType::QReal,    9,   10,   11,

 // properties: name, type, flags
      12, QMetaType::QPointF, 0x00495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

void VEEllipse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VEEllipse *_t = static_cast<VEEllipse *>(_o);
        switch (_id) {
        case 0: _t->elliChanged((*reinterpret_cast< VEEllipse*(*)>(_a[1]))); break;
        case 1: _t->previousPositionChanged(); break;
        case 2: _t->clicked((*reinterpret_cast< VEEllipse*(*)>(_a[1]))); break;
        case 3: _t->signalMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VEEllipse* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VEEllipse* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VEEllipse::*_t)(VEEllipse * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEEllipse::elliChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (VEEllipse::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEEllipse::previousPositionChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (VEEllipse::*_t)(VEEllipse * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEEllipse::clicked)) {
                *result = 2;
            }
        }
        {
            typedef void (VEEllipse::*_t)(QGraphicsItem * , qreal , qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEEllipse::signalMove)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject VEEllipse::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VEEllipse.data,
      qt_meta_data_VEEllipse,  qt_static_metacall, 0, 0}
};


const QMetaObject *VEEllipse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VEEllipse::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VEEllipse.stringdata))
        return static_cast<void*>(const_cast< VEEllipse*>(this));
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(const_cast< VEEllipse*>(this));
    return QObject::qt_metacast(_clname);
}

int VEEllipse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = previousPosition(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPreviousPosition(*reinterpret_cast< QPointF*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VEEllipse::elliChanged(VEEllipse * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VEEllipse::previousPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void VEEllipse::clicked(VEEllipse * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VEEllipse::signalMove(QGraphicsItem * _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

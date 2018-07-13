/****************************************************************************
** Meta object code from reading C++ file 'vepolyline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vector-editor_changed/src/vepolyline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vepolyline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VEPolyline_t {
    QByteArrayData data[15];
    char stringdata[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VEPolyline_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VEPolyline_t qt_meta_stringdata_VEPolyline = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 23),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 7),
QT_MOC_LITERAL(4, 44, 11),
QT_MOC_LITERAL(5, 56, 4),
QT_MOC_LITERAL(6, 61, 10),
QT_MOC_LITERAL(7, 72, 14),
QT_MOC_LITERAL(8, 87, 4),
QT_MOC_LITERAL(9, 92, 2),
QT_MOC_LITERAL(10, 95, 2),
QT_MOC_LITERAL(11, 98, 8),
QT_MOC_LITERAL(12, 107, 11),
QT_MOC_LITERAL(13, 119, 20),
QT_MOC_LITERAL(14, 140, 16)
    },
    "VEPolyline\0previousPositionChanged\0\0"
    "clicked\0VEPolyline*\0rect\0signalMove\0"
    "QGraphicsItem*\0item\0dx\0dy\0slotMove\0"
    "signalOwner\0checkForDeletePoints\0"
    "previousPosition\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VEPolyline[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06,
       3,    1,   40,    2, 0x06,
       6,    3,   43,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    3,   50,    2, 0x08,
      13,    0,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QReal, QMetaType::QReal,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::QReal, QMetaType::QReal,   12,    9,   10,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::QPointF, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void VEPolyline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VEPolyline *_t = static_cast<VEPolyline *>(_o);
        switch (_id) {
        case 0: _t->previousPositionChanged(); break;
        case 1: _t->clicked((*reinterpret_cast< VEPolyline*(*)>(_a[1]))); break;
        case 2: _t->signalMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 3: _t->slotMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 4: _t->checkForDeletePoints(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VEPolyline* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
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
            typedef void (VEPolyline::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEPolyline::previousPositionChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (VEPolyline::*_t)(VEPolyline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEPolyline::clicked)) {
                *result = 1;
            }
        }
        {
            typedef void (VEPolyline::*_t)(QGraphicsItem * , qreal , qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEPolyline::signalMove)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject VEPolyline::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VEPolyline.data,
      qt_meta_data_VEPolyline,  qt_static_metacall, 0, 0}
};


const QMetaObject *VEPolyline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VEPolyline::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VEPolyline.stringdata))
        return static_cast<void*>(const_cast< VEPolyline*>(this));
    if (!strcmp(_clname, "QGraphicsPathItem"))
        return static_cast< QGraphicsPathItem*>(const_cast< VEPolyline*>(this));
    return QObject::qt_metacast(_clname);
}

int VEPolyline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
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
void VEPolyline::previousPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VEPolyline::clicked(VEPolyline * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VEPolyline::signalMove(QGraphicsItem * _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

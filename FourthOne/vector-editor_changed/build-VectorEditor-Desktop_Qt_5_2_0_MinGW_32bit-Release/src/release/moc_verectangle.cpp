/****************************************************************************
** Meta object code from reading C++ file 'verectangle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vector-editor_changed/src/verectangle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'verectangle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VERectangle_t {
    QByteArrayData data[13];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VERectangle_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VERectangle_t qt_meta_stringdata_VERectangle = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 11),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 12),
QT_MOC_LITERAL(4, 38, 4),
QT_MOC_LITERAL(5, 43, 23),
QT_MOC_LITERAL(6, 67, 7),
QT_MOC_LITERAL(7, 75, 10),
QT_MOC_LITERAL(8, 86, 14),
QT_MOC_LITERAL(9, 101, 4),
QT_MOC_LITERAL(10, 106, 2),
QT_MOC_LITERAL(11, 109, 2),
QT_MOC_LITERAL(12, 112, 16)
    },
    "VERectangle\0rectChanged\0\0VERectangle*\0"
    "rect\0previousPositionChanged\0clicked\0"
    "signalMove\0QGraphicsItem*\0item\0dx\0dy\0"
    "previousPosition\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VERectangle[] = {

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

void VERectangle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VERectangle *_t = static_cast<VERectangle *>(_o);
        switch (_id) {
        case 0: _t->rectChanged((*reinterpret_cast< VERectangle*(*)>(_a[1]))); break;
        case 1: _t->previousPositionChanged(); break;
        case 2: _t->clicked((*reinterpret_cast< VERectangle*(*)>(_a[1]))); break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VERectangle* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VERectangle* >(); break;
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
            typedef void (VERectangle::*_t)(VERectangle * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangle::rectChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (VERectangle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangle::previousPositionChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (VERectangle::*_t)(VERectangle * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangle::clicked)) {
                *result = 2;
            }
        }
        {
            typedef void (VERectangle::*_t)(QGraphicsItem * , qreal , qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangle::signalMove)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject VERectangle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VERectangle.data,
      qt_meta_data_VERectangle,  qt_static_metacall, 0, 0}
};


const QMetaObject *VERectangle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VERectangle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VERectangle.stringdata))
        return static_cast<void*>(const_cast< VERectangle*>(this));
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(const_cast< VERectangle*>(this));
    return QObject::qt_metacast(_clname);
}

int VERectangle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void VERectangle::rectChanged(VERectangle * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VERectangle::previousPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void VERectangle::clicked(VERectangle * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VERectangle::signalMove(QGraphicsItem * _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

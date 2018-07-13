/****************************************************************************
** Meta object code from reading C++ file 'vepolylinesettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vector-editor_changed/src/vepolylinesettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vepolylinesettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VEPolyLineSettings_t {
    QByteArrayData data[17];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VEPolyLineSettings_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VEPolyLineSettings_t qt_meta_stringdata_VEPolyLineSettings = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 16),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 5),
QT_MOC_LITERAL(4, 43, 16),
QT_MOC_LITERAL(5, 60, 5),
QT_MOC_LITERAL(6, 66, 12),
QT_MOC_LITERAL(7, 79, 12),
QT_MOC_LITERAL(8, 92, 11),
QT_MOC_LITERAL(9, 104, 11),
QT_MOC_LITERAL(10, 116, 8),
QT_MOC_LITERAL(11, 125, 12),
QT_MOC_LITERAL(12, 138, 8),
QT_MOC_LITERAL(13, 147, 10),
QT_MOC_LITERAL(14, 158, 7),
QT_MOC_LITERAL(15, 166, 9),
QT_MOC_LITERAL(16, 176, 9)
    },
    "VEPolyLineSettings\0lineColorChanged\0"
    "\0color\0lineWidthChanged\0width\0"
    "setLineColor\0setLineWidth\0newPolyline\0"
    "VEPolyline*\0polyline\0loadPolyline\0"
    "deselect\0setVisible\0visible\0lineColor\0"
    "lineWidth\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VEPolyLineSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06,
       4,    1,   57,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   60,    2, 0x0a,
       7,    1,   63,    2, 0x0a,
       8,    1,   66,    2, 0x0a,
      11,    1,   69,    2, 0x0a,
      12,    0,   72,    2, 0x0a,
      13,    1,   73,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,

 // properties: name, type, flags
      15, QMetaType::QColor, 0x00495103,
      16, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void VEPolyLineSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VEPolyLineSettings *_t = static_cast<VEPolyLineSettings *>(_o);
        switch (_id) {
        case 0: _t->lineColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->lineWidthChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->setLineColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->setLineWidth((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->newPolyline((*reinterpret_cast< VEPolyline*(*)>(_a[1]))); break;
        case 5: _t->loadPolyline((*reinterpret_cast< VEPolyline*(*)>(_a[1]))); break;
        case 6: _t->deselect(); break;
        case 7: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VEPolyLineSettings::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEPolyLineSettings::lineColorChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (VEPolyLineSettings::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VEPolyLineSettings::lineWidthChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VEPolyLineSettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VEPolyLineSettings.data,
      qt_meta_data_VEPolyLineSettings,  qt_static_metacall, 0, 0}
};


const QMetaObject *VEPolyLineSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VEPolyLineSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VEPolyLineSettings.stringdata))
        return static_cast<void*>(const_cast< VEPolyLineSettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int VEPolyLineSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = lineColor(); break;
        case 1: *reinterpret_cast< int*>(_v) = lineWidth(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: setLineWidth(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VEPolyLineSettings::lineColorChanged(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VEPolyLineSettings::lineWidthChanged(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

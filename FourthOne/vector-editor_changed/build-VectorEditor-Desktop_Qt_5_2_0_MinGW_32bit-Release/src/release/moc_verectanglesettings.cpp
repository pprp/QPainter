/****************************************************************************
** Meta object code from reading C++ file 'verectanglesettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../vector-editor_changed/src/verectanglesettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'verectanglesettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VERectangleSettings_t {
    QByteArrayData data[25];
    char stringdata[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VERectangleSettings_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VERectangleSettings_t qt_meta_stringdata_VERectangleSettings = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 14),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 5),
QT_MOC_LITERAL(4, 42, 14),
QT_MOC_LITERAL(5, 57, 18),
QT_MOC_LITERAL(6, 76, 18),
QT_MOC_LITERAL(7, 95, 5),
QT_MOC_LITERAL(8, 101, 10),
QT_MOC_LITERAL(9, 112, 10),
QT_MOC_LITERAL(10, 123, 14),
QT_MOC_LITERAL(11, 138, 14),
QT_MOC_LITERAL(12, 153, 12),
QT_MOC_LITERAL(13, 166, 12),
QT_MOC_LITERAL(14, 179, 4),
QT_MOC_LITERAL(15, 184, 13),
QT_MOC_LITERAL(16, 198, 8),
QT_MOC_LITERAL(17, 207, 10),
QT_MOC_LITERAL(18, 218, 7),
QT_MOC_LITERAL(19, 226, 20),
QT_MOC_LITERAL(20, 247, 5),
QT_MOC_LITERAL(21, 253, 7),
QT_MOC_LITERAL(22, 261, 7),
QT_MOC_LITERAL(23, 269, 11),
QT_MOC_LITERAL(24, 281, 11)
    },
    "VERectangleSettings\0color_1Changed\0\0"
    "color\0color_2Changed\0borderColorChanged\0"
    "borderWidthChanged\0width\0setColor_1\0"
    "setColor_2\0setBorderColor\0setBorderWidth\0"
    "newRectangle\0VERectangle*\0rect\0"
    "loadRectangle\0deselect\0setVisible\0"
    "visible\0comboBoxIndexChanged\0index\0"
    "color_1\0color_2\0borderColor\0borderWidth\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VERectangleSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       4,  116, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06,
       4,    1,   82,    2, 0x06,
       5,    1,   85,    2, 0x06,
       6,    1,   88,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       8,    1,   91,    2, 0x0a,
       9,    1,   94,    2, 0x0a,
      10,    1,   97,    2, 0x0a,
      11,    1,  100,    2, 0x0a,
      12,    1,  103,    2, 0x0a,
      15,    1,  106,    2, 0x0a,
      16,    0,  109,    2, 0x0a,
      17,    1,  110,    2, 0x0a,
      19,    1,  113,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,   20,

 // properties: name, type, flags
      21, QMetaType::QColor, 0x00495103,
      22, QMetaType::QColor, 0x00495103,
      23, QMetaType::QColor, 0x00495103,
      24, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void VERectangleSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VERectangleSettings *_t = static_cast<VERectangleSettings *>(_o);
        switch (_id) {
        case 0: _t->color_1Changed((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->color_2Changed((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->borderColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->borderWidthChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->setColor_1((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 5: _t->setColor_2((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 6: _t->setBorderColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setBorderWidth((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 8: _t->newRectangle((*reinterpret_cast< VERectangle*(*)>(_a[1]))); break;
        case 9: _t->loadRectangle((*reinterpret_cast< VERectangle*(*)>(_a[1]))); break;
        case 10: _t->deselect(); break;
        case 11: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->comboBoxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VERectangleSettings::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangleSettings::color_1Changed)) {
                *result = 0;
            }
        }
        {
            typedef void (VERectangleSettings::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangleSettings::color_2Changed)) {
                *result = 1;
            }
        }
        {
            typedef void (VERectangleSettings::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangleSettings::borderColorChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (VERectangleSettings::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VERectangleSettings::borderWidthChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject VERectangleSettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VERectangleSettings.data,
      qt_meta_data_VERectangleSettings,  qt_static_metacall, 0, 0}
};


const QMetaObject *VERectangleSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VERectangleSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VERectangleSettings.stringdata))
        return static_cast<void*>(const_cast< VERectangleSettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int VERectangleSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = color_1(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = color_2(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = borderColor(); break;
        case 3: *reinterpret_cast< int*>(_v) = borderWidth(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setColor_1(*reinterpret_cast< QColor*>(_v)); break;
        case 1: setColor_2(*reinterpret_cast< QColor*>(_v)); break;
        case 2: setBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VERectangleSettings::color_1Changed(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VERectangleSettings::color_2Changed(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VERectangleSettings::borderColorChanged(const QColor & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VERectangleSettings::borderWidthChanged(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

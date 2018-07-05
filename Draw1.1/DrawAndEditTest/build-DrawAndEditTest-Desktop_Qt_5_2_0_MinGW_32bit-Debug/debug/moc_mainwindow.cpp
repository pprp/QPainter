/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawAndEditTest/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 39),
QT_MOC_LITERAL(2, 51, 0),
QT_MOC_LITERAL(3, 52, 8),
QT_MOC_LITERAL(4, 61, 36),
QT_MOC_LITERAL(5, 98, 5),
QT_MOC_LITERAL(6, 104, 29),
QT_MOC_LITERAL(7, 134, 31),
QT_MOC_LITERAL(8, 166, 31),
QT_MOC_LITERAL(9, 198, 8),
QT_MOC_LITERAL(10, 207, 24),
QT_MOC_LITERAL(11, 232, 24),
QT_MOC_LITERAL(12, 257, 24),
QT_MOC_LITERAL(13, 282, 25),
QT_MOC_LITERAL(14, 308, 26),
QT_MOC_LITERAL(15, 335, 27)
    },
    "MainWindow\0on_penStyleComboBox_currentIndexChanged\0"
    "\0penStyle\0on_shapeComboBox_currentIndexChanged\0"
    "shape\0on_penColorToolButton_clicked\0"
    "on_brushColorToolButton_clicked\0"
    "on_penWidthSpinBox_valueChanged\0"
    "penWidth\0on_action_Move_triggered\0"
    "on_action_Edit_triggered\0"
    "on_action_Draw_triggered\0"
    "on_action_Clear_triggered\0"
    "on_action_ZoomIn_triggered\0"
    "on_action_ZoomOut_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08,
       4,    1,   72,    2, 0x08,
       6,    0,   75,    2, 0x08,
       7,    0,   76,    2, 0x08,
       8,    1,   77,    2, 0x08,
      10,    0,   80,    2, 0x08,
      11,    0,   81,    2, 0x08,
      12,    0,   82,    2, 0x08,
      13,    0,   83,    2, 0x08,
      14,    0,   84,    2, 0x08,
      15,    0,   85,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_penStyleComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_shapeComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_penColorToolButton_clicked(); break;
        case 3: _t->on_brushColorToolButton_clicked(); break;
        case 4: _t->on_penWidthSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_action_Move_triggered(); break;
        case 6: _t->on_action_Edit_triggered(); break;
        case 7: _t->on_action_Draw_triggered(); break;
        case 8: _t->on_action_Clear_triggered(); break;
        case 9: _t->on_action_ZoomIn_triggered(); break;
        case 10: _t->on_action_ZoomOut_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

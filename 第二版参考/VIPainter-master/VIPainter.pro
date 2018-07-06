#-------------------------------------------------
#
# Project created by QtCreator 2017-06-26T11:24:42
#
#-------------------------------------------------

QT       += core gui svg
CONFIG   += c++11

CONFIG += c++11s

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VIPainter
TEMPLATE = app

INCLUDEPATH += Shapes Tools

SOURCES += \
    canvassizedialog.cpp \
    changetextdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    penstyledialog.cpp \
    vcursortype.cpp \
    vdelegate.cpp \
    vdocktitlebar.cpp \
    vlistview.cpp \
    Tools/vvector.cpp \
    Tools/vtransform.cpp \
    Tools/vsize.cpp \
    Tools/vpoint.cpp \
    Tools/vmagnification.cpp \
    Tools/interpolation.cpp \
    Shapes/vtype.cpp \
    Shapes/vtext.cpp \
    Shapes/vshape.cpp \
    Shapes/vroundedrectangle.cpp \
    Shapes/vpolyline.cpp \
    Shapes/vpolygon.cpp \
    Shapes/vpointgroupshape.cpp \
    Shapes/vgroupshape.cpp \
    Shapes/vellipse.cpp \
    Shapes/vcurveline.cpp \
    Shapes/vbeziercurve.cpp \
    vectorgraphwidget.cpp \
    paintwidget.cpp \
    Tools/swapqueue.cpp \
    imagewidget.cpp \
    Shapes/vimageshape.cpp

HEADERS  += \
    canvassizedialog.h \
    changetextdialog.h \
    mainwindow.h \
    penstyledialog.h \
    vcursortype.h \
    vdelegate.h \
    vdocktitlebar.h \
    vlistview.h \
    Tools/vvector.h \
    Tools/vtransform.h \
    Tools/vsize.h \
    Tools/vpoint.h \
    Tools/vmagnification.h \
    Tools/interpolation.h \
    Shapes/vtype.h \
    Shapes/vtext.h \
    Shapes/vshape.h \
    Shapes/vroundedrectangle.h \
    Shapes/vpolyline.h \
    Shapes/vpolygon.h \
    Shapes/vpointgroupshape.h \
    Shapes/vgroupshape.h \
    Shapes/vellipse.h \
    Shapes/vcurveline.h \
    Shapes/vbeziercurve.h \
    vectorgraphwidget.h \
    paintwidget.h \
    Tools/swapqueue.h \
    imagewidget.h \
    Shapes/vimageshape.h

FORMS    += mainwindow.ui \
    canvassizedialog.ui \
    changetextdialog.ui \
    penstyledialog.ui

RESOURCES += \
    resourse.qrc

TRANSLATIONS+=translate/zh_CN.ts

RC_ICONS = icon/VIPainter.ico

inst.files += VIPainter
inst.path = /usr/bin

INSTALLS += inst


#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T18:43:49
#
#-------------------------------------------------

QT       += core gui svg xml
RC_ICONS = ico.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


TARGET = VectorEditor
TEMPLATE = app
CONFIG += warn_on




SOURCES += main.cpp\
        mainwindow.cpp \
    svgreader.cpp \
    verectangle.cpp \
    veworkplace.cpp \
    verectanglesettings.cpp \
    veselectionrect.cpp \
    colorlabel.cpp \
    vepolyline.cpp \
    vepolylinesettings.cpp \
    dotsignal.cpp \
    veworkplaceview.cpp \
    vetextitem.cpp \
    veellipse.cpp \
    veellipsesetting.cpp \
    duline.cpp \
    dubezier.cpp \
    baseitem.cpp \
    basicshapeitem.cpp \
    complexshapeitem.cpp \
    handle.cpp

HEADERS  += mainwindow.h \
    svgreader.h \
    verectangle.h \
    veworkplace.h \
    verectanglesettings.h \
    veselectionrect.h \
    colorlabel.h \
    vepolyline.h \
    vepolylinesettings.h \
    dotsignal.h \
    veworkplaceview.h \
    vetextitem.h \
    veellipse.h \
    veellipsesetting.h \
    duline.h \
    dubezier.h \
    baseitem.h \
    basicshapeitem.h \
    complexshapeitem.h \
    handle.h \
    ui_mainwindow.h \
    ui_veellipsesettings.h \
    ui_vepolylinesettings.h \
    ui_verectanglesettings.h

FORMS    += mainwindow.ui \
    verectanglesettings.ui \
    vepolylinesettings.ui \
    veellipsesettings.ui

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    ico.ico \
    VectorEditor_resource.rc \
    Makefile.Debug \
    Makefile.Release \
    object_script.VectorEditor.Debug \
    object_script.VectorEditor.Release

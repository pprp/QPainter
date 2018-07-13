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

UI_DIR=./UI




SOURCES += main.cpp\
        mainwindow.cpp \
    svgreader.cpp \
    verectangle.cpp \
    veworkplace.cpp \
    verectanglesettings.cpp \
    colorlabel.cpp \
    vepolyline.cpp \
    vepolylinesettings.cpp \
    dotsignal.cpp \
    veworkplaceview.cpp \
    veellipse.cpp \
    veellipsesetting.cpp \
    handle.cpp \
    showhelpdialog.cpp \
    textdialog.cpp \
    showsvg.cpp \
    svgwindow.cpp \
    showsvgdialog.cpp \
    vebasicshapeitem.cpp \
    vebaseitem.cpp \
    textItem.cpp \
    vecomplexshapeitem.cpp \
    veselectionrect.cpp

HEADERS  += mainwindow.h \
    svgreader.h \
    verectangle.h \
    veworkplace.h \
    verectanglesettings.h \
    colorlabel.h \
    vepolyline.h \
    vepolylinesettings.h \
    dotsignal.h \
    veworkplaceview.h \
    veellipse.h \
    veellipsesetting.h \
    handle.h \
    showhelpdialog.h \
    textdialog.h \
    ui_mainwindow.h \
    ui_showhelpdialog.h \
    ui_textdialog.h \
    ui_veellipsesettings.h \
    ui_vepolylinesettings.h \
    ui_verectanglesettings.h \
    showsvg.h \
    svgwindow.h \
    showsvgdialog.h \
    vebasicshapeitem.h \
    vebaseitem.h \
    textItem.h \
    vecomplexshapeitem.h \
    ui_showsvgdialog.h \
    veselectionrect.h

FORMS    += mainwindow.ui \
    verectanglesettings.ui \
    vepolylinesettings.ui \
    veellipsesettings.ui \
    showhelpdialog.ui \
    textdialog.ui \
    showsvgdialog.ui

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    ico.ico \
    VectorEditor_resource.rc \
    Makefile.Debug \
    Makefile.Release \
    object_script.VectorEditor.Debug \
    object_script.VectorEditor.Release \
    Makefile \
    VectorEditor_resource.rc \
    Makefile \
    Makefile.Debug \
    Makefile.Release \
    object_script.VectorEditor.Debug \
    object_script.VectorEditor.Release

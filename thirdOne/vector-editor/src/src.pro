#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T18:43:49
#
#-------------------------------------------------

QT       += core gui svg xml

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
    veworkplaceview.cpp

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
    veworkplaceview.h

FORMS    += mainwindow.ui \
    verectanglesettings.ui \
    vepolylinesettings.ui

RESOURCES += \
    icons.qrc

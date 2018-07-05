#-------------------------------------------------
#
# Project created by QtCreator 2015-09-08T15:15:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawAndEditTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editwidget.cpp \
    Drawing.cpp

HEADERS  += mainwindow.h \
    editwidget.h \
    Drawing.h

FORMS    += mainwindow.ui

RESOURCES += \
    ICON/icon.qrc


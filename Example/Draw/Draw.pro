#-------------------------------------------------
#
# Project created by QtCreator 2018-07-03T14:42:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Draw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintarea.cpp \
    donewdialog.cpp \
    helpshowdialog.cpp

HEADERS  += mainwindow.h \
    paintarea.h \
    donewdialog.h \
    helpshowdialog.h

FORMS    += mainwindow.ui \
    donewdialog.ui \
    helpshowdialog.ui

RESOURCES += \
    ../ourico/ourico/ico.qrc

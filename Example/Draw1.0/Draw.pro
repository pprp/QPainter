#-------------------------------------------------
#
# Project created by QtCreator 2018-07-03T14:42:17
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Draw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintarea.cpp \
    donewdialog.cpp \
    helpshowdialog.cpp \
    donewtextdialog.cpp

HEADERS  += mainwindow.h \
    paintarea.h \
    donewdialog.h \
    helpshowdialog.h \
    donewtextdialog.h

FORMS    += mainwindow.ui \
    donewdialog.ui \
    helpshowdialog.ui \
    donewtextdialog.ui

RESOURCES += \
    ../ourico/ourico/ico.qrc


RC_ICONS = paint.ico

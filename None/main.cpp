#include "mainwindow.h"
#include <QApplication>

#include"window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
   // w.show();
    Window w;
    w.show();
    return a.exec();
}


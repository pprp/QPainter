#include "mainwindow.h"
#include <QApplication>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("QPainter");
   // w.setStyle(new QMotifStyle);
    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("QPainter v1.1.0");
    w.show();

    return a.exec();
}

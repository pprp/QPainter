#ifndef SHOWSVG_H
#define SHOWSVG_H

#include <QtSvg/QSvgWidget>
#include <QtSvg/QtSvg>
#include <QtSvg/QSvgRenderer>
#include <QWheelEvent>

class ShowSvg : public QSvgWidget
{
    Q_OBJECT
public:
    ShowSvg(QWidget *parent = 0);

    //响应鼠标滚轮事件，使SVG图片能够通过鼠标滚轮的滚动改变图片大小
    void wheelEvent(QWheelEvent *);

private:
    //图片显示尺寸的确定
    QSvgRenderer *render;
};

#endif // SHOWSVG_H

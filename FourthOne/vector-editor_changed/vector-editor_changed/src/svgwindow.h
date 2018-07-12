#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include <QScrollArea>
#include "showsvg.h"

// QScrollArea 是一个滚动区域，当图片放大超过主窗口的尺寸时，通过拖曳滚动条方式进行查看
class SvgWindow : public QScrollArea
{
    Q_OBJECT
public:
    SvgWindow(QWidget *parent = 0);
    void setFile(QString);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    ShowSvg * showsvg;
    QPoint mousePressPos;
    QPoint scrollBarValueOnMousePress;
};

#endif // SVGWINDOW_H

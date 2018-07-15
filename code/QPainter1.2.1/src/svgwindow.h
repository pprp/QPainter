#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include <QScrollArea>
#include "showsvg.h"

// QScrollArea滚动区域
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

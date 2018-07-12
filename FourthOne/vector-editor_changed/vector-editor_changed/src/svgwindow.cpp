#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent)
    : QScrollArea(parent)
{
    showsvg = new ShowSvg;
    setWidget(showsvg);
}

// 调用setFile()函数设置新的文件
void SvgWindow::setFile(QString fileName)
{
    if (fileName == "")
        return;

    showsvg->load(fileName);
    QSvgRenderer *render = showsvg->renderer();
    showsvg->resize(render->defaultSize());
}

void SvgWindow::mousePressEvent(QMouseEvent *event)
{
    mousePressPos = event->pos();
    //水平滑动条和垂直滑动条
    scrollBarValueOnMousePress.rx() = horizontalScrollBar()->value();
    scrollBarValueOnMousePress.ry() = verticalScrollBar()->value();
    event->accept();
}

void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
    horizontalScrollBar()->setValue(scrollBarValueOnMousePress.x() - event->pos().x() + mousePressPos.x());
    verticalScrollBar()->setValue(scrollBarValueOnMousePress.y() - event->pos().y() + mousePressPos.y());
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    event->accept();
}

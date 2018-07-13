#include "veworkplaceview.h"

VEWorkplaceView::VEWorkplaceView(QWidget *parent) : QGraphicsView(parent)
{

}

void VEWorkplaceView::enterEvent(QEvent *event)
{
    QGraphicsView::enterEvent(event);
    viewport()->setCursor(Qt::CrossCursor);
}

void VEWorkplaceView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    viewport()->setCursor(Qt::CrossCursor);
}

#include "dubezier.h"
#include <QPainter>

DuBezier::DuBezier(const QPointF &puntoInicio,
                   const QPointF &puntoControl,
                   const QPointF &puntoFinal,QGraphicsItem * parent)
    :QGraphicsObject(parent)
{
    mpuntoInicio = puntoInicio;
    mpuntoControl = puntoControl;
    mpuntoFinal = puntoFinal;
}

QPainterPath DuBezier::getPath() const
{
    QPainterPath path(mpuntoInicio);
    path.quadTo(mpuntoControl,mpuntoFinal);
    return path;
}

QRectF DuBezier::boundingRect() const
{
    return getPath().boundingRect();
}

void DuBezier::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    (void)option;
    (void)widget;
    QPen pen;
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawPath(getPath());
}

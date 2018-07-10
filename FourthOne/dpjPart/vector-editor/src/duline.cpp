#include "duline.h"
#include <QPainter>
#include <QDebug>

DuLine::DuLine(const QPointF &pto1,
               const QPointF &pto2,
               QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    this->mpto1 = pto1;
    this->mpto2 = pto2;
}

QRectF DuLine::boundingRect() const
{
    qreal x2 = mpto2.x();qreal y2 = mpto2.y();
    qreal x1 = mpto1.x();qreal y1 = mpto1.y();
    return QRectF(mpto1,QSizeF(x2-x1,y2-y1));
}

void DuLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawRect(boundingRect());
    //painter->drawRect(boundingRect());
    (void)option;
    (void)widget;
    qDebug() << mpto1 << mpto2;
    QPen pen;
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawLine(mpto1,mpto2);
}

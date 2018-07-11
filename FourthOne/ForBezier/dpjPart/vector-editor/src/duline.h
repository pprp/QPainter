#ifndef DULINE_H
#define DULINE_H
#include <QGraphicsObject>

class DuLine : public QGraphicsObject
{
public:
    DuLine(const QPointF&pto1,const QPointF&pto2,
           QGraphicsItem * parent = 0);

protected:
    QRectF boundingRect()const ;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) ;
private:
    QPointF mpto1;
    QPointF mpto2;
};

#endif // DULINE_H

#ifndef DUBEZIER_H
#define DUBEZIER_H
#include <QGraphicsObject>
#include <QGraphicsItem>

class DuBezier:public QGraphicsObject
{
public:
    DuBezier(const QPointF &puntoInicio,
             const QPointF &puntoControl,
             const QPointF &puntoFinal,
             QGraphicsItem * parent = 0);
    void setPuntoControl(const QPointF & puntocontrol){
        mpuntoControl = puntocontrol;
    }
private:
    QPointF mpuntoInicio;
    QPointF mpuntoControl;
    QPointF mpuntoFinal;
    QPainterPath getPath() const;
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
};

#endif // DUBEZIER_H

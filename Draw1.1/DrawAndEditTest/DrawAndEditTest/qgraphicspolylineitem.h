#ifndef QGRAPHICSPOLYLINEITEM_H
#define QGRAPHICSPOLYLINEITEM_H
#include <QRect>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>
#include <QVector>
#include<QGraphicsLineItem>
#include <QtGui>


class QGraphicsPolylineItem : public QGraphicsPathItem
{
public:

    QGraphicsPolylineItem();
    QGraphicsPolylineItem(QVector<QPointF> ps);

    QVector<QPointF> points;
    ~QGraphicsPolylineItem();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);


private:
//    QRectF m_rect;
    bool cScale;
    QCursor* m_cursor;
    QPointF start;
    QPointF end;
    int direction;
    bool isReadyToEdit;

    int nearByPointI(QPointF point);
};

#endif // QGRAPHICSPOLYLINEITEM_H

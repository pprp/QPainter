#ifndef BASEITEM_H
#define BASEITEM_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QList>
#include <QGraphicsSceneMouseEvent>
#include "handle.h"

class BaseItem : public QGraphicsItem
{
public:
    BaseItem(QGraphicsScene *scene = 0,QGraphicsItem *parent = 0);
    virtual QRectF boundingRect() const;
    QPainterPath shape() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setId(QString id);
    QString id();
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void createHandles();
    QList<Handle *> mHandles;
    QRectF mRect;
    QPointF mOrigin;
    bool mDrawBoundingRect;
    void setDrawBoundingRect(bool draw);
private:
    Handle *mCurrentHandle;
    QString mId;
};


#endif // BASEITEM_H

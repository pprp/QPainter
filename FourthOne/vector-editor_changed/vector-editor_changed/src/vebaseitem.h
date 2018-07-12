#ifndef VEBACEITEM_H
#define VEBACEITEM_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QList>
#include <QGraphicsSceneMouseEvent>
#include "handle.h"

class VEBaseItem : public QGraphicsItem
{
public:
    VEBaseItem(QGraphicsScene *scene = 0,QGraphicsItem *parent = 0);
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
    void setDrawBoundingRect(bool draw);

    QList<Handle *> mHandles;
    QRectF mRect;
    QPointF mOrigin;
    bool mDrawBoundingRect;
private:
    Handle *mCurrentHandle;
    QString mId;
};


#endif // VEBACEITEM_H

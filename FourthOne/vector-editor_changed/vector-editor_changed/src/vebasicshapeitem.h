#ifndef VEBASICSHAPESITEM_H
#define VEBASICSHAPESITEM_H

#include "vebaseitem.h"

class VEBasicShapesItem : public VEBaseItem
{
public:
    enum ItemType {ITEM_LINE,ITEM_CIRCLE,ITEM_RECTANGLE,ITEM_ELLIPSE,ITEM_PIXMAP};
    VEBasicShapesItem(qreal x, qreal y, qreal w, qreal h,ItemType type,QGraphicsScene *scene, QGraphicsItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void setType();
    void setPixmap(QString path);
private:
    QPixmap mPixmap;
    ItemType mType;
};

#endif // VEBASICSHAPESITEM_H

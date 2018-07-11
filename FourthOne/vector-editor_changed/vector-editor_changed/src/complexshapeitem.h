#ifndef COMPLEXSHAPEITEM_H
#define COMPLEXSHAPEITEM_H

#include "baseitem.h"
class ComplexShapeItem : public BaseItem
{
public:
    enum SegmentType {SEGEMENT_LINE,SEGEMENT_CURVE};
    struct Segment{SegmentType type;Handle *handles;};
    ComplexShapeItem(QGraphicsScene *scene, QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void addPoint(QPointF point,SegmentType type);
private:
    void recalculateRect();
    QList<Handle *> mShapeHandles;
    QList<Segment *> mSegments;
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // COMPLEXSHAPEITEM_H

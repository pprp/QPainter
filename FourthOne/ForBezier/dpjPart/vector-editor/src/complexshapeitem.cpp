#include "complexshapeitem.h"
#include <QPainter>
#include <QSettings>
#include <QDebug>
ComplexShapeItem::ComplexShapeItem(QGraphicsScene *scene,QGraphicsItem *parent):BaseItem(scene,parent)
{
    this->setDrawBoundingRect(false);
}
void ComplexShapeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPainterPath path;
    //path.moveTo(mHandles.at(10)->pos());
    for(int i=0 ; i < mHandles.size() ; i++) {
        if(i == 0) {
            path.moveTo(mHandles.at(0)->pos());
        } else {
            //TODO: Check segment type.
            //Create a cubic.
            //path.quadTo();
            QLineF line1(path.currentPosition(),mHandles.at(i)->pos());
            QLineF line2(mHandles.at(i+1)->pos(),mHandles.at(i+2)->pos());
            path.cubicTo(mHandles.at(i)->pos(),mHandles.at(i+1)->pos(),mHandles.at(i+2)->pos());
            if(this->isSelected()) {
                //Draw the handle lines.
                painter->drawLine(line1);
                painter->drawLine(line2);
            }
            //qDebug()<<path.elementCount();
            //Skip used points.
            i = i+2;
        }

    }
    painter->drawPath(path);
    BaseItem::paint(painter,option,widget);
}
// Replace this with add segment.
void ComplexShapeItem::addPoint(QPointF point, SegmentType type) {
    QSettings settings;
    int size = settings.value("drawing/hanleSize",10).toInt();
    mHandles<<new Handle(point,size,Handle::HANDLE_SHAPE_CIRCLE,Handle::HANDLE_TYPE_CTRL);
    this->recalculateRect();
}
void ComplexShapeItem::recalculateRect() {
    QList<qreal> listX;
    QList<qreal> listY;
    foreach (Handle *h, mHandles) {
        listX<<h->pos().x();
        listY<<h->pos().y();
    }
    std::sort(listX.begin(),listX.end());
    std::sort(listY.begin(),listY.end());
    QPointF topLeft = QPointF(listX.first(),listY.first());
    QPointF bottomRight = QPointF(listX.last(),listY.last());
    //qDebug()<<topLeft<<bottomRight;
    mRect = QRectF(topLeft,bottomRight);
}
void ComplexShapeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    BaseItem::mouseReleaseEvent(event);
    recalculateRect();
}

QRectF ComplexShapeItem::boundingRect() const {
    QSettings settings;
    //Adjust bounding rectangle to include the handles so clicking them is detected.
    int size = settings.value("drawing/hanleSize",10).toInt();
    return this->mRect.adjusted(-size/2,-size/2 - 50,size/2,size/2);
}

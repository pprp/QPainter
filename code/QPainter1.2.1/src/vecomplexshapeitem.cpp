#include "vecomplexshapeitem.h"
#include <QPainter>
#include <QSettings>
#include <QDebug>
VEComplexShapeItem::VEComplexShapeItem(QGraphicsScene *scene,QGraphicsItem *parent):VEBaseItem(scene,parent)
{
    this->setDrawBoundingRect(false);
}
void VEComplexShapeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen;
    pen.setWidth(4);
    painter->setPen(pen);
    QPainterPath path;
    for(int i=0 ; i < mHandles.size() ; i++) {
        if(i == 0) {
            path.moveTo(mHandles.at(0)->pos());
        } else {
            QLineF line1(path.currentPosition(),mHandles.at(i)->pos());
            QLineF line2(mHandles.at(i+1)->pos(),mHandles.at(i+2)->pos());
            path.cubicTo(mHandles.at(i)->pos(),mHandles.at(i+1)->pos(),mHandles.at(i+2)->pos());
            if(this->isSelected()) {
                //控制线
                painter->drawLine(line1);
                painter->drawLine(line2);
            }
            i = i+2;
        }

    }
    painter->drawPath(path);
    VEBaseItem::paint(painter,option,widget);
}
//加点
void VEComplexShapeItem::addPoint(QPointF point, SegmentType type) {
    Q_UNUSED(type);
    QSettings settings;
    int size = settings.value("drawing/hanleSize",4).toInt();
    mHandles<<new Handle(point,size,Handle::HANDLE_SHAPE_CIRCLE,Handle::HANDLE_TYPE_CTRL);
    this->recalculateRect();
}

void VEComplexShapeItem::recalculateRect() {
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
void VEComplexShapeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    VEBaseItem::mouseReleaseEvent(event);
    recalculateRect();
}

QRectF VEComplexShapeItem::boundingRect() const {
    QSettings settings;
    //Adjust bounding rectangle to include the handles so clicking them is detected.
    int size = settings.value("drawing/hanleSize",4).toInt();
    return this->mRect.adjusted(-size/2,-size/2 - 50,size/2,size/2);
}

#include "basicshapeitem.h"
#include <QPainter>
#include <QGraphicsScene>
#include "handle.h"
BasicShapesItem::BasicShapesItem(qreal x, qreal y, qreal w, qreal h,ItemType type,QGraphicsScene *scene, QGraphicsItem *parent) : BaseItem(scene,parent)
{
    mRect.setRect(x,y,w,h);
    mType = type;
    createHandles();
}

void BasicShapesItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //Fix coordinates for images.
    if(mRect.left() > mRect.right()) {
        qreal left = mRect.left();
        qreal right = mRect.right();
        mRect.setLeft(right);
        mRect.setRight(left);
    }
    if(mRect.top() > mRect.bottom()) {
        qreal top = mRect.top();
        qreal bottom = mRect.bottom();
        mRect.setTop(bottom);
        mRect.setBottom(top);
    }
    //Enable antialiasing.
    painter->setRenderHint(QPainter::Antialiasing, true);
    switch (mType) {
    case ITEM_RECTANGLE:
        painter->drawRect(this->mRect);
        break;
    case ITEM_ELLIPSE:
        painter->drawEllipse(this->mRect);
        break;
    case ITEM_LINE:
        painter->drawLine(this->mRect.topLeft(),this->mRect.bottomRight());
        break;
    case ITEM_PIXMAP:
        //painter->drawPixmap(this->mRect.topLeft(),this->mPixmap,this->mRect);
        painter->drawPixmap(this->mRect.toRect(),this->mPixmap);
        break;
    default:
        break;
    }
    BaseItem::paint(painter,option,widget);
    scene()->update();
}

void BasicShapesItem::setPixmap(QString path) {
    this->mPixmap = QPixmap(path);
}

QRectF BasicShapesItem::boundingRect() const{
    return BaseItem::boundingRect();
}

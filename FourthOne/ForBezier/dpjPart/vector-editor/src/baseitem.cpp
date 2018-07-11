#include "baseitem.h"
#include <QUuid>
#include <QSettings>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include "handle.h"

BaseItem::BaseItem(QGraphicsScene *scene, QGraphicsItem *parent) : QGraphicsItem(parent),mCurrentHandle(0)
{
    QUuid id;
    id = QUuid::createUuid();
    this->mId = id.toString();
    this->mDrawBoundingRect = true;
    this->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemSendsGeometryChanges);
    if(scene) {
        scene->addItem(this);
    }
}
void BaseItem::setId(QString id) {
    this->mId = id;
}
QString BaseItem::id() {
    return this->mId;
}
void BaseItem::setDrawBoundingRect(bool draw) {
    this->mDrawBoundingRect = draw;
}

QRectF BaseItem::boundingRect() const {
    QSettings settings;
    //Adjust bounding rectangle to include the handles so clicking them is detected.
    int size = settings.value("drawing/hanleSize",10).toInt();
    return this->mRect.adjusted(-size/2,-size/2 - 50,size/2,size/2);
}
QPainterPath BaseItem::shape() const {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    if(this->isSelected()) {
        foreach (Handle *handle, mHandles) {
            switch (handle->shape()) {
            case Handle::HANDLE_SHAPE_RECT:
                path.addRect(handle->boundingRect());
                break;
            case Handle::HANDLE_SHAPE_CIRCLE:
                path.addRect(handle->boundingRect());
                break;
            case Handle::HANDLE_SHAPE_TRIANGLE:
                break;
            }
        }
    }
    path.addRect(this->mRect);
    return path;
}
void BaseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //If the item is selected draw selection rectangle and handles.
    if(this->isSelected()) {
        if(this->mDrawBoundingRect) {
            //Draw Selection Triangle.
            QPen pen(Qt::green);
            painter->setPen(pen);
            painter->drawRect(this->mRect);
        }
        //Drawing the handles.
        QPointF p1;
        QPointF p2;
        foreach (Handle *handle, mHandles) {
            if(handle->type() == Handle::HANDLE_TYPE_ROTATE) {
                p1 = handle->pos();
            }
            if(handle->type() == Handle::HANDLE_TYPE_TOP) {
                p2 = handle->pos();
            }
            if(handle->type() == Handle::HANDLE_TYPE_CTRL) {
                painter->save();
                QPen pen(Qt::green);
                painter->setPen(pen);
                //painter->setPen(QPen(Qt::black));
                painter->setBackground(QBrush(Qt::green));
                painter->drawRect(handle->boundingRect());
                painter->restore();
            } else {
                switch (handle->shape()) {
                case Handle::HANDLE_SHAPE_RECT:
                    painter->drawRect(handle->boundingRect());
                    break;
                case Handle::HANDLE_SHAPE_CIRCLE:
                    painter->drawEllipse(handle->boundingRect());
                    break;
                case Handle::HANDLE_SHAPE_TRIANGLE:
                    break;
                }
            }
        }
        painter->drawLine(p1,p2);
        painter->drawPoint(this->mOrigin);
    }
}
void BaseItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);
    if(event->buttons() == Qt::LeftButton) {
        //Detect which handle is clicked.
        foreach (Handle *handle, mHandles) {
            if(handle->boundingRect().contains(event->pos())) {
                this->mCurrentHandle = handle;
            }
        }
    }
}

void BaseItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    //Left mouse button is down.
    //TODO: Add grid support.
    if(event->buttons() == Qt::LeftButton && mCurrentHandle) {
        qreal dx = (mOrigin.x() - mRect.center().x()) / mRect.width();
        qreal dy = (mOrigin.y() - mRect.center().y()) / mRect.height();
        switch (mCurrentHandle->type()) {
        case Handle::HANDLE_TYPE_LEFT:
            this->mRect.setLeft(event->pos().x());
            //Update the origin.
            mOrigin.setX((dx * mRect.width()) + mRect.center().x());
            break;
        case Handle::HANDLE_TYPE_RIGHT:
            this->mRect.setRight(event->pos().x());
            //Update the origin.
            mOrigin.setX((dx * mRect.width()) + mRect.center().x());
            break;
        case Handle::HANDLE_TYPE_TOP:
            this->mRect.setTop(event->pos().y());
            //Update the origin.
            mOrigin.setY((dy * mRect.height()) + mRect.center().y());
            break;
        case Handle::HANDLE_TYPE_BOTTOM:
            this->mRect.setBottom(event->pos().y());
            //Update the origin.
            mOrigin.setY((dy * mRect.height()) + mRect.center().y());
            break;
        case Handle::HANDLE_TYPE_TOPLEFT:
            this->mRect.setTopLeft(event->pos());
            //Update the origin.
            mOrigin.setX((dx * mRect.width()) + mRect.center().x());
            mOrigin.setY((dy * mRect.height()) + mRect.center().y());
            break;
        case Handle::HANDLE_TYPE_TOPRIGHT:
            this->mRect.setTopRight(event->pos());
            //Update the origin.
            mOrigin.setX((dx * mRect.width()) + mRect.center().x());
            mOrigin.setY((dy * mRect.height()) + mRect.center().y());
            break;
        case Handle::HANDLE_TYPE_BOTTOMLEFT:
            this->mRect.setBottomLeft(event->pos());
            //Update the origin.
            mOrigin.setX((dx * mRect.width()) + mRect.center().x());
            mOrigin.setY((dy * mRect.height()) + mRect.center().y());
            break;
        case Handle::HANDLE_TYPE_BOTTOMRIGHT:
            this->mRect.setBottomRight(event->pos());
            //Update the origin.
            mOrigin.setX((dx * mRect.width()) + mRect.center().x());
            mOrigin.setY((dy * mRect.height()) + mRect.center().y());
            break;
        case Handle::HANDLE_TYPE_ROTATE:
            //Setting the origin point.
            this->setTransform(QTransform().translate(mOrigin.x(),mOrigin.y()).rotate(-QLineF(event->scenePos(),mapToScene(mOrigin)).angle() + QLineF(event->lastScenePos(),mapToScene(mOrigin)).angle()).translate(-mOrigin.x(),-mOrigin.y()),true);
            break;
        case Handle::HANDLE_TYPE_ORIGIN:
            mCurrentHandle->setPos(event->pos());
            this->mOrigin = mCurrentHandle->pos();
            break;
        case Handle::HANDLE_TYPE_CTRL:
            mCurrentHandle->setPos(event->pos());
            break;
        default:
            QGraphicsItem::mouseMoveEvent(event);
            break;
        }
        //Update handle positions.
        QPointF left(mRect.left(),mRect.top() + mRect.height()/2);
        QPointF right(mRect.right(),mRect.top() + mRect.height()/2);
        QPointF top(mRect.left()+mRect.width()/2,mRect.top());
        QPointF bottom(mRect.left()+mRect.width()/2,mRect.bottom());
        QPointF rotate(top.x(),top.y()-50);
        foreach (Handle *handle, mHandles) {
            switch (handle->type()) {
            case Handle::HANDLE_TYPE_LEFT:
                handle->setPos(left);
                break;
            case Handle::HANDLE_TYPE_RIGHT:
                handle->setPos(right);
                break;
            case Handle::HANDLE_TYPE_TOP:
                handle->setPos(top);
                break;
            case Handle::HANDLE_TYPE_BOTTOM:
                handle->setPos(bottom);
                break;
            case Handle::HANDLE_TYPE_TOPLEFT:
                handle->setPos(mRect.topLeft());
                break;
            case Handle::HANDLE_TYPE_TOPRIGHT:
                handle->setPos(mRect.topRight());
                break;
            case Handle::HANDLE_TYPE_BOTTOMLEFT:
                handle->setPos(mRect.bottomLeft());
                break;
            case Handle::HANDLE_TYPE_BOTTOMRIGHT:
                handle->setPos(mRect.bottomRight());
                break;
            case Handle::HANDLE_TYPE_ROTATE:
                handle->setPos(rotate);
                break;
            case Handle::HANDLE_TYPE_ORIGIN:
                handle->setPos(mOrigin);
                break;
            }
        }
    } else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void BaseItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);
    //Reset handles states.
    this->mCurrentHandle = 0;
}

QVariant BaseItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        // Value is the new position.
        QSettings settings;
        int gridSize = settings.value("drawing/gridSize").toInt();
        bool gridEnabled = settings.value("drawing/gridEnabled").toBool();

        QPointF newPos = value.toPointF();
        if (gridEnabled) {
            if((int)newPos.x()%gridSize != 0) {
                int x = (int)newPos.x() - (int)newPos.x()%gridSize;
                newPos.setX(x);
            }
            if((int)newPos.y()%gridSize != 0) {
                int y = (int)newPos.y() - (int)newPos.y()%gridSize;
                newPos.setY(y);
            }
        }
        return newPos;
    }
    return QGraphicsItem::itemChange(change, value);
}
void BaseItem::createHandles() {
    QSettings settings;
    int size = settings.value("drawing/hanleSize",10).toInt();
    //Resizing rectangle.
    mOrigin = this->mRect.center();
    QPointF left(mRect.left(),mRect.top() + mRect.height()/2);
    QPointF right(mRect.right(),mRect.top() + mRect.height()/2);
    QPointF top(mRect.left()+mRect.width()/2,mRect.top());
    QPointF bottom(mRect.left()+mRect.width()/2,mRect.bottom());
    QPointF rotate(top.x(),top.y()-50);
    mHandles<<new Handle(mRect.topLeft(),size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_TOPLEFT);
    mHandles<<new Handle(top,size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_TOP);
    mHandles<<new Handle(mRect.topRight(),size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_TOPRIGHT);
    mHandles<<new Handle(left,size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_LEFT);
    mHandles<<new Handle(right,size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_RIGHT);
    mHandles<<new Handle(mRect.bottomLeft(),size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_BOTTOMLEFT);
    mHandles<<new Handle(bottom,size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_BOTTOM);
    mHandles<<new Handle(mRect.bottomRight(),size,Handle::HANDLE_SHAPE_RECT,Handle::HANDLE_TYPE_BOTTOMRIGHT);
    mHandles<<new Handle(rotate,size,Handle::HANDLE_SHAPE_CIRCLE,Handle::HANDLE_TYPE_ROTATE);
    mHandles<<new Handle(mOrigin,size,Handle::HANDLE_SHAPE_CIRCLE,Handle::HANDLE_TYPE_ORIGIN);
}

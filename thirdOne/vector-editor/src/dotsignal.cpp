#include "dotsignal.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

DotSignal::DotSignal(QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::black));
    setRect(-4,-4,8,8);
    setDotFlags(0);
}

DotSignal::DotSignal(QPointF pos, QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::black));
    setRect(-4,-4,8,8);
    setPos(pos);
    setPreviousPosition(pos);
    setDotFlags(0);
}

DotSignal::~DotSignal()
{

}

QPointF DotSignal::previousPosition() const
{
    return m_previousPosition;
}

void DotSignal::setPreviousPosition(const QPointF previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged();
}

void DotSignal::setDotFlags(unsigned int flags)
{
    m_flags = flags;
}

void DotSignal::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        auto dx = event->scenePos().x() - m_previousPosition.x();
        auto dy = event->scenePos().y() - m_previousPosition.y();
        moveBy(dx,dy);
        setPreviousPosition(event->scenePos());
        emit signalMove(this, dx, dy);
    } else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void DotSignal::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        setPreviousPosition(event->scenePos());
    } else {
        QGraphicsItem::mousePressEvent(event);
    }
}

void DotSignal::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseRelease();
    QGraphicsItem::mouseReleaseEvent(event);
}

void DotSignal::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    setBrush(QBrush(Qt::red));
}

void DotSignal::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    setBrush(QBrush(Qt::black));
}

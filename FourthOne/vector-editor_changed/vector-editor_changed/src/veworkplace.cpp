#include "veworkplace.h"
#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include "verectangle.h"
#include "veselectionrect.h"
#include "vepolyline.h"
#include "veellipse.h"
#include <QDebug>
#include <QGraphicsItem>

VEWorkplace::VEWorkplace(QObject *parent) :
    QGraphicsScene(parent),
    currentItem(nullptr),
    m_currentAction(DefaultType),
    m_previousAction(0),
    m_leftMouseButtonPressed(false)
{

}

VEWorkplace::~VEWorkplace()
{
    delete currentItem;
}

int VEWorkplace::currentAction() const
{
    return m_currentAction;
}

QPointF VEWorkplace::previousPosition() const
{
    return m_previousPosition;
}

void VEWorkplace::setCurrentAction(const int type)
{
    m_currentAction = type;
    emit currentActionChanged(m_currentAction);
}

void VEWorkplace::setPreviousPosition(const QPointF previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged();
}



void VEWorkplace::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->button() & Qt::LeftButton) {
        m_leftMouseButtonPressed = true;
        setPreviousPosition(event->scenePos());
        if(QApplication::keyboardModifiers() & Qt::ShiftModifier){
            m_previousAction = m_currentAction;
            setCurrentAction(SelectionType);
        }
    }
    switch (m_currentAction){
    case LineType: {
        if (m_leftMouseButtonPressed && !(event->button() & Qt::RightButton) && !(event->button() & Qt::MiddleButton)) {
            deselectItems();
            VEPolyline *polyline = new VEPolyline();
            currentItem = polyline;
            addItem(currentItem);
            connect(polyline, &VEPolyline::clicked, this, &VEWorkplace::signalSelectItem);
            connect(polyline, &VEPolyline::signalMove, this, &VEWorkplace::slotMove);
            QPainterPath path;
            path.moveTo(m_previousPosition);
            polyline->setPath(path);
            emit signalNewSelectItem(polyline);
        }
        break;
    }
    case RectangleType: {
        if (m_leftMouseButtonPressed && !(event->button() & Qt::RightButton) && !(event->button() & Qt::MiddleButton)) {
            deselectItems();
            VERectangle *rectangle = new VERectangle();
            currentItem = rectangle;
            addItem(currentItem);
            connect(rectangle, &VERectangle::clicked, this, &VEWorkplace::signalSelectItem);
            connect(rectangle, &VERectangle::signalMove, this, &VEWorkplace::slotMove);
            emit signalNewSelectItem(rectangle);
        }
        break;
    }
    case EllipseType:{
        if (m_leftMouseButtonPressed && !(event->button() & Qt::RightButton) && !(event->button() & Qt::MiddleButton)) {
            deselectItems();
            VEEllipse *ellipse = new VEEllipse();
            currentItem = ellipse;
            addItem(currentItem);
            connect(ellipse, &VEEllipse::clicked, this, &VEWorkplace::signalSelectItem);
            connect(ellipse, &VEEllipse::signalMove, this, &VEWorkplace::slotMove);
            emit signalNewSelectItem(ellipse);
        }
        break;
    }
    case SelectionType: {
        if (m_leftMouseButtonPressed && !(event->button() & Qt::RightButton) && !(event->button() & Qt::MiddleButton)) {
            deselectItems();
            VESelectionRect *selection = new VESelectionRect();
            currentItem = selection;
            addItem(currentItem);
        }
        break;
    }
    default: {
        QGraphicsScene::mousePressEvent(event);
        break;
    }
    }

}

void VEWorkplace::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    switch (m_currentAction) {
    case LineType: {
        if (m_leftMouseButtonPressed) {
            VEPolyline * polyline = qgraphicsitem_cast<VEPolyline *>(currentItem);
            QPainterPath path;
            path.moveTo(m_previousPosition);
            path.lineTo(event->scenePos());
            polyline->setPath(path);
        }
        break;
    }
    case RectangleType: {
        if (m_leftMouseButtonPressed) {
            auto dx = event->scenePos().x() - m_previousPosition.x();
            auto dy = event->scenePos().y() - m_previousPosition.y();
            VERectangle * rectangle = qgraphicsitem_cast<VERectangle *>(currentItem);
            rectangle->setRect((dx > 0) ? m_previousPosition.x() : event->scenePos().x(),
                               (dy > 0) ? m_previousPosition.y() : event->scenePos().y(),
                               qAbs(dx), qAbs(dy));
        }
        break;
    }
    case EllipseType: {
        if (m_leftMouseButtonPressed) {
            auto dx = event->scenePos().x() - m_previousPosition.x();
            auto dy = event->scenePos().y() - m_previousPosition.y();
            VEEllipse * ellipse = qgraphicsitem_cast<VEEllipse *>(currentItem);
            ellipse->setRect((dx > 0) ? m_previousPosition.x() : event->scenePos().x(),
                             (dy > 0) ? m_previousPosition.y() : event->scenePos().y(),
                             qAbs(dx), qAbs(dy));
        }
        break;
    }
    case SelectionType: {
        if (m_leftMouseButtonPressed) {
            auto dx = event->scenePos().x() - m_previousPosition.x();
            auto dy = event->scenePos().y() - m_previousPosition.y();
            VESelectionRect * selection = qgraphicsitem_cast<VESelectionRect *>(currentItem);
            selection->setRect((dx > 0) ? m_previousPosition.x() : event->scenePos().x(),
                               (dy > 0) ? m_previousPosition.y() : event->scenePos().y(),
                               qAbs(dx), qAbs(dy));
        }
        break;
    }
    default: {
        QGraphicsScene::mouseMoveEvent(event);
        break;
    }
    }

}

void VEWorkplace::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton) m_leftMouseButtonPressed = false;
    switch (m_currentAction) {
    case LineType:
    case EllipseType:
    case RectangleType: {
        if (!m_leftMouseButtonPressed &&
                !(event->button() & Qt::RightButton) &&
                !(event->button() & Qt::MiddleButton)) {
            currentItem = nullptr;
        }
        break;
    }
    case SelectionType: {
        if (!m_leftMouseButtonPressed &&
                !(event->button() & Qt::RightButton) &&
                !(event->button() & Qt::MiddleButton)) {
            VESelectionRect * selection = qgraphicsitem_cast<VESelectionRect *>(currentItem);
            if(!selection->collidingItems().isEmpty()){
                foreach (QGraphicsItem *item, selection->collidingItems()) {
                    item->setSelected(true);
                }
            }
            selection->deleteLater();
            if(selectedItems().length() == 1){
                signalSelectItem(selectedItems().at(0));
            }
            setCurrentAction(m_previousAction);
            currentItem = nullptr;
        }
        break;
    }
    default: {
        QGraphicsScene::mouseReleaseEvent(event);
        break;
    }
    }
    update();
}

void VEWorkplace::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_currentAction) {
    case LineType:
    case RectangleType:
    case SelectionType:
    case EllipseType:
        break;
    default:
        QGraphicsScene::mouseDoubleClickEvent(event);
        break;
    }
}

void VEWorkplace::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Delete: {
        foreach (QGraphicsItem *item, selectedItems()) {
            removeItem(item);
            delete item;
        }
        deselectItems();
        break;
    }
    case Qt::Key_A: {
        if(QApplication::keyboardModifiers() & Qt::ControlModifier){
            foreach (QGraphicsItem *item, items()) {
                item->setSelected(true);
            }
            if(selectedItems().length() == 1)
                signalSelectItem(selectedItems().at(0));
        }
        break;
    }
    default:
        break;
    }
    QGraphicsScene::keyPressEvent(event);
}

void VEWorkplace::deselectItems()
{
    foreach (QGraphicsItem *item, selectedItems()) {
        item->setSelected(false);
    }
    selectedItems().clear();
}

void VEWorkplace::slotMove(QGraphicsItem *signalOwner, qreal dx, qreal dy)
{
    foreach (QGraphicsItem *item, selectedItems()) {
        if(item != signalOwner) item->moveBy(dx,dy);
    }
}

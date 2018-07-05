#include "editwidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPolygonItem>
#include <QPainterPath>
#include "qgraphicspolylineitem.h"
#include <QMessageBox>
#include <math.h>

EditWidget::EditWidget(QWidget *parent):QGraphicsScene(parent)
{
    curShape = this->PolylineType;
    curState=this->DrawType;
    isDrawing=false;
    isEditing=false;

    penColor = Qt::black;
    brushColor = Qt::black;
    penWidth = 1;
    penStyle = Qt::SolidLine;
    pen=new QPen();
    editPointIndex=-1;
}
void EditWidget::mousePressDraw(QGraphicsSceneMouseEvent *event)
{
        setPen();
        if(curShape==this->PointType)
        {
//            if(event->button()==Qt::LeftButton && this->isDrawing)
//            {
//                points.append(event->scenePos());
//                QGraphicsEllipseItem *newPointCircle=
//                        new QGraphicsEllipseItem(points[i].x()-5,points[i].y()-5,10,10);
//                newPointCircle->setBrush(Qt::red);
//                QGraphicsItem *origPointCricle=
//                        this->itemAt(points[i],this->items()[0]->transform());
//                tempShapes.removeOne(origPointCricle);
//                tempShapes.append(newPointCircle);
//                showShape(tempShapes);
//                editPointIndex=i;
//            }
        }
        else if(curShape==this->PolylineType)
        {
            if(event->button()==Qt::LeftButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<points.count();++i)
                {
                    path->lineTo(points[i]);
                }
                QGraphicsPathItem *cur=new QGraphicsPathItem();
                cur->setPath(*path);
//                QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
                cur->setPen(*pen);
                tempShapes=shapes;
                tempShapes.append(cur);
                showShape(tempShapes);
            }
            else if(event->button()==Qt::LeftButton && !this->isDrawing)     //如果之前没有开始画图，则单击开始画图
            {
                points.clear();
                points.append(event->scenePos());
                isDrawing=true;
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<points.count();++i)
                {
                    path->lineTo(points[i]);
                }
                QGraphicsPathItem *cur=new QGraphicsPathItem();
                cur->setPath(*path);
//                QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
                cur->setFlag(QGraphicsItem::ItemIsMovable,true);
                cur->setFlag(QGraphicsItem::ItemIsSelectable,true);
                cur->setPen(*pen);
                shapes.append(cur);
                showShape(shapes);

                isDrawing=false;
            }
        }
        else if(curShape==this->PolygonType)
        {

            if(event->button()==Qt::LeftButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QGraphicsPolygonItem *cur=new QGraphicsPolygonItem();
                QPolygonF *curPolygon=new QPolygonF(points);
                cur->setPolygon(*curPolygon);
                cur->setPen(*pen);
                cur->setBrush(brushColor);
                tempShapes=shapes;
                tempShapes.append(cur);
                showShape(tempShapes);
            }
            else if(event->button()==Qt::LeftButton && !this->isDrawing)     //如果之前没有开始画图，则单击开始画图
            {

                points.clear();
                points.append(event->scenePos());
                isDrawing=true;
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                QGraphicsPolygonItem *cur=new QGraphicsPolygonItem();
                QPolygonF *curPolygon=new QPolygonF(points);
                cur->setPolygon(*curPolygon);
                cur->setFlag(QGraphicsItem::ItemIsMovable,true);
                cur->setFlag(QGraphicsItem::ItemIsSelectable,true);

                cur->setPen(*pen);
                cur->setBrush(brushColor);
                shapes.append(cur);
                showShape(shapes);

                isDrawing=false;
            }
        }else if(curShape == this->EllispeType)
        {
            if(event->button()==Qt::LeftButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<points.count();++i)
                {
                    path->moveTo(points[i]);
                    path->addEllipse(points[i].rx()-50,points[i].ry()-50,100,100);
                }


                QGraphicsPathItem *cur=new QGraphicsPathItem();
                cur->setPath(*path);

                tempShapes=shapes;
                tempShapes.append(cur);
                showShape(tempShapes);
            }
            else if(event->button()==Qt::LeftButton && !this->isDrawing)     //如果之前没有开始画图，则单击开始画图
            {
                points.clear();
                points.append(event->scenePos());
                isDrawing=true;
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<points.count();++i)
                {
                    path->moveTo(points[i]);
                    path->addEllipse(points[i].rx()-50,points[i].ry()-50,100,100);

                }
                QGraphicsPathItem *cur=new QGraphicsPathItem();
                cur->setPath(*path);
//                QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
                cur->setFlag(QGraphicsItem::ItemIsMovable,true);
                cur->setFlag(QGraphicsItem::ItemIsSelectable,true);
                cur->setPen(*pen);
                shapes.append(cur);
                showShape(shapes);
                isDrawing=false;
            }
        }else if(curShape == this->RectangleType)
        {
            if(event->button()==Qt::LeftButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<points.count();++i)
                {
                    path->moveTo(points[i]);
                    path->addRect(points[i].rx()-50,points[i].ry()-50,100,100);
                    QGraphicsPathItem *cur=new QGraphicsPathItem();
                    cur->setPath(*path);

                    tempShapes=shapes;
                    tempShapes.append(cur);
                    showShape(tempShapes);
                }

            }
            else if(event->button()==Qt::LeftButton && !this->isDrawing)     //如果之前没有开始画图，则单击开始画图
            {
                points.clear();
                points.append(event->scenePos());
                isDrawing=true;
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<points.count();++i)
                {
                    path->moveTo(points[i]);
                    path->addRect(points[i].rx()-50,points[i].ry()-50,100,100);



                }
                QGraphicsPathItem *cur=new QGraphicsPathItem();
                cur->setPath(*path);
//                QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
                cur->setFlag(QGraphicsItem::ItemIsMovable,true);
                cur->setFlag(QGraphicsItem::ItemIsSelectable,true);
                cur->setPen(*pen);
                shapes.append(cur);
                showShape(shapes);
                isDrawing=false;


            }
        }else if(curShape == this->RoundedRectangleType)
                {
                    if(event->button()==Qt::LeftButton && this->isDrawing)
                    {
                        points.append(event->scenePos());
                        QPainterPath *path=new QPainterPath(points[0]);
                        for(int i=1;i<points.count();++i)
                        {
                            path->moveTo(points[i]);
                            path->addRoundedRect(points[i].rx()-50,points[i].ry()-50,100,100,20,20,Qt::AbsoluteSize);
                            QGraphicsPathItem *cur=new QGraphicsPathItem();
                            cur->setPath(*path);

                            tempShapes=shapes;
                            tempShapes.append(cur);
                            showShape(tempShapes);
                        }

                    }
                    else if(event->button()==Qt::LeftButton && !this->isDrawing)     //如果之前没有开始画图，则单击开始画图
                    {
                        points.clear();
                        points.append(event->scenePos());
                        isDrawing=true;
                    }
                    else if(event->button()==Qt::RightButton && this->isDrawing)
                    {
                        QPainterPath *path=new QPainterPath(points[0]);
                        for(int i=1;i<points.count();++i)
                        {
                            path->moveTo(points[i]);
                            path->addRect(points[i].rx()-50,points[i].ry()-50,100,100);



                        }
                        QGraphicsPathItem *cur=new QGraphicsPathItem();
                        cur->setPath(*path);
        //                QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
                        cur->setFlag(QGraphicsItem::ItemIsMovable,true);
                        cur->setFlag(QGraphicsItem::ItemIsSelectable,true);
                        cur->setPen(*pen);
                        shapes.append(cur);
                        showShape(shapes);
                        isDrawing=false;


                    }
                }
        else if (curShape == this->LineType)
        {
            if(event->button()==Qt::LeftButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<2;++i)
                {
                    path->lineTo(points[i]);
                }
                QGraphicsPathItem *cur=new QGraphicsPathItem();
                cur->setPath(*path);
//                QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
                cur->setPen(*pen);
                tempShapes=shapes;
                tempShapes.append(cur);
                showShape(tempShapes);
            }
            else if(event->button()==Qt::LeftButton && !this->isDrawing)     //如果之前没有开始画图，则单击开始画图
            {
                points.clear();
                points.append(event->scenePos());
                isDrawing=true;
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<2;++i)
                {
                    path->lineTo(points[i]);
                }
                QGraphicsPathItem *cur=new QGraphicsPathItem();
                cur->setPath(*path);
//                QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
                cur->setFlag(QGraphicsItem::ItemIsMovable,true);
                cur->setFlag(QGraphicsItem::ItemIsSelectable,true);
                cur->setPen(*pen);
                shapes.append(cur);
                showShape(shapes);

                isDrawing=false;
            }
        }
}

void EditWidget::mousePressMove(QGraphicsSceneMouseEvent *event)
{
   this->views()[0]->setCursor(Qt::ClosedHandCursor);
   if(this->items().count()>0)
   {
       QGraphicsItem* curSelectItem = this->itemAt(event->scenePos(), this->items()[0]->transform());
                if(curSelectItem != NULL)
                {
                    this->clearSelection();
                    origPoint=event->scenePos();
                    curSelectItem->setSelected(true);
                }
   }
}

void EditWidget::mousePressEdit(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton && this->isEditing)
    {
        this->views()[0]->setCursor(Qt::SizeAllCursor);
        QPointF pressPoint=event->scenePos();
        for(int i=0;i<points.count();++i)
        {
            if(abs(pressPoint.x()-points[i].x())<5 && abs(pressPoint.y()-points[i].y())<5)
            {
                QGraphicsEllipseItem *newPointCircle=
                        new QGraphicsEllipseItem(points[i].x()-5,points[i].y()-5,10,10);
                newPointCircle->setBrush(Qt::red);
                QGraphicsItem *origPointCricle=
                        this->itemAt(points[i],this->items()[0]->transform());
                //tempShapes.removeOne(origPointCricle);
                tempShapes.append(newPointCircle);
                showShape(tempShapes);
                editPointIndex=i;
            }
        }
    }
    if(event->button()==Qt::LeftButton && editPointIndex==-1 && this->items().count()>0)     //如果之前没有开始编辑，则单击开始编辑
    {
        this->views()[0]->setCursor(Qt::PointingHandCursor);
        points.clear();
        curEditItem = this->itemAt(event->scenePos(), this->items()[0]->transform());
        tempShapes=shapes;
        QGraphicsPathItem*curEditPathItem=dynamic_cast<QGraphicsPathItem*>(curEditItem);
        if(curEditPathItem!=NULL)
        {
            for(int i=0;i<curEditPathItem->path().elementCount();++i)
            {
                QPointF curPoint(curEditPathItem->path().elementAt(i).x,
                                 curEditPathItem->path().elementAt(i).y);
                points.append(curPoint);
                QGraphicsEllipseItem *pointCircle=new
                        QGraphicsEllipseItem(curPoint.x()-3,curPoint.y()-3,6,6);
                pointCircle->setBrush(Qt::red);
                tempShapes.append(pointCircle);
                showShape(tempShapes);
            }
        }
        QGraphicsPolygonItem*curEditPolygonItem=dynamic_cast<QGraphicsPolygonItem*>(curEditItem);
        if(curEditPolygonItem!=NULL)
        {
            for(int i=0;i< curEditPolygonItem->polygon().count();++i)
            {
                points.append(curEditPolygonItem->polygon().data()[i]);
                QGraphicsEllipseItem *pointCircle=new
                        QGraphicsEllipseItem(points[i].x()-3,points[i].y()-3,6,6);
                pointCircle->setBrush(Qt::red);
                tempShapes.append(pointCircle);
                showShape(tempShapes);
            }
        }
        isEditing=true;

    }
    else if(event->button()==Qt::RightButton && this->isEditing)
    {
        this->views()[0]->setCursor(Qt::PointingHandCursor);
        showShape(shapes);
        isEditing=false;
        points.clear();
        tempShapes.clear();
        curEditItem=NULL;
        editPointIndex=-1;
    }
}

void EditWidget::mouseMoveDraw(QGraphicsSceneMouseEvent *event)
{
    this->views()[0]->setCursor(Qt::CrossCursor);
    if(isDrawing)
    {
        setPen();
        if(curShape==this->PointType)
        {
        }
        else if(curShape==this->PolylineType)
        {
            QVector<QPointF> tempPoints=points;
            tempPoints.append(event->scenePos());
            QPainterPath *path=new QPainterPath(tempPoints[0]);
            for(int i=1;i<tempPoints.count();++i)
            {
                path->lineTo(tempPoints[i]);
            }
            QGraphicsPathItem *cur=new QGraphicsPathItem();
            cur->setPath(*path);
            cur->setPen(*pen);
            tempShapes=shapes;
            tempShapes.append(cur);
            showShape(tempShapes);
        }
        else if(curShape==this->PolygonType)
        {
            QVector<QPointF> tempPoints=points;
            tempPoints.append(event->scenePos());
            QGraphicsPolygonItem *cur=new QGraphicsPolygonItem();
            QPolygonF *curPolygon=new QPolygonF(tempPoints);
            cur->setPolygon(*curPolygon);
            cur->setPen(*pen);
            cur->setBrush(brushColor);
            tempShapes=shapes;
            tempShapes.append(cur);
            showShape(tempShapes);
        }
    }
}

void EditWidget::mouseMoveMove(QGraphicsSceneMouseEvent *event)
{
    if(( event->buttons()&Qt::LeftButton)&& isDrawing==false && this->selectedItems().count()>0)
    {
      movePoint=event->scenePos();
      qreal dx=movePoint.x()-origPoint.x();
      qreal dy=movePoint.y()-origPoint.y();
      for(int i=0;i<this->selectedItems().count();++i)
      {
          this->selectedItems()[i]->moveBy(dx,dy);
      }
      origPoint=movePoint;
    }

}

void EditWidget::mouseMoveEdit(QGraphicsSceneMouseEvent *event)
{
    if((event->buttons()&Qt::LeftButton)&& editPointIndex!=-1)
    {
        movePoint=event->scenePos();
        points[editPointIndex]=event->scenePos();
            QGraphicsPathItem*curEditPathItem=dynamic_cast<QGraphicsPathItem*>(curEditItem);
            if(curEditPathItem!=NULL)
            {
                QPainterPath *path=new QPainterPath(points[0]);
                for(int i=1;i<points.count();++i)
                {
                    path->lineTo(points[i]);
                }
                curEditPathItem->setPath(*path);

            }
            QGraphicsPolygonItem*curEditPolygonItem=dynamic_cast<QGraphicsPolygonItem*>(curEditItem);
            if(curEditPolygonItem!=NULL)
            {
                QPolygonF *curPolygon=new QPolygonF(points);
                curEditPolygonItem->setPolygon(*curPolygon);
            }
            tempShapes=shapes;
            for(int i=0;i<points.count();++i)
            {

                if(i==editPointIndex)
                {
                    QGraphicsEllipseItem *pointCircle=new
                            QGraphicsEllipseItem(points[i].x()-5,points[i].y()-5,10,10);
                    pointCircle->setBrush(Qt::red);
                    tempShapes.append(pointCircle);
                }
                else
                {
                    QGraphicsEllipseItem *pointCircle=new
                            QGraphicsEllipseItem(points[i].x()-3,points[i].y()-3,6,6);
                    pointCircle->setBrush(Qt::red);
                    tempShapes.append(pointCircle);
                }
            }
            showShape(tempShapes);
    }
}

void EditWidget::mouseReleaseDraw(QGraphicsSceneMouseEvent *event)
{

}

void EditWidget::mouseReleaseMove(QGraphicsSceneMouseEvent *event)
{
    this->views()[0]->setCursor(Qt::OpenHandCursor);
    this->clearSelection();
}

void EditWidget::mouseReleaseEdit(QGraphicsSceneMouseEvent *event)
{
    this->views()[0]->setCursor(Qt::PointingHandCursor);
    tempShapes=shapes;
    for(int i=0;i<points.count();++i)
    {
        QGraphicsEllipseItem *pointCircle=new
                QGraphicsEllipseItem(points[i].x()-3,points[i].y()-3,6,6);
        pointCircle->setBrush(Qt::red);
        tempShapes.append(pointCircle);
    }
    editPointIndex=-1;
    showShape(tempShapes);
}

void EditWidget::mouseDoubleClickEdit(QGraphicsSceneMouseEvent *event)
{

}

void EditWidget::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    if(curState==DrawType)
    {
        mousePressDraw(event);
    }
    else if(curState==MoveType)
    {
        mousePressMove(event);
    }
    else if(curState==EditType)
    {
        mousePressEdit(event);
    }
}


void EditWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    if(curState==DrawType)
    {
        mouseMoveDraw(event);
    }
    else if(curState==MoveType)
    {
        mouseMoveMove(event);
    }
    else if(curState==EditType)
    {
        mouseMoveEdit(event);
    }
}


void EditWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

    if(curState==DrawType)
    {
        mouseReleaseDraw(event);
    }
    else if(curState==MoveType)
    {
        mouseReleaseMove(event);
    }
    else if(curState==EditType)
    {
        mouseReleaseEdit(event);
    }
}

void EditWidget::showShape(QVector<QGraphicsItem*> shapes)
{
    while(this->items().count()>0)
    {
        this->removeItem(this->items()[0]);
    }
    for(int i=0;i<shapes.count();++i)
    {
        this->addItem(shapes[i]);
    }
}


void EditWidget::setPen()
{
    pen->setStyle(penStyle);
    pen->setWidth(penWidth);
    pen->setColor(penColor);
}

void EditWidget::setPenStyle(Qt::PenStyle style)
{
    penStyle=style;
}

void EditWidget::setPenColor(QColor color)
{
    penColor=color;
}

void EditWidget::setPenWidth(int width)
{
    penWidth=width;
}

void EditWidget::setBrushColor(QColor color)
{
    brushColor=color;
}
void EditWidget::setShape(ShapeType shape)
{
    curShape=shape;
}
void EditWidget::setState(viewState state)
{
    curState=state;
}


EditWidget::~EditWidget()
{

}


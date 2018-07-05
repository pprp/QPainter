#include "qgraphicspolylineitem.h"
#include "math.h"

QGraphicsPolylineItem::QGraphicsPolylineItem()
{
    setAcceptDrops(true);
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}
QGraphicsPolylineItem::QGraphicsPolylineItem(QVector<QPointF> ps)
{
    this->points=ps;
    setAcceptDrops(true);
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}

int QGraphicsPolylineItem::nearByPointI(QPointF point)
{
    for(int i=0;i<points.count();++i)
    {
        double distance=(point.x()-points[i].x())*(point.x()-points[i].x())
                +(point.y()-points[i].y())*(point.y()-points[i].y());
        if(distance<25)
            return i;
    }
    return -1;
}

void QGraphicsPolylineItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
//    QPointF pos1=event->scenePos();
//    QPointF lt=this->scenePos()+QPointF(m_rect.x(),m_rect.y());
//    QPointF lb=this->scenePos()+QPointF(m_rect.x(),m_rect.y()+m_rect.height());
//    QPointF rt=this->scenePos()+QPointF(m_rect.x()+m_rect.width(),m_rect.y());
//    QPointF rb=this->scenePos()+QPointF(m_rect.x()+m_rect.width(),m_rect.y()+m_rect.height());
//    if((pos1.x()<=lt.x()+2&&pos1.y()<=lt.y()+2)
//     ||(pos1.x()>=rb.x()-2&&pos1.y()>=rb.y()-2)){
//        m_cursor->setShape(Qt::SizeFDiagCursor);
//        if(pos1.x()<=lt.x()+2)direction=8;
//        else direction=4;
//    }else if((pos1.x()<=lb.x()+2&&pos1.y()>=lb.y()-2)
//             ||(pos1.x()>=rt.x()-2&&pos1.y()<=rt.y()+2)){
//        m_cursor->setShape(Qt::SizeBDiagCursor);
//        if(pos1.x()<=lb.x()+2)direction=6;
//        else direction=2;
//    }else if((pos1.x()<=lt.x()+2||pos1.x()>=rt.x()-2)
//             &&(pos1.y()<=lb.y()&&pos1.y()>=lt.y())){
//        m_cursor->setShape(Qt::SizeHorCursor);
//        if(pos1.x()<=lt.x()+2)direction=7;
//        else direction=3;
//    }else if((pos1.y()<=lt.y()+2||pos1.y()>=lb.y()-2)
//             &&(pos1.x()>=lt.x()&&pos1.x()<=rt.x())){
//        m_cursor->setShape(Qt::SizeVerCursor);
//        if(pos1.y()<=lt.y()+2)direction=1;
//        else direction=5;
//    }else{
//        cScale=false;
//        m_cursor->setShape(Qt::ArrowCursor);
//    }
//    this->setCursor(*m_cursor);
//    update();
//    QGraphicsItem::hoverEnterEvent(event);
}

void QGraphicsPolylineItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
//    QPointF pos1=event->scenePos();
//    QPointF lt=this->scenePos()+QPointF(m_rect.x(),m_rect.y());
//    QPointF lb=this->scenePos()+QPointF(m_rect.x(),m_rect.y()+m_rect.height());
//    QPointF rt=this->scenePos()+QPointF(m_rect.x()+m_rect.width(),m_rect.y());
//    QPointF rb=this->scenePos()+QPointF(m_rect.x()+m_rect.width(),m_rect.y()+m_rect.height());
//    if((pos1.x()<=lt.x()+2&&pos1.y()<=lt.y()+2)
//     ||(pos1.x()>=rb.x()-2&&pos1.y()>=rb.y()-2)){
//        m_cursor->setShape(Qt::SizeFDiagCursor);
//        if(pos1.x()<=lt.x()+2)direction=8;
//        else direction=4;
//    }else if((pos1.x()<=lb.x()+2&&pos1.y()>=lb.y()-2)
//             ||(pos1.x()>=rt.x()-2&&pos1.y()<=rt.y()+2)){
//        m_cursor->setShape(Qt::SizeBDiagCursor);
//        if(pos1.x()<=lb.x()+2)direction=6;
//        else direction=2;
//    }else if((pos1.x()<=lt.x()+2||pos1.x()>=rt.x()-2)
//             &&(pos1.y()<=lb.y()&&pos1.y()>=lt.y())){
//        m_cursor->setShape(Qt::SizeHorCursor);
//        if(pos1.x()<=lt.x()+2)direction=7;
//        else direction=3;
//    }else if((pos1.y()<=lt.y()+2||pos1.y()>=lb.y()-2)
//             &&(pos1.x()>=lt.x()&&pos1.x()<=rt.x())){
//        m_cursor->setShape(Qt::SizeVerCursor);
//        if(pos1.y()<=lt.y()+2)direction=1;
//        else direction=5;
//    }else{
//        cScale=false;
//        m_cursor->setShape(Qt::ArrowCursor);
//    }
//    this->setCursor(*m_cursor);
//    update();
//    QGraphicsItem::hoverMoveEvent(event);
}

void QGraphicsPolylineItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
//    m_cursor->setShape(Qt::ArrowCursor);
//    cScale=false;
//    this->setCursor(*m_cursor);
//    update();
//    QGraphicsItem::hoverLeaveEvent(event);
}

void QGraphicsPolylineItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
//    if(event->button()==Qt::LeftButton){
//        start=event->scenePos();
//        cScale=true;
//    }
//    update();
//    QGraphicsItem::mousePressEvent(event);
}

void QGraphicsPolylineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QPointF movePoint=this->scenePos();

//    update();
//    QGraphicsItem::mouseMoveEvent(event);
}

void QGraphicsPolylineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
//    cScale=false;
//    update();
//    QGraphicsItem::mouseReleaseEvent(event);
}






QGraphicsPolylineItem::~QGraphicsPolylineItem()
{

}


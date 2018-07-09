#ifndef VEBEZIERCURVE_H
#define VEBEZIERCURVE_H
#include <QGraphicsPathItem>
#include <QPainterPath>

class VEBezierCurve:public QGraphicsPathItem
{
public:
    VEBezierCurve();
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void paintEvent(QGraphicsSceneEvent * event);
    QPainterPath createBezierCurve();
    QRect createControlPointBoundingRect(int index);//这是控制的外边框
    QPointF translatePoint(const QPointF &point) const;//这是平移点的函数
private:
    QPainterPath bezierCurve;
    QList<QPointF*> breakPoints;// 贝塞尔曲线
};

#endif // VEBEZIERCURVE_H

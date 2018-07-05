#ifndef EDITWIDGET_H
#define EDITWIDGET_H

#include <QGraphicsScene>
#include <QLabel>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPen>


class EditWidget: public QGraphicsScene
{
public:
    EditWidget(QWidget *parent=0);
    bool isDrawing;      //false表示结束画图，true表示正在画图
    bool isEditing;
    int editPointIndex;
    QPointF movePoint;
    QPointF origPoint;
    QPen *pen;

    QGraphicsItem* curEditItem;

    enum ShapeType   //枚举变量,要绘制的图形的类型
    {
        NoneType,
        PointType,
        LineType,
        RectangleType,
        EllispeType,
        PolylineType,
        PolygonType
    };

    enum viewState
    {
        NoneState,
        DrawType,
        MoveType,
        EditType,
        RotateType
    };

    void setPenStyle(Qt::PenStyle style); //设置画笔风格
    void setPenWidth(int width);   //设置画笔宽度
    void setPenColor(QColor color);   //设置画笔颜色
    void setBrushColor(QColor color);   //设置填充颜色
    void setShape(ShapeType shape);  //设置要绘制的图形
    void setState(viewState state);
    void showShape(QVector<QGraphicsItem*> shapes);
    void setPen();
    QVector<QPointF> points;    //绘制的图形对应的坐标
    QVector<QGraphicsItem*> shapes;
    QVector<QGraphicsItem*> tempShapes;


    ~EditWidget();

protected:
//    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);   //鼠标移动事件
    void mousePressEvent(QGraphicsSceneMouseEvent *);   //鼠标按下事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);   //鼠标释放事件
private:
    QColor penColor;    //画笔颜色
    QColor brushColor;   //填充颜色
    int penWidth;     //画笔宽度
    Qt::PenStyle penStyle;    //画笔风格

    ShapeType curShape;
    viewState curState;

    void mousePressDraw(QGraphicsSceneMouseEvent *);
    void mousePressMove(QGraphicsSceneMouseEvent *);
    void mousePressEdit(QGraphicsSceneMouseEvent *);

    void mouseMoveDraw(QGraphicsSceneMouseEvent *);
    void mouseMoveMove(QGraphicsSceneMouseEvent *);
    void mouseMoveEdit(QGraphicsSceneMouseEvent *);

    void mouseReleaseDraw(QGraphicsSceneMouseEvent *);
    void mouseReleaseMove(QGraphicsSceneMouseEvent *);
    void mouseReleaseEdit(QGraphicsSceneMouseEvent *);

    void mouseDoubleClickEdit(QGraphicsSceneMouseEvent *);
};

#endif // EDITWIDGET_H

#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QPen>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QLabel>
#include <QGraphicsSceneEvent>


class PaintArea : public QGraphicsScene
{

public:
    PaintArea();//构造函数
    void setImageSize(int width, int height);
    void setImageColor(QColor color);
    bool isModified()const{return modified;}
    bool saveImage(const QString & fileName,const char*fileFormat);
    bool openImage(const QString & fileName);//打开图片
    QSize getImageSize();
    //编辑菜单中的功能
    void zoomIn();
    void zoomOut();
    void zoom_1();
    void doRotate();
    void doShear();
    void doClear();
    //进行绘图工具函数声明
    void setPenStyle(Qt::PenStyle);
    void setPenWidth(int width);
    void setPenColor(QColor color);
    void setBrushColor(QColor color);
    enum ShapeType
    {
        None,Line,Rectangle,Ellipse,Polygon
    };
    void setShape(ShapeType shape);//选择要绘制的图形

protected:
    //事件处理函数
    void paintEvent(QPaintEvent *);
    //添加鼠标事件
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paint(QImage &theImage);
private:
    QImage image;
    QRgb backColor;
    QPoint lastPoint,endPoint;
    bool modified;//是否被更改标志
    //编辑菜单中需要的属性
    qreal scale;//所放量
    int angle;//角度
    qreal shear;//拉伸量

    //绘图工具栏所需要的属性
    QColor penColor;
    QColor brushColor;
    int penWidth;
    Qt::PenStyle penStyle;//画笔风格

    ShapeType curShape;
    //添加临时绘图区，解决多个图形的不停画图的问题
    QImage tempImage;
    bool isDrawing;//是否再绘制特殊图形，初始化为 false;
    //记录点坐标
    QVector<QPointF> points;    //绘制的图形对应的坐标
    QVector<QGraphicsItem*> shapes;
    QVector<QGraphicsItem*> tempShapes;


    //鼠标事件处理
    void mousePressDraw(QGraphicsSceneMouseEvent *);
    void mousePressMove(QGraphicsSceneMouseEvent *);
    void mousePressEdit(QGraphicsSceneMouseEvent *);

    void mouseMoveDraw(QGraphicsSceneMouseEvent *);
    void mouseMoveMove(QGraphicsSceneMouseEvent *);
    void mouseMoveEdit(QGraphicsSceneMouseEvent *);

    void mouseReleaseDraw(QGraphicsSceneMouseEvent *);
    void mouseReleaseMove(QGraphicsSceneMouseEvent *);
    void mouseReleaseEdit(QGraphicsSceneMouseEvent *);
    void setPen();
};

#endif // PAINTAREA_H

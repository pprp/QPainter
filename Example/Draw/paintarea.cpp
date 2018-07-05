#include "paintarea.h"
#include <QPainter>
#include <QMessageBox>
#include <math.h>
#include <QPainterPath>


//构造函数
PaintArea::PaintArea(QWidget *parent):QGraphicsScene(parent)
{
    modified = false;
    pen=new QPen();
    //编辑属性的初始化
    scale=1;
    angle=0;
    shear=0;

    image=QImage(400,300,QImage::Format_RGB32);
    backColor=qRgb(255,255,255);
    image.fill(backColor);
    //菜单工具栏的初始化
    penColor=QColor(Qt::black);
    brushColor=QColor(Qt::black);
    penWidth=1;
    penStyle=Qt::SolidLine;
    curShape=None;
    //临时绘图区初始化
    isDrawing=false;
}

void PaintArea::mousePressDraw(QGraphicsSceneMouseEvent *event)
{
    setPen();
    if(curShape == this->Line)
    {
        if(event->button() == Qt::LeftButton && this->isDrawing)
        {
            points.append(event->scenePos());
            QPainterPath * path=new QPainterPath(points[0]);
            for(int i = 1 ; i < points.count(); i++){
                path->lineTo(points[i]);
            }
            QGraphicsPathItem *cur=new QGraphicsPathItem();
            cur->setPath(*path);
            tempShapes=shapes;
            tempShapes.append(cur);
            showShape(tempShapes);
        }
        else if(event->button() == Qt::LeftButton && !this->isDrawing)
        {
            points.clear();
            points.append(event->scenePos());
            isDrawing=true;
        }
        else if(event->button() == Qt::RightButton && this->isDrawing)
        {
            QPainterPath * path = new QPainterPath(points[0]);
            for(int i=1;i<points.count();++i)
            {
                path->lineTo(points[i]);
            }
            QGraphicsPathItem *cur=new QGraphicsPathItem();
            cur->setPath(*path);
            //QGraphicsPolylineItem *cur=new QGraphicsPolylineItem(points);
            cur->setFlag(QGraphicsItem::ItemIsMovable,true);
            cur->setFlag(QGraphicsItem::ItemIsSelectable,true);
            cur->setPen(*pen);
            shapes.append(cur);
            showShape(shapes);
            isDrawing=false;
        }
    }
    else if(curShape == this->Rectangle)
    {

    }
    else if(curShape == this->Ellipse)
    {

    }
    else if(curShape == this->Polygon)
    {

    }

}

//事件处理函数
//创建了一个QPainter对象
//对旋转的操作，先复制再传回
void PaintArea::paintEvent(QPaintEvent *){

    QPainter painter(this);

    //重写事件函数painter.drawImage(0,0,image);
    painter.scale(scale,scale);

    //解决图形重影问题
    if(isDrawing)//如果正在绘制图形,显示临时绘图区内容
    {
        painter.drawImage(0,0,tempImage);
    }
    else//否则进行正常的显示
    {

        if(angle)
        {
            QImage copyImage=image;
            QPainter pp(&copyImage);
            //找到画布的中心位置
            QPointF center(copyImage.width()/2.0,copyImage.height()/2.0);
            pp.translate(center);
            pp.rotate(angle);
            pp.translate(-center);
            pp.drawImage(0,0,image);
            image=copyImage;//复制图片
            angle=0;//重设角度
        }
        if(shear)
        {
            QImage copyImage=image;
            QPainter pp(&copyImage);
            pp.shear(shear,shear);
            pp.drawImage(0,0,image);
            image=copyImage;
            shear=0;
        }
        painter.drawImage(0,0,image);
    }
}

//鼠标事件处理函数
//为了解决多个图形重影的问题
void PaintArea::mousePressEvent(QMouseEvent *event)
{
    /*
    if(event->button() == Qt::LeftButton)//左键下按
        lastPoint=event->pos();//当前为起始
    */
    if(event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        isDrawing = true;
    }
}
void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)//左键按下并拖动
    {
        endPoint=event->pos();
        //解决图形重影问题
        if(curShape==None)//如果不是特殊图形,而是普通的直线，那么可以直接进行绘制
        {
            isDrawing=false;
            paint(image);
        }
        else
        {
            tempImage = image;//复制一份
            paint(tempImage);
        }
    }
}
void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)//左键释放
    {
        endPoint=event->pos();
        isDrawing=false;//解决图形重影问题
        paint(image);
    }
}
void PaintArea::paint(QImage &theImage)
{
    /*新增画图方法
    QPainter pp(&theImage);
    pp.drawLine(lastPoint,endPoint);
    lastPoint = endPoint;
    modified = true;
    update();//进行更新界面显示
    */
    QPainter pp(&theImage);
    pp.setRenderHint(QPainter::Antialiasing,true);
    pp.setRenderHint(QPainter::SmoothPixmapTransform,true);
    setPen();

    QBrush brush = QBrush(brushColor);
    pp.setPen(pen);
    pp.setBrush(brush);

    int x, y, w, h;
    x=lastPoint.x()/scale;
    y=lastPoint.y()/scale;
    w=endPoint.x()/scale-x;
    h=endPoint.y()/scale-y;

    switch(curShape)
    {
    case None: //不绘制特殊图形
    {
        pp.drawLine(lastPoint/scale,endPoint/scale); //由起始坐标和终止坐标绘制直线
        lastPoint = endPoint; //让终止坐标变为起始坐标
        break;
    }
    case Line: //绘制直线
    {
        pp.drawLine(lastPoint/scale,endPoint/scale);
        break;
    }
    case Rectangle: //绘制矩形
    {
        pp.drawRect(x,y,w,h);
        break;
    }
    case Ellipse: //绘制椭圆
    {
        pp.drawEllipse(x,y,w,h);
        break;
    }
    }
    update(); //进行更新界面显示，可引起窗口重绘事件，重绘窗口
    modified = true;
}

void PaintArea::setPen()
{
    pen.setColor(penColor);
    pen.setStyle(penStyle);
    pen.setWidth(penWidth);
}

void PaintArea::setImageSize(int width, int height)
{
    QImage newImage(width,height,QImage::Format_RGB32);
    image=newImage;
    update();
}

void PaintArea::setImageColor(QColor color)
{
    backColor = color.rgb();//将QColor转化为QRgb类型对象
    image.fill(backColor);
    update();
}

bool PaintArea::saveImage(const QString & fileName,const char*fileFormat)
{
    QImage visibleImage = image;
    if(visibleImage.save(fileName,fileFormat))
    {
        modified = false;
        return true;
    }
    else
        return false;
}

bool PaintArea::openImage(const QString &fileName)
{
    QImage loadedImage;
    if(!loadedImage.load(fileName)) //是否可以加载
        return false;
    QSize newSize = loadedImage.size();
    setImageSize(newSize.width(),newSize.height());
    image=loadedImage;
    modified = false;
    update();
    return true;
}

//解决放大的时候出现的问题
QSize PaintArea::getImageSize()
{
    return image.size()*scale;
}

//编辑栏中的操作
void PaintArea::zoomIn()
{
    scale*=1.2;
    update();
}
void PaintArea::zoomOut()
{
    scale /= 1.2;
    update();
}
void PaintArea::zoom_1()
{
    scale = 1;
    update();
}

void PaintArea::doRotate()
{
    angle += 90;
    update();
}
void PaintArea::doShear()
{
    shear = 0.2;
    update();
}
void PaintArea::doClear()
{
    image.fill(backColor);
    update();
}

//菜单工具栏中提供的功能
void PaintArea::setPenStyle(Qt::PenStyle style)
{
    penStyle=style;
}
void PaintArea::setPenWidth(int width)
{
    penWidth=width;
}
void PaintArea::setPenColor(QColor color)
{
    penColor=color;
}
void PaintArea::setBrushColor(QColor color)
{
    brushColor=color;
}
void PaintArea::setShape(ShapeType shape)
{
    curShape = shape;
}





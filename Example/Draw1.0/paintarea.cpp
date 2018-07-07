#include "paintarea.h"
#include <QPainter>

//构造函数
PaintArea::PaintArea()
{
    modified = false;
    //编辑属性的初始化
    scale=1;
    angle=0;
    shear=0;

    image=QImage(1000,800,QImage::Format_RGB32);

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

//事件处理函数
//创建了一个QPainter对象
//对旋转的操作，先复制再传回
void PaintArea::paintEvent(QPaintEvent *){
    /*QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);

    //重写事件函数painter.drawImage(0,0,image);
    painter.scale(scale,scale);
    if(angle)
    {
        QPointF center(image.width()/2.0,image.height()/2.0);
        painter.translate(center);
        painter.rotate(angle);
        painter.translate(-center);
    }
    if(shear)
    {
        painter.shear(shear,shear);
    }
    painter.drawImage(0,0,image);
    */
    QPainter painter(this);

    //重写事件函数painter.drawImage(0,0,image);
    painter.scale(scale,scale);
   // painter.setRenderHint(QPainter::Antialiasing);
   // painter.setRenderHints(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::Antialiasing);


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
          //  pp.setRenderHints(QPainter::Antialiasing);
          //  pp.setRenderHints(QPainter::Antialiasing);
            pp.setRenderHints(QPainter::SmoothPixmapTransform);
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
            pp.setRenderHint(QPainter::SmoothPixmapTransform);
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
    QPen pen=QPen();
    pen.setColor(penColor);
    pen.setStyle(penStyle);
    pen.setWidth(penWidth);

    QBrush brush = QBrush(brushColor);
    pp.setPen(pen);
    pp.setBrush(brush);

    double x, y, w, h;
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
        QPainterPath *path = new QPainterPath;
        path->lineTo(100,200);
        pp.drawPath(*path);
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

void PaintArea::setImageSize(double width, double height)
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
void PaintArea::setPenWidth(double width)
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





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

    image=QImage(400,300,QImage::Format_RGB32);
    backColor=qRgb(255,255,255);
    image.fill(backColor);
    //菜单工具栏的初始化
    penColor=QColor(Qt::black);
    brushColor=QColor(Qt::black);
    penWidth=1;
    penStyle=Qt::SolidLine;
    curShape=None;
}

//事件处理函数
//创建了一个QPainter对象
void PaintArea::paintEvent(QPaintEvent *){
    QPainter painter(this);
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
}

//鼠标事件处理函数
void PaintArea::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)//左键下按
        lastPoint=event->pos()*scale;//当前为起始
}
void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)//左键瞎按并拖动
    {
        endPoint=event->pos()*scale;
        paint(image); //??绘制图形
    }
}
void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)//左键释放
    {
        endPoint=event->pos()*scale;
        paint(image);
    }
}
void PaintArea::paint(QImage &theImage)
{
    QPainter pp(&theImage);
    pp.drawLine(lastPoint,endPoint);
    lastPoint = endPoint;
    modified = true;
    update();//进行更新界面显示
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


QSize PaintArea::getImageSize()
{
    return image.size();
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







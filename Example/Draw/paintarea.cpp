#include "paintarea.h"
#include <QPainter>


//构造函数
PaintArea::PaintArea()
{
    modified = false;
    image=QImage(400,300,QImage::Format_RGB32);
    backColor=qRgb(255,255,255);
    image.fill(backColor);
}

//事件处理函数
//创建了一个QPainter对象
void PaintArea::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawImage(0,0,image);
}

//鼠标事件处理函数
void PaintArea::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)//左键下按
        lastPoint=event->pos();//当前为起始
}
void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)//左键瞎按并拖动
    {
        endPoint=event->pos();
        paint(image); //??绘制图形
    }
}
void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)//左键释放
    {
        endPoint=event->pos();
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












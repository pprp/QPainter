#include "renderarea.h"
#include<QPainter>



RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{

    //构造函数，完成了对变量的初始化，以及图片的加载等
    shape = Polygon;
    antiliased = false;
    transformed = false;

    pixmap.load(":/images/qt-logo.png");


    setBackgroundRole(QPalette::Base);

    setAutoFillBackground(true);

}

RenderArea::~RenderArea()
{

}


QSize RenderArea::minimumSizeHint()const{

    //设置最小窗口大小
    return QSize(100 , 100);
}


QSize RenderArea::sizeHint()const{
    //设置窗口的大小

    return QSize(400 , 200);
}


void RenderArea::setShape(Shape shape){
    //设置图形
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    //设置画笔
    this->pen = pen;
    update();
}


void RenderArea::setBrush(const QBrush &brush)
{
    //设置画刷
    this->brush = brush;
    update();



}


void RenderArea::setAnntialiased(bool antialiased)
{

    this->antiliased = antialiased;
    update();

}


void RenderArea::setTransformed(bool transformed)
{

    this->transformed = transformed;
    update();
}


void RenderArea::paintEvent(QPaintEvent *event){
    //完成窗口的绘制



    static const QPoint points[4] = {
        QPoint(10,80),
        QPoint(20,10),
        QPoint(80,30),
        QPoint(90,70)

    };



    QRect rect(10 , 20 , 80 , 60);

    QPainterPath path;

    path.moveTo(20 ,80);
    path.lineTo(20 , 30);
    path.cubicTo(80 , 0,50,50 , 80,80);



    int startAngle = 20 * 16;
    int arcLength = 120*16;


    //定义Painter，用来画画

    //完成Painter的定义和初始化
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if(antiliased){
        painter.setRenderHint(QPainter::Antialiasing , true);

    }

    for(int x = 0 ; x < width() ; x += 100){

        for(int y = 0 ; y < height() ; y+= 100){
            painter.save();
            painter.translate(x , y);


            if(transformed){
                painter.translate(50,50);
                painter.rotate(60.0);
                painter.scale(0.6 , 0.9);
                painter.translate(-50 , -50);

            }



            //完成图形的绘制
            switch (shape) {


           // enum Shape{
             //   Line , Points , Ploygon , Rect , RoundedRect , Ellipse ,
             //   Arc , Chord , Path , Text , Pixmap
            //};
            case Line:
                    painter.drawLine(rect.bottomLeft() , rect.topRight());
                break;

            case Points:
                    painter.drawPoints(points , 4);
                break;
            case Polygon:
                    painter.drawPolygon(points , 4);
                break;
            case Rect:
                painter.drawRect(rect);

                break;
            case RoundedRect:
                painter.drawRoundedRect(rect , 25 , 25 , Qt::RelativeSize);

                break;
            case Ellipse:
                painter.drawEllipse(rect);

                break;
            case Arc:
                painter.drawArc(rect , startAngle , arcLength);

                break;
            case Chord:
                painter.drawChord(rect , startAngle , arcLength);
                break;

            case Path:
                painter.drawPath(path);

                break;
            case Pie:
                painter.drawPie(rect, startAngle , arcLength);
                break;
            case Text:
                painter.drawText(rect , Qt::AlignCenter , tr("Qt by "
                                                             "\nDigia"));

                break;
            case Pixmap:
                painter.drawPixmap(10 ,10 , pixmap);
                break;

            }
            painter.restore();
        }
    }


//完成画笔的恢复
    painter.setRenderHint(QPainter::Antialiasing , false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0,0, width() - 1 ,  height() - 1));



}

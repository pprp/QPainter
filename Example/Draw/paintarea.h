#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QMOuseEvent>
#include <QPoint>

class PaintArea : public QWidget
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


};

#endif // PAINTAREA_H

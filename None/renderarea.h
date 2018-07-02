#ifndef RENDERAREA_H
#define RENDERAREA_H

#include<QBrush>
#include<QPen>
#include<QPixmap>
#include<QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    ~RenderArea();

    enum Shape{
        Line , Points , Polygon , Rect , RoundedRect , Ellipse ,
        Arc , Chord , Path , Text,Pie , Pixmap
    };


    QSize minimumSizeHint()const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;


signals:

public slots:
    void setShape(Shape shape);
    void setPen(const QPen& pen);
    void setBrush(const QBrush& brush);
    void setAnntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent * event)Q_DECL_OVERRIDE ;



private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antiliased;
    bool transformed;
    QPixmap pixmap;

};

#endif // RENDERAREA_H

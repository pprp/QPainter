#ifndef TEXTITEM_H
#define TEXTITEM_H
#include <QCursor>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneEvent>
#include <QObject>
#include <QFont>
#include "textdialog.h"

class TextItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit TextItem(QObject *parent = 0);
    virtual ~TextItem();
    QRectF boundingRect(void) const;
    //不进行重写
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QGraphicsTextItem *text_item;
    QGraphicsRectItem *rect_item;
    bool text_interaction; //可编辑状态

    QString tFont;//字体： 黑体等
    QFont myFont; //字体
    int tWeight;//字宽
    qreal myWidth; //文本框的宽度
    qreal adjust; //距离调整
    QRectF text_rect; //文本的边框

    void reset_text_rect(void); //重新设置文本边框的函数

    TextDialog td; //出现窗口，设置字体



protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent (QGraphicsSceneHoverEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);

signals:

public slots:

};

#endif // TEXTITEM_H

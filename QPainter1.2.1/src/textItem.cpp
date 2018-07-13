#include "TextItem.h"
#include <QFont>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QTextBlockFormat>

TextItem::TextItem(QObject *parent) :
    QObject(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);

    QTextBlockFormat format;
    format.setAlignment(Qt::AlignCenter);
    //出现窗口，获得字体
    if(td.exec() == QDialog::Accepted)
    {
        tFont = td.getFont();
        tWeight = td.getWidth();
        myWidth = td.getKWidth();//文本框宽度
    }
    //尺寸
    adjust = 20;
    myFont.setFamily(tFont);
    myFont.setPointSize(tWeight);
    //文本项
    text_item = new QGraphicsTextItem(this);
    text_item->setTextWidth(myWidth);
    text_item->setFont(myFont);
    text_item->setTextInteractionFlags(Qt::TextEditorInteraction);
    text_interaction = true;
    text_item->setPlainText(trUtf8("请在这里编辑^_^"));
    text_rect = text_item->boundingRect();
    text_item->setPos(520, 520);
    //矩形框
    rect_item = new QGraphicsRectItem(this);
    QPen *pen = new QPen(Qt::lightGray);
    rect_item->setPen(*pen);
    rect_item->setRect(500, 500,
                       text_rect.width() + 3*adjust,
                       text_rect.height() + 3*adjust);


};

TextItem::~TextItem()
{
    delete text_item;
    delete rect_item;
}

QRectF TextItem::boundingRect(void) const //初始化长方形的位置，大小
{
    rect_item->setRect(500, 500,
                       text_rect.width() + 2*adjust,
                       text_rect.height() + 2*adjust);
    return rect_item->boundingRect();
}
void TextItem::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
}

void TextItem::keyPressEvent(QKeyEvent *event)
{
    QGraphicsItem::keyPressEvent(event);
}
void TextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //setFocus();
    QGraphicsItem::mousePressEvent(event);
}
void TextItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
}
void TextItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::ArrowCursor);
}
void TextItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void TextItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu; //显示文本和图标，但是不执行操作
    QAction *edit_action = menu.addAction(trUtf8("编辑开关"));
    QAction *selected_action = menu.exec(event->screenPos());
    if(selected_action == edit_action){
        if(text_interaction){
            text_item->setTextInteractionFlags(Qt::NoTextInteraction);
            text_interaction = false;
            reset_text_rect();
            update(); //每次编辑完都更新
        }else{
            text_item->setTextInteractionFlags(Qt::TextEditorInteraction);//可编辑
            text_interaction = true;
        }
    }
}

void TextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    QGraphicsItem::mouseDoubleClickEvent(event);
}
void TextItem::reset_text_rect(void)
{
    text_rect = text_item->boundingRect();
}



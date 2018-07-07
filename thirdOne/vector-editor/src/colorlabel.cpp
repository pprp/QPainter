#include "colorlabel.h"
#include <QMouseEvent>

ColorLabel::ColorLabel(QWidget *parent)
    : QLabel(parent)
{

}

ColorLabel::~ColorLabel()
{

}

void ColorLabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    emit clicked();
}

void ColorLabel::setColor(const QColor &color)
{
    setStyleSheet("QLabel { background-color: " + color.name() + ";}");
}

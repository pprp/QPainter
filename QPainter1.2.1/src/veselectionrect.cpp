#include "veselectionrect.h"
#include <QPen>
#include <QBrush>

VESelectionRect::VESelectionRect(QObject *parent) :
    QObject(parent)
{
    setBrush(QBrush(QColor(158,182,255,96)));
    setPen(QPen(QColor(158,182,255,200),1));
}

VESelectionRect::~VESelectionRect()
{
}

int VESelectionRect::type() const
{
    return Type;
}

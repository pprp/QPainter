/**
 * Copyright (C) 2017 VIPainter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/
#include "vimageshape.h"
#include "cmath"
#include <QPainter>
#include <QDebug>
#include <QRect>
#include <vtype.h>
#include <QTransform>

VImageShape::~VImageShape()
{
}

void VImageShape::draw(QPainter *painter, const VTransform &transform)
{
    painter->setTransform(transform,true);
    painter->drawImage(-image.width()/2,-image.height()/2,image);
}

const QImage& VImageShape::getImage()const
{
    return image;
}

QJsonObject VImageShape::toJsonObject()const
{
    qDebug()<<"ImageShape can't save as JsonObject";
    return QJsonObject();
}

VShape* VImageShape::clone() const
{
    return new VImageShape(*this);
}

bool VImageShape::contains(VPoint point)
{
    return image.rect().contains(point.x+image.width()/2,point.y+image.height()/2);
}

QString VImageShape::type()const
{
    return VType::Image;
}

VSize VImageShape::getSize()
{
    return image.size();
}

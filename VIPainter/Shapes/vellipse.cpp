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
#include "vellipse.h"
#include "cmath"
#include <QPainter>
#include <QDebug>
#include <vtype.h>
#include <QTransform>

VEllipse::~VEllipse()
{
}

VEllipse::VEllipse(const QJsonObject &jsonObject):VShape(jsonObject)
{
}


const VEllipse& VEllipse::operator=(const QJsonObject &jsonObject)
{
    VShape::operator=(jsonObject);
    return *this;
}

const VEllipse& VEllipse::operator=(const VEllipse &shape)
{
    if(this==&shape)return *this;
    VShape::operator=(shape);
    return *this;
}

void VEllipse::draw(QPainter *painter, const VTransform &transform)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    VPoint loc=transform.map(VPoint(0,0));
    double width=transform.map(VPoint(1,0))-loc;
    double height=transform.map(VPoint(0,1))-loc;
    QTransform ptrans=QTransform::fromScale(1/width,1/height)*transform*painter->worldTransform();
    painter->setTransform(ptrans);
    painter->drawEllipse(-width/2.0,-height/2.0,width,height);
}

QJsonObject VEllipse::toJsonObject()const
{
    QJsonObject jsonObject(VShape::toJsonObject());
    return jsonObject;
}

VShape* VEllipse::clone() const
{
    return new VEllipse(*this);
}

bool VEllipse::contains(VPoint point)
{
    return point.x*point.x*4+point.y*point.y*4 <= 1;
}

QString VEllipse::type()const
{
    return VType::Ellipse;
}

VSize VEllipse::getSize()
{
    return VSize(1,1);
}

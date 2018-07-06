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
#include "vsize.h"
#include <cmath>
#include <cfloat>

VSize::VSize():width(0), height(0){}

VSize::VSize(double x,double y):width(x), height(y){}

const VSize& VSize::operator=(const VSize &size){
    this->width = size.width;
    this->height = size.height;
    return *this;
}

VSize::VSize(QSizeF size)
{
    this->width = size.width();
    this->height = size.height();
}

VSize::VSize(QSize size)
{
    this->width = size.width();
    this->height = size.height();
}

QSizeF VSize::toQSizeF()const
{
    return QSizeF(width,height);
}

const VSize& VSize::operator=(const QJsonObject &jsonObject)
{
    this->width=jsonObject.value("width").toDouble();
    this->height=jsonObject.value("height").toDouble();
    return *this;
}


VSize VSize::operator *(const VMagnification &magnification)const
{
    return VSize(width*magnification.horizontal,height*magnification.vertical);
}

VSize VSize::operator /(const VMagnification &magnification)const
{
    VSize size;
    if(std::abs(magnification.horizontal)<1e-9)
    {
        if(std::abs(width)<1e-9)size.width=0;
        else size.width=DBL_MAX;
    }
    else size.width=width/magnification.horizontal;
    if(std::abs(magnification.vertical)<1e-9)
    {
        if(std::abs(width)<1e-9)size.height=0;
        else size.height=DBL_MAX;
    }
    else size.height=height/magnification.horizontal;
    return size;
}

VMagnification VSize::operator /(const VSize &size)const
{
    VMagnification mag;
    if(std::abs(size.width)<1e-9)
    {
        if(std::abs(width)<1e-9)mag.horizontal=0;
        else mag.horizontal=DBL_MAX;
    }
    else mag.horizontal=width/size.width;
    if(std::abs(size.height)<1e-9)
    {
        if(std::abs(height)<1e-9)mag.vertical=0;
        else mag.vertical=DBL_MAX;
    }
    else mag.vertical=height/size.height;
    return mag;
}

VSize VSize::operator +(const VSize & Right)const
{
    return VSize(width+Right.width, height+Right.height);
}

VSize VSize::operator -(const VSize & Right)const
{
    return VSize(width-Right.width, height-Right.height);
}

VSize::operator QJsonValue()const
{
    QJsonObject jsonObject;
    jsonObject.insert("width",width);
    jsonObject.insert("height",height);
    return jsonObject;
}

QJsonObject VSize::toJsonObject()const
{
    QJsonObject jsonObject;
    jsonObject.insert("width",width);
    jsonObject.insert("height",height);
    return jsonObject;
}

VSize::VSize(const QJsonObject &jsonObject)
{
    *this=jsonObject;
}

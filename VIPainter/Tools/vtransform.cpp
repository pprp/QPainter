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
#include "vtransform.h"
#include <QPoint>
#include <cmath>

VTransform::VTransform():QTransform()
{
}

VTransform::VTransform(const VTransform &trans):QTransform(trans)
{

}

VTransform::VTransform(QJsonArray arr)
{
    if(arr.size()==6)arr.append(0.0);
    if(arr.size()==7)arr.append(0.0);
    if(arr.size()==8)arr.append(1.0);
    if(arr.size()==9)
    {
        setMatrix(
                    arr.at(0).toDouble(),
                    arr.at(1).toDouble(),
                    arr.at(2).toDouble(),
                    arr.at(3).toDouble(),
                    arr.at(4).toDouble(),
                    arr.at(5).toDouble(),
                    arr.at(6).toDouble(),
                    arr.at(7).toDouble(),
                    arr.at(8).toDouble()
                    );
    }
}

VTransform::VTransform(const QTransform &trans):QTransform(trans)
{

}

QJsonArray VTransform::toJsonArray()const
{
    QJsonArray arr;
    arr.append(this->m11());
    arr.append(this->m12());
    arr.append(this->m13());
    arr.append(this->m21());
    arr.append(this->m22());
    arr.append(this->m23());
    arr.append(this->m31());
    arr.append(this->m32());
    arr.append(this->m33());
    return arr;
}

VPoint VTransform::map(const VPoint &point)const
{
    return QTransform::map(point.toQPointF());
}

VTransform VTransform::inverted()const
{
    return QTransform::inverted();
}

void VTransform::scale(const VMagnification &mag)
{
    QTransform::scale(mag.horizontal,mag.vertical);
}

VSize operator*(const VSize &size,const VTransform &transform)
{
    VPoint point(transform.map(VPoint(size.width,size.height)));
    return VSize(std::abs(point.x),std::abs(point.y));
}

VPoint operator*(const VPoint &point,const VTransform &transform)
{
    return transform.map(point);
}

void VTransform::translate(const VPoint &point)
{
    QTransform::translate(point.x,point.y);
}

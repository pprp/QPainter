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
#ifndef VPOINT_H
#define VPOINT_H

#include "vsize.h"
#include <QPointF>
#include <QJsonObject>
#include <vmagnification.h>

class VPoint{   
public:
    double x;
    double y;
    VPoint();
    VPoint(double x,double y);
    VPoint(const QJsonObject &jsonObject);
    VPoint(const QPoint &point);
    VPoint(const QPointF &pointf);
    QPointF toQPointF() const;

    const VPoint& operator=(const VPoint &point);
    const VPoint& operator=(const QJsonObject &jsonObject);

    operator QJsonValue()const;
    QJsonObject toJsonObject()const;
    VPoint operator*(const VMagnification &magnification)const;
    VPoint operator/(const VMagnification &magnification)const;
    double operator-(const VPoint &point)const;
    VPoint operator-()const;
    VPoint operator+(const VSize &size)const;
    VPoint operator+(const VPoint &size)const;
    VPoint operator-(const VSize &size)const;
    bool operator!=(const VPoint &point)const;

    VPoint rotate(const VPoint & center, double a);
    VPoint floor();
    VPoint centralTransformation();//中心变换
};

#endif //#ifndef VPOINT_H

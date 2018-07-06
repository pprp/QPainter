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
#ifndef VPOLYLINE_H
#define VPOLYLINE_H

#include "vpointgroupshape.h"
#include "QVector"
#include "vpoint.h"

class VPolyline:public VPointGroupShape
{
public:
    VPolyline();
    VPolyline(const VPolyline &polyline);
    VPolyline(const QJsonObject &jsonObject);
    VPolyline(QVector<VPoint> vec);
    QJsonObject toJsonObject()const;
    const VPolyline& operator=(const VPolyline &polyline);
    const VPolyline& operator=(const QJsonObject &jsonObject);
    bool contains(VPoint point) override;
    QString type()const;
    //QImage toImage() override;
    void draw(QPainter *painter,const VTransform &transform)override;
    VShape* clone()const override;
};

#endif // VPOLYLINE_H

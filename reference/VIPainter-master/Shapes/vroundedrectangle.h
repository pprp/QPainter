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
#ifndef VROUNDEDRECTANGLE_H
#define VROUNDEDRECTANGLE_H

#include "vpolygon.h"
#include "QVector"
#include "vpoint.h"
#include "vtext.h"

class VRoundedRectangle : public VPolygon
{
public:
    VRoundedRectangle();
    VRoundedRectangle(const VRoundedRectangle &roundedRectangle);
    VRoundedRectangle(const QJsonObject &jsonObject);
    VRoundedRectangle(QVector<VPoint> vec);
    QJsonObject toJsonObject()const;
    const VRoundedRectangle& operator=(const VRoundedRectangle &roundedRectangle);
    const VRoundedRectangle& operator=(const QJsonObject &jsonObject);
    bool contains(VPoint point) override;
    QString type()const;
    //QImage toImage() override;
    void draw(QPainter *painter,const VTransform &transform)override;
    VShape* clone()const override;
};

#endif // VROUNDEDRECTANGLE_H

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
#ifndef VELLIPSE_H
#define VELLIPSE_H

#include "vshape.h"
#include "vpoint.h"
#include "vsize.h"

class VEllipse : public VShape{
public:
    VEllipse(const QString &name="", const VPoint &location=VPoint(0,0), const VMagnification &magnification=VMagnification(1,1), double angle=0);
    VEllipse(const QJsonObject &jsonObject);
    const VEllipse& operator=(const VEllipse &shape);
    const VEllipse& operator=(const QJsonObject &jsonObject);
    QJsonObject toJsonObject()const override;

    void draw(QPainter *painter,const VTransform & transform)override;
    VSize getSize()override;
    virtual bool contains(VPoint point)override;
    virtual QString type()const override;
    VShape* clone()const override;
    ~VEllipse()override;
};

#endif // VELLIPSE_H

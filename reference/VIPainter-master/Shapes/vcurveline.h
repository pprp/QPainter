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
#ifndef VCURVELINE_H
#define VCURVELINE_H

#include "vpointgroupshape.h"
#include "vpoint.h"
#include <QVector>

class VCurveline : public VPointGroupShape
{
public:
    VCurveline();
    VCurveline(const VCurveline &shape);
    VCurveline(const QJsonObject &jsonObject);
    ~VCurveline()override;
    const VCurveline& operator=(const VCurveline &shape);
    const VCurveline& operator=(const QJsonObject &jsonObject);

    void addPoint(VPoint point);

    QJsonObject toJsonObject()const override;
    void draw(QPainter *painter,const VTransform &transform)override;
    QString type()const override;
    bool contains(VPoint point)override;
    VShape* clone()const override;
};

#endif // VCURVELINE_H

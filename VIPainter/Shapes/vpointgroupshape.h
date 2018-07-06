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
#ifndef VPOINTGROUP_H
#define VPOINTGROUP_H

#include "vshape.h"
#include "QVector"
#include "vpoint.h"
#include <QJsonArray>

class VPointGroupShape:public VShape
{
protected:
    QVector<VPoint> points;//折线的各个端点
    VPoint cr1,cr2;
public:
    VPointGroupShape();
    VPointGroupShape(const VPointGroupShape &polyline);
    VPointGroupShape(const QJsonObject &jsonObject);
    VPointGroupShape(QVector<VPoint> vec);

    QJsonObject toJsonObject()const override;

    virtual void movePoint(int i, VPoint point);//move the ith point to (x,y)
    virtual void erasePoint(int i);
    virtual void addPoint(const VPoint &p);
    virtual QVector<VPoint> getPointList() const;

    const VPointGroupShape& operator=(const VPointGroupShape &polyline);
    const VPointGroupShape& operator=(const QJsonObject &jsonObject);

    virtual void getCircumscribedRectangle();//获得外接矩形的右下点

    VSize getSize()override;
//    void setSize(const VSize &size) override;

    int atPoints(const VPoint & point, double scale)const;
    int atPoints(const VPoint & point, VMagnification mag)const;
    bool changePoint(int i, const VPoint & point);
    void drawCR(QPainter *painter, const VTransform &trans, double scale, bool isExtended);

};

#endif // VPOINTGROUP_H

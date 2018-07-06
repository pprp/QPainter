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
#ifndef VGROUPSHAPE_H
#define VGROUPSHAPE_H

#include "vshape.h"
#include "vpoint.h"
#include <QJsonArray>
#include <QList>
#include <QVector>
#include <QPair>

class VGroupShape : public VShape
{
private:
    QVector<VShape*> shapes;
    void caculateSubShapeAndSize();
    VSize cr;
    bool force=false;

public:

    static QVector<VShape *> breakUp (VGroupShape * group);

    VGroupShape();
    VGroupShape(const VGroupShape &shape);
    VGroupShape(const QJsonObject &jsonObject);
    VGroupShape(const QJsonArray &jsonArray);
    QJsonArray toJsonArray()const;
    ~VGroupShape()override;
    QJsonObject toJsonObject()const;

    // insert shape into group,  return its index
    int insertShape(VShape * other);
    int insertShape(VShape * other, int pos);
    // insert shapeVector into group,  return the last shape's index
    int insertShape(const QVector<VShape *> & other);
    int insertShape(const QVector<VShape *> & other, int pos);

    bool eraseShape(int i);
    bool eraseShape(VShape * other);
    VShape *takeShape(VShape * other);
    VShape *takeShape(QVector<VShape*>::iterator it);
    bool moveShape(int i, VPoint location);
    bool contains(VPoint point);
    void clear(bool force=true);
    VShape * atShape(const VPoint &point);

    const QVector<VShape *>& getShapes();
    QVector<VShape *> takeShapes();

    int getVectorSize()const;
    VSize getSize()override;

    bool isforce();
    void setForce(bool force);

    void draw(QPainter *painter,const VTransform &transform)override;
    QString type()const override;

    const VGroupShape& operator=(const VGroupShape &shape);
    const VGroupShape& operator=(const QJsonObject &jsonObject);
    const VGroupShape& operator=(const QJsonArray &jsonArray);
    virtual void getCircumscribedRectangle(bool force=false);//获得外接矩形的左上点、右下点
    VShape* clone()const override;

    void setPen(QPen pen)override;
    void setBrush(QBrush brush)override;
    void setPen(QColor pen)override;
    void setBrush(QColor brush)override;
};

#endif // VGROUPSHAPE_H


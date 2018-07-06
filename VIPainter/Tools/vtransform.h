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
#ifndef VTRANSFORM_H
#define VTRANSFORM_H

#include <QTransform>
#include <QJsonArray>
#include "vpoint.h"
#include "vsize.h"
#include "vmagnification.h"

class VTransform : public QTransform
{
public:
    VTransform();
    VTransform(QJsonArray arr);
    VTransform(const VTransform &trans);
    VTransform(const QTransform& trans);
    QJsonArray toJsonArray()const;
    VPoint map(const VPoint &point) const;
    VTransform inverted()const;
    void scale(const VMagnification &mag);
    void translate(const VPoint &point);
    friend VSize operator *(const VSize &size,const VTransform &transform);
    friend VPoint operator *(const VPoint &size,const VTransform &transform);
};

#endif // VTRANSFORM_H

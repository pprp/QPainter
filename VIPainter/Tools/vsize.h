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
#ifndef VSIZE_H
#define VSIZE_H

#include <QJsonObject>
#include <QJsonValue>
#include <QSizeF>
#include <vmagnification.h>

class VSize
{
public:
    VSize();
    double width;
    double height;
    VSize(double width,double height);
    VSize(QSizeF size);
    VSize(QSize size);
    VSize(const QJsonObject &jsonObject);

    QSizeF toQSizeF()const;
    const VSize& operator=(const VSize &size);
    const VSize& operator=(const QJsonObject &jsonObject);
    VSize operator +(const VSize & Right)const;
    VSize operator -(const VSize & Right)const;
    VSize operator *(const VMagnification &magnification)const;
    VSize operator /(const VMagnification &magnification)const;
    VMagnification operator /(const VSize &size)const;
    operator QJsonValue()const;
    QJsonObject toJsonObject()const;
};

#endif // VSIZE_H

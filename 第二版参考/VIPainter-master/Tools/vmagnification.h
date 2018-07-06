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
#ifndef VMAGNIFICATION_H
#define VMAGNIFICATION_H

#include <QJsonObject>

class VMagnification
{
public:
    VMagnification();
    double horizontal=1;
    double vertical=1;
    VMagnification(double magnification);
    VMagnification(double horizontal,double vertical );
    VMagnification(const QJsonObject &jsonObject);

    const VMagnification& operator=(const VMagnification &magnification);
    const VMagnification& operator=(const QJsonObject &jsonObject);
    VMagnification operator *(const VMagnification &magnification)const;
    VMagnification operator /(const VMagnification &magnification)const;
    VMagnification operator +(const VMagnification &magnification)const;
    VMagnification operator -(const VMagnification &magnification)const;
    VMagnification rotate(double a) const;
    operator QJsonValue()const;
    QJsonObject toJsonObject()const;
};

#endif // VMAGNIFICATION_H

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
#ifndef VVECTOR_H
#define VVECTOR_H

#include "vpoint.h"
#include "vmagnification.h"
#include "vsize.h"

class VVector
{
public:

    double x;
    double y;
    VVector(double _x = 0,double _y = 0);
    VVector(const VPoint & from, const VPoint & to);
    VVector(const VPoint & p);

    static double includedAngle(const VVector & from, const VVector & to);
    static double rotationAngle(const VVector & from, const VVector & to);

    const VVector& operator=(const VVector &Right);
    VVector operator +(const VVector & Right)const;
    VPoint operator +(const VPoint & Right)const;
    VVector operator -(const VVector & Right)const;
    VVector operator -()const;
    double operator *(const VVector & Right)const;
    VVector operator *(double Right)const;
    VVector operator *(const VMagnification & Right)const;
    VVector operator /(double Right)const;
    VVector operator /(const VMagnification & Right)const;
    bool operator ==(const VVector & Right)const;

    VVector rotate(double angle)const;

    double norm()const;
};

#endif // VVECTOR_H

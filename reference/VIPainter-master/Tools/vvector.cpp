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
#include "vvector.h"
#include "vshape.h"
#include <cmath>
#include <cfloat>

VVector::VVector(double _x,double _y):x(_x), y(_y)
{
}

bool VVector::operator ==(const VVector & Right)const
{
    return std::abs(x-Right.x)<=1e-9&&std::abs(y-Right.y)<=1e-9;
}

VVector::VVector(const VPoint & from, const VPoint & to)
{
    x=to.x - from.x;
    y=to.y - from.y;
}

VVector::VVector(const VPoint & p):x(p.x),y(p.y)
{
}

const VVector& VVector::operator=(const VVector &Right)
{
    x = Right.x;
    y = Right.y;
    return *this;
}

VVector VVector::operator +(const VVector & Right)const
{
    return VVector(x+Right.x, y+Right.y);
}

VVector VVector::operator -(const VVector & Right)const
{
    return VVector(x-Right.x, y-Right.y);
}

double VVector::operator *(const VVector & Right)const
{
    return x*Right.x + y*Right.y;
}

VVector VVector::operator *(double Right)const
{
    return VVector(Right*x, Right*y);
}

double VVector::norm()const
{
    return sqrt(x*x+ y*y);
}

VPoint VVector::operator +(const VPoint & Right)const
{
    return VPoint(Right.x+x, Right.y+y);
}

VVector VVector::operator /(double Right)const
{
    return (*this)/VMagnification(Right,Right);
}

VVector VVector::operator /(const VMagnification & Right)const
{
    VVector vector;
    if(std::abs(Right.horizontal)<1e-9)
    {
        if(std::abs(x)<1e-9)vector.x=0;
        else vector.x=DBL_MAX;
    }
    else vector.x=x/Right.horizontal;
    if(std::abs(Right.vertical)<1e-9)
    {
        if(std::abs(y)<1e-9)vector.y=0;
        else vector.y=DBL_MAX;
    }
    else vector.y=y/Right.horizontal;
    return vector;
}

VVector VVector::operator *(const VMagnification & Right)const
{
    return VVector(x*Right.horizontal, y*Right.vertical);
}

VVector VVector::operator -()const
{
    return (*this)*(-1);
}

VVector VVector::rotate(double angle)const
{
    return VVector(VPoint(0,0), ((*this)+VPoint(0,0)).rotate(VPoint(0,0),angle));
}

double VVector::includedAngle(const VVector & from, const VVector & to)
{
    double normFrom = from.norm(), normTo = to.norm();
    if(normFrom * normTo < 1e-9) return 0;
    return acos(from*to/(normFrom*normTo)) * 180.0 / VShape::PI;
}

double VVector::rotationAngle(const VVector & from, const VVector & to)
{
    VVector reference = from.rotate(90);
    double angle = includedAngle(from, to);
    if(to*reference >= 0)
    {
        return angle;
    }else
    {
        return 360-angle;
    }
}

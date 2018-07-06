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
#include "vmagnification.h"
#include <cmath>
#include "vshape.h"

VMagnification::VMagnification():horizontal(1), vertical (1){}

VMagnification::VMagnification(double magnification):horizontal(magnification), vertical(magnification){}

VMagnification::VMagnification(double x,double y):horizontal(x), vertical (y){}

const VMagnification& VMagnification::operator=(const VMagnification &magnification){
    this->horizontal = magnification.horizontal;
    this->vertical  = magnification.vertical ;
    return *this;
}

const VMagnification& VMagnification::operator=(const QJsonObject &jsonObject)
{
    if(jsonObject.isEmpty())
    {
        this->horizontal=this->vertical=1;
    }
    else
    {
        this->horizontal=jsonObject.value("horizontal").toDouble();
        this->vertical =jsonObject.value("vertical").toDouble();
    }
    return *this;
}
VMagnification::operator QJsonValue()const
{
    QJsonObject jsonObject;
    jsonObject.insert("horizontal",horizontal);
    jsonObject.insert("vertical",vertical );
    return jsonObject;
}


VMagnification VMagnification::operator *(const VMagnification &magnification) const
{
    return VMagnification(horizontal*magnification.horizontal,vertical*magnification.vertical);
}

VMagnification VMagnification::operator /(const VMagnification &magnification)const
{
    return VMagnification(horizontal/magnification.horizontal,vertical/magnification.vertical);
}

VMagnification VMagnification::operator +(const VMagnification &magnification)const
{
    return VMagnification(horizontal+magnification.horizontal,vertical+magnification.vertical);
}

VMagnification VMagnification::operator -(const VMagnification &magnification)const
{
    return VMagnification(horizontal-magnification.horizontal,vertical-magnification.vertical);
}

QJsonObject VMagnification::toJsonObject()const
{
    QJsonObject jsonObject;
    jsonObject.insert("horizontal",horizontal);
    jsonObject.insert("vertical",vertical );
    return jsonObject;
}

VMagnification::VMagnification(const QJsonObject &jsonObject)
{
    *this=jsonObject;
}

VMagnification VMagnification::rotate(double a)const
{
    VMagnification mag(*this);
    a = a / 180 * VShape::PI;
    mag.horizontal = horizontal*cos(a) - vertical*sin(a);
    mag.vertical = horizontal*sin(a) + vertical*cos(a);
    return mag;
}

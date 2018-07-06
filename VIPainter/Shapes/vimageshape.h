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
#ifndef VIMAGESHAPE_H
#define VIMAGESHAPE_H
#include "vshape.h"
#include <QImage>

class VImageShape:public VShape
{
private:
    QImage image;
public:
    template<class IMAGE>VImageShape(IMAGE &&image);
    QJsonObject toJsonObject()const override;

    void draw(QPainter *painter,const VTransform & transform)override;
    VSize getSize()override;
    virtual bool contains(VPoint point)override;
    virtual QString type()const override;
    VShape* clone()const override;
    const QImage& getImage()const;
    ~VImageShape()override;
};


template<class IMAGE>
VImageShape::VImageShape(IMAGE &&image):image(std::forward<IMAGE>(image))
{
}

#endif // VIMAGESHAPE_H

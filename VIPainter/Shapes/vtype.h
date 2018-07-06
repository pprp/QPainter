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
#ifndef VTYPE_H
#define VTYPE_H

#include <QString>
#include <QJsonValue>

class VType
{
public:
    static QString Polygon;
    static QString Polyline;
    static QString Ellipse;
    static QString Curveline;
    static QString Group;
    static QString BezierCurve;
    static QString Text;
    static QString RoundedRectangle;
    static QString Image;
    VType()=delete;
};

#endif // VTYPE_H

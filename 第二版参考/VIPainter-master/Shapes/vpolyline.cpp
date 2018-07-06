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
#include "vpolyline.h"
#include "vtype.h"
#include "vvector.h"
#include <QPainter>
#include <QJsonArray>
#include <QDebug>
#include <cmath>

VPolyline::VPolyline()
{
}

VPolyline::VPolyline(const VPolyline &polyline):VPointGroupShape(polyline){
}

VPolyline::VPolyline(const QJsonObject &jsonObject):VPointGroupShape(jsonObject){
}

VPolyline::VPolyline(QVector<VPoint> vec):VPointGroupShape(vec){
}

const VPolyline& VPolyline::operator=(const VPolyline &polyline){
    if(this==&polyline)return *this;
    VPointGroupShape::operator=(polyline);
    return *this;
}

const VPolyline& VPolyline::operator=(const QJsonObject &jsonObject){
    VPointGroupShape::operator=(jsonObject);
    return *this;
}

void VPolyline::draw(QPainter *painter, const VTransform &transform)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    QPolygonF qpf;
    if(points.size() == 1)
    {
        VPoint p = transform.map(VPoint(0,0));
        painter->drawPoint(p.x, p.y);
        return;
    }
    for(auto &i : this->points){
        qpf << (i*transform).toQPointF();
    }
    painter->drawPolyline(qpf);
}
//QImage VPolyline::toImage(){
//    int width = cr2.y-cr1.y, height = cr2.x-cr1.x;
//    QImage image(width, height, QImage::Format_ARGB32);
//    QPainter painter(&image);
//    QPolygonF qpf;
//    for(auto &i : vertex){
//        qpf << i.toQPointF();
//    }
//    painter.drawPolyline(qpf);

//    return image;
//}

QString VPolyline::type() const{
    return VType::Polyline;
}

bool VPolyline::contains(VPoint point){
    double width = (pen.width()+2.0);
    double x = point.x;
    double y = point.y;
    VVector PiPi_1, Pi_1Pi, PiP, Pi_1P;
    for(int i = 1; i < points.size(); i++){
        double A = points[i].y-points[i-1].y;
        double B = points[i].x-points[i-1].x;

        PiPi_1 = VVector(points[i], points[i-1]);
        Pi_1Pi =PiPi_1 * (-1);
        PiP = VVector(points[i], point);
        Pi_1P = VVector(points[i-1], point);

        if(
                std::abs(B*(y-points[i-1].y)-A*(x-points[i-1].x))<=width*sqrt(A*A+B*B) &&
                PiPi_1 * PiP >= 0 &&
                Pi_1Pi * Pi_1P >= 0
           )
            return true;
    }
    return false;
//    if(x >= cr1.x && x <= cr2.x && y >= cr1.y && y <= cr2.y)
//        return true;
//    else return false;
}

VShape* VPolyline::clone() const
{
    return new VPolyline(*this);
}

//VPolyline* VPolyline::fromJsonObject(const QJsonObject &jsonObject)
//{
//    VPolyline *vPolyline=new VPolyline();
//    vPolyline->n = jsonObject.value("n").toInt();
//    vPolyline->vertex.clear();
//    QJsonArray jsonVertex = jsonObject.value("vertex").toArray();
//    for(const auto &i : jsonVertex){
//        vPolyline->vertex.push_back(VPoint::fromJsonObject(i.toObject()));
//    }
//    return vPolyline;
//}

QJsonObject VPolyline::toJsonObject()const
{
    QJsonObject jsonObject(VPointGroupShape::toJsonObject());
    return jsonObject;
}

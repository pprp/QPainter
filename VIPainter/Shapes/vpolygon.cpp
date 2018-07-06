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
#include "vpolygon.h"
#include "vpoint.h"
#include <QDebug>
#include <QPainter>
#include "vtype.h"

VPolygon::VPolygon():VPointGroupShape(){
}

VPolygon::~VPolygon(){
}

VPolygon::VPolygon(const VPolygon &shape):VPointGroupShape(shape){
}

VPolygon::VPolygon(const QJsonObject &jsonObject):VPointGroupShape(jsonObject){
}

bool VPolygon::contains(VPoint point)
{
//    Q_UNUSED(point);
//    return false;
    //TODO:
    qreal x=point.x,y=point.y;
        int left=0;
        int right=0;
        int j=points.size()-1;
        for(int i=0;i<points.size();i++){
            if((points[i].y<y&&points[j].y>=y)||(points[j].y<y&&points[i].y>=y)){
                if((y-points[i].y)*(points[i].x-points[j].x)/(points[i].y-points[j].y)+points[i].x<=x){
                    left++;
                }
                else right++;
            }
            j=i;
        }
        return left&right;
}

const VPolygon& VPolygon::operator=(const VPolygon &vpolygon){
    if(this==&vpolygon)return *this;
    VPointGroupShape::operator=(vpolygon);
    return *this;
}

QJsonObject VPolygon::toJsonObject()const
{
    QJsonObject obj=VPointGroupShape::toJsonObject();
    return obj;
}

const VPolygon& VPolygon::operator=(const QJsonObject &jsonObject){
    VPointGroupShape::operator=(jsonObject);
    return *this;
}

VShape* VPolygon::clone() const
{
    return new VPolygon(*this);
}

void VPolygon::draw(QPainter *painter, const VTransform &transform)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    QPolygonF qpf;
    for(auto &i : points){
        qpf << (i*transform).toQPointF();
    }
    painter->drawPolygon(qpf);
}

//QImage VPolygon::toImage(){
//    int width = cr2.y-cr1.y, height = cr2.x-cr1.x;
//    QImage image(width, height, QImage::Format_ARGB32);
//    QPainter painter(&image);
//    QPolygonF qpf;
//    for(auto &i : vertex){
//        qpf << i.toQPointF();
//    }
//    painter.drawPolygon(qpf);

//    return image;
//}

QString VPolygon::type() const{
    return VType::Polygon;
}

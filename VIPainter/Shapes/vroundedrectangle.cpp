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
#include "vroundedrectangle.h"
#include "vtype.h"
#include "vvector.h"
#include <QPainter>
#include <QJsonArray>
#include <QDebug>
#include <cmath>

VRoundedRectangle::VRoundedRectangle()
{
}

VRoundedRectangle::VRoundedRectangle(const VRoundedRectangle &roundedRectangle):VPolygon(roundedRectangle){
}

VRoundedRectangle::VRoundedRectangle(const QJsonObject &jsonObject):VPolygon(jsonObject){
    //qDebug()<<"ok gz"<<endl;
}

VRoundedRectangle::VRoundedRectangle(QVector<VPoint> vec){
    Q_UNUSED(vec);
}

const VRoundedRectangle& VRoundedRectangle::operator=(const VRoundedRectangle &roundedRectangle){
    if(this==&roundedRectangle)return *this;
    VPointGroupShape::operator=(roundedRectangle);
    return *this;
}

const VRoundedRectangle& VRoundedRectangle::operator=(const QJsonObject &jsonObject){
    VPointGroupShape::operator=(jsonObject);
    return *this;
}

void VRoundedRectangle::draw(QPainter *painter,const VTransform &transform)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->save();
    VPoint loc=transform.map(VPoint(0,0));
    VPoint p1 = points[1];
    VPoint p2 = points[3];
    double W = p2.x-p1.x;
    double H = p2.y-p1.y;
    double width=transform.map(VPoint(1,0))-loc;
    double height=transform.map(VPoint(0,1))-loc;
    QTransform ptrans=QTransform::fromScale(1/width,1/height)*transform*painter->worldTransform();
    painter->setTransform(ptrans);
    width*=W;
    height*=H;
    QRectF rec(-width/2, -height/2, width, height);
    painter->drawRoundRect(rec);
    painter->restore();
}

QString VRoundedRectangle::type() const{
    return VType::RoundedRectangle;
}

bool VRoundedRectangle::contains(VPoint point){
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

VShape* VRoundedRectangle::clone()const
{
    return new VRoundedRectangle(*this);
}

QJsonObject VRoundedRectangle::toJsonObject()const
{
    QJsonObject jsonObject(VPointGroupShape::toJsonObject());
    return jsonObject;
}

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
#include "vbeziercurve.h"
#include "vpoint.h"
#include <QDebug>
#include <QPainter>
#include <QPainterPath>
#include "vtype.h"

VBezierCurve::VBezierCurve():VPointGroupShape(){
}

VBezierCurve::~VBezierCurve(){
}

VBezierCurve::VBezierCurve(const VBezierCurve &shape):VPointGroupShape(shape){
}

VBezierCurve::VBezierCurve(const QJsonObject &jsonObject):VPointGroupShape(jsonObject){
}

bool VBezierCurve::contains(VPoint point)
{
    QPainterPath path;
    auto i=points.begin();
    VPoint p1=*i;
    path.moveTo(p1.toQPointF());
    for(++i;i!=points.end();++i)
    {
        p1=*i;
        if((++i)==points.end())
        {
            path.lineTo((p1).toQPointF());
            break;
        }
        else path.quadTo(p1.toQPointF(),i->toQPointF());
    }
    return path.contains(point.toQPointF());
}

const VBezierCurve& VBezierCurve::operator=(const VBezierCurve &vbezlerCurve){
    if(this==&vbezlerCurve)return *this;
    VPointGroupShape::operator=(vbezlerCurve);
    return *this;
}

const VBezierCurve& VBezierCurve::operator=(const QJsonObject &jsonObject){
    VPointGroupShape::operator=(jsonObject);
    return *this;
}

VShape* VBezierCurve::clone() const
{
    return new VBezierCurve(*this);
}

void VBezierCurve::draw(QPainter *painter,const VTransform &transform)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    QPainterPath path;
    auto i=points.begin();
    VPoint p1=*i;
    path.moveTo((p1*transform).toQPointF());
    for(++i;i!=points.end();++i)
    {
        p1=*i;
        if((++i)==points.end())
        {
            path.lineTo((p1*transform).toQPointF());
            break;
        }
        else path.quadTo((p1*transform).toQPointF(),((*i)*transform).toQPointF());
    }
    painter->drawPath(path);
}

//QImage VBezlerShape::toImage(){
//    int width = cr2.y-cr1.y, height = cr2.x-cr1.x;
//    QImage image(width, height, QImage::Format_ARGB32);
//    QPainter painter(&image);
//    QBezlerShapeF qpf;
//    for(auto &i : vertex){
//        qpf << i.toQPointF();
//    }
//    painter.drawBezlerShape(qpf);

//    return image;
//}

QString VBezierCurve::type() const{
    return VType::BezierCurve;
}

void VBezierCurve::drawCR(QPainter * painter, const VTransform &transform, double scale)
{
    VPointGroupShape::drawCR(painter,transform,scale);
    painter->save();
    QPen pen;
    //pen.setColor(Qt::gray);
    QColor color=this->pen.color();
    color.setAlpha(color.alpha()/2);
    pen.setColor(color);
    pen.setWidth(2);
    pen.setStyle(Qt::DashDotDotLine);
    painter->setPen(pen);
    for(int i=1; i<points.size()-1; i+=2)
    {
        painter->drawLine((points[i-1]*transform).toQPointF(), (points[i]*transform).toQPointF());
        if(i+1<points.size())
            painter->drawLine((points[i+1]*transform).toQPointF(), (points[i]*transform).toQPointF());
    }
    painter->restore();
}

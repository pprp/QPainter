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
#include "vshape.h"
#include "vpolygon.h"
#include "vpolyline.h"
#include "vellipse.h"
#include "vcurveline.h"
#include "vgroupshape.h"
#include "vbeziercurve.h"
#include "vtext.h"
#include "vtype.h"
#include "vpoint.h"
#include "vroundedrectangle.h"
#include <cmath>
#include <QDebug>
#include <QTransform>

const double VShape::PI=atan(1)*4.0;
const QPen VShape::defaultPen(QBrush(Qt::black),1);
const QBrush VShape::defaultBrush(Qt::white,Qt::NoBrush);

VShape::~VShape()
{
}

VShape::VShape(VShape *parent):parent(parent)
{
}

VShape* VShape::clone() const
{
    return fromJsonObject(toJsonObject());
}

VShape* VShape::fromJsonObject(const QJsonObject &jsonObject)
{
    QString type=jsonObject.value("type").toString();
    if(type==VType::Ellipse)return new VEllipse(jsonObject);
    else if(type==VType::Polyline)return new VPolyline(jsonObject);
    else if(type==VType::Polygon)return new VPolygon(jsonObject);
    else if(type==VType::Group)return new VGroupShape(jsonObject);
    else if(type==VType::Curveline)return new VCurveline(jsonObject);
    else if(type==VType::BezierCurve)return new VBezierCurve(jsonObject);
    else if(type==VType::Text)return new VText(jsonObject);
    else if(type==VType::RoundedRectangle)return new VRoundedRectangle(jsonObject);
    else return nullptr;
}

void VShape::setName(const QString &name)
{
    this->name=name;
}

const QString &VShape::getName()const
{
    return name;
}

VShape::operator QJsonValue()const
{
    return toJsonObject();
}


void VShape::setTransform(const VTransform& transform)
{
    this->transform=transform;
}

VTransform &VShape::getTransform()
{
    return transform;
}

void VShape::zoomin(const VMagnification &mag)
{
    VTransform trans;
    trans.scale(mag);
    transform = transform * trans;
}


VPoint VShape::getLocation()const
{
    return transform.map(VPoint(0,0));
}

VShape::VShape(const QJsonObject jsonObject)
    :name(jsonObject.value("name").toString())
    ,transform(jsonObject.value("transform").toArray())
{
    QJsonObject brush=jsonObject.value("brush").toObject();
    if(brush.isEmpty())this->brush=defaultBrush;
    else
    {
        this->brush.setColor(QColor(brush.value("color").toString()));
        this->brush.setStyle(Qt::BrushStyle(brush.value("style").toInt()));
    }
    QJsonObject pen=jsonObject.value("pen").toObject();
    if(pen.isEmpty())this->pen=defaultPen;
    else
    {
        this->pen.setColor(QColor(pen.value("color").toString()));
        this->pen.setWidth(pen.value("width").toInt());
        this->pen.setStyle(Qt::PenStyle(pen.value("style").toInt()));
        this->pen.setCapStyle(Qt::PenCapStyle(pen.value("capStyle").toInt()));
        this->pen.setJoinStyle(Qt::PenJoinStyle(pen.value("joinStyle").toInt()));
    }
}


const VShape& VShape::operator=(const QJsonObject &jsonObject)
{
    name=jsonObject.value("name").toString();
    transform=jsonObject.value("transform").toArray();
    QJsonObject brush=jsonObject.value("brush").toObject();
    if(brush.isEmpty())this->brush=defaultBrush;
    else
    {
        this->brush.setColor(QColor(brush.value("color").toString()));
        this->brush.setStyle(Qt::BrushStyle(brush.value("style").toInt()));
    }
    QJsonObject pen=jsonObject.value("pen").toObject();
    if(pen.isEmpty())this->pen=defaultPen;
    else
    {
        this->pen.setColor(QColor(pen.value("color").toString()));
        this->pen.setWidth(pen.value("width").toInt());
        this->pen.setStyle(Qt::PenStyle(pen.value("style").toInt()));
        this->pen.setCapStyle(Qt::PenCapStyle(pen.value("capStyle").toInt()));
        this->pen.setJoinStyle(Qt::PenJoinStyle(pen.value("joinStyle").toInt()));
    }
    return *this;
}

QJsonObject VShape::toJsonObject()const
{
    QJsonObject jsonObject;
    jsonObject.insert("type",this->type());
    jsonObject.insert("name",this->getName());
    jsonObject.insert("transform",this->transform.toJsonArray());
    if(brush!=defaultBrush){
        QJsonObject brush;
        brush.insert("color",this->brush.color().name(QColor::HexArgb));
        brush.insert("style",this->brush.style());
        jsonObject.insert("brush",brush);
    }
    if(pen!=defaultPen){
        QJsonObject pen;
        //(color,width,style, cap,join)
        pen.insert("color",this->pen.color().name(QColor::HexArgb));
        pen.insert("width",this->pen.width());
        pen.insert("style",this->pen.style());
        pen.insert("capStyle",this->pen.capStyle());
        pen.insert("joinStyle",this->pen.joinStyle());
        jsonObject.insert("pen",pen);
    }
    return jsonObject;
}

void VShape::setParent(VShape *parent)
{
    this->parent=parent;
}

VShape * VShape::getParent()const
{
    return parent;
}

QVector<VPoint> VShape::getRect()
{
    QVector<VPoint> points;
    double x=crDis/(transform.map(VPoint(1,0))-transform.map(VPoint(0,0)));
    double y=crDis/(transform.map(VPoint(0,1))-transform.map(VPoint(0,0)));
    VSize size = VSize(getSize().width/2+x, getSize().height/2+y);

    points.append(VPoint(size.width,size.height));
    points.append(VPoint(0, size.height));
    points.append(VPoint(-size.width,size.height));
    points.append(VPoint(-size.width,0));
    points.append(VPoint(-size.width,-size.height));
    points.append(VPoint(0,-size.height));
    points.append(VPoint(size.width,-size.height));
    points.append(VPoint(size.width,0));
    return points;
}

QVector<VPoint> VShape::getSizeRect()
{
    QVector<VPoint> points;
    VSize size=getSize()/VMagnification(2);
    points.append(VPoint(size.width,size.height));
    points.append(VPoint(-size.width,size.height));
    points.append(VPoint(-size.width,-size.height));
    points.append(VPoint(size.width,-size.height));
    return points;
}

VPoint VShape::transformPoint(const VPoint & point)const
{
    return transform.inverted().map(point);
}

VPoint VShape::reverseTransformPoint(const VPoint &point)const
{
    return transform.map(point);
}

void VShape::moveLoc(const VPoint & point)
{
    //qDebug() << point;
    transform.translate(point);
    VGroupShape *groupShape=dynamic_cast<VGroupShape*>(getParent());
    if(groupShape!=nullptr)groupShape->getCircumscribedRectangle();
}

void VShape::drawCR(QPainter * painter, const VTransform &trans, double scale)
{
    Q_UNUSED(scale);
    painter->save();
    QVector<VPoint> points = this->getRect();
    QList<QPointF> qpoints;
    QPolygonF qpf;
    for(auto &i : points){
        i=i*trans;
        QPointF qpoint =i.toQPointF();
        qpoints.append(qpoint);
        qpf << qpoint;
    }

    QBrush bru;
    QPen pen;
    pen.setWidth(1);
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
    painter->setBrush(bru);
    painter->drawPolygon(qpf);

    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    bru.setStyle(Qt::SolidPattern);
    bru.setColor(Qt::white);
    painter->setPen(pen);
    painter->setBrush(bru);
    for(auto &i : qpoints){
        painter->drawEllipse(i, crDis, crDis);
    }
    painter->restore();

}

int VShape::atCrPoints(const VPoint & point,double scale)
{
    QVector<VPoint> points = this->getRect();
    double x=crDis/(transform.map(VPoint(1,0))-transform.map(VPoint(0,0)));
    double y=crDis/(transform.map(VPoint(0,1))-transform.map(VPoint(0,0)));

    VSize siz(x/scale,y/scale);
    int cnt = 0;
    for(auto it: points)
    {
        VPoint pos = VPoint(point.x-it.x, point.y-it.y);
        //qDebug()<<point<<it<<scale;
        if(pow(pos.x * siz.height, 2)+pow(pos.y*siz.width, 2) <= pow(siz.width*siz.height, 2))
            return cnt;
        cnt++;
    }
    return -1;
}

int VShape::atCrPoints(const VPoint & point, VMagnification mag)
{
    VVector ve(mag.horizontal,mag.vertical);
    QVector<VPoint> points = this->getRect();
    int cnt = 0;
    for(auto it: points)
    {
        VPoint tmp=reverseTransformPoint(it);
        if(reverseTransformPoint(point)-VPoint(tmp.x-0.5,tmp.y-0.5)<=std::max(1.0,crDis/ve.norm()))
            return cnt;
        cnt++;
    }
    return -1;
}

void VShape::changeMag(int i, const VVector & vec, bool center)
{
    VMagnification mag;
    VPoint point=getRect().at(i);
    if(point.x==0)mag.horizontal=1;
    else if(center)mag.horizontal=vec.x/point.x;
    else mag.horizontal=vec.x/point.x/2+0.5;
    if(point.y==0)mag.vertical=1;
    else if(center)mag.vertical=vec.y/point.y;
    else mag.vertical=vec.y/point.y/2+0.5;
    VSize size=getSize();
    size=VSize((transform.map(VPoint(size.width,0))-transform.map(VPoint(0,0))),
                (transform.map(VPoint(0,size.height))-transform.map(VPoint(0,0))))*mag;
    if(std::abs(size.width)<1)mag.horizontal =size.width<0?-1:1;
    if(std::abs(size.height)<1)mag.vertical =size.height<0?-1:1;
    if(mag.horizontal==1&&mag.vertical==1)return;
    if(center)
    {
        this->transform.scale(mag);
    }
    else
    {
        VPoint old=transform.map(getRect().at((i+4)%8));
        this->transform.scale(mag);
        VPoint now=transform.map(getRect().at((i+4)%8));
        VPoint location=getLocation();
        moveLoc(this->transformPoint(VPoint(location.x+old.x-now.x,
                                            location.y+old.y-now.y)));
    }
}

void VShape::setPen(QPen pen)
{
    this->pen=pen;
}

void VShape::setBrush(QBrush brush)
{
    this->brush=brush;
}

QPen VShape::getPen()
{
    return pen;
}

QBrush VShape::getBrush()
{
    return brush;
}

void VShape::setPen(QColor pen)
{
    this->pen.setColor(pen);
}

void VShape::setBrush(QColor brush)
{
    this->brush=QBrush(brush);
}


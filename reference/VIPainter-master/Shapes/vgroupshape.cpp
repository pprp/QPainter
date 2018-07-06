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
#include <QPainter>
#include <QPointF>
#include <QJsonArray>
#include <QDebug>
#include <cmath>
#include <algorithm>
#include "vgroupshape.h"
#include "vtype.h"


VGroupShape::VGroupShape():cr(0,0)
{
}

VGroupShape::~VGroupShape()
{
    for(auto &it : this->shapes)
    {
        delete it;
    }
}

VGroupShape::VGroupShape(const VGroupShape &shape):VShape(shape),cr(0,0)
{
    for(auto & it : shape.shapes)
    {
        VShape *sp=it->clone();
        sp->setParent(this);
        this->shapes.push_back(sp);
    }
    force=shape.force;
    getCircumscribedRectangle(true);
}


VGroupShape::VGroupShape(const QJsonArray &jsonArray)
{
    VShape * tmp ;
    for(const auto &it: jsonArray)
    {
        tmp = VShape::fromJsonObject(it.toObject());
        if(tmp != nullptr)
        {
            shapes.push_back(tmp);
            tmp->setParent(this);
        }
    }
    force=false;
    getCircumscribedRectangle(true);
}

QJsonArray VGroupShape::toJsonArray()const
{
    QJsonArray jsonArray;
    for(const auto &it: shapes)
    {
        jsonArray.push_back(*it);
    }
    return jsonArray;
}

const VGroupShape & VGroupShape:: operator=(const VGroupShape &shape)
{
    setTransform(VTransform());
    if(this==&shape)return *this;
    VShape::operator =(shape);
    this->clear();
    for(auto & it : shape.shapes)
    {
        VShape *sp=it->clone();
        sp->setParent(this);
        this->shapes.push_back(sp);
    }
    getCircumscribedRectangle(true);
    force=shape.force;
    return *this;
}

const VGroupShape & VGroupShape:: operator=(const QJsonObject &jsonObject)
{
    setTransform(VTransform());
    VShape::operator =(jsonObject);
    this->clear();
    QJsonArray jsonArray = jsonObject.value("shapes").toArray();
    VShape * tmp ;
    for(const auto &it: jsonArray)
    {
        tmp = VShape::fromJsonObject(it.toObject());
        if(tmp != nullptr)
        {
            tmp->setParent(this);
            shapes.push_back(tmp);
        }
    }
    getCircumscribedRectangle();
    force=jsonObject.value("force").toBool(false);
    return *this;
}

const VGroupShape & VGroupShape:: operator=(const QJsonArray &jsonArray)
{
    setTransform(VTransform());
    this->clear();
    VShape * tmp ;
    for(const auto &it: jsonArray)
    {
        tmp = VShape::fromJsonObject(it.toObject());
        if(tmp != nullptr)
        {
            tmp->setParent(this);
            shapes.push_back(tmp);
        }
    }
    getCircumscribedRectangle();
    force=false;
    return *this;
}

bool VGroupShape::isforce()
{
    return force;
}

void VGroupShape::setForce(bool force)
{
    this->force=force;
}

int VGroupShape::insertShape(VShape * other)
{
    return insertShape(other,shapes.size());
}

int VGroupShape::insertShape(VShape * other, int pos)
{
    if(pos<0 || pos>this->shapes.size() || other == nullptr) return -1;
    other->setParent(this);
    this->shapes.insert(this->shapes.begin()+pos, other);
    //VPoint orign = other->getLocation();
    //other->setLocation(VPoint(orign.x-getLocation().x, orign.y-getLocation().y));
    getCircumscribedRectangle();
    return pos;
}

int VGroupShape::insertShape(const QVector<VShape *> & other)
{
    for(auto &it:other)
    {
        it->setParent(this);
        it->getTransform()=it->getTransform()*this->getTransform();
        this->shapes.push_back(it);
        //it->setLocation(VPoint(orign.x-getLocation().x, orign.y-getLocation().y));
    }

    getCircumscribedRectangle();
    return this->getVectorSize()-1;
}

int VGroupShape::insertShape(const QVector<VShape *> & other, int pos)
{
    if(pos<0 || pos>this->shapes.size()) return -1;
    //VPoint orign;
    for(auto &it:other)
    {
        it->setParent(this);
        it->getTransform()=it->getTransform()*this->getTransform();
        this->shapes.insert(pos++, it);
        //orign = it->getLocation();
        //it->setLocation(VPoint(orign.x-getLocation().x, orign.y-getLocation().y));
    }
    getCircumscribedRectangle();
    return pos-1;
}

bool VGroupShape::moveShape(int i,  VPoint  location)
{
    if(i<0 || i>=shapes.size()) return false;
    this->shapes[i]->getTransform().translate(this->shapes[i]->getTransform().map(location));
    getCircumscribedRectangle();
    return true;
}

const QVector<VShape *> &VGroupShape::getShapes()
{
    return shapes;
}

QVector<VShape *> VGroupShape::takeShapes()
{
    QVector<VShape *> shapes=std::move(this->shapes);
    this->shapes.clear();
    for(auto &it:shapes)
        it->getTransform()=it->getTransform()*this->getTransform();
    return shapes;
}

VShape* VGroupShape::clone() const
{
    return new VGroupShape(*this);
}


void VGroupShape::draw(QPainter *painter,const VTransform &trans)
{
    for(VShape *shape:shapes)
    {
        painter->save();
        if(force)
        {
            painter->setWorldTransform(trans,true);
            shape->draw(painter,shape->getTransform());
        }
        else
        {
            shape->draw(painter,shape->getTransform()*trans);
        }
        //qDebug() << *it;
        painter->restore();
    }

    //painter->drawRect(0,0,1,1);
}
//获得外接矩形的左上点、右下点
void VGroupShape::getCircumscribedRectangle(bool force){

    if(shapes.empty())
    {
        cr.width=cr.height=1;
        return;
    }

//    double x1 = shapes[0]->getLocation().x, y1 = shapes[0]->getLocation().y;
//    double x2 = x1, y2 = y1;
//    for(int i = 1; i < shapes.size(); i++){
//        x1 = x1 < shapes[i]->getLocation().x ? x1 : shapes[i]->getLocation().x;
//        y1 = y1 < shapes[i]->getLocation().y ? y1 : shapes[i]->getLocation().y;
//        x2 = x2 > shapes[i]->getLocation().x ? x2 : shapes[i]->getLocation().x;
//        y2 = y2 > shapes[i]->getLocation().y ? y2 : shapes[i]->getLocation().y;
//    }
//    cr1.x = x1;
//    cr1.y = y1;
//    cr2.x = x2;
//    cr2.y = y2;

    double minX=0, minY=0;
    double maxX=0, maxY=0;

    // if no subShape, return (0,0)

    //init max&min
    for(auto &p:shapes[0]->getSizeRect())
    {
        VPoint point=shapes[0]->reverseTransformPoint(p);
        maxX = point.x;
        maxY = point.y;
        minX = point.x;
        minY = point.y;
    }

    // loop
    for(auto & it : this->shapes)
    {
        for(auto &p:it->getSizeRect())
        {
            VPoint point=it->reverseTransformPoint(p);
            maxX = std::max(maxX, point.x);
            maxY = std::max(maxY, point.y);
            minX = std::min(minX, point.x);
            minY = std::min(minY, point.y);
        }
    }
//    qDebug()<<maxX<<minX<<maxY<<minY;
//    VPoint mid((minX+maxX)/2,(minY+maxY)/2);
//    for(const auto&i:shapes)
//    {
//        VPoint loc=i->getLocation();
//        i->setLocation(VPoint(loc.x-mid.x,loc.y-mid.y));
//    }
    double midx=(minX+maxX)/2;
    double midy=(minY+maxY)/2;
    cr=VSize(maxX-minX,maxY-minY);


    if(!(std::abs(midx)<1e-9 && std::abs(midy)<1e-9))
    {
        VGroupShape *groupShape=dynamic_cast<VGroupShape*>(getParent());
        if(groupShape==nullptr&&!force) return;


        //标准化，使外接矩形的中点移到坐标原点
        for(int i = 0; i < shapes.size(); i++){
            VPoint loc=shapes[i]->getLocation();
            shapes[i]->getTransform().translate(shapes[i]->transformPoint(VPoint(loc.x-midx,loc.y-midy)));
        }

        if(groupShape==nullptr)return;
        getTransform().translate(VPoint(midx,midy));
        groupShape->getCircumscribedRectangle();


    }


}

bool VGroupShape::eraseShape(VShape * other)
{
    return eraseShape(std::find(shapes.begin(),shapes.end(),other)-shapes.begin());
}

VShape* VGroupShape::atShape(const VPoint &point)
{
    VPoint subPoint;
    for(int i=shapes.size()-1;i>=0;i--)
    {
        subPoint = shapes[i]->transformPoint(point);
        //        qDebug() << subPoint;
        //        qDebug() << subMag;
        if(shapes[i]->contains(subPoint))
        {
            //            qDebug() << it->type();
            return shapes[i];
        }
    }
    return nullptr;
}

VShape * VGroupShape::takeShape(VShape * other)
{
    auto it=std::find(shapes.begin(),shapes.end(),other);
    if(it==shapes.end())return nullptr;
    shapes.erase(it);
    getCircumscribedRectangle();
    return other;
}

VShape * VGroupShape::takeShape(QVector<VShape*>::iterator it)
{
    VShape *shape=*it;
    shapes.erase(it);
    return shape;
}

bool VGroupShape::eraseShape(int i)
{
    if(i<0 || i>=shapes.size()) return false;
    VShape * tmp = shapes[i];
    shapes.erase(shapes.begin()+i);
    delete tmp;
    getCircumscribedRectangle();
    return true;
}

QString VGroupShape::type()const
{
    return VType::Group;
}

bool VGroupShape::contains(VPoint point)
{
    VPoint subPoint;
    for(VShape * it:this->shapes)
    {
        subPoint = it->transformPoint(point);
        if(it->contains(subPoint))
        {
            return true;
        }
    }
    return false;
}

QJsonObject VGroupShape::toJsonObject()const
{
    QJsonObject jsonObject(VShape::toJsonObject());
    QJsonArray jsonArray;
    for(const auto &it: shapes)
    {
        jsonArray.push_back(*it);
    }
    jsonObject.insert("shapes", jsonArray);
    if(force)jsonObject.insert("force",force);
    return jsonObject;
}

VGroupShape::VGroupShape(const QJsonObject &jsonObject):VShape(jsonObject)
{
    cr=VSize(1,1);
    QJsonArray jsonArray = jsonObject.value("shapes").toArray();
    VShape * tmp ;
    for(const auto &it: jsonArray)
    {
        tmp = VShape::fromJsonObject(it.toObject());
        if(tmp != nullptr)
            shapes.push_back(tmp);
    }
    getCircumscribedRectangle(true);
    force=jsonObject.value("force").toBool(false);
}

QVector<VShape *> VGroupShape::breakUp (VGroupShape * group)
{
    QVector<VShape *> tmp;
    if(group == nullptr) return tmp;
    tmp=std::move(group->shapes);
    group->shapes.clear();

    for(VShape* it:tmp)
    {
        it->getTransform()=it->getTransform()*group->getTransform();
        it->setParent(nullptr);
    }

    VGroupShape *parent=dynamic_cast<VGroupShape*>(group->getParent());
    if(parent!=nullptr)
    {
        auto it=std::find(parent->shapes.begin(),parent->shapes.end(),group);
        parent->shapes.erase(it);
        parent->getCircumscribedRectangle();
    }
    delete group;
    return tmp;
}

int VGroupShape::getVectorSize()const
{
    return this->shapes.size();
}

void VGroupShape::clear(bool force)
{
    if(force)
    {
        for(auto &it : this->shapes)
        {
            delete it;
        }
    }
    this->shapes.clear();
}

VSize VGroupShape::getSize()
{
    return cr;
}

void VGroupShape::setPen(QPen pen)
{
    VShape::setPen(pen);
    for(VShape *shape:shapes)shape->setPen(pen);
}

void VGroupShape::setBrush(QBrush brush)
{
    VShape::setBrush(brush);
    for(VShape *shape:shapes)shape->setBrush(brush);
}

void VGroupShape::setPen(QColor pen)
{
    VShape::setPen(pen);
    for(VShape *shape:shapes)shape->setPen(pen);
}

void VGroupShape::setBrush(QColor brush)
{
    VShape::setBrush(brush);
    for(VShape *shape:shapes)shape->setBrush(brush);
}

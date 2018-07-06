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
#include "vtext.h"
#include "vtype.h"
#include <QJsonObject>
#include <cmath>
#include <QDebug>

VText::VText()
{
    text = "";
    center.x = 0;
    center.y = 0;
}

VText::VText(QString str):text(str){
    calSize();
    center.x = 0;
    center.y = 0;
//    qDebug()<<"gouzao() "<<text<<";"<<endl;
}

VText::VText(const QJsonObject jsonObject):VShape(jsonObject){
    this->text = jsonObject.value("text").toString();
    calSize();
    center.x = 0;
    center.y = 0;
}


const VText& VText::operator=(const VText &vText){
    if(this==&vText)return *this;
    VShape::operator=(vText);
    this->text = vText.getText();
    this->size=vText.size;
    this->center = vText.getCenter();
    return *this;
}

const VText& VText::operator=(const QJsonObject &jsonObject){
    VShape::operator=(jsonObject);
    this->text = jsonObject.value("text").toString();
    calSize();
    return *this;
}

VText::~VText(){

}

QString VText::getText() const{
    return this->text;
}

void VText::setText(QString str){
    this->text = str;
}

VSize VText::getSize(){
    return this->size;
}

void VText::setSize(VSize s){
    size.width = s.width;
    size.height = s.height;
}

VPoint VText::getCenter() const{
    return this->center;
}

void VText::setCenter(VPoint point){
    center.x = point.x;
    center.y = point.y;
}

QJsonObject VText::toJsonObject()const{
    QJsonObject jsonObject(VShape::toJsonObject());
    jsonObject.insert("text", this->text);
    return jsonObject;
}

void VText::draw(QPainter *painter, const VTransform &transform){
    painter->setPen(defaultPen);
    painter->setBrush(brush);

    QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
    option.setWrapMode(QTextOption::WordWrap);
//    QFontMetrics fm = painter->fontMetrics();
//    this->size.width = fm.width(this->text);
//    this->size.height = fm.ascent()+fm.descent();

//    QFontMetrics fm = painter->fontMetrics();
//    QString strElidedText = fm.elidedText(this->text, Qt::ElideRight, this->size.width, Qt::TextShowMnemonic);

    VPoint loc=transform.map(VPoint(0,0));
    double width=transform.map(VPoint(1,0))-loc;
    double height=transform.map(VPoint(0,1))-loc;
    QTransform ptrans=QTransform::fromScale(1/width,1/height)*transform*painter->worldTransform();
    painter->setTransform(ptrans);
    width*=size.width;
    height*=size.height;
    QRectF rec(-width/2, -height/2, width, height);
    //rec=transform.mapRect(rec);
//    painter->drawRect(rec);
    painter->drawText(rec, Qt::AlignCenter, this->text);
//    qDebug()<<"draw()"<<text<<endl;
}

bool VText::contains(VPoint point){
    if(std::abs(point.x-center.x)*2<=size.width && std::abs(point.y-center.y)*2<=size.height)
        return true;
    else
        return false;
}

QString VText::type()const{
    return VType::Text;
}

void VText::calSize(){
    int cnt = 1, wid = 0, tmp = 0;
    for(int i = 0; i < text.length(); i++){
        tmp++;
        if(text[i] == '\n'){
            cnt++;
            wid = wid > tmp ? wid : tmp;
            tmp = 0;
        }
    }
    wid = wid > tmp ? wid : tmp;
    size.width = wid*8;
    size.height = cnt*16;
}

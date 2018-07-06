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
#ifndef VTEXT_H
#define VTEXT_H

#include <QString>
#include <cstring>
#include <QJsonObject>
#include "vshape.h"
#include "vsize.h"

class VText : public VShape
{
private:
    QString text;
    VSize size;
    VPoint center;
public:
    VText();
    VText(QString str);
    VText(const QJsonObject jsonObject);
    const VText& operator=(const VText &vText);
    const VText& operator=(const QJsonObject &jsonObject);
    ~VText();

    QString getText() const;
    void setText(QString str);

    VSize getSize()override;
    void setSize(VSize s);

    VPoint getCenter() const;
    void setCenter(VPoint point);

    QJsonObject toJsonObject()const;

    void draw(QPainter *painter,const VTransform &transform);
    bool contains(VPoint point);
    QString type()const;
    void calSize();
};

#endif // VTEXT_H

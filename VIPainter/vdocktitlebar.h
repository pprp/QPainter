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
#ifndef VDOCKTITLEBAR_H
#define VDOCKTITLEBAR_H

#include <QSize>
#include <QDockWidget>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include "QDebug"
#include <QStyle>

class VDockTitleBar:public QWidget
{
    Q_OBJECT
public:
    VDockTitleBar(QWidget *parent = 0);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void updateMask();

private:
    QPixmap maxPix, closePix, minPix;

};

#endif // VDOCKTITLEBAR_H

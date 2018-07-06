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
#include "penstyledialog.h"
#include "ui_penstyledialog.h"
#include <QHash>
#include <QDebug>

PenStyleDialog::PenStyleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PenStyleDialog)
{
    ui->setupUi(this);
}

PenStyleDialog::~PenStyleDialog()
{
    delete ui;
}

void PenStyleDialog::showDialog(const QString title, const QVector<VShape *>shapes)
{
//    static QHash mp{
//        {"NoPen",Qt::NoPen},	//no line at all. For example, QPainter::drawRect() fills but does not draw any boundary line.
//        {"SolidLine",Qt::SolidLine},	//A plain line.
//        {"DashLine",Qt::DashLine},	//Dashes separated by a few pixels.
//        {"DotLine",Qt::DotLine},	//Dots separated by a few pixels.
//        {"DashDotLine",Qt::DashDotLine},	//Alternate dots and dashes.
//        {"DashDotDotLine",Qt::DashDotDotLine},	//One dash, two dots, one dash, two dots.
//        {"CustomDashLine",Qt::CustomDashLine}	//A custom pattern defined using QPainterPathStroker::setDashPattern().
//    };
    if(shapes.empty())return;
    PenStyleDialog dialog;
    dialog.setWindowTitle(title);
    QPen pen(shapes.first()->getPen());
    dialog.ui->spinBox->setValue(pen.width());
    dialog.ui->comboBox->setCurrentIndex(pen.style());
    int res=dialog.exec();
    if (res == QDialog::Accepted)
    {
        pen.setWidth(dialog.ui->spinBox->value());
        pen.setStyle((Qt::PenStyle)dialog.ui->comboBox->currentIndex());
        for(VShape *shape:shapes)shape->setPen(pen);
    }
}

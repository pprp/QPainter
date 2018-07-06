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
#include "paintwidget.h"
#include <QFile>
#include <QImage>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFileDialog>

PaintWidget::PaintWidget(QMainWindow *mainwindow, bool antialiasing) : QWidget(mainwindow),antialiasing(antialiasing),cursorType(VCursorType::CHOOSE),mainwindow(mainwindow)
{
    listModel=new QStringListModel(this);
    selectionModel=new QItemSelectionModel(listModel,this);
    connect(selectionModel,SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &))
            ,this,SLOT(changeSelected()));
    connect(this,SIGNAL(selected(const QItemSelection&,QItemSelectionModel::SelectionFlags)),
            selectionModel,SLOT(select(const QItemSelection&,QItemSelectionModel::SelectionFlags)));
}


void PaintWidget::changeModelData(const QModelIndex &index)
{
    Q_UNUSED(index);
    //do nothing
}

void PaintWidget::changeSelected()
{
//do nothing
}

void PaintWidget::updateList()
{
//do nothing
}

void PaintWidget::on_actionCanvasSize_triggered()
{
//do nothing
}

void PaintWidget::on_actionShapeSize_triggered()
{
//do nothing
}

void PaintWidget::on_actionBreakUp_triggered()
{
//do nothing
}

void PaintWidget::on_actionRedo_triggered()
{
//do nothing
}

void PaintWidget::on_actionUndo_triggered()
{
//do nothing
}

void PaintWidget::on_actionDelete_triggered()
{
//do nothing
}

void PaintWidget::on_actionCopy_triggered()
{
//do nothing
}

void PaintWidget::on_actionCut_triggered()
{
    on_actionCopy_triggered();
    on_actionDelete_triggered();
}

void PaintWidget::on_actionPaste_triggered()
{
//do nothing
}

void PaintWidget::on_actionGroup_triggered()
{
//do nothing
}

void PaintWidget::on_actionSelectAll_triggered()
{
//do nothing
}

void PaintWidget::on_actionBrushColor_triggered()
{
//do nothing
}

void PaintWidget::on_actionPenColor_triggered()
{
//do nothing
}

void PaintWidget::on_actionPenStyle_triggered()
{
//do nothing
}

void PaintWidget::on_actionForceGroup_triggered()
{
//do nothing
}

void PaintWidget::setScale(double scale)
{
    this->scale=scale;
}

double PaintWidget::getScale()
{
    return scale;
}

void PaintWidget::setDock(QDockWidget * dock)
{
    this->dock=dock;
}

QDockWidget* PaintWidget::getDock()
{
    return dock;
}

void PaintWidget::setFileName(QString filename)
{
    this->filename=filename;
}

QString PaintWidget::getFileName() const
{
    return filename;
}

void PaintWidget::on_actionAntialiasing_toggled(bool antialiasing)
{
    this->antialiasing=antialiasing;
    //qDebug()<<"antialiasing"<<antialiasing;
    update();
}

void PaintWidget::on_actionZoomIn_triggered()
{
    scale*=1.1;
    update();
}

void PaintWidget::on_actionZoomOut_triggered()
{
    scale/=1.1;
    update();
}

void PaintWidget::on_actionResume_triggered()
{
    scale=1.0;
    update();
}

void PaintWidget::on_actionSave_triggered()
{
    QString filename = getFileName();
    if(filename=="")on_actionSaveAs_triggered();
    else saveFile(filename);
}

void PaintWidget::changeCursor(VCursorType type,VShape *plugin)
{
    if(cursorType==VCursorType::PLUGIN)update();
    this->cursorType = type;
    switch(type)
    {
    case VCursorType::CHOOSE:
    {
        this->setCursor(Qt::ArrowCursor);
    }break;
    case VCursorType::MOVE:
    {
        this->setCursor(Qt::OpenHandCursor);
    }break;
    case VCursorType::ROTATE:
    {
        this->setCursor(QCursor(VRotate, 15, 15));
    }break;
    case VCursorType::POLYLINE: case VCursorType::BEZIERCURVE: case VCursorType::PEN:
    {
        static QCursor pen = QCursor(QPixmap(":/icon/pen.png").scaled(20,20), 0, 19);
        this->setCursor(pen);
    }break;
    case VCursorType::PLUGIN:
    {
        this->setCursor(Qt::ArrowCursor);
        this->plugin=plugin;
    }break;
    default:
    {
    }
    }
}

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
#include "vectorgraphwidget.h"
#include "vpolygon.h"
#include "vellipse.h"
#include "vpoint.h"
#include "vsize.h"
#include "vcurveline.h"
#include "vmagnification.h"
#include "vvector.h"
#include "vtext.h"
#include "changetextdialog.h"
#include "vroundedrectangle.h"
#include "vbeziercurve.h"
#include "canvassizedialog.h"
#include "penstyledialog.h"
#include <QPainter>
#include <QSize>
#include <QPen>
#include <QBrush>
#include <QtMath>
#include <QStatusBar>
#include <QDebug>
#include <QVector>
#include <QAction>
#include <QApplication>
#include <QCursor>
#include <QStringList>
#include <QColor>
#include <QFile>
#include <QImage>
#include <QDockWidget>
#include <QMessageBox>
#include <QClipboard>
#include <QMimeData>
#include <QModelIndex>
#include <QColorDialog>
#include <QJsonDocument>
#include <QSvgGenerator>
#include <QBuffer>
#include <QFileDialog>

VectorgraphWidget::VectorgraphWidget(QMainWindow *parent, bool antialiasing) :
    PaintWidget(parent,antialiasing),crPos(-1),canvasSize(800,600),canvasLocation(0,0)
{
    setWindowTitle(tr("矢量图"));
    setMouseTracking(true);
//    groupShape.setName("main shape");
//    groupShape.setLocation(VPoint(0,0));
//    groupShape.setSize(VSize(10,10));
}

VectorgraphWidget::~VectorgraphWidget()
{
}

void VectorgraphWidget::wheelEvent(QWheelEvent * event)
{
    QPoint qpoint=event->pos();
    VPoint vpoint(qpoint);
    VPoint oldp(getLoc(vpoint));
    if(event->delta() > 0){
        scale*=1.1;
        if(scale>10)scale=10;
    }else{
        scale/=1.1;
        if(scale<0.05)scale=0.05;
    }
    VPoint newp(getLoc(vpoint));
    canvasLocation.x+=(newp.x-oldp.x)*scale;
    canvasLocation.y+=(newp.y-oldp.y)*scale;
    update();
}

void VectorgraphWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPoint=event->pos();
    VPoint point(pressPoint.x(), pressPoint.y());
    if(event->button()==Qt::LeftButton)
    {
        switch(cursorType)
        {
        case VCursorType::MOVE:
        {
            this->setCursor(Qt::ClosedHandCursor);
        }break;
        case VCursorType::CHOOSE:
        {
            if(!focusShapes.empty())
            {
                //qDebug() << focusShape->transformPoint(getLoc(point));
                for(VShape *shape:focusShapes)
                {
                    crPos = shape->atCrPoints(shape->transformPoint( getLoc(point)),scale);
                    if(crPos == -1)
                    {
                        VPointGroupShape * pgs = dynamic_cast<VPointGroupShape *>(shape);
                        if (pgs != nullptr)
                        {
                            int tmp = pgs->atPoints(shape->transformPoint( getLoc(point)),scale);
                            if(tmp != -1)
                            {
                                crPos = tmp+8;
                                focusShapes.clear();
                                focusShapes.append(shape);
                                emitSelected();
                                break;
                            }
                        }
                    }
                    else
                    {
                        focusShapes.clear();
                        focusShapes.append(shape);
                        emitSelected();
                        break;
                    }
                }
            }

            if(crPos == -1)
            {
                VShape *shape= getShape(point);
                if(shape!=nullptr)
                {
                    auto it=std::find(focusShapes.begin(),focusShapes.end(),shape);
                    if(it==focusShapes.end())
                    {
                        if(QApplication::keyboardModifiers () != Qt::ControlModifier)focusShapes.clear();
                        focusShapes.append(shape);
                        emitSelected();
                    }
                    else
                    {
                        if(QApplication::keyboardModifiers () == Qt::ControlModifier)
                        {
                            focusShapes.erase(it);
                            emitSelected();
                        }
                    }
                }
                else
                {
                    if(QApplication::keyboardModifiers () != Qt::ControlModifier)
                    {
                        focusShapes.clear();
                        emitSelected();
                    }
                    crPos=-2;
                }
            }

            update();
        }break;
        case VCursorType::ROTATE:
        {
            if(!focusShapes.empty())
            {
                VShape *shape= focusShapes.back();
                focusShapes.clear();
                focusShapes.append(shape);
                emitSelected();
                lastAngle = 0;
            }
        }break;
        case VCursorType::POLYLINE:
        case VCursorType::PEN:
        case VCursorType::BEZIERCURVE:
        {
            VPointGroupShape * pl;
            if(crPos == -1)
            {
//                qDebug() << "!!!!!!";
                if(cursorType == VCursorType::POLYLINE || cursorType == VCursorType::PEN || cursorType == VCursorType::PEN)
                    pl = new VPolyline();
                else if (cursorType == VCursorType::BEZIERCURVE)
                    pl = new VBezierCurve();
                groupShape.insertShape(pl);
                pl->moveLoc(pl->transformPoint(getLoc(point)));
                focusShapes.push_back(pl);

//                pl->addPoint(pl->transformPoint(getLoc((point))));
//                crPos++;
                updateList();
            }
            else
            {
                pl = dynamic_cast<VPointGroupShape *>(focusShapes[0]);
            }

//            qDebug() << pl << focusShapes.size() << crPos;
            pl->addPoint(pl->transformPoint(getLoc((point))));
            crPos++;
            update();
        }break;
        case VCursorType::PLUGIN:
        {
            VShape *shape=plugin->clone();
            shape->moveLoc(shape->transformPoint(getLoc(point)));
            groupShape.insertShape(shape);
            focusShapes.clear();
            focusShapes.append(shape);
            update();
            updateList();
            saveSwp();
        }break;
        default:
            break;
        }
    }
    lastMove=VPoint(pressPoint.x(),pressPoint.y());
    locMove=locPress=getLoc(lastMove);
}

void VectorgraphWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    QPoint qpoint=event->pos();
    VPoint point(qpoint.x(),qpoint.y());
    point=getLoc(point);
    if(event->button()==Qt::LeftButton)
    {
        VShape *shape=groupShape.atShape(point);
        if(shape!=nullptr)
        {
            //qDebug()<<point.x<<" "<<point.y<<endl;
            VText * vt = dynamic_cast<VText *>(shape);
            if(vt != nullptr)
            {
                ChangeTextDialog::showDialog(vt);
                saveSwp();
            }
        }
    }
}

void VectorgraphWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint qpoint=event->pos();
    VPoint pos=getLoc(VPoint(qpoint.x(),qpoint.y()));
    if(event->button()==Qt::LeftButton)
    {
        switch(cursorType)
        {
        case VCursorType::MOVE:
        {
            this->setCursor(Qt::OpenHandCursor);
        }break;
        case VCursorType::CHOOSE:
        {
            if(crPos==-2)
            {
                QRectF rect(locPress.x,locPress.y,
                            pos.x-locPress.x,pos.y-locPress.y);
                for(VShape *shape:groupShape.getShapes())
                {
                    bool flag=true;
                    for(const VPoint &point:shape->getSizeRect())
                    {
                        VPoint p=shape->reverseTransformPoint(point);
                        if(!rect.contains(p.x,p.y))
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        focusShapes.append(shape);
                        emitSelected();
                    }
                }
                std::sort(focusShapes.begin(),focusShapes.end());
                std::unique(focusShapes.begin(),focusShapes.end());
                //emit selected(listModel.createIndex(1,0));
                update();
            }
            else if(pos.x!=locPress.x||pos.y!=locPress.y)
            {
                saveSwp();
            }
        }break;
        case VCursorType::ROTATE:
        {
            if(focusShapes.size()==1&&(pos.x!=locPress.x||pos.y!=locPress.y))
            {
                saveSwp();
            }
        }break;
        default:
            break;
        }
        if(cursorType != VCursorType::BEZIERCURVE && cursorType != VCursorType::POLYLINE && cursorType != VCursorType::PEN)
            crPos = -1;
    }
}

void VectorgraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint qpoint=event->pos();
    VPoint vpoint(qpoint.x(), qpoint.y());
    VPoint loc = getLoc(vpoint);
    if(cursorType == VCursorType::CHOOSE)
    {
        bool flag=true;
        for(int i=focusShapes.size()-1;i>=0;i--)
        {
            if(crPos < 8 && (crPos >= 0 || (focusShapes[i]->atCrPoints(focusShapes[i]->transformPoint(loc),scale) != -1)))
            {
                this->setCursor(QCursor(VSizeAll, 15, 15));
                flag=false;
                break;
            }
        }
        if(flag)
        {
            for(int i=focusShapes.size()-1;i>=0;i--)
            {
                VPointGroupShape * pgs = dynamic_cast<VPointGroupShape *>(focusShapes.at(i));
                if(crPos>=8||(pgs != nullptr && pgs->atPoints(pgs->transformPoint(loc),scale) != -1))
                {
                    this->setCursor(Qt::ArrowCursor);
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
        {
            if(groupShape.contains(groupShape.transformPoint(loc)))
                this->setCursor(Qt::SizeAllCursor);
            else this->setCursor(Qt::ArrowCursor);
        }
    }
    else if(cursorType == VCursorType::PLUGIN)
    {
        update();
    }

    if(event->buttons()&Qt::LeftButton)
    {
        switch(cursorType)
        {
        case VCursorType::MOVE:
        {
            canvasLocation.x+=(vpoint.x-lastMove.x);
            canvasLocation.y+=(vpoint.y-lastMove.y);
            update();
        }break;
        case VCursorType::CHOOSE:
        {
            if(!focusShapes.empty())
            {
                VPoint lp = groupShape.transformPoint(locMove);
                VPoint v(loc.x-lp.x, loc.y-lp.y);
                if(crPos == -2)
                {
                    //do nothing
                }
                else if(crPos == -1)
                {
                    for(VShape *shape:focusShapes)
                    {
                        shape->moveLoc(shape->transformPoint(v+shape->getLocation()));
                    }
                    this->setCursor(Qt::SizeAllCursor);
                }
                else if(crPos < 8)
                {
                    if(focusShapes.size()==1)
                    {
                        VShape *shape=focusShapes.first();
                        shape->changeMag(crPos, shape->transformPoint(loc), QApplication::keyboardModifiers() == Qt::ControlModifier);
                    }
                }
                else if(crPos >= 8)
                {
                    if(focusShapes.size()==1)
                    {
                        VPointGroupShape * shape=dynamic_cast<VPointGroupShape *>(focusShapes.first());
                        if(shape!=nullptr)
                        {
                            shape->changePoint(crPos - 8, shape->transformPoint(loc));
                        }
                    }
                }
            }
            update();
        }break;
        case VCursorType::ROTATE:
        {
            if(focusShapes.size()==1)
            {
                VShape *shape=focusShapes.first();
                VVector vlp(shape->getLocation(), locMove),
                        vnow(shape->getLocation(), loc);
                VPoint loc=shape->getLocation();
                shape->getTransform().translate(
                            shape->getTransform().inverted().map(VPoint(0,0))
                            );
                VTransform trans;
                trans.rotate(VVector::rotationAngle(vlp, vnow));
                shape->getTransform()*=trans;
                shape->getTransform().translate(
                            shape->getTransform().inverted().map(loc)
                            );
                update();
            }
        }break;
        case VCursorType::BEZIERCURVE:
        case VCursorType::POLYLINE:
        case VCursorType::PEN:
        {
            if(crPos > -1)
            {
                VPointGroupShape * shape=dynamic_cast<VPointGroupShape *>(focusShapes.first());
                if(shape!=nullptr)
                {
                    int index = shape->getPointList().size() - 1;
                    if(index >= 0)
                        shape->changePoint(index, shape->transformPoint(loc));
                    update();
                }
            }

        }break;
        default:
            break;
        }
    }
    mainwindow->statusBar()->showMessage(QString("%1,%2").arg(floor(loc.x+0.5)).arg(floor(loc.y+0.5)));
    locMove = loc;
    lastMove=vpoint;
}

void VectorgraphWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if(antialiasing)painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(this->width()/2+canvasLocation.x,this->height()/2+canvasLocation.y);

    painter.save();
    {
        painter.scale(scale,scale);
        painter.save();
        {
            painter.setBrush(QBrush(Qt::white));
            painter.setPen(QPen(Qt::lightGray,1));
            painter.drawRect(-canvasSize.width/2, -canvasSize.height/2, canvasSize.width, canvasSize.height);
        }
        painter.restore();
        groupShape.draw(&painter,groupShape.getTransform());
    }
    painter.restore();

    for(VShape *shape:focusShapes)
    {
        painter.save();
        VTransform trans;
        trans.scale(VMagnification(scale));
        trans=shape->getTransform()*trans;
        shape->drawCR(&painter,trans,scale);
        //qDebug() << *it;
        painter.restore();
    }

    if(cursorType==VCursorType::PLUGIN)
    {
        painter.save();
        painter.scale(scale,scale);
        painter.translate(locMove.toQPointF());
        plugin->draw(&painter,plugin->getTransform());
        painter.restore();
    }

    if(crPos==-2)
    {
        VPoint point=locMove;
        painter.setPen(QPen(QBrush(Qt::gray),2,Qt::DotLine,Qt::SquareCap,Qt::MiterJoin));
        painter.setBrush(QColor(0xaa,0xaa,0xaa,9));
        painter.drawRect(locPress.x*scale,locPress.y*scale,
                         (point.x-locPress.x)*scale,(point.y-locPress.y)*scale);
    }

}


bool VectorgraphWidget::eventFilter(QObject * obj, QEvent * ev)
{
    Q_UNUSED(obj);
    if(ev->type()==QEvent::KeyPress)
    {
        QKeyEvent *event=static_cast<QKeyEvent*>(ev);
        switch(event->key())
        {
        case Qt::Key_Up:
            for(auto &shape:focusShapes)
            {
                VPoint loc=shape->getLocation();
                shape->moveLoc(shape->transformPoint(VPoint(loc.x,loc.y-1)));
            }
            break;
        case Qt::Key_Down:
            for(auto &shape:focusShapes)
            {
                VPoint loc=shape->getLocation();
                shape->moveLoc(shape->transformPoint(VPoint(loc.x,loc.y+1)));
            }
            break;
        case Qt::Key_Left:
            for(auto &shape:focusShapes)
            {
                VPoint loc=shape->getLocation();
                shape->moveLoc(shape->transformPoint(VPoint(loc.x-1,loc.y)));
            }
            break;
        case Qt::Key_Right:
            for(auto &shape:focusShapes)
            {
                VPoint loc=shape->getLocation();
                shape->moveLoc(shape->transformPoint(VPoint(loc.x+1,loc.y)));
            }
            break;
        case Qt::Key_Return:
        case Qt::Key_Escape:
            {
                if(cursorType == VCursorType::BEZIERCURVE || cursorType == VCursorType::POLYLINE || cursorType == VCursorType::PEN)
                {
                    focusShapes.clear();
                    crPos = -1;
                    saveSwp();
                    update();
                }
            }
        }
        update();
        return true;
    }
    return false;
}

void VectorgraphWidget::changeCursor(VCursorType type,VShape *plugin)
{
    PaintWidget::changeCursor(type,plugin);
    crPos=-1;
    switch(type)
    {
    case VCursorType::MARQUEE:
    {
        this->cursorType=VCursorType::CHOOSE;
        this->setCursor(Qt::ArrowCursor);
    }break;
    case VCursorType::POLYLINE:
    case VCursorType::PEN:
    case VCursorType::BEZIERCURVE:
    {
        focusShapes.clear();
    }break;
    default:
        break;
    }
}

VShape * VectorgraphWidget::getShape(const VPoint &point)
{
    VPoint subPoint;
    VPoint loc = getLoc(point);
//    qDebug() << loc;
    for(VShape *shape:focusShapes)
    {
//        subLocation = focusShape->getLocation();
//        subAngle = focusShape->getAngle();
//        subMag = focusShape->getMagnification();
//        subPoint = VPoint(loc.x - subLocation.x, loc.y - subLocation.y).rotate(VPoint(0,0),-subAngle)/subMag;
        subPoint=shape->transformPoint(loc);
//        qDebug() << subPoint;
//        qDebug() << subMag;
        if(shape->contains(subPoint))
        {
//            qDebug() << it->type();
            return shape;
        }
    }
    return this->groupShape.atShape(loc);
    //return nullptr;
}

VPoint VectorgraphWidget::getLoc(const VPoint & point)
{
    return VPoint((point.x-(this->width()/2+canvasLocation.x))/scale,(point.y-(this->height()/2+canvasLocation.y))/scale);
}

void VectorgraphWidget::updateList()
{
    QStringList list;
    for(int i=groupShape.getShapes().size()-1;i>=0;i--)
    {
        if(groupShape.getShapes().at(i)->getName()=="")groupShape.getShapes().at(i)->setName(tr("没有名字的图形"));
        list.append(groupShape.getShapes().at(i)->getName());
    }
    listModel->setStringList(list);
    emitSelected();
}

void VectorgraphWidget::changeSelected()
{
    if(cursorType == VCursorType::BEZIERCURVE || cursorType == VCursorType::POLYLINE || cursorType == VCursorType::PEN) return;
    decltype(focusShapes) newFocus;
    for(auto &index:selectionModel->selectedRows())
        newFocus.append(groupShape.getShapes().at(groupShape.getVectorSize()-index.row()-1));
    if(focusShapes!=newFocus)
    {
        focusShapes=std::move(newFocus);
        update();
    }
}

void VectorgraphWidget::emitSelected()
{
    QItemSelection list;
    for(VShape *shape:focusShapes)
    {
        QModelIndex index=listModel->index
                (groupShape.getShapes().end()-
                 std::find(groupShape.getShapes().begin(),groupShape.getShapes().end(),shape)-1
                 );
        list.select(index,index);
    }
    emit selected(list,QItemSelectionModel::ClearAndSelect);
}

void VectorgraphWidget::saveSwp()
{
    swapQueue.push(groupShape.toJsonArray());
}

void VectorgraphWidget::on_actionSaveAs_triggered()
{
    QString filename=getFileName();
    if(filename=="")filename="image.json";
    filename=
            QFileDialog::getSaveFileName(this,
                                         tr("保存文件"),
                                         filename,
                                         tr("json file (*.json);;"
                                            "svg file (*.svg);;"
                                            "png file (*.png);;"
                                            "jpg file (*.jpg);;"
                                            "bmp file (*.bmp)"));
    saveFile(filename);
}

void VectorgraphWidget::on_actionUndo_triggered()
{
    if(swapQueue.atFirst())return;
    focusShapes.clear();
    groupShape=swapQueue.undo();
    update();
    updateList();
}

void VectorgraphWidget::on_actionRedo_triggered()
{
    if(swapQueue.atLast())return;
    focusShapes.clear();
    groupShape=swapQueue.redo();
    update();
    updateList();
}

void VectorgraphWidget::saveFile(QString filename)
{
    if(filename=="")return;
    QString format=filename.split('.').back().toUpper();
    if(format==tr("JSON"))
    {
        QJsonDocument jsonDocument(toJsonObject());
        QFile file(filename);
        if(file.open(QFile::WriteOnly|QFile::Text))
        {
            file.write(jsonDocument.toJson());
            file.close();
            dock->setWindowTitle(filename.split("/").back()+" - "+this->windowTitle());
            setFileName(filename);
        }
        else QMessageBox::warning(this,tr("错误"),tr("保存文件")+filename+tr("失败"));
    }
    else if(format=="JPG"||format=="PNG"||format=="BMP")
    {
        QImage image(getCanvasSize().width,getCanvasSize().height,QImage::Format_ARGB32_Premultiplied);
        image.fill(0x00ffffff);
        QPainter painter(&image);
        if(antialiasing)painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(getCanvasSize().width/2,getCanvasSize().height/2);
        groupShape.draw(&painter,groupShape.getTransform());
        if(!image.save(filename,format.toStdString().c_str(),100))QMessageBox::warning(this,tr("错误"),tr("保存文件")+filename+tr("失败"));
    }
    else if(format=="SVG")
    {
        QSvgGenerator svgGenerator;
        svgGenerator.setSize(getCanvasSize().toQSizeF().toSize());
        svgGenerator.setTitle(this->dock->windowTitle());
        svgGenerator.setFileName(filename);
        VSize size=getCanvasSize();
        svgGenerator.setViewBox(QRectF(QPointF(-size.width/2,-size.height/2),size.toQSizeF()));
        QPainter painter(&svgGenerator);
        groupShape.draw(&painter,groupShape.getTransform());
    }
    else QMessageBox::warning(this,tr("错误"),format+tr("不能识别的文件格式"));
}

void VectorgraphWidget::on_actionResume_triggered()
{
    canvasLocation=VPoint(0,0);
    PaintWidget::on_actionResume_triggered();
}

void VectorgraphWidget::on_actionCanvasSize_triggered()
{
    setCanvasSize(CanvasSizeDialog::showDialog(tr("画布大小"),getCanvasSize()));
}


void VectorgraphWidget::setCanvasSize(VSize canvasSize)
{
    this->canvasSize=canvasSize;
}

VSize VectorgraphWidget::getCanvasSize()
{
    return canvasSize;
}

void VectorgraphWidget::on_actionShapeSize_triggered()
{
    VSize size=
            groupShape.getSize()*
            groupShape.getTransform();
    VSize toSize=CanvasSizeDialog::showDialog(tr("图像大小"),size);
    VMagnification mag=toSize/size;
    for(auto &i:groupShape.getShapes())
    {
        i->zoomin(mag);
    }
    saveSwp();
}

void VectorgraphWidget::on_actionBreakUp_triggered()
{
    if(focusShapes.size()==1)
    {
        VGroupShape *shape=dynamic_cast<VGroupShape*>(focusShapes.first());
        focusShapes.clear();
        if(shape!=nullptr)
        {
            auto &shapes=groupShape.getShapes();
            int i=std::find(shapes.begin(),shapes.end(),shape)-shapes.begin();
            QVector<VShape *> shs = VGroupShape::breakUp(shape);
            groupShape.insertShape(shs,i);
            focusShapes=std::move(shs);
        }
        update();
        updateList();
        saveSwp();
    }
}

void VectorgraphWidget::on_actionDelete_triggered()
{
    for(VShape *shape:focusShapes)
    {
        groupShape.eraseShape(shape);
    }
    focusShapes.clear();
    update();
    updateList();
    saveSwp();
}

void VectorgraphWidget::on_actionCopy_triggered()
{
    if(focusShapes.size()>0)
    {
        //  Get clipboard
        QClipboard *cb = QApplication::clipboard();

        // Ownership of the new data is transferred to the clipboard.
        QMimeData* newMimeData = new QMimeData();

        // Copy old mimedata
        //            const QMimeData* oldMimeData = cb->mimeData();
        //            for ( const QString &f : oldMimeData->formats())
        //                newMimeData->setData(f, oldMimeData->data(f));

        // Copy file (gnome)
        ////////////////////////////////////////////////////////////////////////////////////////////////START
        ////////////////////////////////////JSON
        QJsonDocument doc;
        if(focusShapes.size()>1)
        {
            QJsonArray arr;
            for(VShape *shape:focusShapes)
                arr.append(shape->toJsonObject());
            doc.setArray(arr);
        }
        else doc.setObject(focusShapes.first()->toJsonObject());
        newMimeData->setData("application/x-JavaScript", doc.toBinaryData());

        // Copy file (gnome)
        ////////////////////////////////////TEXT

        VText *text=dynamic_cast<VText*>(focusShapes.first());
        if(focusShapes.size()==1&&text!=nullptr)
        {
            newMimeData->setText(text->getText());
        }
        else
        {

            ////////////////////////////////////IMAGE
            VGroupShape group;
            for(const VShape*shape:groupShape.getShapes())
            {
                if(std::find(focusShapes.begin(),focusShapes.end(),shape)!=focusShapes.end())
                {
                    group.insertShape(shape->clone());
                }
            }
            group.getCircumscribedRectangle(true);
            VSize size=group.getSize()*group.getTransform();
            size.width+=4;size.height+=4;
            {
                QImage image(size.width,size.height,QImage::Format_ARGB32);
                image.fill(0x00ffffff);
                QPainter painter;
                painter.begin(&image);
                if(antialiasing)painter.setRenderHint(QPainter::Antialiasing);
                painter.translate(size.width/2,size.height/2);
                //qDebug()<<*(group.getShapeVector().back());
                group.draw(&painter,group.getTransform());
                painter.end();
                //newMimeData->setImageData(image);
            }

            ////////////////////////////////////SVG
            {
                QBuffer buffer;
                //qDebug()<<buffer.open(QIODevice::ReadWrite);
                QSvgGenerator svgGenerator;
                svgGenerator.setOutputDevice(&buffer);
                svgGenerator.setSize(size.toQSizeF().toSize());
                svgGenerator.setViewBox(QRectF(QPointF(-size.width/2,-size.height/2),size.toQSizeF()));
                QPainter painter;
                painter.begin(&svgGenerator);
                group.draw(&painter,group.getTransform());
                painter.end();
                newMimeData->setData("image/svg+xml", buffer.data());
            }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////FI
        // Set the mimedata
        cb->setMimeData(newMimeData);
    }
}

void VectorgraphWidget::on_actionPaste_triggered()
{
        //  Get clipboard
        QClipboard *cb = QApplication::clipboard();
        const QMimeData* mimeData = cb->mimeData();
        QList<VShape*>shapes;
        if(mimeData->hasFormat("application/x-JavaScript"))
        {
//            qDebug()<<QJsonDocument::fromBinaryData(mimeData->data("application/x-JavaScript"));
            QJsonDocument doc=QJsonDocument::fromBinaryData(mimeData->data("application/x-JavaScript"));
            if(doc.isObject())
            {
                shapes.append(VShape::fromJsonObject(doc.object()));
                //qDebug()<<*shape;
            }
            else if(doc.isArray())
            {
                for(auto i:doc.array())
                {
                    VShape *shape=VShape::fromJsonObject(
                                i.toObject()
                                );
                    shapes.append(shape);
                }
            }
        }
        else if(mimeData->hasText())
        {
            VText *text=new VText(mimeData->text());
            text->setName(mimeData->text());
            shapes.append(text);
        }
        if(!shapes.empty())
        {
            focusShapes.clear();
            for(VShape *shape:shapes)
            {
                groupShape.insertShape(shape);
                focusShapes.append(shape);
            }
            update();
            updateList();
            saveSwp();
        }
}

void VectorgraphWidget::on_actionGroup_triggered()
{
    if(focusShapes.empty())return;
    VGroupShape *group=new VGroupShape;
    QString name;
    for(QVector<VShape*>::iterator it=const_cast<QVector<VShape*>::iterator>(groupShape.getShapes().begin());it!=groupShape.getShapes().end();)
    {
        if(focusShapes.contains(*it))
        {
            if(name!="")name.append(", ");
            name.append((*it)->getName());
            group->insertShape(groupShape.takeShape(it));
        }
        else it++;
    }
    groupShape.insertShape(group);
    group->getCircumscribedRectangle();
    focusShapes.clear();
    group->setName("("+name+")");
    focusShapes.append(group);
    update();
    updateList();
    saveSwp();
}

void VectorgraphWidget::on_actionForceGroup_triggered()
{
    if(focusShapes.empty())return;
    VGroupShape *group=new VGroupShape;
    QString name;
    for(QVector<VShape*>::iterator it=const_cast<QVector<VShape*>::iterator>(groupShape.getShapes().begin());it!=groupShape.getShapes().end();)
    {
        if(focusShapes.contains(*it))
        {
            if(name!="")name.append(", ");
            name.append((*it)->getName());
            group->insertShape(groupShape.takeShape(it));
        }
        else it++;
    }
    groupShape.insertShape(group);
    group->getCircumscribedRectangle();
    focusShapes.clear();
    group->setName("["+name+"]");
    group->setForce(true);
    focusShapes.append(group);
    update();
    updateList();
    saveSwp();
}

void VectorgraphWidget::changeModelData(const QModelIndex &index)
{
    groupShape.getShapes().at(groupShape.getVectorSize()-index.row()-1)->setName(index.data().toString());
}

void VectorgraphWidget::on_actionSelectAll_triggered()
{
    focusShapes.clear();
    for(auto &i:groupShape.getShapes())focusShapes.append(i);
    update();
    emitSelected();
}

void VectorgraphWidget::on_actionBrushColor_triggered()
{
    if(focusShapes.empty())return;
    QColorDialog dialog(focusShapes.first()->getBrush().color(),this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    if(dialog.exec()==QDialog::Accepted)
    {
        for(VShape *shape:focusShapes)shape->setBrush(dialog.selectedColor());
        update();
        saveSwp();
    }
}

void VectorgraphWidget::on_actionPenColor_triggered()
{
    if(focusShapes.empty())return;
    QColorDialog dialog(focusShapes.first()->getPen().color(),this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    if(dialog.exec()==QDialog::Accepted)
    {
        for(VShape *shape:focusShapes)shape->setPen(dialog.selectedColor());
        update();
        saveSwp();
    }
}

void VectorgraphWidget::on_actionPenStyle_triggered()
{
    if(focusShapes.empty())return;
    PenStyleDialog::showDialog(tr("线条设置"),focusShapes);
    update();
    saveSwp();
}

bool VectorgraphWidget::fileChanged()
{
    if(!swapQueue.changed())return false;
    if(filename=="")
    {
        if(!groupShape.getShapes().empty())return true;
    }
    else
    {
        QFile file(filename);
        if(file.open(QFile::ReadOnly|QFile::Text))
        {
            QJsonDocument doc=QJsonDocument::fromJson(file.readAll());
            file.close();
            if(doc!=QJsonDocument(toJsonObject()))return true;
        }
    }
    return false;
}

QJsonObject VectorgraphWidget::toJsonObject()
{
    QJsonObject obj;
    obj.insert("type",QString("canvas"));
    obj.insert("size",getCanvasSize());
    obj.insert("shapes",groupShape.toJsonArray());
    return obj;
}


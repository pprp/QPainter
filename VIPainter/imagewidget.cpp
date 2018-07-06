#include "imagewidget.h"
#include <QFileDialog>
#include <QPainter>
#include <QDebug>
#include <QRect>
#include <QStatusBar>
#include <QScrollBar>
#include <QBrush>
#include <QPen>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMimeData>
#include <QClipboard>
#include <QJsonDocument>
#include <cmath>
#include <QApplication>
#include <QTransform>
#include "canvassizedialog.h"
#include "vtype.h"
#include "vtransform.h"
#include "vpointgroupshape.h"
#include "vimageshape.h"
#include "vpolyline.h"

ImageWidget::ImageWidget(QMainWindow *mainwindow, bool antialiasing):PaintWidget(mainwindow,antialiasing)
{
    setWindowTitle(tr("画图"));
    setMouseTracking(true);

    scrollArea=new QScrollArea;
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setWidgetResizable(false);
    scrollArea->setWidget(this);
    scrollArea->setWindowTitle(this->windowTitle());
    scrollArea->installEventFilter(this);
    scrollArea->setMouseTracking(true);
    scrollArea->verticalScrollBar()->installEventFilter(this);
    scrollArea->horizontalScrollBar()->installEventFilter(this);
    this->move(1,1);
}

void ImageWidget::saveFile(QString filename)
{
    if(filename=="")return;
    QString format=filename.split('.').back().toUpper();
    if(format=="JPG"||format=="PNG"||format=="BMP")
    {
        if(!canvas.save(filename,format.toStdString().c_str(),100))QMessageBox::warning(this,tr("错误"),tr("保存文件")+filename+tr("失败"));
        else if(getFileName()=="")
        {
            dock->setWindowTitle(filename.split("/").back()+" - "+windowTitle());
            setFileName(filename);
        }
    }
    else QMessageBox::warning(this,tr("错误"),format+tr("不能识别的文件格式"));
}

bool ImageWidget::fileChanged()
{
    return swapQueue.changed();
}

QImage& ImageWidget::getCanvas()
{
    return canvas;
}

void ImageWidget::setCanvasSize(VSize canvasSize)
{
    QImage tmp(canvasSize.toQSizeF().toSize(),QImage::Format_ARGB32_Premultiplied);
    tmp.fill(Qt::transparent);
    QPainter painter;
    painter.begin(&tmp);
    painter.drawImage(0,0,canvas);
    painter.end();
    canvas=std::move(tmp);
    this->resize(canvas.width()*scale,canvas.height()*scale);
}

void ImageWidget::setImageSize(VSize size)
{
    canvas=canvas.scaled(size.toQSizeF().toSize());
    this->resize(canvas.width()*scale,canvas.height()*scale);
}

void ImageWidget::setScale(double scale)
{
    PaintWidget::setScale(scale);
    this->resize(canvas.width()*scale,canvas.height()*scale);
}

VSize ImageWidget::getCanvasSize()
{
    return canvas.size();
}

VMagnification ImageWidget::getScale()
{
    return VSize(this->width(),this->height())/getCanvasSize();
}

void ImageWidget::emitSelected()
{
    QItemSelection list;
    QModelIndex index=listModel->index(swapQueue.getNow());
    list.select(index,index);
    emit selected(list,QItemSelectionModel::ClearAndSelect);
}

void ImageWidget::changeSelected()
{
    if(selectionModel->selectedRows().empty())
    {
        emitSelected();
        return;
    }
    int row=selectionModel->selectedRows().first().row();
    if(row!=swapQueue.getNow())
    {
        clearFocusShape();
        canvas=swapQueue.todo(row);
        update();
    }
}

void ImageWidget::updateList()
{
    listModel->setStringList(swapQueue.namelist());
    emitSelected();
}

void ImageWidget::on_actionCanvasSize_triggered()
{
    finishFocusShape();
    setCanvasSize(CanvasSizeDialog::showDialog(tr("画布大小"),getCanvasSize()));
    saveSwp(tr("调整画布大小"));
    update();
}

void ImageWidget::on_actionShapeSize_triggered()
{
    finishFocusShape();
    setImageSize(CanvasSizeDialog::showDialog(tr("图像大小"),getCanvasSize()));
    saveSwp(tr("调整图像大小"));
    update();
}

VPoint ImageWidget::getLoc(const VPoint & point)
{
    return (point/getScale()).floor();
}

QScrollArea* ImageWidget::getScrollArea()
{
    return scrollArea;
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if(antialiasing)painter.setRenderHint(QPainter::Antialiasing);
    QImage tmp(canvas);
    if(focusShape!=nullptr)
    {
        QPainter tmpPainter;
        tmpPainter.begin(&tmp);
        if(antialiasing)tmpPainter.setRenderHint(QPainter::Antialiasing);
        focusShape->draw(&tmpPainter,focusShape->getTransform());
        tmpPainter.end();
    }

    painter.save();
    VMagnification mag=getScale();
    painter.scale(mag.horizontal,mag.vertical);
    painter.drawImage(0,0,tmp);
    painter.restore();
    if(focusShape!=nullptr)
    {
        VTransform trans;
        trans.scale(mag);
        focusShape->drawCR(&painter,focusShape->getTransform()*trans,mag.horizontal,false);
    }

    if(isPressing&&cursorType==VCursorType::MARQUEE)
    {
        painter.save();
        VPoint point=locMove;
        painter.setPen(QPen(QBrush(Qt::gray),2,Qt::DotLine,Qt::SquareCap,Qt::MiterJoin));
        painter.setBrush(QColor(0xaa,0xaa,0xaa,9));
        painter.drawRect(locPress.x*scale,locPress.y*scale,
                         (point.x-locPress.x)*scale,(point.y-locPress.y)*scale);
        painter.restore();
    }

    painter.setPen(QPen(QBrush(Qt::lightGray),0,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter.drawRect(0,0,width(),height());
}

void ImageWidget::wheelEvent(QWheelEvent * event)
{
    QPoint point=event->pos();
    double oldScale=scale;
    if(event->delta() > 0){
        scale*=1.1;
        if(scale>20)scale=20;
    }else{
        scale/=1.1;
        if(scale<0.05)scale=0.05;
    }
    this->resize(canvas.width()*scale,canvas.height()*scale);
    scrollArea->horizontalScrollBar()->setValue(point.x()*scale/oldScale-(point.x()-scrollArea->horizontalScrollBar()->value()));
    scrollArea->verticalScrollBar()->setValue(point.y()*scale/oldScale-(point.y()-scrollArea->verticalScrollBar()->value()));
    update();
}

void ImageWidget::on_actionZoomIn_triggered()
{
    scale*=1.1;
    if(scale>20)scale=20;
    this->resize(canvas.width()*scale,canvas.height()*scale);
    update();
}

void ImageWidget::on_actionZoomOut_triggered()
{
    scale/=1.1;
    if(scale<0.05)scale=0.05;
    this->resize(canvas.width()*scale,canvas.height()*scale);
    update();
}

void ImageWidget::on_actionResume_triggered()
{
    scale=1.0;
    this->resize(canvas.size());
    update();
}

void ImageWidget::on_actionDelete_triggered()
{
    clearFocusShape();
    update();
}

void ImageWidget::on_actionCopy_triggered()
{
    if(focusShape==nullptr)return;
    QClipboard *cb = QApplication::clipboard();
    QMimeData *mimeData=new QMimeData();
    if(focusShape->type()==VType::Image)
    {
        VImageShape *ims=dynamic_cast<VImageShape*>(focusShape);
        mimeData->setImageData(ims->getImage());
    }
    else
    {
        QJsonDocument doc;
        doc.setObject(focusShape->toJsonObject());
        mimeData->setData("application/x-JavaScript", doc.toBinaryData());
    }
    cb->setMimeData(mimeData);
}

void ImageWidget::on_actionPaste_triggered()
{
    if(focusShape!=nullptr)finishFocusShape();
    QClipboard *cb = QApplication::clipboard();
    const QMimeData* mimeData = cb->mimeData();
    if(mimeData->hasImage())
    {
        QImage image=mimeData->imageData().value<QImage>();
        if(swapQueue.atFirst())setImageSize(VSize(image.width(),image.height()));
        focusShape=new VImageShape(image);
    }
    else if(mimeData->hasFormat("application/x-JavaScript"))
    {
        QJsonDocument doc=QJsonDocument::fromBinaryData(mimeData->data("application/x-JavaScript"));
        if(doc.isObject())
        {
            focusShape=VShape::fromJsonObject(doc.object());
            //qDebug()<<*shape;
        }
    }
    VPoint point((canvas.width())/2,canvas.height()/2);
    if(focusShape!=nullptr)
    {
        pasting=true;
        focusShape->moveLoc(focusShape->transformPoint(point));
    }
    update();
}

void ImageWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint qpoint=event->pos();
    VPoint vpoint(qpoint.x(), qpoint.y());
    VPoint loc = getLoc(vpoint);
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
            if(focusShape!=nullptr)
            {
                crPos = focusShape->atCrPoints(focusShape->transformPoint(loc),getScale());
                if(crPos == -1)
                {
                    VPointGroupShape * pgs = dynamic_cast<VPointGroupShape *>(focusShape);
                    if (pgs != nullptr)
                    {
                        int tmp = pgs->atPoints(focusShape->transformPoint(loc),getScale());
                        if(tmp != -1)
                        {
                            crPos = tmp+8;
                            break;
                        }
                    }
                }

                if(crPos == -1)
                {
                    //if(!focusShape->contains(focusShape->transformPoint(loc)))finishFocusShape();
                }
            }

            update();
        }break;
        case VCursorType::ROTATE:
        {
        }break;
        case VCursorType::POLYLINE:
        {
            QPoint pressPoint=event->pos();
            VPoint point(pressPoint.x(), pressPoint.y());
            VPointGroupShape * pl;
            if(crPos == -1){
                if(focusShape != nullptr) finishFocusShape();
                pl = new VPolyline();
                pl->moveLoc(pl->transformPoint(getLoc(point)));
                focusShape = pl;
                updateList();
            }else{
                pl = dynamic_cast<VPointGroupShape *>(focusShape);
            }
            pl->addPoint(pl->transformPoint(getLoc((point))));
            crPos++;
            update();
            qDebug() << *pl;
        }break;
        case VCursorType::PEN:
        {
            finishFocusShape();
            QPainter painter(&canvas);
            if(antialiasing)painter.setRenderHint(QPainter::Antialiasing);
            painter.drawPoint(loc.toQPointF());
            update();
        }break;
        case VCursorType::PLUGIN:
        {
            finishFocusShape();
            focusShape=plugin->clone();
            focusShape->moveLoc(focusShape->transformPoint(loc));
            focusShape->changeMag(0,focusShape->transformPoint(loc+VPoint(1,1)),true);
            update();
        }break;
        case VCursorType::MARQUEE:
        {
            finishFocusShape();
            update();
        }break;
        default:
            break;
        }
        isPressing=true;
    }
    lastMove=vpoint;
    locMove=locPress=loc;
    globalMove=event->globalPos();
}

void ImageWidget::changeCursor(VCursorType type,VShape *plugin)
{
    PaintWidget::changeCursor(type,plugin);
    crPos=-1;
    if(type==VCursorType::MARQUEE)setCursor(Qt::ArrowCursor);
}

void ImageWidget::on_actionSelectAll_triggered()
{
    finishFocusShape();
    cutCanvas(0,0,canvas.width(),canvas.height(),Qt::transparent);
    update();
}

void ImageWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPoint qpoint=event->pos();
    VPoint vpoint(qpoint.x(), qpoint.y());
    VPoint loc = getLoc(vpoint);
    if(cursorType==VCursorType::CHOOSE)
    {
        if(focusShape!=nullptr)
        {
            if(focusShape->contains(focusShape->transformPoint(loc)))
            {
                finishFocusShape();
                setCursor(Qt::ArrowCursor);
                update();
            }
        }
    }
}

void ImageWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint qpoint=event->pos();
    VPoint vpoint(qpoint.x(), qpoint.y());
    VPoint loc = getLoc(vpoint);
    VPoint globalPoint(event->globalPos());
    mainwindow->statusBar()->showMessage(QString("%1,%2").arg(loc.x).arg(loc.y));

    if(cursorType == VCursorType::CHOOSE)
    {
        if(focusShape!=nullptr)
        {
            bool flag=true;
            if(crPos < 8 && (crPos >= 0 || (focusShape->atCrPoints(focusShape->transformPoint(loc),getScale()) != -1)))
            {
                this->setCursor(QCursor(VSizeAll, 15, 15));
                flag=false;
            }
            if(flag)
            {
                VPointGroupShape * pgs = dynamic_cast<VPointGroupShape *>(focusShape);
                if(crPos>=8||(pgs != nullptr && pgs->atPoints(pgs->transformPoint(loc),getScale()) != -1))
                {
                    this->setCursor(Qt::ArrowCursor);
                    flag=false;
                }
            }
            if(flag)
            {
                if((event->buttons()&Qt::LeftButton)||focusShape->contains(focusShape->transformPoint(loc)))
                    this->setCursor(Qt::SizeAllCursor);
                else this->setCursor(Qt::ArrowCursor);
            }
        }
        else this->setCursor(Qt::ArrowCursor);
    }

    if(event->buttons()&Qt::LeftButton)
    {
        switch(cursorType)
        {
        case VCursorType::MOVE:
        {
            scrollArea->horizontalScrollBar()->setValue(scrollArea->horizontalScrollBar()->value()+globalMove.x-globalPoint.x);
            scrollArea->verticalScrollBar()->setValue(scrollArea->verticalScrollBar()->value()+globalMove.y-globalPoint.y);
        }break;
        case VCursorType::CHOOSE:
        {
            if(focusShape!=nullptr)
            {
                VPoint lp = locMove;
                VPoint v(loc.x-lp.x, loc.y-lp.y);
                if(crPos == -2)
                {
                    //do nothing
                }
                else if(crPos == -1)
                {
                    focusShape->moveLoc(focusShape->transformPoint(v+focusShape->getLocation()));
                    this->setCursor(Qt::SizeAllCursor);
                }
                else if(crPos < 8)
                {
                    focusShape->changeMag(crPos, focusShape->transformPoint(loc), QApplication::keyboardModifiers() == Qt::ControlModifier);
                }
                else if(crPos >= 8)
                {
                    VPointGroupShape * shape=dynamic_cast<VPointGroupShape *>(focusShape);
                    if(shape!=nullptr)
                    {
                        shape->changePoint(crPos - 8, shape->transformPoint(loc));
                    }
                }
            }
            update();
        }break;
        case VCursorType::ROTATE:
        {
            if(focusShape!=nullptr)
            {
                VVector vlp(focusShape->getLocation(), locMove),
                        vnow(focusShape->getLocation(), loc);
                if(!(vlp==vnow))
                {
                    VPoint loc=focusShape->getLocation();
                    focusShape->getTransform().translate(
                                focusShape->getTransform().inverted().map(VPoint(0,0))
                                );
                    VTransform trans;
                    trans.rotate(VVector::rotationAngle(vlp, vnow));
                    focusShape->getTransform()*=trans;
                    focusShape->getTransform().translate(
                                focusShape->getTransform().inverted().map(loc)
                                );
                    update();
                }
            }
        }break;
        case VCursorType::PEN:
        {
            if(loc!=locMove)
            {
                finishFocusShape();
                QPainter painter(&canvas);
                if(antialiasing)painter.setRenderHint(QPainter::Antialiasing);
                painter.drawLine(locMove.toQPointF(),loc.toQPointF());
                update();
            }
        }break;
        case VCursorType::POLYLINE:
        {
            if(crPos > -1)
            {
                VPointGroupShape * shape=dynamic_cast<VPointGroupShape *>(focusShape);
                if(shape!=nullptr)
                {
                    int index = shape->getPointList().size() - 1;
                    if(index >= 0)
                        shape->changePoint(index, shape->transformPoint(loc));
                    update();
                }
            }

        }break;
        case VCursorType::PLUGIN:
        {
            if(focusShape!=nullptr)
            {
                focusShape->changeMag(0,focusShape->transformPoint(loc));
                update();
            }
        }break;
        case VCursorType::MARQUEE:
        {
            update();
        }break;
        default:
            break;
        }
    }
    locMove = loc;
    lastMove=vpoint;
    globalMove=globalPoint;
}

void ImageWidget::cutCanvas(int x,int y,int width,int height,const QColor &color)
{
    focusShape=new VImageShape(canvas.copy(x,y,width,height));
    VTransform trans;
    trans.translate(VPoint(floor(x+width/2.0),floor(y+height/2.0)));
    focusShape->setTransform(trans);
    //for(int i=x;i<x+width;i++)
      //  for(int j=y;j<y+height;j++)
        //    canvas.setPixelColor(i,j,color);
}

void ImageWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint qpoint=event->pos();
    VPoint loc=getLoc(VPoint(qpoint.x(),qpoint.y()));
    if(event->button()==Qt::LeftButton)
    {
        isPressing=false;
        switch(cursorType)
        {
        case VCursorType::MOVE:
        {
            this->setCursor(Qt::OpenHandCursor);
        }break;
        case VCursorType::CHOOSE:
        {
        }break;
        case VCursorType::ROTATE:
        {
        }break;
        case VCursorType::PEN:
        {
            saveSwp(tr("画笔"));
        }break;
        case VCursorType::PLUGIN:
        {
        }break;
        case VCursorType::MARQUEE:
        {
            VPoint a,b;
            a.x=std::min(loc.x,locPress.x);
            a.y=std::min(loc.y,locPress.y);
            b.x=std::max(loc.x,locPress.x);
            b.y=std::max(loc.y,locPress.y);
            if(a.x<canvas.width()&&b.x>=0&&a.y<canvas.height()&&b.y>=0)
            {
                a.x=std::max(a.x,0.0);a.y=std::max(a.y,0.0);
                b.x=std::min(b.x,(double)canvas.width());b.y=std::min(b.y,(double)canvas.height());
                if(a!=b)
                {
                    cutCanvas(a.x,a.y,b.x-a.x,b.y-a.y,Qt::transparent);
                    update();
                }
            }
        }break;
        default:
            break;
        }
    }
    if(cursorType != VCursorType::BEZIERCURVE && cursorType != VCursorType::POLYLINE)
        crPos = -1;
}

void ImageWidget::finishFocusShape()
{
    if(focusShape==nullptr)return;
    QPainter painter;
    painter.begin(&canvas);
    if(antialiasing)painter.setRenderHint(QPainter::Antialiasing);
    focusShape->draw(&painter,focusShape->getTransform());
    painter.end();
    if(pasting)saveSwp(tr("粘贴"));
    else if(focusShape->type()==VType::Image)saveSwp(tr("变换"));
    else saveSwp(tr("加入图形(")+focusShape->getName()+")");
    clearFocusShape();
}


void ImageWidget::clearFocusShape()
{
    if(focusShape==nullptr)return;
    delete focusShape;
    focusShape=nullptr;
    pasting=false;
}

bool ImageWidget::eventFilter(QObject * obj, QEvent * ev)
{
    QScrollArea *scrollArea=qobject_cast<QScrollArea*>(obj);
    if(scrollArea!=nullptr)
    {
        switch (ev->type()) {
        case QEvent::FocusIn:
        {
            qApp->postEvent(dock, new QFocusEvent(QEvent::FocusIn));
        }break;
        case QEvent::MouseMove:
        {
            QMouseEvent *event=static_cast<QMouseEvent*>(ev);
            QMouseEvent *newEvent=new QMouseEvent(event->type(),
                                                 this->mapFrom(scrollArea,event->pos()),
                                                 event->windowPos(),
                                                 event->screenPos(),
                                                 event->button(),
                                                 event->buttons(),
                                                 event->modifiers()                                                 );
            mouseMoveEvent(newEvent);
            delete newEvent;
        }break;
        case QEvent::Wheel:
        {
            QWheelEvent *event=static_cast<QWheelEvent*>(ev);
            QWheelEvent *newEvent=new QWheelEvent(QPointF(this->mapFrom(scrollArea,event->pos())),
                                           event->globalPosF(),
                                           event->pixelDelta(),
                                           event->angleDelta(),
                                           event->delta(),
                                           event->orientation(),
                                           event->buttons(),
                                           event->modifiers(),
                                           event->phase()
                               );
            if(!this->rect().contains(newEvent->pos())&&this->mapToGlobal(newEvent->pos())==newEvent->globalPos())wheelEvent(newEvent);
            delete newEvent;
        }break;
        case QEvent::KeyPress:
        {
            QKeyEvent *event=static_cast<QKeyEvent*>(ev);
            switch(event->key())
            {
            case Qt::Key_Space:
            case Qt::Key_Return:
                finishFocusShape();
                update();
                break;
            case Qt::Key_Escape:
                clearFocusShape();
                update();
                break;
            }
        }break;
        default:
            break;
        }
        return false;
    }
    if(qobject_cast<QScrollBar*>(obj)!=nullptr&&ev->type()==QEvent::Wheel)return true;
    return false;
}

void ImageWidget::saveSwp(QString name)
{
    swapQueue.push(canvas,name);
    updateList();
}

void ImageWidget::on_actionSaveAs_triggered()
{
    QString filename=getFileName();
    if(filename=="")filename="image.jpg";
    filename=
            QFileDialog::getSaveFileName(this,
                                         tr("保存文件"),
                                         filename,
                                         tr(
                                            "jpg file (*.jpg);;"
                                            "png file (*.png);;"
                                            "bmp file (*.bmp)"));
    saveFile(filename);
}

void ImageWidget::on_actionUndo_triggered()
{
    if(swapQueue.atFirst())return;
    clearFocusShape();
    canvas=swapQueue.undo();
    setScale(scale);
    update();
    emitSelected();
}

void ImageWidget::on_actionRedo_triggered()
{
    if(swapQueue.atLast())return;
    clearFocusShape();
    canvas=swapQueue.redo();
    setScale(scale);
    update();
    emitSelected();
}

void ImageWidget::on_actionSaveLabel_triggered()
{
    if(filename == "" || isPressing || focusShape == nullptr) return;
    QString label_filename = filename + ".txt";
    QFile label_file(label_filename);
    if (!label_file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QMessageBox::critical(NULL, "提示", "无法创建文件");
        return;
    }
    QTextStream ts(&label_file);
    auto points = focusShape->getSizeRect();
    VPoint p1 = focusShape->reverseTransformPoint(points[0]), p2 = focusShape->reverseTransformPoint(points[2]);
    int p_left = p2.x+0.5, p_top = p2.y+0.5, p_right = p1.x + 0.5, p_buttom = p1.y+0.5;
    qDebug() << p_left << p_top << p_right << p_buttom;
    ts << p_left << endl << p_top << endl << p_right << endl << p_buttom << endl;
    label_file.close();
}

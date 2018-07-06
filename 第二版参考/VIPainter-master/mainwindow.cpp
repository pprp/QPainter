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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vdocktitlebar.h"
#include "vtype.h"
#include "canvassizedialog.h"
#include "vtransform.h"
#include "vtext.h"
#include <QJsonDocument>
#include <QApplication>
#include <QJsonObject>
#include <QFile>
#include <QScrollArea>
#include <QDockWidget>
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QString>
#include <QFileDialog>
#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QAction>
#include <QIcon>
#include <QList>
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>
#include <QContextMenuEvent>
#include <QMimeData>
#include <QUrl>
#include <QToolButton>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),focus(nullptr),cursorState(VCursorType::CHOOSE)
{
    ui->setupUi(this);
    delete takeCentralWidget();//去掉中心控件
    setDockNestingEnabled(true);//设置DOCK可随意移动
    //shapeBar
    ui->shapeBar->installEventFilter(this);//注册过滤器

    this->setContextMenuPolicy(Qt::NoContextMenu);//取消右键菜单
    ui->menuTools->addAction(ui->mainToolBar->toggleViewAction());
    ui->menuTools->addAction(ui->shapeBar->toggleViewAction());
    ui->menuTools->addAction(ui->shapesDock->toggleViewAction());
    setWindowTitle("VIPainter");
    ui->shapesDock->hide();

    //工具栏编组 bar group
    barGroup = new QActionGroup(this);
    barGroup->addAction(ui->actionChoose);
    barGroup->addAction(ui->actionMarquee);
    barGroup->addAction(ui->actionMove);
    barGroup->addAction(ui->actionRotate);
    barGroup->addAction(ui->actionPen);
    barGroup->addAction(ui->actionCurveLine);
    barGroup->addAction(ui->actionPolyLine);
    connect(this, SIGNAL(cursorChange(VCursorType,VShape*)), this, SLOT(changeCursor(VCursorType,VShape*)));
    QTimer::singleShot(0,this,[this]{
#if defined(Q_OS_LINUX)
        initAction(QDir("/usr/share/VIPainter/plugin"));
#endif
        initAction();
    });

    //List View init
    listView=new VListView(this);
    ui->shapesDock->setWidget(listView);
    delegate=new VDelegate(this);
    listView->setItemDelegate(delegate);

    //contextMenu init
    contextMenu=new QMenu(this);
    contextMenu->addAction(ui->actionSelectAll);
    contextMenu->addAction(ui->actionCanvasSize);
    contextMenu->addSeparator();
    contextMenu->addAction(ui->actionCopy);
    contextMenu->addAction(ui->actionCut);
    contextMenu->addAction(ui->actionPaste);
    contextMenu->addAction(ui->actionDelete);
    contextMenu->addSeparator();
    contextMenu->addAction(ui->actionPenColor);
    contextMenu->addAction(ui->actionPenStyle);
    contextMenu->addAction(ui->actionBrushColor);
    contextMenu->addSeparator();
    contextMenu->addAction(ui->actionGroup);
    contextMenu->addAction(ui->actionForceGroup);
    contextMenu->addAction(ui->actionBreakUp);

    //open file in arguments
    QTimer::singleShot(0,[this]{
        QStringList files=QApplication::arguments();
        files.erase(files.begin());
        for(QString filename:files)openFile(filename);
    });

    update();
}

void MainWindow::loadPlugin(QString filename)
{
    ui->statusBar->showMessage(tr("加载插件 ")+filename);
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|QFile::Text))return;
    QJsonDocument doc=QJsonDocument::fromJson(file.readAll());
    file.close();
    VShape *shape=nullptr;
    if(doc.isObject()&&doc.object().value("type")==QString("canvas"))
    {
        doc.setArray(doc.object().value("shapes").toArray());
    }
    if(doc.isArray())
    {
        VGroupShape *groupshape=new VGroupShape(doc.array());
        groupshape->getCircumscribedRectangle(true);
        shape=groupshape;
        if(groupshape->getShapes().size()==1)shape=VGroupShape::breakUp(groupshape).first();
    }
    else if(doc.isObject())shape=VShape::fromJsonObject(doc.object());
    else ui->statusBar->showMessage(tr("加载插件 ")+filename+" 失败");
    if(shape==nullptr)return;
    if(shape->getName()==QString(""))shape->setName(filename.split('/').back().split('.').first());
    plugins.append(shape);
    QAction *action=new QAction(ui->shapeBar);
    action->setCheckable(true);
    barGroup->addAction(action);

    const int SIZE=30;
    VSize size=shape->getSize();
    VMagnification mag;
    if(size.width>size.height)mag=SIZE/size.width;
    else mag=SIZE/size.height;

    QPixmap pixmap(SIZE,SIZE);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.translate(SIZE/2,SIZE/2);
    painter.setRenderHint(QPainter::Antialiasing);
    VTransform transform;
    transform.scale(mag);
    shape->draw(&painter,transform);

    action->setIcon(QIcon(pixmap));
    action->setToolTip(shape->getName());
    ui->shapeBar->addAction(action);

    connect(action,&QAction::triggered,[this,action,shape]{
        if(action->isChecked())
            emit cursorChange(VCursorType::PLUGIN,shape);
        else
            emit cursorChange(VCursorType::DEFAULT);
    });
}

void MainWindow::initAction(QDir dir)
{
    if(!dir.exists())return;
    dir.setFilter(QDir::Files|QDir::Readable);
    dir.setNameFilters(QStringList()<<"*.json"<<"*.JSON");
    QStringList files=dir.entryList();
    for(auto i:files)
    {
        loadPlugin(dir.filePath(i));
    }

}

ImageWidget *MainWindow::newImageWidget()
{
    ImageWidget* widget=new ImageWidget(this,ui->actionAntialiasing->isChecked());
    connect(ui->actionAntialiasing,SIGNAL(triggered(bool)),widget,SLOT(on_actionAntialiasing_toggled(bool)));
    connect(this, SIGNAL(cursorChange(VCursorType,VShape*)), widget, SLOT(changeCursor(VCursorType,VShape*)));
    widget->changeCursor(this->cursorState,this->plugin);
    widget->installEventFilter(this);

    return widget;
}

VectorgraphWidget* MainWindow::newVectorgraphWidget()
{
    VectorgraphWidget* widget=new VectorgraphWidget(this,ui->actionAntialiasing->isChecked());
    connect(ui->actionAntialiasing,SIGNAL(triggered(bool)),widget,SLOT(on_actionAntialiasing_toggled(bool)));
    connect(this, SIGNAL(cursorChange(VCursorType,VShape*)), widget, SLOT(changeCursor(VCursorType,VShape*)));
    widget->changeCursor(this->cursorState,this->plugin);
    widget->installEventFilter(this);

    connect(widget,&PaintWidget::selected,[this,widget]{
        if(widget==getPaintWidget())
        {
            changeMenuAction(widget,true);
        }
    });

    return widget;
}

QDockWidget* MainWindow::newDock(QWidget *widget, QString dockname)
{
    QDockWidget *old = focus;

    static int id = 0;

    QDockWidget *dockWidget=new QDockWidget;
    dockWidget->installEventFilter(widget);
    dockWidget->setWidget(widget);
    //dockWidget->setAttribute(Qt::WA_DeleteOnClose);
    this->addDockWidget(Qt::TopDockWidgetArea,dockWidget);

    dockWidget->setFocusPolicy(Qt::StrongFocus);
    dockWidget->installEventFilter(this);

    dockWidget->show();
    if(old != nullptr && !old->isFloating())
    {
        this->tabifyDockWidget(old, dockWidget);
    }
    else
    {
        for(auto it: docks)
        {
            if(!it->isFloating())
            {
                this->tabifyDockWidget(it, dockWidget);
            }
        }
    }

    this->focusDock(dockWidget);

    connect(dockWidget,SIGNAL(visibilityChanged(bool)),this,SLOT(focusDock(bool)));

    if(dockname=="")dockWidget->setWindowTitle(QString("untitled %1 - ").arg(id++) + widget->windowTitle());
    else dockWidget->setWindowTitle(dockname);
    docks.push_back(dockWidget);

    if(!ui->shapesDock->isVisible())
    {
        ui->shapesDock->show();
        splitDockWidget(dockWidget,ui->shapesDock,Qt::Horizontal);
    }
    return dockWidget;
}

MainWindow::~MainWindow()
{
    for(auto &i:plugins)delete i;
    delete ui;
}

void MainWindow::on_actionZoomIn_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionZoomOut_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionResume_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionSave_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionSaveAs_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

bool MainWindow::openFile(QString filename)
{
    if(filename=="")return false;
    bool flag=false;
    for(auto &dock:docks)
    {
        PaintWidget *widget=getPaintWidget(dock);
        if(widget->getFileName()==filename)
        {
            focusDock(dock);
            flag=true;
        }
    }
    if(flag)return false;
    ui->statusBar->showMessage(tr("打开文件 ")+filename);
    QString format=filename.split('.').back().toUpper();
    if(format=="JPG"||format=="PNG"||format=="BMP")
    {
        ImageWidget *widget=newImageWidget();
        widget->setFileName(filename);
        widget->setCanvas(QImage(filename));
        widget->setDock(newDock(widget->getScrollArea(),filename.split("/").back() + " - " + widget->windowTitle()));
        //widget->getScrollArea()->update();
        widget->saveSwp(tr("打开"));
        widget->update();
    }
    else
    {
        QFile file(filename);
        if(!file.open(QFile::ReadOnly|QFile::Text))return false;
        QJsonDocument doc=QJsonDocument::fromJson(file.readAll());
        file.close();
        if(!doc.isArray()&&!doc.isObject())
        {
            QMessageBox::warning(this,tr("错误"),tr("打开文件 ")+filename+tr("失败"));
            return false;
        }
        VectorgraphWidget *widget=newVectorgraphWidget();
        widget->setDock(newDock(widget,filename.split("/").back() + " - " + widget->windowTitle()));
        if(doc.isObject()&&doc.object().value("type")==QString("canvas"))
        {
            widget->setCanvasSize(doc.object().value("size").toObject());
            doc.setArray(doc.object().value("shapes").toArray());
        }
        if(doc.isArray())widget->groupShape=doc.array();
        else if(doc.isObject())
        {
            widget->groupShape.insertShape(VShape::fromJsonObject(doc.object()));
        }
        widget->setFileName(filename);
        widget->saveSwp();
        widget->update();
        return true;
    }
    return false;
}

void MainWindow::on_actionOpen_triggered()
{
    QStringList filenames=
            QFileDialog::getOpenFileNames(this,
                                         tr("打开文件"),
                                         tr(""),
                                         tr("json file (*.json);;"
                                            "jpg file (*.jpg);;"
                                            "bmp file (*.bmp);;"
                                            "png file (*.png);;"
                                            "all (*)"));
    for(auto &filename:filenames)openFile(filename);
}

void MainWindow::on_actionMove_triggered()
{
    if(ui->actionMove->isChecked())
        emit cursorChange(VCursorType::MOVE);
    else
        emit cursorChange(VCursorType::DEFAULT);
}

void MainWindow::on_actionChoose_triggered()
{
    if(ui->actionChoose->isChecked())
        emit cursorChange(VCursorType::CHOOSE);
    else
        emit cursorChange(VCursorType::DEFAULT);
}

void MainWindow::changeCursor(VCursorType type, VShape *plugin)
{
    this->plugin=plugin;
    cursorState = type;
    if(qobject_cast<VectorgraphWidget*>(getPaintWidget())!=nullptr)changeMenuAction(qobject_cast<VectorgraphWidget*>(getPaintWidget()),true);

}

void MainWindow::on_actionNew_triggered()
{
    VectorgraphWidget *widget=newVectorgraphWidget();
    widget->setDock(newDock(widget));
    if(widget)widget->saveSwp();
    widget->update();
}

//判断Action的显示状态
void MainWindow::changeMenuAction(VectorgraphWidget *widget,bool flag)
{
    ui->actionResume->setVisible(true);
    ui->actionSave->setVisible(true);
    ui->actionSaveAs->setVisible(true);
    ui->actionCanvasSize->setVisible(true);
    ui->actionShapeSize->setVisible(true);
    ui->actionBreakUp->setVisible(true);
    ui->actionSelectAll->setVisible(true);
    if(widget==nullptr||widget->focusShapes.empty())
    {
        ui->actionPenColor->setVisible(false);
        ui->actionPenStyle->setVisible(false);
        ui->actionBrushColor->setVisible(false);
        ui->actionGroup->setVisible(false);
        ui->actionForceGroup->setVisible(false);
        ui->actionBreakUp->setVisible(false);
    }
    else
    {
        if(flag)
        {
            ui->actionPenColor->setVisible(true);
            ui->actionPenStyle->setVisible(true);
            ui->actionBrushColor->setVisible(true);
            ui->actionGroup->setVisible(true);
            ui->actionForceGroup->setVisible(true);
            ui->actionBreakUp->setVisible(true);
        }
        else
        {
            ui->actionPenColor->setVisible(false);
            ui->actionPenStyle->setVisible(false);
            ui->actionBrushColor->setVisible(false);
            ui->actionGroup->setVisible(false);
            ui->actionForceGroup->setVisible(false);
            ui->actionBreakUp->setVisible(false);
        }
    }
    ////////////////////////////////////////////////////
    if(cursorState == VCursorType::BEZIERCURVE || cursorState == VCursorType::POLYLINE || cursorState == VCursorType::PEN)
    {
        ui->actionDelete->setEnabled(false);
        ui->actionPaste->setEnabled(false);
        ui->actionCopy->setEnabled(false);
        ui->actionCut->setEnabled(false);
        ui->actionRedo->setEnabled(false);
        ui->actionUndo->setEnabled(false);
        ui->actionGroup->setEnabled(false);
        ui->actionForceGroup->setEnabled(false);
        ui->actionBreakUp->setEnabled(false);
        ui->actionSelectAll->setEnabled(false);
    }
    else
    {
        ui->actionDelete->setEnabled(true);
        ui->actionPaste->setEnabled(true);
        ui->actionCopy->setEnabled(true);
        ui->actionCut->setEnabled(true);
        ui->actionRedo->setEnabled(true);
        ui->actionUndo->setEnabled(true);
        ui->actionGroup->setEnabled(true);
        ui->actionForceGroup->setEnabled(true);
        ui->actionBreakUp->setEnabled(true);
        ui->actionSelectAll->setEnabled(true);
    }
    ////////////////////////////////////////////////////
    if(widget==nullptr||widget->focusShapes.empty())
    {
        ui->actionCopy->setEnabled(false);
        ui->actionCut->setEnabled(false);
        ui->actionDelete->setEnabled(false);
    }
    else
    {
        ui->actionCopy->setEnabled(true);
        ui->actionCut->setEnabled(true);
        ui->actionDelete->setEnabled(true);
        if(flag)
        {
            if(widget->focusShapes.size()==1
                    &&widget->focusShapes.first()->type()==VType::Group)
            {
                ui->actionBreakUp->setEnabled(true);
            }
            else ui->actionBreakUp->setEnabled(false);
        }
    }
}

bool MainWindow::closeWidget(PaintWidget *widget)
{
    if(widget->fileChanged())
    {
        int button
                =QMessageBox::information(this,tr("退出"),
                                          widget->parentWidget()->windowTitle()+tr("已修改,是否在退出之前保存文件?"),
                                          QMessageBox::Cancel,QMessageBox::No,QMessageBox::Yes);
        if(button==QMessageBox::Yes)widget->on_actionSave_triggered();
        else if(button!=QMessageBox::No)
        {
            return false;
        }
    }
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    bool flag=true;
    for(auto &dock:docks)
    {
        PaintWidget *widget=getPaintWidget(dock);
        if(!closeWidget(widget))flag=false;
    }
    if(!flag)
    {
        event->ignore();
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
        event->acceptProposedAction(); //可以在这个窗口部件上拖放对象
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        QList<QUrl> files(event->mimeData()->urls());
        if(ui->shapeBar->rect().contains(event->pos()))
        {
            for(QUrl fileurl:files)
            {
                loadPlugin(fileurl.toLocalFile());
            }
        }
        else
        {
            for(QUrl fileurl:files)
            {
                openFile(fileurl.toLocalFile());
            }
        }
    }
}

bool MainWindow::eventFilter(QObject * obj, QEvent * ev)
{
    switch(ev->type())
    {
    case QEvent::FocusIn:
    {
        QDockWidget *dock=qobject_cast<QDockWidget*>(obj);
        if(dock!=nullptr)
        {
            PaintWidget *widget=getPaintWidget(dock);
            disconnect(delegate,0,0,0);
            connect(delegate,SIGNAL(dataChanged(const QModelIndex &)),widget,SLOT(changeModelData(const QModelIndex &)));
#define KCONNECT(action) disconnect(ui->action,0,0,0),\
                            connect(ui->action,SIGNAL(triggered()),widget,SLOT(on_##action##_triggered()))
            KCONNECT(actionZoomIn);
            KCONNECT(actionZoomOut);
            KCONNECT(actionResume);
            KCONNECT(actionSave);
            KCONNECT(actionSaveAs);
            KCONNECT(actionCanvasSize);
            KCONNECT(actionShapeSize);
            KCONNECT(actionBreakUp);
            KCONNECT(actionRedo);
            KCONNECT(actionUndo);
            KCONNECT(actionDelete);
            KCONNECT(actionCopy);
            KCONNECT(actionCut);
            KCONNECT(actionPaste);
            KCONNECT(actionGroup);
            KCONNECT(actionSelectAll);
            KCONNECT(actionBrushColor);
            KCONNECT(actionPenColor);
            KCONNECT(actionPenStyle);
            KCONNECT(actionForceGroup);
#undef KCONNECT

            focus = dock;
            listView->setModel(widget->listModel);
            listView->setSelectionModel(widget->selectionModel);
            widget->updateList();
            VectorgraphWidget *vectorgraphWidget=qobject_cast<VectorgraphWidget *>(widget);
            if(vectorgraphWidget!=nullptr)
            {
                listView->setSelectionMode(QListView::ExtendedSelection);
                listView->setEditTriggers(QListView::DoubleClicked);
                changeMenuAction(vectorgraphWidget,true);
            }
            else
            {
                listView->setSelectionMode(QListView::SingleSelection);
                listView->setEditTriggers(QListView::NoEditTriggers);
                ui->actionDelete->setEnabled(true);
                ui->actionPaste->setEnabled(true);
                ui->actionCopy->setEnabled(true);
                ui->actionCut->setEnabled(true);
                ui->actionRedo->setEnabled(true);
                ui->actionUndo->setEnabled(true);
                ui->actionSelectAll->setEnabled(true);
            }
            return false;
        }
    }break;
    case QEvent::Close:
    {
        auto it=std::find(docks.begin(),docks.end(),obj);
        if(it!=docks.end())
        {
            PaintWidget *widget=getPaintWidget(*it);
            if(!closeWidget(widget))
            {
                ev->ignore();
                return true;
            }
            (*it)->deleteLater();
            docks.erase(it);
            if(!docks.empty())
            {
                this->focusDock(docks.back());
            }
            else if(ui->shapesDock->isVisible())ui->shapesDock->hide();
            focus = nullptr;
            return true;
        }
    }break;
    case QEvent::ContextMenu:
    {
        if(cursorState != VCursorType::BEZIERCURVE && cursorState != VCursorType::POLYLINE && cursorState != VCursorType::PEN)
        {
            QContextMenuEvent *event=static_cast<QContextMenuEvent*>(ev);
            VectorgraphWidget *widget=qobject_cast<VectorgraphWidget*>(obj);
            if(widget!=nullptr)
            {
                contextMenu->exec(event->globalPos());
                return true;
            }
        }
    }break;
    case QEvent::Drop:
    {
        dropEvent(static_cast<QDropEvent*>(ev));
        return false;
    }break;
    case QEvent::DragEnter:
    {
        dragEnterEvent(static_cast<QDragEnterEvent*>(ev));
        return false;
    }break;
    default:
        break;
    }

    return false;
}


void MainWindow::focusDock(bool checked)
{
    if(checked)
    {
        focusDock(qobject_cast<QDockWidget*>(sender()));
    }
}

void MainWindow::focusDock(QDockWidget * target)
{
    if(target==nullptr)return;
    target->raise();
    target->setFocus();
    qApp->postEvent(target, new QFocusEvent(QEvent::FocusIn));
//    qDebug() << "focusing";
//    focus = target;
}

void MainWindow::on_actionCanvasSize_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionShapeSize_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

PaintWidget * MainWindow::getPaintWidget()
{
    return getPaintWidget(focus);
}

PaintWidget * MainWindow::getPaintWidget(QDockWidget *target)
{
    if(target==nullptr)return nullptr;
    QScrollArea *scrollArea=qobject_cast<QScrollArea *>(target->widget());
    if(scrollArea!=nullptr)return qobject_cast<PaintWidget *>(scrollArea->widget());
    return qobject_cast<PaintWidget *>(target->widget());
}

void MainWindow::on_actionBreakUp_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionRotate_triggered()
{
    if(ui->actionRotate->isChecked())
        emit cursorChange(VCursorType::ROTATE);
    else
        emit cursorChange(VCursorType::DEFAULT);

}

void MainWindow::on_actionRedo_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionReloadPlugon_triggered()
{
    ui->actionChoose->trigger();
    for(auto &i:ui->shapeBar->actions())
    {
        delete i;
    }
    for(auto &i:plugins)delete i;
    plugins.clear();
#if defined(Q_OS_LINUX)
        initAction(QDir("/usr/share/VIPainter/plugin"));
#endif
    this->initAction();
}

void MainWindow::on_actionLoadExPlugin_triggered()
{
    QStringList filenames=
            QFileDialog::getOpenFileNames(this,
                                         tr("打开文件"),
                                         tr(""),
                                         tr("json file (*.json);;"
                                            "all (*)"));
    for(auto &filename:filenames)loadPlugin(filename);
}

void MainWindow::on_actionAntialiasing_toggled(bool antialiasing)
{
    Q_UNUSED(antialiasing);
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionDelete_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionClose_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionCopy_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionCut_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionPaste_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionGroup_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionSelectAll_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionBrushColor_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionPenColor_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionPenStyle_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,tr("关于VIPainter")
                             ,tr("VIPainter是一款轻量的矢量图绘图软件\n"
                                 "\n"
                                 "版权所有(C) 2017 VIPainter\n"
                                 "本程序为自由软件；您可依据自由软件基金会所发表的GNU通用公共授权条款，对本程序再次发布和/或修改；无论您依据的是本授权的第三版，或（您可选的）任一日后发行的版本。\n"
                                 "本程序是基于使用目的而加以发布，然而不负任何担保责任；亦无对适售性或特定目的适用性所为的默示性担保。详情请参照GNU通用公共授权。\n"
                                 "您应已收到附随于本程序的GNU通用公共授权的副本；如果没有，请参照\n"
                                 "<http://www.gnu.org/licenses/>.\n"));
}

void MainWindow::on_actionPen_triggered()
{
    if(ui->actionPen->isChecked())
        emit cursorChange(VCursorType::PEN);
    else
        emit cursorChange(VCursorType::DEFAULT);
}

void MainWindow::on_actionUndo_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionCurveLine_triggered()
{
    if(ui->actionCurveLine->isChecked())
        emit cursorChange(VCursorType::BEZIERCURVE);
    else
        emit cursorChange(VCursorType::DEFAULT);
}

void MainWindow::on_actionPolyLine_triggered()
{
    if(ui->actionPolyLine->isChecked())
        emit cursorChange(VCursorType::POLYLINE);
    else
        emit cursorChange(VCursorType::DEFAULT);
}

void MainWindow::on_actionForceGroup_triggered()
{
    //Do nothing
    //Edit in PaintWidget
}

void MainWindow::on_actionTest_triggered()
{
    //this is used to test
    //do whatever you want
    ui->shapeBar->show();
}

void MainWindow::on_actionNewImage_triggered()
{
    ImageWidget *widget=newImageWidget();
    QImage image(800,600,QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::white);
    widget->setCanvas(std::move(image));
    widget->setDock(newDock(widget->getScrollArea()));
    //widget->getScrollArea()->update();
    widget->saveSwp(tr("新建"));
    widget->update();
}

void MainWindow::on_actionMarquee_triggered()
{
    if(ui->actionMarquee->isChecked())
        emit cursorChange(VCursorType::MARQUEE);
    else
        emit cursorChange(VCursorType::DEFAULT);
}

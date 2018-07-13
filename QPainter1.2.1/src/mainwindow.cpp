#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSvgGenerator>
#include <QFileDialog>
#include <QDebug>
#include <QGraphicsItem>
#include <QMessageBox>
#include "svgreader.h"
#include "veworkplace.h"
#include "vepolyline.h"
#include "verectangle.h"
#include "veellipse.h"
#include "vebasicshapeitem.h"
#include "vecomplexshapeitem.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    workplaceScene = new VEWorkplace(this);
    workplaceScene->setSceneRect(0,0,1000,1000);
    ui->workplaceView->setScene(workplaceScene);
    ui->workplaceView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->workplaceView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->workplaceView->setDragMode(QGraphicsView::RubberBandDrag);
    ui->workplaceView->setCursor(QCursor());
    ui->splitter->setStretchFactor(0,0);
    ui->splitter->setStretchFactor(1,1);
    ui->rectangleSettings->setVisible(false);
    ui->polylineSettings->setVisible(false);
    ui->ellipseSettings->setVisible(false);

    connect(ui->butLine, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(VEWorkplace::LineType);});
    connect(ui->butRectangle, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(VEWorkplace::RectangleType);});
    connect(ui->butDefault, &QToolButton::clicked, [=](){workplaceScene->setCurrentAction(VEWorkplace::DefaultType);});
    connect(ui->toolButton_ellipse,&QToolButton::clicked,[=](){workplaceScene->setCurrentAction(VEWorkplace::EllipseType);});
    connect(workplaceScene, &VEWorkplace::selectionChanged, this, &MainWindow::checkSelection);
    connect(workplaceScene, &VEWorkplace::currentActionChanged, this, &MainWindow::checkActionStates);
    connect(workplaceScene, &VEWorkplace::signalSelectItem, this, &MainWindow::selectItem);
    connect(workplaceScene, &VEWorkplace::signalNewSelectItem, this, &MainWindow::selectNewItem);

    //创建背景
    QPolygonF myPolygon1;
    myPolygon1 << QPointF(0,10) << QPointF(20,10);
    QPolygonF myPolygon2;
    myPolygon2 << QPointF(10,0) << QPointF(10,20);
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);

    QVector<qreal> dashes;//line style--虚线
    qreal space = 3;
    dashes << 3 << space << 3 <<space;
    QPen pen(Qt::lightGray,1);
    pen.setDashPattern(dashes);
    pen.setWidth(0.1);

    painter.setPen(pen);
    painter.translate(0, 0);
    painter.drawPolyline(myPolygon1);
    painter.drawPolyline(myPolygon2);
    workplaceScene->setBackgroundBrush(pixmap);


    //时间部分
    currentTimeLabel=new QLabel;
    timer=new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));

    //Home
    judge = false;
    judge1 = false;
    record = 0;
    record1 = 0;
}
//滚轮的放缩
void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        workplaceScene->views()[0]->scale(1.2,1.2);
    }
    else
    {
        workplaceScene->views()[0]->scale(1/1.2,1/1.2);
    }
}

void MainWindow::timeUpdate()
{
    QDateTime CurrentTime=QDateTime::currentDateTime();
    QString TimeStr = CurrentTime.toString(trUtf8("yyyy年-MM月-dd日 hh:mm:ss "));
    currentTimeLabel->setText(TimeStr);
    ui->statusBar->addWidget(currentTimeLabel);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete workplaceScene;
}

void MainWindow::on_butSave_clicked()
{
    QString newPath = QFileDialog::getSaveFileName(this, trUtf8("保存照片"),
                                                   path, tr("SVG files (*.svg *.png *.bmp *.jpg)"));
    if (newPath.isEmpty())
        return;

    path = newPath;

    QSvgGenerator generator;
    generator.setFileName(path);
    generator.setSize(QSize(workplaceScene->width(), workplaceScene->height()));
    generator.setViewBox(QRect(0, 0, workplaceScene->width(), workplaceScene->height()));
    generator.setTitle(trUtf8("QPainter v1.1.0"));
    generator.setDescription(trUtf8("File created by QPainter"));

    QPainter painter;
    painter.begin(&generator);
    workplaceScene->render(&painter);
    painter.end();
}

void MainWindow::on_butOpen_clicked()
{
    QString newPath = QFileDialog::getOpenFileName(this, trUtf8("打开文件"),
                                                   path, tr("Image files (*.svg)"));
    if (newPath.isEmpty())
        return;
    path = newPath;
    workplaceScene->clear();

    workplaceScene->setSceneRect(SvgReader::getSizes(path));

    foreach (QGraphicsItem *item, SvgReader::getElements(path)) {
        switch (item->type()) {
        case QGraphicsPathItem::Type: {
            VEPolyline *polyline = qgraphicsitem_cast<VEPolyline*>(item);
            workplaceScene->addItem(polyline);
            connect(polyline, &VEPolyline::clicked, workplaceScene, &VEWorkplace::signalSelectItem);
            connect(polyline, &VEPolyline::signalMove, workplaceScene, &VEWorkplace::slotMove);
            break;
        }
        case QGraphicsRectItem::Type: {
            VERectangle *rect = qgraphicsitem_cast<VERectangle*>(item);
            workplaceScene->addItem(rect);
            connect(rect, &VERectangle::clicked, workplaceScene, &VEWorkplace::signalSelectItem);
            connect(rect, &VERectangle::signalMove, workplaceScene, &VEWorkplace::slotMove);
            break;
        }
        case QGraphicsEllipseItem::Type:{
            VEEllipse *rect = qgraphicsitem_cast<VEEllipse*>(item);
            workplaceScene->addItem(rect);
            connect(rect, &VEEllipse::clicked, workplaceScene, &VEWorkplace::signalSelectItem);
            connect(rect, &VEEllipse::signalMove, workplaceScene, &VEWorkplace::slotMove);
            break;
        }
        default:
            break;
        }
    }
}

void MainWindow::checkSelection()
{
    checkActionStates();
    switch (workplaceScene->selectedItems().length()) {
    case 0:
        ui->rectangleSettings->deselect();
        ui->polylineSettings->deselect();
        ui->ellipseSettings->deselect();
        checkActionStates();
        ui->toolsWidget->setEnabled(true);
        break;
    case 1:
        switch (workplaceScene->selectedItems().at(0)->type()) {
        case QGraphicsRectItem::Type:{
            ui->rectangleSettings->setVisible(true);
            ui->polylineSettings->deselect();
            ui->ellipseSettings->deselect();
            ui->ellipseSettings->setVisible(false);
            ui->polylineSettings->setVisible(false);
            break;
        }
        case QGraphicsEllipseItem::Type:{
            ui->ellipseSettings->setVisible(true);
            ui->polylineSettings->deselect();
            ui->rectangleSettings->deselect();
            ui->rectangleSettings->setVisible(false);
            ui->polylineSettings->setVisible(false);
            break;
        }
        default: {
            ui->rectangleSettings->deselect();
            ui->rectangleSettings->setVisible(false);
            ui->ellipseSettings->deselect();
            ui->ellipseSettings->setVisible(false);
            ui->polylineSettings->setVisible(true);
            break;
        }
        }
        checkActionStates();
        ui->toolsWidget->setEnabled(true);
        break;
    default:
        ui->rectangleSettings->deselect();
        ui->polylineSettings->deselect();
        ui->ellipseSettings->deselect();
        ui->toolsWidget->setEnabled(false);
        break;
    }
}


void MainWindow::checkActionStates()
{
    ui->workplaceView->setDragMode(QGraphicsView::NoDrag);
    ui->rectangleSettings->setVisible(false);
    ui->polylineSettings->setVisible(false);
    ui->ellipseSettings->setVisible(false);
    switch (workplaceScene->currentAction()){
    case VEWorkplace::LineType:
        ui->polylineSettings->setVisible(true);
        break;
    case VEWorkplace::RectangleType:
        ui->rectangleSettings->setVisible(true);
        break;
    case VEWorkplace::EllipseType:
        ui->ellipseSettings->setVisible(true);
        break;
    case VEWorkplace::SelectionType:
        break;
    default:
        ui->workplaceView->setDragMode(QGraphicsView::ScrollHandDrag);
        break;
    }
}

void MainWindow::selectItem(QGraphicsItem *item)
{
    switch (item->type()) {
    case QGraphicsRectItem::Type: {
        VERectangle *rect = qgraphicsitem_cast<VERectangle *>(item);
        ui->rectangleSettings->loadRectangle(rect);
        break;
    }
    case QGraphicsPathItem::Type: {
        VEPolyline *polyline = qgraphicsitem_cast<VEPolyline *>(item);
        ui->polylineSettings->loadPolyline(polyline);
        break;
    }
    case QGraphicsEllipseItem::Type:{
        VEEllipse *elli = qgraphicsitem_cast<VEEllipse *>(item);
        ui->ellipseSettings->loadEllipse(elli);
        break;
    }
    default:
        break;
    }
}

void MainWindow::selectNewItem(QGraphicsItem *item)
{
    switch (item->type()) {
    case QGraphicsRectItem::Type: {
        VERectangle *rect = qgraphicsitem_cast<VERectangle *>(item);
        ui->rectangleSettings->newRectangle(rect);
        break;
    }
    case QGraphicsPathItem::Type: {
        VEPolyline *polyline = qgraphicsitem_cast<VEPolyline *>(item);
        ui->polylineSettings->newPolyline(polyline);
        break;
    }
    case QGraphicsEllipseItem::Type:{
        VEEllipse *ellipse = qgraphicsitem_cast<VEEllipse *>(item);
        ui->ellipseSettings->newEllipse(ellipse);
        break;
    }
    default:
        break;
    }
}

void MainWindow::saveAs()
{    
    QString newPath = QFileDialog::getSaveFileName(this, trUtf8("另存为"),
                                                   path, tr("SVG files (*.svg)"));
    if (newPath.isEmpty())
        return;
    path = newPath;
    QSvgGenerator generator;
    generator.setFileName(path);
    generator.setSize(QSize(workplaceScene->width(), workplaceScene->height()));
    generator.setViewBox(QRect(0, 0, workplaceScene->width(), workplaceScene->height()));
    generator.setTitle(trUtf8("QPainter"));
    generator.setDescription(trUtf8("File created by QPainter."));
    QPainter painter;
    painter.begin(&generator);
    workplaceScene->render(&painter);
    painter.end();
}

void MainWindow::newFile()
{
    this->saveAs();
    workplaceScene->clear();
}

void MainWindow::open()
{
    this->on_butOpen_clicked();
}

void MainWindow::clear()
{
    workplaceScene->clear();
}

void MainWindow::selectAll()
{
    workplaceScene->selectionArea();
}

void MainWindow::on_actionExit_triggered()
{
    this->saveAs();
    this->close();
}

void MainWindow::save()
{
    this->saveAs();
}

void MainWindow::on_toolButton_SaveAs_clicked()
{
    this->saveAs();
}

void MainWindow::on_toolButton_ZoomIn_clicked()
{
    workplaceScene->views()[0]->scale(1.2,1.2);
    record++;
    judge = true;
}

void MainWindow::on_toolButton_ZoomOut_clicked()
{
    workplaceScene->views()[0]->scale(1/1.2,1/1.2);
    record1++;
    judge1 = true;
}

void MainWindow::on_toolButton_text_clicked()
{
    txtItem = new TextItem();
    workplaceScene->addItem(txtItem);
}

void MainWindow::on_actionNew_triggered()
{
    this->saveAs();
    this->clear();
}

void MainWindow::on_toolButton_clear_clicked()
{
    while(workplaceScene->items().count()>0)
    {
        workplaceScene->removeItem(workplaceScene->items()[0]);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString newPath = QFileDialog::getOpenFileName(this, trUtf8("打开文件"),
                                                   path, tr("Image files (*.svg *.png *.jpg *.bmp)"));
    if (newPath.isEmpty())
        return;

    path = newPath;
    workplaceScene->clear();

    workplaceScene->setSceneRect(SvgReader::getSizes(path));

    foreach (QGraphicsItem *item, SvgReader::getElements(path)) {
        switch (item->type()) {
        case QGraphicsPathItem::Type: {
            VEPolyline *polyline = qgraphicsitem_cast<VEPolyline*>(item);
            workplaceScene->addItem(polyline);
            connect(polyline, &VEPolyline::clicked, workplaceScene, &VEWorkplace::signalSelectItem);
            connect(polyline, &VEPolyline::signalMove, workplaceScene, &VEWorkplace::slotMove);
            break;
        }
        case QGraphicsRectItem::Type: {
            VERectangle *rect = qgraphicsitem_cast<VERectangle*>(item);
            workplaceScene->addItem(rect);
            connect(rect, &VERectangle::clicked, workplaceScene, &VEWorkplace::signalSelectItem);
            connect(rect, &VERectangle::signalMove, workplaceScene, &VEWorkplace::slotMove);
            break;
        }
        case QGraphicsEllipseItem::Type:{
            VEEllipse *elli = qgraphicsitem_cast<VEEllipse *>(item);
            workplaceScene->addItem(elli);
            connect(elli, &VEEllipse::clicked, workplaceScene,&VEWorkplace::signalSelectItem );
            connect(elli, &VEEllipse::signalMove, workplaceScene, &VEWorkplace::slotMove);
        }
        default:
            break;
        }
    }
    this->saveAs();
}

void MainWindow::on_actionSave_triggered()
{
    this->save();
}

void MainWindow::on_actionSaveAs_triggered()
{
    this->saveAs();
}
void MainWindow::on_toolButton_Home_clicked()
{

    if(this->judge == true && this->judge1 == false){
        for(int i = 0;i<this->record;i++)
        {
            workplaceScene->views()[0]->scale(1/1.2,1/1.2);
            update();
        }
    }else if(this->judge == false && this->judge1 == true){
        for(int i = 0;i<this->record1;i++)
        {
            workplaceScene->views()[0]->scale(1.2,1.2);
            update();
        }
    }else if(this->judge == true && this->judge1 == true){
        if(this->record > this->record1){
            for(int i = 0;i<(this->record - this->record1);i++)
            {
                workplaceScene->views()[0]->scale(1/1.2,1/1.2);
                update();
            }
        }else if(this->record1 > this->record){
            for(int i = 0;i<(this->record1 - this->record);i++)
            {
                workplaceScene->views()[0]->scale(1/1.2,1/1.2);
                update();
            }
        }else{}
    }else{}
    this->record = 0;
    this->record1 = 0;
    this->judge = false;
    this->judge1 = false;


}

void MainWindow::on_toolButton_pixmap_clicked()
{
    VEBasicShapesItem * item = new VEBasicShapesItem(12,12,200,200,VEBasicShapesItem::ITEM_PIXMAP,workplaceScene);
    item->setPos(500,500);
    item->setPixmap("://icons/QPainter.ico");
}

void MainWindow::on_toolButton_bezier_clicked()
{
    VEComplexShapeItem * item4 = new VEComplexShapeItem(workplaceScene);
    item4->addPoint(QPointF(400,400),VEComplexShapeItem::SEGEMENT_LINE);
    item4->addPoint(QPointF(412,412),VEComplexShapeItem::SEGEMENT_LINE);
    item4->addPoint(QPointF(450,450),VEComplexShapeItem::SEGEMENT_LINE);
    item4->addPoint(QPointF(500,500),VEComplexShapeItem::SEGEMENT_LINE);

}


void MainWindow::on_actionZoomIn_triggered()
{
    workplaceScene->views()[0]->scale(1.2,1.2);
    record++;
    judge = true;
}

void MainWindow::on_actionZoomOut_triggered()
{
    workplaceScene->views()[0]->scale(1/1.2,1/1.2);
    record1++;
    judge1 = true;
}

void MainWindow::on_actionHelp_triggered()
{
    ShowHelpDialog show;
    show.exec();
}

void MainWindow::on_toolButton_show_clicked()
{
    ShowSvgDialog * newSSD = new ShowSvgDialog;
    newSSD->exec();
}

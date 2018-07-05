#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editwidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    area=new EditWidget(this);


    //    QLineF *f=new QLineF(100,100,200,200);
    //    QGraphicsLineItem *l=new QGraphicsLineItem() ;
    //    l->setLine(*f);
    //    l->setFlag(QGraphicsItem::ItemIsMovable, true);
    //    l->setFlag(QGraphicsItem::ItemIsSelectable, true);
    //    area->addItem(l);
    QGraphicsView *view = new QGraphicsView(area,this);
    //    view->resize(1366,268);
    area->setSceneRect(view->rect());
    view->setMouseTracking(true);
    setCentralWidget(view);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_penStyleComboBox_currentIndexChanged(const QString penStyle)
{
    if(penStyle == QStringLiteral("实线"))
    {
        area->setPenStyle(Qt::SolidLine);   //利用PaintArea类中的枚举变量
    }
    else if(penStyle == QStringLiteral("虚线"))
    {
        area->setPenStyle(Qt::DotLine);
    }
}
void MainWindow::on_shapeComboBox_currentIndexChanged(const QString shape)
{
    if(shape == QStringLiteral("点"))
    {
        area->setShape(EditWidget::PointType);
    }
    else if(shape == QStringLiteral("线"))
    {
        area->setShape(EditWidget::PolylineType);
    }
    else if(shape == QStringLiteral("面"))
    {
        area->setShape(EditWidget::PolygonType);
    }
}

void MainWindow::on_penWidthSpinBox_valueChanged(int penWidth)
{
    area->setPenWidth(penWidth);
}




void MainWindow::on_penColorToolButton_clicked()
{
    QColor newColor = QColorDialog::getColor();  //从颜色对话框获得颜色
    if (newColor.isValid())   //如果得到的是可用的颜色
    {
        area->setPenColor(newColor);
        QPalette palette = ui->textBrowser_Pen->palette(); //显示这个颜色
        palette.setColor(QPalette::Base,newColor);
        ui->textBrowser_Pen->setPalette(palette);
    }
}

void MainWindow::on_brushColorToolButton_clicked()
{
    QColor newColor = QColorDialog::getColor();  //从颜色对话框获得颜色
    if (newColor.isValid())   //如果得到的是可用的颜色
    {
        area->setBrushColor(newColor);
        QPalette palette = ui->textBrowser_Brush->palette(); //显示这个颜色
        palette.setColor(QPalette::Base,newColor);
        ui->textBrowser_Brush->setPalette(palette);
    }
}

void MainWindow::on_action_Draw_triggered()
{
    if( ui->action_Draw->isChecked()==true)
    {
        area->views()[0]->setCursor(Qt::CrossCursor);
        area->setState(EditWidget::DrawType);
        ui->action_Move->setChecked(false);
        ui->action_Edit->setChecked(false);
    }
}

void MainWindow::on_action_Move_triggered()
{
    if( ui->action_Move->isChecked()==true)
    {
        area->views()[0]->setCursor(Qt::OpenHandCursor);
        area->setState(EditWidget::MoveType);
        ui->action_Draw->setChecked(false);
        ui->action_Edit->setChecked(false);
    }
}

void MainWindow::on_action_Edit_triggered()
{
    if( ui->action_Edit->isChecked()==true)
    {
        area->views()[0]->setCursor(Qt::PointingHandCursor);
        area->setState(EditWidget::EditType);
        ui->action_Move->setChecked(false);
        ui->action_Draw->setChecked(false);
    }
}



void MainWindow::on_action_Clear_triggered()
{
    while(area->items().count()>0)
    {
        area->removeItem(area->items()[0]);
    }
    area->shapes.clear();
    area->tempShapes.clear();
    area->points.clear();
}

void MainWindow::on_action_ZoomIn_triggered()
{
    area->views()[0]->scale(1.2,1.2);
}

void MainWindow::on_action_ZoomOut_triggered()
{
    area->views()[0]->scale(1/1.2,1/1.2);
}


void MainWindow::on_shapeComboBox_currentIndexChanged(int index)
{

}

void MainWindow::on_shapeComboBox_activated(const QString &arg1)
{

}

void MainWindow::on_actionCircle_triggered()
{
    area->setShape(EditWidget::EllispeType);
}

void MainWindow::on_actionRectangle_triggered()
{
    area->setShape(EditWidget::RectangleType);
}

void MainWindow::on_actionText_triggered()
{
    area->setShape(EditWidget::Edit);
}

void MainWindow::on_actionRoundRectangle_triggered()
{
     area->setShape(EditWidget::RoundedRectangleType);
}

void MainWindow::on_actionLine_triggered()
{
    area->setShape(EditWidget::LineType);
}

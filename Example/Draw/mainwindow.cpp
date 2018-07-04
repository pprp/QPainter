#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "donewdialog.h"
#include "helpshowdialog.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(700,500);
    area=new PaintArea;
    scrollArea=new QScrollArea;
    //设置背景色
    scrollArea->setBackgroundRole(QPalette::Dark);
    //将画布添加到滚动条中
    scrollArea->setWidget(area);
    //设置画布大小
    scrollArea->widget()->setMinimumSize(800,600);
    setCentralWidget(scrollArea);
    //对两个颜色组合框进行初始化
    createColorComboBox(ui->penColorComboBox);
    createColorComboBox(ui->brushColorComboBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    doNew();
    /*DoNewDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
        int width = dlg.getWidth();
        int height = dlg.getHeight();

        area->setImageSize(width,height);//更改画布大小
        scrollArea->widget()->resize(width,height);//更改ScrollArea大小
        area->setImageColor(dlg.getBackColor());
    }
    */
}

void MainWindow::doOpen()
{
    if(maybeSave())//可以保存
    {
        QString fileName = QFileDialog::getOpenFileName(this,tr("打开文件"),QDir::currentPath());
        if(!fileName.isEmpty())
        {
            area->openImage(fileName);
            scrollArea->widget()->resize(area->getImageSize());
            //获得图片大小，然后更改scrollArea大小
            isSaved = true;
            curFile = fileName;
        }
    }
}
void MainWindow::doNew()
{
    if(maybeSave())
    {
        DoNewDialog dlg;
        if(dlg.exec() == QDialog::Accepted)
        {
            int width = dlg.getWidth();
            int height = dlg.getHeight();
            area->setImageSize(width,height);
            scrollArea->widget()->resize(width,height);
            area->setImageColor(dlg.getBackColor());
            isSaved=false;
        }
    }
}

bool MainWindow::maybeSave()
{
    if(area->isModified())
    {
        QMessageBox::StandardButton box;
        box = QMessageBox::warning(this,tr("保存文件"),tr("图片已经改变，是否保存?"),QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(box == QMessageBox::Yes)
            return doFileSave();
        else if(box == QMessageBox::Cancel)
            return false;
    }
    return true;
}

bool MainWindow::doFileSave()
{
    if(isSaved)
    {
        return saveFile(curFile);
    }
    else
        return doFileSaveAs();
}

bool MainWindow::saveFile(QString fileName)
{
    if(area->saveImage(fileName,"png"))
    {
        isSaved = true;
        return true;
    }
    else
        return false;
}

bool MainWindow::doFileSaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(fileName.isEmpty())
        return false;
    else
        return saveFile(fileName);
}


void MainWindow::on_actionOpen_triggered()
{
    doOpen();
}

void MainWindow::on_actionSave_triggered()
{
    doFileSave();
}

void MainWindow::on_actionSaveAs_triggered()
{
    doFileSaveAs();
}

void MainWindow::on_actionExit_triggered()
{
    if(maybeSave())
        qApp->quit();
}


//重写窗口关闭的事件函数

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(maybeSave())
        qApp->quit();
    else
        event->ignore();
}



void MainWindow::on_actionZoomIn_triggered()
{
    area->zoomIn();
    scrollArea->widget()->resize(area->getImageSize());
}

void MainWindow::on_actionReturn_triggered()
{
    area->zoom_1();
    scrollArea->widget()->resize(area->getImageSize());
}

void MainWindow::on_actionRotate_triggered()
{
    area->doRotate();
}
void MainWindow::on_actionZoomOut_triggered()
{
    area->zoomOut();
    scrollArea->widget()->resize(area->getImageSize());
}
void MainWindow::on_actionClear_triggered()
{
    area->doClear();
}

void MainWindow::on_actionStretch_triggered()
{
    area->doShear();
}

void MainWindow::on_actionDrawingToolbar_triggered()
{
    ui->DrawTools->show();
}

void MainWindow::on_actionAbout_Draw_triggered()
{
    HelpShowDialog hsd;
    if(hsd.exec() == QDialog::Accepted)
    {
        hsd.show();
    }
}
void MainWindow::createColorComboBox(QComboBox *comboBox)
{
    QPixmap pix(16,16);
    QPainter painter(&pix);

    painter.fillRect(0,0,16,16,QColor(Qt::black));
    comboBox->addItem(QIcon(pix),tr("黑色"),QColor(Qt::black));

    painter.fillRect(0,0,16,16,Qt::white);
    comboBox->addItem(QIcon(pix),tr("白色"),QColor(Qt::white));

    painter.fillRect(0,0,16,16,Qt::red);
    comboBox->addItem(QIcon(pix),tr("红色"),QColor(Qt::red));

    painter.fillRect(0,0,16,16,Qt::green);
    comboBox->addItem(QIcon(pix),tr("绿色"),QColor(Qt::green));

    painter.fillRect(0,0,16,16,Qt::yellow);
    comboBox->addItem(QIcon(pix),tr("黄色"),QColor(Qt::yellow));

    comboBox->addItem(tr("无颜色"),QColor(Qt::transparent));
}

void MainWindow::on_shapeComboBox_currentIndexChanged(const QString shape)
{
    if(shape == tr("无"))
        area->setShape(PaintArea::None); //利用 PaintArea 类中的枚举变量
    else if(shape == tr("矩形"))
        area->setShape(PaintArea::Rectangle);
    else if(shape == tr("直线"))
        area->setShape(PaintArea::Line);
    else if(shape == tr("椭圆"))
        area->setShape(PaintArea::Ellipse);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "donewdialog.h"

#include <QMessageBox>
#include <QFileDialog>

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

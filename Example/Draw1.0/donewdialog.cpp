#include "donewdialog.h"
#include "ui_donewdialog.h"

DoNewDialog::DoNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoNewDialog)
{
    ui->setupUi(this);
    backColor=Qt::white;
}

DoNewDialog::~DoNewDialog()
{
    delete ui;
}

double DoNewDialog::getWidth()
{
    return ui->widthSpinBox->text().toDouble();
}

double DoNewDialog::getHeight()
{
    return ui->heightSpinBox->text().toDouble();
}
QColor DoNewDialog::getBackColor()
{
    return backColor;
}

void DoNewDialog::on_toolButton_clicked()
{
    //创建颜色对话框
    QColor newColor=QColorDialog::getColor();
    if(newColor.isValid())//可用颜色
    {
        backColor = newColor;
        //调色
        QPalette palette = ui->textBrowser->palette();
        palette.setColor(QPalette::Base,backColor);//设置颜色
        ui->textBrowser->setPalette(palette);//设置textBrower中颜色
        update();
    }
}

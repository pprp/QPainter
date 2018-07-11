#include "textdialog.h"
#include "ui_textdialog.h"

TextDialog::TextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextDialog)
{
    ui->setupUi(this);
    ui->spinBox_text->setMaximum(100);
    ui->spinBox_text->setMinimum(15);
    ui->spinBox_Width->setMinimum(150);
    ui->spinBox_Width->setMaximum(1000);
}

TextDialog::~TextDialog()
{
    delete ui;
}

QString TextDialog::getFont()
{
    return ui->comboBox_text->currentText();
}

int TextDialog::getWidth()
{
    return ui->spinBox_text->value();
}

qreal TextDialog::getKWidth()
{
    return ui->spinBox_Width->value();
}

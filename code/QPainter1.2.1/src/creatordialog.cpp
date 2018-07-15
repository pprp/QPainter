#include "creatordialog.h"
#include "ui_creatordialog.h"

CreatorDialog::CreatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatorDialog)
{
    ui->setupUi(this);
}

CreatorDialog::~CreatorDialog()
{
    delete ui;
}

void CreatorDialog::on_pushButton_close_clicked()
{
    this->close();
}

#include "helpshowdialog.h"
#include "ui_helpshowdialog.h"

HelpShowDialog::HelpShowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpShowDialog)
{
    ui->setupUi(this);
}

HelpShowDialog::~HelpShowDialog()
{
    delete ui;
}


void HelpShowDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    this->close();
}

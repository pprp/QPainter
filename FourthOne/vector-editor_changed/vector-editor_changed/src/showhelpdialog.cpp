#include "showhelpdialog.h"
#include "ui_showhelpdialog.h"

ShowHelpDialog::ShowHelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowHelpDialog)
{
    ui->setupUi(this);
}

ShowHelpDialog::~ShowHelpDialog()
{
    delete ui;
}

void ShowHelpDialog::on_pushButton_2_clicked()
{
    close();
}

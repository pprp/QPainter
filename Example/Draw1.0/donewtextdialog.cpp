#include "donewtextdialog.h"
#include "ui_donewtextdialog.h"

doNewTextDialog::doNewTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::doNewTextDialog)
{
    ui->setupUi(this);
}

doNewTextDialog::~doNewTextDialog()
{
    delete ui;
}

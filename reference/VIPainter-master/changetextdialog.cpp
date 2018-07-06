/**
 * Copyright (C) 2017 VIPainter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "changetextdialog.h"
#include "ui_changetextdialog.h"
#include <QPushButton>
#include <QDebug>

ChangeTextDialog::ChangeTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeTextDialog)
{
    ui->setupUi(this);
//    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("确定"));
//    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("取消"));
}

void ChangeTextDialog::showDialog(VText *vt){
    ChangeTextDialog dialog;
    dialog.ui->textEdit->setText(vt->getText());
    int res=dialog.exec();
    if (res == QDialog::Accepted)
    {
        QString str =dialog.ui->textEdit->toPlainText();
        //qDebug()<<"dialog text "<<str<<";"<<endl;
        vt->setText(str);
    }
}

ChangeTextDialog::~ChangeTextDialog()
{
    delete ui;
}

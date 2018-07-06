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
#include "canvassizedialog.h"
#include "ui_canvassizedialog.h"
#include <QPushButton>

CanvasSizeDialog::CanvasSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CanvasSizeDialog)
{
    ui->setupUi(this);
//    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("确定"));
//    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("取消"));
}

CanvasSizeDialog::~CanvasSizeDialog()
{
    delete ui;
}


VSize CanvasSizeDialog::showDialog(const QString title,const VSize &size)
{
    CanvasSizeDialog dialog;
    dialog.setWindowTitle(title);
    dialog.ui->curHeight->setText(QString("%1").arg((int)size.height));
    dialog.ui->curWidth->setText(QString("%1").arg((int)size.width));
    dialog.ui->widthSpinBox->setValue((int)size.width);
    dialog.ui->heightSpinBox->setValue((int)size.height);
    int res=dialog.exec();
    if (res == QDialog::Accepted)
    {
        return VSize(dialog.ui->widthSpinBox->value(),dialog.ui->heightSpinBox->value());
    }
    return size;
}

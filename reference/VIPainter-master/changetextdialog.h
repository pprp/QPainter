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

#ifndef CHANGETEXTDIALOG_H
#define CHANGETEXTDIALOG_H

#include <QDialog>
#include "vtext.h"

namespace Ui {
class ChangeTextDialog;
}

class ChangeTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTextDialog(QWidget *parent = 0);
    static void showDialog(VText *vt);
    ~ChangeTextDialog();

private:
    Ui::ChangeTextDialog *ui;
};

#endif // CHANGETEXTDIALOG_H

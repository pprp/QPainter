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

#ifndef CANVASSIZEDIALOG_H
#define CANVASSIZEDIALOG_H

#include <QDialog>
#include "vsize.h"

namespace Ui {
class CanvasSizeDialog;
}

class CanvasSizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CanvasSizeDialog(QWidget *parent = 0);
    ~CanvasSizeDialog();
    static VSize showDialog(const QString title, const VSize &size);

private:
    Ui::CanvasSizeDialog *ui;
};

#endif // CANVASSIZEDIALOG_H

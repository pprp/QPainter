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
#ifndef PENSTYLEDIALOG_H
#define PENSTYLEDIALOG_H

#include <QDialog>
#include <QVector>
#include "vshape.h"

namespace Ui {
class PenStyleDialog;
}

class PenStyleDialog : public QDialog
{

public:
    explicit PenStyleDialog(QWidget *parent = 0);
    ~PenStyleDialog()override;
    static void showDialog(const QString title, const QVector<VShape *> shapes);

private:
    Ui::PenStyleDialog *ui;
};

#endif // PENSTYLEDIALOG_H

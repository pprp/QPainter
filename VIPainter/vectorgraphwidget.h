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
#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QPaintEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QWidget>
#include <QMainWindow>
#include <QRect>
#include <QDir>
#include <QWheelEvent>
#include <QContextMenuEvent>
#include <QMenu>
#include <QKeyEvent>
#include <QList>
#include <QString>
#include <QJsonObject>
#include "paintwidget.h"
#include "vgroupshape.h"
#include "vsize.h"
#include "vpoint.h"
#include "vcursortype.h"
#include "vshape.h"
#include "vpoint.h"
#include "swapqueue.h"

class VectorgraphWidget : public PaintWidget
{
    Q_OBJECT

public:
    explicit VectorgraphWidget(QMainWindow *mainwindow, bool antialiasing);
    int crPos=-1;
    VGroupShape groupShape;
    QVector<VShape*> focusShapes;
    VSize canvasSize;
    VPoint canvasLocation;
    QMenu *contextMenu;
    ~VectorgraphWidget();
    VPoint getLoc(const VPoint & point);
    void saveFile(QString filename)override;
    bool fileChanged()override;
    QJsonObject toJsonObject();
    void setCanvasSize(VSize canvasSize);
    VSize getCanvasSize();

protected:
    void paintEvent(QPaintEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    void wheelEvent(QWheelEvent * event)override;
    bool eventFilter(QObject * obj, QEvent * ev)override;

private:
    VShape * getShape(const VPoint &point);
    SwapQueue<QJsonArray,20> swapQueue;
    VPoint locMove;
    VPoint lastMove;
    VPoint locPress;
    double lastAngle;
    void emitSelected();

public slots:
    void updateList()override;
    void changeSelected()override;
    void saveSwp();
    void changeCursor(VCursorType type, VShape *plugin)override;
    void on_actionSaveAs_triggered()override;
    void on_actionResume_triggered()override;
    void on_actionCanvasSize_triggered()override;
    void on_actionShapeSize_triggered()override;
    void on_actionBreakUp_triggered()override;
    void on_actionUndo_triggered()override;
    void on_actionRedo_triggered()override;
    void on_actionDelete_triggered()override;
    void on_actionCopy_triggered()override;
    void on_actionPaste_triggered()override;
    void on_actionGroup_triggered()override;
    void changeModelData(const QModelIndex &index)override;
    void on_actionSelectAll_triggered()override;
    void on_actionBrushColor_triggered()override;
    void on_actionPenColor_triggered()override;
    void on_actionPenStyle_triggered()override;
    void on_actionForceGroup_triggered()override;
};

#endif // TESTWIDGET_H

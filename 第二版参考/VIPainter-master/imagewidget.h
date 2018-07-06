#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include "paintwidget.h"
#include "vpoint.h"
#include "vsize.h"
#include "vmagnification.h"
#include "swapqueue.h"
#include <QPaintEvent>
#include <QDebug>
#include <QScrollArea>
#include <QColor>
#include <QResizeEvent>
#include <QFocusEvent>

class ImageWidget : public PaintWidget
{
    Q_OBJECT
private:
    QImage canvas;
    VShape *focusShape=nullptr;
    VPoint locMove;
    VPoint lastMove;
    VPoint globalMove;
    VPoint locPress;
    int crPos=-1;
    bool isPressing=false;
    QScrollArea *scrollArea;
    SwapQueue<QImage,20>swapQueue;
    bool pasting=false;

public:
    ImageWidget(QMainWindow *mainwindow, bool antialiasing=true);

    QScrollArea *getScrollArea();
    void saveFile(QString filename)override;
    bool fileChanged()override;
    void setCanvasSize(VSize canvasSize);
    void setImageSize(VSize size);
    VSize getCanvasSize();
    void setImage(const QImage &image);
    void setImage(QImage);
    template<class IMAGE>void setCanvas(IMAGE &&canvas);
    QImage &getCanvas();
    VPoint getLoc(const VPoint &point);
    void setScale(double scale)override;
    VMagnification getScale();
    void saveSwp(QString name);
private:
    void finishFocusShape();
    void clearFocusShape();
    void cutCanvas(int x,int y,int width,int height,const QColor &color);
    void emitSelected();
protected:
    void paintEvent(QPaintEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    void wheelEvent(QWheelEvent * event)override;
    bool eventFilter(QObject * obj, QEvent * ev)override;

public slots:
    void updateList()override;
    void changeSelected()override;
    void changeCursor(VCursorType type, VShape *plugin)override;
    void on_actionZoomIn_triggered()override;
    void on_actionZoomOut_triggered()override;
    void on_actionResume_triggered()override;
    void on_actionSaveAs_triggered()override;
    void on_actionCanvasSize_triggered()override;
    void on_actionShapeSize_triggered()override;
//    void on_actionBreakUp_triggered()override;
    void on_actionRedo_triggered()override;
    void on_actionUndo_triggered()override;
    void on_actionDelete_triggered()override;
    void on_actionCopy_triggered()override;
//    void on_actionCut_triggered()override;
    void on_actionPaste_triggered()override;
//    void on_actionGroup_triggered()override;
    void on_actionSelectAll_triggered()override;
//    void on_actionBrushColor_triggered()override;
//    void on_actionPenColor_triggered()override;
//    void on_actionPenStyle_triggered()override;
//    void on_actionForceGroup_triggered()override;
};

template<class IMAGE>void ImageWidget::setCanvas(IMAGE &&canvas)
{
    this->canvas=std::forward<IMAGE>(canvas);
    this->resize(this->canvas.width()*scale,this->canvas.height()*scale);
}

#endif // IMAGEWIDGET_H

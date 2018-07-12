#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWheelEvent>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include "showhelpdialog.h"
#include "textdialog.h"
#include "TextItem.h"
#include "showsvgdialog.h"

class QGraphicsItem;
class VEWorkplace;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void save();
    void saveAs();
    void newFile();
    void open();
    void clear();
    void selectAll();
    void timeUpdate();
    void on_butSave_clicked();
    void on_butOpen_clicked();
    void checkSelection();
    void checkActionStates();
    void selectItem(QGraphicsItem *item);
    void selectNewItem(QGraphicsItem *item);
    void on_actionExit_triggered();
    void on_toolButton_SaveAs_clicked();
    void on_toolButton_ZoomIn_clicked();
    void on_toolButton_ZoomOut_clicked();
    void on_toolButton_text_clicked();
    void on_actionNew_triggered();
    void on_toolButton_clear_clicked();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_toolButton_Home_clicked();    
    void on_toolButton_pixmap_clicked();
    void on_toolButton_bezier_clicked();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionHelp_triggered();
    void on_toolButton_show_clicked();
protected:
    void wheelEvent(QWheelEvent *event);
private:
    Ui::MainWindow *ui;
    VEWorkplace *workplaceScene;
    QString path;
    QAction * cutAct;

    TextItem * txtItem;

    QTimer * timer;
    QLabel * currentTimeLabel;

    int record;
    int record1;
    bool judge;
    bool judge1;

};

#endif // MAINWINDOW_H

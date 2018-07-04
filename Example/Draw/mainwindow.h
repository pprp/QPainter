#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintarea.h"
#include <QScrollArea>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //文件操作
    void doNew();
    void doOpen();
    bool doFileSave();
    bool doFileSaveAs();
    //完成绘图工具栏的功能
    void createColorComboBox(QComboBox*comboBox);//创建颜色组合
protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionExit_triggered();
    void on_actionZoomIn_triggered();

    void on_actionReturn_triggered();

    void on_actionRotate_triggered();

    void on_actionZoomIn_2_triggered();

    void on_actionZoomOut_triggered();

    void on_actionClear_triggered();

    void on_actionStretch_triggered();

    void on_actionDrawingToolbar_triggered();

    void on_actionAbout_Draw_triggered();

    void on_shapeComboBox_currentIndexChanged(const QString shape);

private:
    Ui::MainWindow *ui;
    //图区对象
    //滚动条对象
    PaintArea * area;
    QScrollArea * scrollArea;

    //是否保存过
    bool isSaved;
    QString curFile;//保存文件路径
    bool maybeSave();//是否保存文件
    bool saveFile(QString fileName);//实现文件的存储
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintarea.h"
#include <QScrollArea>

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

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

    void on_actionExit_triggered();

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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editwidget.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    EditWidget *area;


    ~MainWindow();

private slots:
    void on_penStyleComboBox_currentIndexChanged(const QString penStyle);
    void on_shapeComboBox_currentIndexChanged(const QString shape);
    void on_penColorToolButton_clicked();
    void on_brushColorToolButton_clicked();
    void on_penWidthSpinBox_valueChanged(int penWidth);
    void on_action_Move_triggered();
    void on_action_Edit_triggered();
    void on_action_Draw_triggered();
    void on_action_Clear_triggered();
    void on_action_ZoomIn_triggered();
    void on_action_ZoomOut_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

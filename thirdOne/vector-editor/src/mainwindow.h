#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_butSave_clicked();
    void on_butOpen_clicked();
    void checkSelection();
    void checkActionStates();
    void selectItem(QGraphicsItem *item);
    void selectNewItem(QGraphicsItem *item);
    void slotHelp();
    void on_butRectangle_clicked();
    void on_toolButton_6_clicked();
    void on_toolButton_7_clicked();
    void on_toolButton_9_clicked();
    void cut();
    void copy();
    void deleteSelected();
    void paste();
    void save();
    void saveAs();
    void newFile();
    void open();
    void clear();
    void selectAll();
    void on_actionExit_triggered();
    void on_toolButton_10_clicked();
    void on_cut_clicked();
    void on_toolButton_3_clicked();

private:
    Ui::MainWindow *ui;
    VEWorkplace *workplaceScene;
    QString path;
    QAction * cutAct;
};

#endif // MAINWINDOW_H

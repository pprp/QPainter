#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWheelEvent>
#include <QLabel>
#include <QTimer>
#include <QDateTime>

class QGraphicsItem;
class VEWorkplace;
class Dialog;

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
    void on_toolButton_SaveAs_clicked();
    void on_toolButton_ZoomIn_clicked();
    void on_toolButton_ZoomOut_clicked();
    void on_toolButton_text_clicked();
    void on_actionNew_triggered();
    void on_toolButton_clear_clicked();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void addDialog(int a, QString b);
    void timeUpdate();


protected:
    void wheelEvent(QWheelEvent *event);
private:
    Ui::MainWindow *ui;
    VEWorkplace *workplaceScene;
    QString path;
    QAction * cutAct;
    Dialog *tItem;
    QTimer * timer;
    QLabel * currentTimeLabel;
};

#endif // MAINWINDOW_H

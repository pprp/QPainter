#ifndef DONEWDIALOG_H
#define DONEWDIALOG_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
class DoNewDialog;
}

class DoNewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoNewDialog(QWidget *parent = 0);
    ~DoNewDialog();
    int getWidth();//画布的宽
    int getHeight();//画布的高
    QColor getBackColor();//返回画布背景颜色

private slots:
    void on_toolButton_clicked();

private:
    Ui::DoNewDialog *ui;
    QColor backColor;//保存画布背景色
};

#endif // DONEWDIALOG_H

#ifndef CREATORDIALOG_H
#define CREATORDIALOG_H

#include <QDialog>

namespace Ui {
class CreatorDialog;
}

class CreatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreatorDialog(QWidget *parent = 0);
    ~CreatorDialog();

private slots:
    void on_pushButton_close_clicked();

private:
    Ui::CreatorDialog *ui;
};

#endif // CREATORDIALOG_H

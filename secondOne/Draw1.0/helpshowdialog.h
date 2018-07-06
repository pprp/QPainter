#ifndef HELPSHOWDIALOG_H
#define HELPSHOWDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class HelpShowDialog;
}

class HelpShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpShowDialog(QWidget *parent = 0);
    ~HelpShowDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::HelpShowDialog *ui;
};

#endif // HELPSHOWDIALOG_H

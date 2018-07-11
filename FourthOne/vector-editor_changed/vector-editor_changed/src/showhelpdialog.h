#ifndef SHOWHELPDIALOG_H
#define SHOWHELPDIALOG_H

#include <QDialog>

namespace Ui {
class ShowHelpDialog;
}

class ShowHelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowHelpDialog(QWidget *parent = 0);
    ~ShowHelpDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::ShowHelpDialog *ui;
};

#endif // SHOWHELPDIALOG_H

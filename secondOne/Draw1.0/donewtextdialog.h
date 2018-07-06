#ifndef DONEWTEXTDIALOG_H
#define DONEWTEXTDIALOG_H

#include <QDialog>

namespace Ui {
class doNewTextDialog;
}

class doNewTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit doNewTextDialog(QWidget *parent = 0);
    ~doNewTextDialog();

private:
    Ui::doNewTextDialog *ui;
};

#endif // DONEWTEXTDIALOG_H

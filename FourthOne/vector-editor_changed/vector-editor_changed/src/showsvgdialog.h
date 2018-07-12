#ifndef SHOWSVGDIALOG_H
#define SHOWSVGDIALOG_H

#include <QDialog>
#include "svgwindow.h"
#include <QMenu>

namespace Ui {
class ShowSvgDialog;
}

class ShowSvgDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowSvgDialog(QWidget *parent = 0);
    ~ShowSvgDialog();


private slots:
    void slotOpenFile();
    void on_actionOpen_triggered();

private:
    Ui::ShowSvgDialog *ui;
    SvgWindow * svgWindow;
};

#endif // SHOWSVGDIALOG_H

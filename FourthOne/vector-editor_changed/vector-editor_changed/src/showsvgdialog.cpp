#include "showsvgdialog.h"
#include "ui_showsvgdialog.h"

ShowSvgDialog::ShowSvgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowSvgDialog)
{
    ui->setupUi(this);
    this->resize(700, 700);
    setWindowTitle(trUtf8("SvgWindow"));
    svgWindow = new SvgWindow;
    QVBoxLayout * toplayout=new QVBoxLayout(this);
    toplayout->setContentsMargins(50,50,50,50);
    toplayout->setAlignment(Qt::AlignCenter);
    toplayout->addWidget(svgWindow);

}

ShowSvgDialog::~ShowSvgDialog()
{
    delete ui;
}


void ShowSvgDialog::slotOpenFile()
{
    QString name = QFileDialog::getOpenFileName(this, trUtf8("打开"), "/", "svg files(*.svg)");
    svgWindow->setFile(name);
}



void ShowSvgDialog::on_actionOpen_triggered()
{
    this->slotOpenFile();
}

/********************************************************************************
** Form generated from reading UI file 'donewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONEWDIALOG_H
#define UI_DONEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DoNewDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;
    QToolButton *toolButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *DoNewDialog)
    {
        if (DoNewDialog->objectName().isEmpty())
            DoNewDialog->setObjectName(QStringLiteral("DoNewDialog"));
        DoNewDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(DoNewDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DoNewDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 54, 12));
        label_2 = new QLabel(DoNewDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 54, 12));
        label_3 = new QLabel(DoNewDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 180, 54, 12));
        widthSpinBox = new QSpinBox(DoNewDialog);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setGeometry(QRect(130, 50, 42, 22));
        widthSpinBox->setMinimum(400);
        widthSpinBox->setMaximum(10000);
        heightSpinBox = new QSpinBox(DoNewDialog);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setGeometry(QRect(130, 120, 42, 22));
        heightSpinBox->setMinimum(300);
        heightSpinBox->setMaximum(10000);
        toolButton = new QToolButton(DoNewDialog);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(190, 180, 37, 18));
        textBrowser = new QTextBrowser(DoNewDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(150, 170, 31, 31));

        retranslateUi(DoNewDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DoNewDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DoNewDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DoNewDialog);
    } // setupUi

    void retranslateUi(QDialog *DoNewDialog)
    {
        DoNewDialog->setWindowTitle(QApplication::translate("DoNewDialog", "Dialog", 0));
        label->setText(QApplication::translate("DoNewDialog", "\345\256\275\357\274\232", 0));
        label_2->setText(QApplication::translate("DoNewDialog", "\351\253\230\357\274\232", 0));
        label_3->setText(QApplication::translate("DoNewDialog", "\350\203\214\346\231\257\351\242\234\350\211\262\357\274\232", 0));
        toolButton->setText(QApplication::translate("DoNewDialog", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class DoNewDialog: public Ui_DoNewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONEWDIALOG_H

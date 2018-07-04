/********************************************************************************
** Form generated from reading UI file 'helpshowdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPSHOWDIALOG_H
#define UI_HELPSHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HelpShowDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *HelpShowDialog)
    {
        if (HelpShowDialog->objectName().isEmpty())
            HelpShowDialog->setObjectName(QStringLiteral("HelpShowDialog"));
        HelpShowDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(HelpShowDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(HelpShowDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 120, 101, 16));
        label_2 = new QLabel(HelpShowDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 150, 231, 16));
        label_3 = new QLabel(HelpShowDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 180, 211, 16));
        pushButton = new QPushButton(HelpShowDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 20, 75, 91));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/\345\233\276\347\211\2071.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(64, 64));

        retranslateUi(HelpShowDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HelpShowDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HelpShowDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HelpShowDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpShowDialog)
    {
        HelpShowDialog->setWindowTitle(QApplication::translate("HelpShowDialog", "Dialog", 0));
        label->setText(QApplication::translate("HelpShowDialog", "Version 1.0", 0));
        label_2->setText(QApplication::translate("HelpShowDialog", "License and Open Source Notices", 0));
        label_3->setText(QApplication::translate("HelpShowDialog", "More:www.github.com/pprp/QPainter", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HelpShowDialog: public Ui_HelpShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPSHOWDIALOG_H

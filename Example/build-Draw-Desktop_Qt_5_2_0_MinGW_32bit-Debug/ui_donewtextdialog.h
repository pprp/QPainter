/********************************************************************************
** Form generated from reading UI file 'donewtextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONEWTEXTDIALOG_H
#define UI_DONEWTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_doNewTextDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;

    void setupUi(QDialog *doNewTextDialog)
    {
        if (doNewTextDialog->objectName().isEmpty())
            doNewTextDialog->setObjectName(QStringLiteral("doNewTextDialog"));
        doNewTextDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(doNewTextDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        plainTextEdit = new QPlainTextEdit(doNewTextDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(40, 70, 311, 161));
        label = new QLabel(doNewTextDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 231, 16));

        retranslateUi(doNewTextDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), doNewTextDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), doNewTextDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(doNewTextDialog);
    } // setupUi

    void retranslateUi(QDialog *doNewTextDialog)
    {
        doNewTextDialog->setWindowTitle(QApplication::translate("doNewTextDialog", "Dialog", 0));
        label->setText(QApplication::translate("doNewTextDialog", "\350\257\267\345\234\250\346\226\207\346\234\254\346\241\206\344\270\255\350\277\233\350\241\214\346\226\207\345\255\227\345\206\205\345\256\271\347\232\204\347\274\226\350\276\221", 0));
    } // retranslateUi

};

namespace Ui {
    class doNewTextDialog: public Ui_doNewTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONEWTEXTDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'changetextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGETEXTDIALOG_H
#define UI_CHANGETEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChangeTextDialog
{
public:
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChangeTextDialog)
    {
        if (ChangeTextDialog->objectName().isEmpty())
            ChangeTextDialog->setObjectName(QStringLiteral("ChangeTextDialog"));
        ChangeTextDialog->resize(412, 187);
        verticalLayout = new QVBoxLayout(ChangeTextDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolButton = new QToolButton(ChangeTextDialog);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        verticalLayout->addWidget(toolButton);

        textEdit = new QTextEdit(ChangeTextDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(ChangeTextDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ChangeTextDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeTextDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeTextDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeTextDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeTextDialog)
    {
        ChangeTextDialog->setWindowTitle(QApplication::translate("ChangeTextDialog", "\346\226\207\346\234\254", 0));
        toolButton->setText(QApplication::translate("ChangeTextDialog", "\345\255\227\344\275\223", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangeTextDialog: public Ui_ChangeTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGETEXTDIALOG_H

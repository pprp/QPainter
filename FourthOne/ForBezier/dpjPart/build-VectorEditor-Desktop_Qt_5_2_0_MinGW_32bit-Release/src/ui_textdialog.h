/********************************************************************************
** Form generated from reading UI file 'textdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTDIALOG_H
#define UI_TEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_TextDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_txt;
    QLabel *label_width;
    QComboBox *comboBox_text;
    QSpinBox *spinBox_text;
    QLabel *label;
    QSpinBox *spinBox_Width;

    void setupUi(QDialog *TextDialog)
    {
        if (TextDialog->objectName().isEmpty())
            TextDialog->setObjectName(QStringLiteral("TextDialog"));
        TextDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(TextDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_txt = new QLabel(TextDialog);
        label_txt->setObjectName(QStringLiteral("label_txt"));
        label_txt->setGeometry(QRect(70, 90, 54, 12));
        label_width = new QLabel(TextDialog);
        label_width->setObjectName(QStringLiteral("label_width"));
        label_width->setGeometry(QRect(70, 130, 54, 12));
        comboBox_text = new QComboBox(TextDialog);
        comboBox_text->setObjectName(QStringLiteral("comboBox_text"));
        comboBox_text->setGeometry(QRect(170, 80, 111, 22));
        spinBox_text = new QSpinBox(TextDialog);
        spinBox_text->setObjectName(QStringLiteral("spinBox_text"));
        spinBox_text->setGeometry(QRect(170, 130, 111, 22));
        label = new QLabel(TextDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 170, 81, 16));
        spinBox_Width = new QSpinBox(TextDialog);
        spinBox_Width->setObjectName(QStringLiteral("spinBox_Width"));
        spinBox_Width->setGeometry(QRect(170, 170, 111, 22));

        retranslateUi(TextDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TextDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TextDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TextDialog);
    } // setupUi

    void retranslateUi(QDialog *TextDialog)
    {
        TextDialog->setWindowTitle(QApplication::translate("TextDialog", "Dialog", 0));
        label_txt->setText(QApplication::translate("TextDialog", "\345\255\227\344\275\223:", 0));
        label_width->setText(QApplication::translate("TextDialog", "\345\256\275\345\272\246:", 0));
        comboBox_text->clear();
        comboBox_text->insertItems(0, QStringList()
         << QApplication::translate("TextDialog", "\345\256\213\344\275\223", 0)
         << QApplication::translate("TextDialog", "\345\276\256\350\275\257\351\233\205\351\273\221", 0)
         << QApplication::translate("TextDialog", "\344\273\277\345\256\213", 0)
         << QApplication::translate("TextDialog", "\346\245\267\344\275\223", 0)
         << QApplication::translate("TextDialog", "\346\226\260\345\256\213\344\275\223", 0)
         << QApplication::translate("TextDialog", "\351\273\221\344\275\223", 0)
         << QApplication::translate("TextDialog", "Times New Roman", 0)
         << QApplication::translate("TextDialog", "Verdana", 0)
         << QApplication::translate("TextDialog", "Vrinda", 0)
         << QApplication::translate("TextDialog", "Tunga", 0)
         << QApplication::translate("TextDialog", "Vani", 0)
        );
        label->setText(QApplication::translate("TextDialog", "\345\255\227\346\241\206\345\256\275\345\272\246\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class TextDialog: public Ui_TextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'canvassizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVASSIZEDIALOG_H
#define UI_CANVASSIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CanvasSizeDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *curSizeBox;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *curWidth;
    QLabel *label_2;
    QLabel *curHeight;
    QGroupBox *setSizeBox;
    QFormLayout *formLayout;
    QLabel *label_3;
    QSpinBox *widthSpinBox;
    QLabel *label_4;
    QSpinBox *heightSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CanvasSizeDialog)
    {
        if (CanvasSizeDialog->objectName().isEmpty())
            CanvasSizeDialog->setObjectName(QStringLiteral("CanvasSizeDialog"));
        CanvasSizeDialog->resize(400, 200);
        CanvasSizeDialog->setMinimumSize(QSize(400, 150));
        CanvasSizeDialog->setMaximumSize(QSize(400, 200));
        gridLayout = new QGridLayout(CanvasSizeDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        curSizeBox = new QGroupBox(CanvasSizeDialog);
        curSizeBox->setObjectName(QStringLiteral("curSizeBox"));
        formLayout_2 = new QFormLayout(curSizeBox);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(curSizeBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        curWidth = new QLabel(curSizeBox);
        curWidth->setObjectName(QStringLiteral("curWidth"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, curWidth);

        label_2 = new QLabel(curSizeBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        curHeight = new QLabel(curSizeBox);
        curHeight->setObjectName(QStringLiteral("curHeight"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, curHeight);


        gridLayout->addWidget(curSizeBox, 0, 0, 1, 1);

        setSizeBox = new QGroupBox(CanvasSizeDialog);
        setSizeBox->setObjectName(QStringLiteral("setSizeBox"));
        formLayout = new QFormLayout(setSizeBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_3 = new QLabel(setSizeBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        widthSpinBox = new QSpinBox(setSizeBox);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setMinimum(1);
        widthSpinBox->setMaximum(4096);

        formLayout->setWidget(0, QFormLayout::FieldRole, widthSpinBox);

        label_4 = new QLabel(setSizeBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        heightSpinBox = new QSpinBox(setSizeBox);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setMinimum(1);
        heightSpinBox->setMaximum(4096);

        formLayout->setWidget(1, QFormLayout::FieldRole, heightSpinBox);

        label_3->raise();
        widthSpinBox->raise();
        label_4->raise();
        heightSpinBox->raise();

        gridLayout->addWidget(setSizeBox, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CanvasSizeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(CanvasSizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CanvasSizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CanvasSizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CanvasSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *CanvasSizeDialog)
    {
        CanvasSizeDialog->setWindowTitle(QApplication::translate("CanvasSizeDialog", "Dialog", 0));
        curSizeBox->setTitle(QApplication::translate("CanvasSizeDialog", "\345\275\223\345\211\215\345\244\247\345\260\217", 0));
        label->setText(QApplication::translate("CanvasSizeDialog", "\345\256\275\345\272\246", 0));
        curWidth->setText(QString());
        label_2->setText(QApplication::translate("CanvasSizeDialog", "\351\253\230\345\272\246", 0));
        curHeight->setText(QString());
        setSizeBox->setTitle(QApplication::translate("CanvasSizeDialog", "\350\256\276\347\275\256\345\244\247\345\260\217", 0));
        label_3->setText(QApplication::translate("CanvasSizeDialog", "\345\256\275\345\272\246", 0));
        label_4->setText(QApplication::translate("CanvasSizeDialog", "\351\253\230\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class CanvasSizeDialog: public Ui_CanvasSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVASSIZEDIALOG_H

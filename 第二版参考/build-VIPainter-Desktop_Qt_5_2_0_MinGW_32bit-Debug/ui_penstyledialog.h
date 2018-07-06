/********************************************************************************
** Form generated from reading UI file 'penstyledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENSTYLEDIALOG_H
#define UI_PENSTYLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PenStyleDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QComboBox *comboBox;

    void setupUi(QDialog *PenStyleDialog)
    {
        if (PenStyleDialog->objectName().isEmpty())
            PenStyleDialog->setObjectName(QStringLiteral("PenStyleDialog"));
        PenStyleDialog->resize(400, 300);
        PenStyleDialog->setMinimumSize(QSize(400, 300));
        PenStyleDialog->setMaximumSize(QSize(400, 300));
        gridLayout = new QGridLayout(PenStyleDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(PenStyleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(PenStyleDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);


        retranslateUi(PenStyleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PenStyleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PenStyleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PenStyleDialog);
    } // setupUi

    void retranslateUi(QDialog *PenStyleDialog)
    {
        PenStyleDialog->setWindowTitle(QApplication::translate("PenStyleDialog", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("PenStyleDialog", "\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("PenStyleDialog", "\347\272\277\346\235\241\347\262\227\347\273\206", 0));
        label_2->setText(QApplication::translate("PenStyleDialog", "\347\272\277\346\235\241\351\243\216\346\240\274", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PenStyleDialog", "NoPen", 0)
         << QApplication::translate("PenStyleDialog", "SolidLine", 0)
         << QApplication::translate("PenStyleDialog", "DashLine ", 0)
         << QApplication::translate("PenStyleDialog", "DotLine ", 0)
         << QApplication::translate("PenStyleDialog", "DashDotLine ", 0)
         << QApplication::translate("PenStyleDialog", "DashDotDotLine ", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class PenStyleDialog: public Ui_PenStyleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENSTYLEDIALOG_H

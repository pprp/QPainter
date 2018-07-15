/********************************************************************************
** Form generated from reading UI file 'verectanglesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERECTANGLESETTINGS_H
#define UI_VERECTANGLESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "colorlabel.h"

QT_BEGIN_NAMESPACE

class Ui_VERectangleSettings
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox;
    QWidget *fillingWidget;
    QGridLayout *gridLayout_2;
    QSpinBox *borderWidth;
    ColorLabel *borderColor;
    QLabel *label_4;
    ColorLabel *color_1;
    QLabel *labelColor_1;
    QLabel *label_2;
    QLabel *labelColor_2;
    ColorLabel *color_2;

    void setupUi(QWidget *VERectangleSettings)
    {
        if (VERectangleSettings->objectName().isEmpty())
            VERectangleSettings->setObjectName(QStringLiteral("VERectangleSettings"));
        VERectangleSettings->resize(185, 215);
        gridLayout = new QGridLayout(VERectangleSettings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        comboBox = new QComboBox(VERectangleSettings);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        fillingWidget = new QWidget(VERectangleSettings);
        fillingWidget->setObjectName(QStringLiteral("fillingWidget"));
        gridLayout_2 = new QGridLayout(fillingWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        borderWidth = new QSpinBox(fillingWidget);
        borderWidth->setObjectName(QStringLiteral("borderWidth"));
        borderWidth->setMinimum(0);
        borderWidth->setMaximum(200);
        borderWidth->setValue(1);

        gridLayout_2->addWidget(borderWidth, 3, 1, 1, 1);

        borderColor = new ColorLabel(fillingWidget);
        borderColor->setObjectName(QStringLiteral("borderColor"));

        gridLayout_2->addWidget(borderColor, 2, 1, 1, 1);

        label_4 = new QLabel(fillingWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        color_1 = new ColorLabel(fillingWidget);
        color_1->setObjectName(QStringLiteral("color_1"));

        gridLayout_2->addWidget(color_1, 0, 1, 1, 1);

        labelColor_1 = new QLabel(fillingWidget);
        labelColor_1->setObjectName(QStringLiteral("labelColor_1"));
        labelColor_1->setFont(font);

        gridLayout_2->addWidget(labelColor_1, 0, 0, 1, 1);

        label_2 = new QLabel(fillingWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        labelColor_2 = new QLabel(fillingWidget);
        labelColor_2->setObjectName(QStringLiteral("labelColor_2"));
        labelColor_2->setFont(font);

        gridLayout_2->addWidget(labelColor_2, 1, 0, 1, 1);

        color_2 = new ColorLabel(fillingWidget);
        color_2->setObjectName(QStringLiteral("color_2"));

        gridLayout_2->addWidget(color_2, 1, 1, 1, 1);


        gridLayout->addWidget(fillingWidget, 1, 0, 1, 1);


        retranslateUi(VERectangleSettings);

        QMetaObject::connectSlotsByName(VERectangleSettings);
    } // setupUi

    void retranslateUi(QWidget *VERectangleSettings)
    {
        VERectangleSettings->setWindowTitle(QApplication::translate("VERectangleSettings", "Form", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("VERectangleSettings", "\346\227\240\346\270\220\345\217\230", 0)
         << QApplication::translate("VERectangleSettings", "\346\270\220\345\217\230", 0)
        );
        borderColor->setText(QString());
        label_4->setText(QApplication::translate("VERectangleSettings", "<font color=\"white\">\345\256\275\345\272\246</font>", 0));
        color_1->setText(QString());
        labelColor_1->setText(QApplication::translate("VERectangleSettings", "<font color=\"white\">\351\242\234\350\211\2621</font>", 0));
        label_2->setText(QApplication::translate("VERectangleSettings", "<font color=\"white\">\350\276\271\346\241\206\351\242\234\350\211\262</font>", 0));
        labelColor_2->setText(QApplication::translate("VERectangleSettings", "<font color=\"white\">\351\242\234\350\211\2622</font>", 0));
        color_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VERectangleSettings: public Ui_VERectangleSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERECTANGLESETTINGS_H

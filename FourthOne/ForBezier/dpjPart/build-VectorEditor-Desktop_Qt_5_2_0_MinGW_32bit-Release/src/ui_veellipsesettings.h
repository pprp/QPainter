/********************************************************************************
** Form generated from reading UI file 'veellipsesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEELLIPSESETTINGS_H
#define UI_VEELLIPSESETTINGS_H

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

class Ui_VEEllipseSettings
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

    void setupUi(QWidget *VEEllipseSettings)
    {
        if (VEEllipseSettings->objectName().isEmpty())
            VEEllipseSettings->setObjectName(QStringLiteral("VEEllipseSettings"));
        VEEllipseSettings->resize(185, 215);
        VEEllipseSettings->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:#1d1d1d;\n"
"}\n"
"\n"
"QMenuBar{\n"
"background-color:#1d1d1d;\n"
"padding:5px;\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background-color:#1d1d1d;\n"
"color:#fff;\n"
"padding:5px;\n"
"\n"
"}\n"
"\n"
"QMenu{\n"
"color:#fff;\n"
"padding:0;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#fff;\n"
"background-color:#00aba9;\n"
"}\n"
"\n"
"QTableWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"  selection-background-color: #da532c;\n"
"border:solid;\n"
"border-width:3px;\n"
"border-color:#da532c;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"color:#fff;\n"
"\n"
"}\n"
"QHeaderView{\n"
"background-color:qlineargradient"
                        "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:#149ED9;\n"
"color:#fff;\n"
"	font: 75 12pt \"Calibri\";\n"
"}\n"
"\n"
"QTableCornerButton::section{\n"
"border:none;\n"
"background-color:#149ED9;\n"
"}\n"
"\n"
"QListWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"}\n"
"\n"
"QMenu{\n"
"background-color:#3d3d3d;\n"
"}\n"
"QStatusBar{\n"
"background-color:#7e3878;\n"
"color:#fff;\n"
"}\n"
"\n"
"QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"QPushButton:hover{\n"
"color:#ccc;\n"
"	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"	border-color:#2d89ef;\n"
"border-width:2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x"
                        "1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"}\n"
"\n"
"\n"
"QTabWidget::tab{\n"
"background-color:#3d3d3d;\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-radius:0;\n"
"}\n"
"\n"
"QProgressBar{\n"
"border-radius:0;\n"
"text-align:center;\n"
"color:#fff;\n"
"background-color:transparent;\n"
"border: 2px solid #e3a21a;\n"
"border-radius:7px;\n"
"	font: 75 12pt \"Open Sans\";\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"background-color:#2d89ef;\n"
"width:20px;\n"
"}"));
        gridLayout = new QGridLayout(VEEllipseSettings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        comboBox = new QComboBox(VEEllipseSettings);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        fillingWidget = new QWidget(VEEllipseSettings);
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
        borderColor->setStyleSheet(QLatin1String("QLabel{\n"
"	border: 1px solid white;\n"
"	backgroud: white;	\n"
"	font-color:white;\n"
"}"));

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


        retranslateUi(VEEllipseSettings);

        QMetaObject::connectSlotsByName(VEEllipseSettings);
    } // setupUi

    void retranslateUi(QWidget *VEEllipseSettings)
    {
        VEEllipseSettings->setWindowTitle(QApplication::translate("VEEllipseSettings", "Form", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("VEEllipseSettings", "\346\227\240\346\225\210\346\236\234", 0)
         << QApplication::translate("VEEllipseSettings", "\346\270\220\345\217\230\345\241\253\345\205\205", 0)
        );
        borderColor->setText(QString());
        label_4->setText(QApplication::translate("VEEllipseSettings", "<font color=\"white\">\350\276\271\346\241\206\345\256\275\345\272\246</font>", 0));
        color_1->setText(QString());
        labelColor_1->setText(QApplication::translate("VEEllipseSettings", "<font color=\"white\">\351\242\234\350\211\2621</font>", 0));
        label_2->setText(QApplication::translate("VEEllipseSettings", "<font color=\"white\">\350\276\271\346\241\206\351\242\234\350\211\262</font>", 0));
        labelColor_2->setText(QApplication::translate("VEEllipseSettings", "<font color=\"white\">\351\242\234\350\211\2622</font>", 0));
        color_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VEEllipseSettings: public Ui_VEEllipseSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEELLIPSESETTINGS_H

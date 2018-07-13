/********************************************************************************
** Form generated from reading UI file 'showhelpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWHELPDIALOG_H
#define UI_SHOWHELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ShowHelpDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;

    void setupUi(QDialog *ShowHelpDialog)
    {
        if (ShowHelpDialog->objectName().isEmpty())
            ShowHelpDialog->setObjectName(QStringLiteral("ShowHelpDialog"));
        ShowHelpDialog->resize(448, 417);
        ShowHelpDialog->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:#qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));\n"
"}\n"
"\n"
""));
        pushButton = new QPushButton(ShowHelpDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 121, 161));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/QPainter.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(128, 128));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        label = new QLabel(ShowHelpDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 30, 141, 21));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(ShowHelpDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 50, 131, 31));
        label_3 = new QLabel(ShowHelpDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 80, 191, 16));
        label_4 = new QLabel(ShowHelpDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 110, 121, 16));
        label_5 = new QLabel(ShowHelpDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 280, 361, 91));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(11);
        font1.setItalic(false);
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::PlainText);
        pushButton_2 = new QPushButton(ShowHelpDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 370, 75, 23));
        label_6 = new QLabel(ShowHelpDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 140, 131, 16));
        label_7 = new QLabel(ShowHelpDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 180, 81, 16));
        label_8 = new QLabel(ShowHelpDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 180, 61, 16));
        label_9 = new QLabel(ShowHelpDialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(130, 200, 81, 16));
        label_10 = new QLabel(ShowHelpDialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(130, 220, 54, 12));
        label_11 = new QLabel(ShowHelpDialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(280, 140, 91, 16));
        label_12 = new QLabel(ShowHelpDialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(210, 180, 54, 12));
        label_13 = new QLabel(ShowHelpDialog);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(290, 180, 61, 16));
        label_14 = new QLabel(ShowHelpDialog);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(290, 200, 54, 12));
        label_15 = new QLabel(ShowHelpDialog);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 250, 54, 12));
        label_16 = new QLabel(ShowHelpDialog);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(100, 250, 231, 16));
        label_17 = new QLabel(ShowHelpDialog);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 400, 261, 16));

        retranslateUi(ShowHelpDialog);

        QMetaObject::connectSlotsByName(ShowHelpDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowHelpDialog)
    {
        ShowHelpDialog->setWindowTitle(QApplication::translate("ShowHelpDialog", "Dialog", 0));
        pushButton->setText(QString());
        label->setText(QApplication::translate("ShowHelpDialog", "QPainter 1.2.1", 0));
        label_2->setText(QApplication::translate("ShowHelpDialog", "Based on Qt 5.2", 0));
        label_3->setText(QApplication::translate("ShowHelpDialog", "Built on July 11 2018 at 12:00", 0));
        label_4->setText(QApplication::translate("ShowHelpDialog", "Copyright 2017-2020", 0));
        label_5->setText(QApplication::translate("ShowHelpDialog", "    This is an open source vector editing software that\n"
" is implemented as an object-oriented internship\n"
" project. The software is open source and can be used\n"
" privately.", 0));
        pushButton_2->setText(QApplication::translate("ShowHelpDialog", "Close", 0));
        label_6->setText(QApplication::translate("ShowHelpDialog", "<a style=\"color:blue;align:center;\" href=\"https://www.github.com/pprp/QPainter/\">\351\241\271\347\233\256\345\234\260\345\235\200</a>", 0));
        label_7->setText(QApplication::translate("ShowHelpDialog", "Members:", 0));
        label_8->setText(QApplication::translate("ShowHelpDialog", "Dongpeijie", 0));
        label_9->setText(QApplication::translate("ShowHelpDialog", "Wangzhengning", 0));
        label_10->setText(QApplication::translate("ShowHelpDialog", "Lianghui", 0));
        label_11->setText(QString());
        label_12->setText(QApplication::translate("ShowHelpDialog", "Teacher:", 0));
        label_13->setText(QApplication::translate("ShowHelpDialog", "Wangzepeng", 0));
        label_14->setText(QApplication::translate("ShowHelpDialog", "Yanglong", 0));
        label_15->setText(QApplication::translate("ShowHelpDialog", "college", 0));
        label_16->setText(QApplication::translate("ShowHelpDialog", "NWAFU Information Engineering College", 0));
        label_17->setText(QApplication::translate("ShowHelpDialog", "More: https://www.github.com/pprp/QPainter", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowHelpDialog: public Ui_ShowHelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWHELPDIALOG_H

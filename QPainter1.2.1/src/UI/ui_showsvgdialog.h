/********************************************************************************
** Form generated from reading UI file 'showsvgdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSVGDIALOG_H
#define UI_SHOWSVGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowSvgDialog
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QDialog *ShowSvgDialog)
    {
        if (ShowSvgDialog->objectName().isEmpty())
            ShowSvgDialog->setObjectName(QStringLiteral("ShowSvgDialog"));
        ShowSvgDialog->resize(400, 300);
        actionOpen = new QAction(ShowSvgDialog);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(ShowSvgDialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 100, 30));
        menuBar = new QMenuBar(ShowSvgDialog);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        mainToolBar = new QToolBar(ShowSvgDialog);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 4, 12));
        statusBar = new QStatusBar(ShowSvgDialog);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 18));

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(ShowSvgDialog);

        QMetaObject::connectSlotsByName(ShowSvgDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowSvgDialog)
    {
        ShowSvgDialog->setWindowTitle(QApplication::translate("ShowSvgDialog", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("ShowSvgDialog", "Open", 0));
        menuFile->setTitle(QApplication::translate("ShowSvgDialog", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowSvgDialog: public Ui_ShowSvgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSVGDIALOG_H

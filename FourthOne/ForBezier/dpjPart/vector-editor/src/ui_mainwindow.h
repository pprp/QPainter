/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "vepolylinesettings.h"
#include "verectanglesettings.h"
#include "veworkplaceview.h"
#include "veellipsesetting.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionCut;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *toolsWidget;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_clear;
    QToolButton *toolButton_pixmap;
    QToolButton *toolButton_text;
    QToolButton *toolButton_SaveAs;
    QToolButton *butLine;
    QToolButton *butOpen;
    QToolButton *butDefault;
    QToolButton *toolButton_curveLine;
    QToolButton *toolButton_ZoomOut;
    QToolButton *butRectangle;
    QToolButton *toolButton_ZoomIn;
    QToolButton *butSave;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButton_Home;
    QToolButton *cut;
    QToolButton *toolButton_copy;
    VEPolyLineSettings *polylineSettings;
    VERectangleSettings *rectangleSettings;
    VEEllipseSettings *ellipseSettings;
    QToolButton *toolButton_bezier;
    VEWorkplaceView *workplaceView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(795, 556);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/scene.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/cursor-openhand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon5);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolsWidget = new QWidget(splitter);
        toolsWidget->setObjectName(QStringLiteral("toolsWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolsWidget->sizePolicy().hasHeightForWidth());
        toolsWidget->setSizePolicy(sizePolicy);
        toolsWidget->setMinimumSize(QSize(120, 0));
        gridLayout_2 = new QGridLayout(toolsWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(toolsWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon7);
        toolButton->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton, 2, 2, 1, 1);

        toolButton_clear = new QToolButton(toolsWidget);
        toolButton_clear->setObjectName(QStringLiteral("toolButton_clear"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_clear->setIcon(icon8);
        toolButton_clear->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_clear, 1, 3, 1, 1);

        toolButton_pixmap = new QToolButton(toolsWidget);
        toolButton_pixmap->setObjectName(QStringLiteral("toolButton_pixmap"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/canvas.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_pixmap->setIcon(icon9);
        toolButton_pixmap->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_pixmap, 3, 3, 1, 1);

        toolButton_text = new QToolButton(toolsWidget);
        toolButton_text->setObjectName(QStringLiteral("toolButton_text"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_text->setIcon(icon10);
        toolButton_text->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_text, 3, 0, 1, 1);

        toolButton_SaveAs = new QToolButton(toolsWidget);
        toolButton_SaveAs->setObjectName(QStringLiteral("toolButton_SaveAs"));
        toolButton_SaveAs->setIcon(icon4);
        toolButton_SaveAs->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_SaveAs, 0, 2, 1, 1);

        butLine = new QToolButton(toolsWidget);
        butLine->setObjectName(QStringLiteral("butLine"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/\347\233\264\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        butLine->setIcon(icon11);
        butLine->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(butLine, 2, 0, 1, 1);

        butOpen = new QToolButton(toolsWidget);
        butOpen->setObjectName(QStringLiteral("butOpen"));
        butOpen->setEnabled(true);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        butOpen->setIcon(icon12);
        butOpen->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(butOpen, 0, 0, 1, 1);

        butDefault = new QToolButton(toolsWidget);
        butDefault->setObjectName(QStringLiteral("butDefault"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        butDefault->setIcon(icon13);
        butDefault->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(butDefault, 1, 2, 1, 1);

        toolButton_curveLine = new QToolButton(toolsWidget);
        toolButton_curveLine->setObjectName(QStringLiteral("toolButton_curveLine"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/\346\233\262\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_curveLine->setIcon(icon14);
        toolButton_curveLine->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_curveLine, 2, 1, 1, 1);

        toolButton_ZoomOut = new QToolButton(toolsWidget);
        toolButton_ZoomOut->setObjectName(QStringLiteral("toolButton_ZoomOut"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/zoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ZoomOut->setIcon(icon15);
        toolButton_ZoomOut->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_ZoomOut, 1, 1, 1, 1);

        butRectangle = new QToolButton(toolsWidget);
        butRectangle->setObjectName(QStringLiteral("butRectangle"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        butRectangle->setIcon(icon16);
        butRectangle->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(butRectangle, 2, 3, 1, 1);

        toolButton_ZoomIn = new QToolButton(toolsWidget);
        toolButton_ZoomIn->setObjectName(QStringLiteral("toolButton_ZoomIn"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/icons/zoomIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ZoomIn->setIcon(icon17);
        toolButton_ZoomIn->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_ZoomIn, 1, 0, 1, 1);

        butSave = new QToolButton(toolsWidget);
        butSave->setObjectName(QStringLiteral("butSave"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/icons/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        butSave->setIcon(icon18);
        butSave->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(butSave, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 4);

        toolButton_Home = new QToolButton(toolsWidget);
        toolButton_Home->setObjectName(QStringLiteral("toolButton_Home"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/icons/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Home->setIcon(icon19);
        toolButton_Home->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_Home, 3, 1, 1, 1);

        cut = new QToolButton(toolsWidget);
        cut->setObjectName(QStringLiteral("cut"));
        cut->setIcon(icon6);
        cut->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(cut, 3, 2, 1, 1);

        toolButton_copy = new QToolButton(toolsWidget);
        toolButton_copy->setObjectName(QStringLiteral("toolButton_copy"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_copy->setIcon(icon20);
        toolButton_copy->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_copy, 0, 3, 1, 1);

        polylineSettings = new VEPolyLineSettings(toolsWidget);
        polylineSettings->setObjectName(QStringLiteral("polylineSettings"));
        polylineSettings->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(polylineSettings, 6, 0, 1, 4);

        rectangleSettings = new VERectangleSettings(toolsWidget);
        rectangleSettings->setObjectName(QStringLiteral("rectangleSettings"));
        rectangleSettings->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(rectangleSettings, 5, 0, 1, 4);

        ellipseSettings = new VEEllipseSettings(toolsWidget);
        ellipseSettings->setObjectName(QStringLiteral("ellipseSettings"));
        ellipseSettings->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(ellipseSettings, 5, 0, 1, 4);

        toolButton_bezier = new QToolButton(toolsWidget);
        toolButton_bezier->setObjectName(QStringLiteral("toolButton_bezier"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/icons/bezier.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_bezier->setIcon(icon21);
        toolButton_bezier->setIconSize(QSize(24, 24));

        gridLayout_2->addWidget(toolButton_bezier, 4, 0, 1, 1);

        splitter->addWidget(toolsWidget);
        workplaceView = new VEWorkplaceView(splitter);
        workplaceView->setObjectName(QStringLiteral("workplaceView"));
        splitter->addWidget(workplaceView);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 795, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addSeparator();
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addSeparator();
        menu->addAction(actionCut);
        menu->addAction(actionExit);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Readme", 0));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "SaveAs", 0));
        actionSaveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_clear->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_pixmap->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_text->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_SaveAs->setText(QApplication::translate("MainWindow", "...", 0));
        butLine->setText(QApplication::translate("MainWindow", "...", 0));
        butOpen->setText(QApplication::translate("MainWindow", "...", 0));
        butDefault->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_curveLine->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_ZoomOut->setText(QApplication::translate("MainWindow", "...", 0));
        butRectangle->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_ZoomIn->setText(QApplication::translate("MainWindow", "...", 0));
        butSave->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_Home->setText(QApplication::translate("MainWindow", "...", 0));
        cut->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_copy->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_bezier->setText(QApplication::translate("MainWindow", "...", 0));
        menu->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

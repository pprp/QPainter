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
#include "veellipsesettings.h"
#include "vepolylinesettings.h"
#include "verectanglesettings.h"
#include "veworkplaceview.h"

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
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *toolsWidget;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_ellipse;
    QToolButton *toolButton_text;
    QToolButton *toolButton_SaveAs;
    QToolButton *butLine;
    QToolButton *butOpen;
    QToolButton *butDefault;
    QToolButton *toolButton_ZoomOut;
    QToolButton *toolButton_ZoomIn;
    QToolButton *butSave;
    QToolButton *toolButton_Home;
    QToolButton *toolButton_bezier;
    QToolButton *butRectangle;
    QToolButton *toolButton_clear;
    QToolButton *toolButton_pixmap;
    VEPolyLineSettings *polylineSettings;
    QSpacerItem *verticalSpacer;
    VERectangleSettings *rectangleSettings;
    VEEllipseSettings *ellipseSettings;
    QToolButton *toolButton_show;
    VEWorkplaceView *workplaceView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuHelp;
    QMenu *menuTool;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(795, 556);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow{\n"
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
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/zoomIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon6);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/zoomOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon7);
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
        toolButton_ellipse = new QToolButton(toolsWidget);
        toolButton_ellipse->setObjectName(QStringLiteral("toolButton_ellipse"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ellipse->setIcon(icon8);
        toolButton_ellipse->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_ellipse, 2, 2, 1, 1);

        toolButton_text = new QToolButton(toolsWidget);
        toolButton_text->setObjectName(QStringLiteral("toolButton_text"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_text->setIcon(icon9);
        toolButton_text->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_text, 3, 0, 1, 1);

        toolButton_SaveAs = new QToolButton(toolsWidget);
        toolButton_SaveAs->setObjectName(QStringLiteral("toolButton_SaveAs"));
        toolButton_SaveAs->setIcon(icon4);
        toolButton_SaveAs->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_SaveAs, 0, 2, 1, 1);

        butLine = new QToolButton(toolsWidget);
        butLine->setObjectName(QStringLiteral("butLine"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/\347\233\264\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        butLine->setIcon(icon10);
        butLine->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(butLine, 2, 0, 1, 1);

        butOpen = new QToolButton(toolsWidget);
        butOpen->setObjectName(QStringLiteral("butOpen"));
        butOpen->setEnabled(true);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        butOpen->setIcon(icon11);
        butOpen->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(butOpen, 0, 0, 1, 1);

        butDefault = new QToolButton(toolsWidget);
        butDefault->setObjectName(QStringLiteral("butDefault"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        butDefault->setIcon(icon12);
        butDefault->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(butDefault, 1, 2, 1, 1);

        toolButton_ZoomOut = new QToolButton(toolsWidget);
        toolButton_ZoomOut->setObjectName(QStringLiteral("toolButton_ZoomOut"));
        toolButton_ZoomOut->setIcon(icon7);
        toolButton_ZoomOut->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_ZoomOut, 1, 1, 1, 1);

        toolButton_ZoomIn = new QToolButton(toolsWidget);
        toolButton_ZoomIn->setObjectName(QStringLiteral("toolButton_ZoomIn"));
        toolButton_ZoomIn->setIcon(icon6);
        toolButton_ZoomIn->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_ZoomIn, 1, 0, 1, 1);

        butSave = new QToolButton(toolsWidget);
        butSave->setObjectName(QStringLiteral("butSave"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        butSave->setIcon(icon13);
        butSave->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(butSave, 0, 1, 1, 1);

        toolButton_Home = new QToolButton(toolsWidget);
        toolButton_Home->setObjectName(QStringLiteral("toolButton_Home"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icons/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Home->setIcon(icon14);
        toolButton_Home->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_Home, 3, 1, 1, 1);

        toolButton_bezier = new QToolButton(toolsWidget);
        toolButton_bezier->setObjectName(QStringLiteral("toolButton_bezier"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/bezier.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_bezier->setIcon(icon15);
        toolButton_bezier->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_bezier, 2, 1, 1, 1);

        butRectangle = new QToolButton(toolsWidget);
        butRectangle->setObjectName(QStringLiteral("butRectangle"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        butRectangle->setIcon(icon16);
        butRectangle->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(butRectangle, 3, 2, 1, 1);

        toolButton_clear = new QToolButton(toolsWidget);
        toolButton_clear->setObjectName(QStringLiteral("toolButton_clear"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_clear->setIcon(icon17);
        toolButton_clear->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_clear, 4, 0, 1, 1);

        toolButton_pixmap = new QToolButton(toolsWidget);
        toolButton_pixmap->setObjectName(QStringLiteral("toolButton_pixmap"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/icons/canvas.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_pixmap->setIcon(icon18);
        toolButton_pixmap->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_pixmap, 4, 1, 1, 1);

        polylineSettings = new VEPolyLineSettings(toolsWidget);
        polylineSettings->setObjectName(QStringLiteral("polylineSettings"));
        polylineSettings->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(polylineSettings, 6, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 3);

        rectangleSettings = new VERectangleSettings(toolsWidget);
        rectangleSettings->setObjectName(QStringLiteral("rectangleSettings"));
        rectangleSettings->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(rectangleSettings, 5, 0, 1, 3);

        ellipseSettings = new VEEllipseSettings(toolsWidget);
        ellipseSettings->setObjectName(QStringLiteral("ellipseSettings"));
        ellipseSettings->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(ellipseSettings, 5, 0, 1, 3);

        toolButton_show = new QToolButton(toolsWidget);
        toolButton_show->setObjectName(QStringLiteral("toolButton_show"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/icons/add_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_show->setIcon(icon19);
        toolButton_show->setIconSize(QSize(31, 31));

        gridLayout_2->addWidget(toolButton_show, 4, 2, 1, 1);

        splitter->addWidget(toolsWidget);
        workplaceView = new VEWorkplaceView(splitter);
        workplaceView->setObjectName(QStringLiteral("workplaceView"));
        workplaceView->setMaximumSize(QSize(16777195, 16777215));
        workplaceView->setStyleSheet(QStringLiteral(""));
        splitter->addWidget(workplaceView);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 795, 39));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addSeparator();
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addSeparator();
        menu->addAction(actionExit);
        menuHelp->addAction(actionHelp);
        menuTool->addAction(actionZoomIn);
        menuTool->addAction(actionZoomOut);

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
        actionZoomIn->setText(QApplication::translate("MainWindow", "ZoomIn", 0));
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "ZoomOut", 0));
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        toolButton_ellipse->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_text->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_SaveAs->setText(QApplication::translate("MainWindow", "...", 0));
        butLine->setText(QApplication::translate("MainWindow", "...", 0));
        butOpen->setText(QApplication::translate("MainWindow", "...", 0));
        butDefault->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_ZoomOut->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_ZoomIn->setText(QApplication::translate("MainWindow", "...", 0));
        butSave->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_Home->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_bezier->setText(QApplication::translate("MainWindow", "...", 0));
        butRectangle->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_clear->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_pixmap->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_show->setText(QApplication::translate("MainWindow", "...", 0));
        menu->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuTool->setTitle(QApplication::translate("MainWindow", "Tool", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

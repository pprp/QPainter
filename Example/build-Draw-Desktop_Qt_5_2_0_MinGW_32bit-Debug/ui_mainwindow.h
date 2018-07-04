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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionZoomIn;
    QAction *actionReturn;
    QAction *actionRotate;
    QAction *actionStretch;
    QAction *actionDrawingToolbar;
    QAction *actionAbout_Draw;
    QAction *actionZoomOut;
    QAction *actionClear;
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *DrawTools;
    QWidget *dockWidgetContents;
    QLabel *label;
    QSpinBox *penWidthspinBox;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *shapeComboBox;
    QComboBox *penStyleComboBox;
    QLabel *label_4;
    QComboBox *penColorComboBox;
    QLabel *label_5;
    QComboBox *brushColorComboBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTool;
    QMenu *menuHelp;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(761, 459);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionNew->setCheckable(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setCheckable(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSaveAs->setCheckable(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setCheckable(true);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon1);
        actionReturn = new QAction(MainWindow);
        actionReturn->setObjectName(QStringLiteral("actionReturn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/cursor-openhand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReturn->setIcon(icon2);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon3);
        actionStretch = new QAction(MainWindow);
        actionStretch->setObjectName(QStringLiteral("actionStretch"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/cursor-sizeall.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStretch->setIcon(icon4);
        actionDrawingToolbar = new QAction(MainWindow);
        actionDrawingToolbar->setObjectName(QStringLiteral("actionDrawingToolbar"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrawingToolbar->setIcon(icon5);
        actionAbout_Draw = new QAction(MainWindow);
        actionAbout_Draw->setObjectName(QStringLiteral("actionAbout_Draw"));
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon6);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/cursor-forbidden.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        DrawTools = new QDockWidget(MainWindow);
        DrawTools->setObjectName(QStringLiteral("DrawTools"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 54, 12));
        penWidthspinBox = new QSpinBox(dockWidgetContents);
        penWidthspinBox->setObjectName(QStringLiteral("penWidthspinBox"));
        penWidthspinBox->setGeometry(QRect(10, 130, 61, 22));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 54, 12));
        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 54, 12));
        shapeComboBox = new QComboBox(dockWidgetContents);
        shapeComboBox->setObjectName(QStringLiteral("shapeComboBox"));
        shapeComboBox->setGeometry(QRect(10, 30, 61, 22));
        penStyleComboBox = new QComboBox(dockWidgetContents);
        penStyleComboBox->setObjectName(QStringLiteral("penStyleComboBox"));
        penStyleComboBox->setGeometry(QRect(10, 80, 61, 22));
        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 54, 12));
        penColorComboBox = new QComboBox(dockWidgetContents);
        penColorComboBox->setObjectName(QStringLiteral("penColorComboBox"));
        penColorComboBox->setGeometry(QRect(10, 180, 61, 22));
        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 210, 54, 12));
        brushColorComboBox = new QComboBox(dockWidgetContents);
        brushColorComboBox->setObjectName(QStringLiteral("brushColorComboBox"));
        brushColorComboBox->setGeometry(QRect(10, 230, 61, 22));
        DrawTools->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DrawTools);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 761, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        dockWidget->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        mainToolBar->addAction(actionStretch);
        mainToolBar->addAction(actionZoomIn);
        mainToolBar->addAction(actionZoomOut);
        mainToolBar->addAction(actionRotate);
        mainToolBar->addAction(actionReturn);
        mainToolBar->addAction(actionClear);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionExit);
        menuTool->addAction(actionDrawingToolbar);
        menuHelp->addAction(actionAbout_Draw);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New(&N)", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open(&O)", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save(&S)", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "SaveAs(&A)", 0));
        actionSaveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit(&X)", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionZoomIn->setText(QApplication::translate("MainWindow", "ZoomIn", 0));
        actionReturn->setText(QApplication::translate("MainWindow", "Return", 0));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate", 0));
        actionStretch->setText(QApplication::translate("MainWindow", "Stretch", 0));
        actionDrawingToolbar->setText(QApplication::translate("MainWindow", "DrawingToolbar", 0));
        actionAbout_Draw->setText(QApplication::translate("MainWindow", "About Draw", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "ZoomOut", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomOut->setToolTip(QApplication::translate("MainWindow", "ZoomOut", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        label->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\345\275\242", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224\347\272\277\345\256\275", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224\347\261\273\345\236\213", 0));
        shapeComboBox->clear();
        shapeComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\227\240", 0)
         << QApplication::translate("MainWindow", "\347\237\251\345\275\242", 0)
         << QApplication::translate("MainWindow", "\346\244\255\345\234\206", 0)
         << QApplication::translate("MainWindow", "\345\256\236\347\272\277", 0)
        );
        penStyleComboBox->clear();
        penStyleComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\256\236\347\272\277", 0)
         << QApplication::translate("MainWindow", "\346\233\262\347\272\277", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224\351\242\234\350\211\262", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\241\253\345\205\205\351\242\234\350\211\262", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuTool->setTitle(QApplication::translate("MainWindow", "Tool", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

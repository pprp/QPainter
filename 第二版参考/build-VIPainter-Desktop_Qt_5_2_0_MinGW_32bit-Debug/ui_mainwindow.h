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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPen;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionRotate;
    QAction *actionRedo;
    QAction *actionChoose;
    QAction *actionMove;
    QAction *actionResume;
    QAction *actionCanvasSize;
    QAction *actionShapeSize;
    QAction *actionBreakUp;
    QAction *actionReloadPlugon;
    QAction *actionLoadExPlugin;
    QAction *actionAntialiasing;
    QAction *actionDelete;
    QAction *actionPaste;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionGroup;
    QAction *actionSelectAll;
    QAction *actionPenColor;
    QAction *actionBrushColor;
    QAction *actionPenStyle;
    QAction *actionCurveLine;
    QAction *actionPolyLine;
    QAction *actionAbout;
    QAction *actionUndo;
    QAction *actionForceGroup;
    QAction *actionTest;
    QAction *actionNewImage;
    QAction *actionMarquee;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuLineStyle;
    QMenu *menu_3;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *shapeBar;
    QDockWidget *shapesDock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1206, 786);
        MainWindow->setAcceptDrops(true);
        actionPen = new QAction(MainWindow);
        actionPen->setObjectName(QStringLiteral("actionPen"));
        actionPen->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPen->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon1);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon2);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionRotate->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon3);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon4);
        actionChoose = new QAction(MainWindow);
        actionChoose->setObjectName(QStringLiteral("actionChoose"));
        actionChoose->setCheckable(true);
        actionChoose->setChecked(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChoose->setIcon(icon5);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QStringLiteral("actionMove"));
        actionMove->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/hand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon6);
        actionResume = new QAction(MainWindow);
        actionResume->setObjectName(QStringLiteral("actionResume"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/zoomzero.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResume->setIcon(icon7);
        actionCanvasSize = new QAction(MainWindow);
        actionCanvasSize->setObjectName(QStringLiteral("actionCanvasSize"));
        actionCanvasSize->setCheckable(false);
        actionCanvasSize->setChecked(false);
        actionShapeSize = new QAction(MainWindow);
        actionShapeSize->setObjectName(QStringLiteral("actionShapeSize"));
        actionBreakUp = new QAction(MainWindow);
        actionBreakUp->setObjectName(QStringLiteral("actionBreakUp"));
        actionReloadPlugon = new QAction(MainWindow);
        actionReloadPlugon->setObjectName(QStringLiteral("actionReloadPlugon"));
        actionLoadExPlugin = new QAction(MainWindow);
        actionLoadExPlugin->setObjectName(QStringLiteral("actionLoadExPlugin"));
        actionAntialiasing = new QAction(MainWindow);
        actionAntialiasing->setObjectName(QStringLiteral("actionAntialiasing"));
        actionAntialiasing->setCheckable(true);
        actionAntialiasing->setChecked(true);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionGroup = new QAction(MainWindow);
        actionGroup->setObjectName(QStringLiteral("actionGroup"));
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        actionPenColor = new QAction(MainWindow);
        actionPenColor->setObjectName(QStringLiteral("actionPenColor"));
        actionBrushColor = new QAction(MainWindow);
        actionBrushColor->setObjectName(QStringLiteral("actionBrushColor"));
        actionPenStyle = new QAction(MainWindow);
        actionPenStyle->setObjectName(QStringLiteral("actionPenStyle"));
        actionCurveLine = new QAction(MainWindow);
        actionCurveLine->setObjectName(QStringLiteral("actionCurveLine"));
        actionCurveLine->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/Bezier.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCurveLine->setIcon(icon8);
        actionPolyLine = new QAction(MainWindow);
        actionPolyLine->setObjectName(QStringLiteral("actionPolyLine"));
        actionPolyLine->setCheckable(true);
        actionPolyLine->setChecked(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/PolyLine.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolyLine->setIcon(icon9);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionForceGroup = new QAction(MainWindow);
        actionForceGroup->setObjectName(QStringLiteral("actionForceGroup"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        actionNewImage = new QAction(MainWindow);
        actionNewImage->setObjectName(QStringLiteral("actionNewImage"));
        actionMarquee = new QAction(MainWindow);
        actionMarquee->setObjectName(QStringLiteral("actionMarquee"));
        actionMarquee->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icon/marquee.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMarquee->setIcon(icon10);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1206, 29));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuLineStyle = new QMenu(menu_2);
        menuLineStyle->setObjectName(QStringLiteral("menuLineStyle"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        shapeBar = new QToolBar(MainWindow);
        shapeBar->setObjectName(QStringLiteral("shapeBar"));
        shapeBar->setMinimumSize(QSize(30, 0));
        shapeBar->setAcceptDrops(true);
        shapeBar->setAllowedAreas(Qt::AllToolBarAreas);
        shapeBar->setOrientation(Qt::Vertical);
        MainWindow->addToolBar(Qt::LeftToolBarArea, shapeBar);
        shapesDock = new QDockWidget(MainWindow);
        shapesDock->setObjectName(QStringLiteral("shapesDock"));
        shapesDock->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shapesDock->sizePolicy().hasHeightForWidth());
        shapesDock->setSizePolicy(sizePolicy);
        shapesDock->setMaximumSize(QSize(524287, 524287));
        shapesDock->setFloating(false);
        shapesDock->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shapesDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), shapesDock);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu->addAction(actionNewImage);
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addSeparator();
        menu->addAction(actionClose);
        menu_2->addAction(actionCanvasSize);
        menu_2->addAction(actionShapeSize);
        menu_2->addSeparator();
        menu_2->addAction(actionAntialiasing);
        menu_2->addSeparator();
        menu_2->addAction(menuLineStyle->menuAction());
        menuLineStyle->addAction(actionCurveLine);
        menuLineStyle->addAction(actionPolyLine);
        menu_3->addAction(actionReloadPlugon);
        menu_3->addAction(actionLoadExPlugin);
        menuEdit->addAction(actionSelectAll);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addSeparator();
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionGroup);
        menuEdit->addAction(actionForceGroup);
        menuEdit->addAction(actionBreakUp);
        menuEdit->addAction(actionDelete);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionChoose);
        mainToolBar->addAction(actionMarquee);
        mainToolBar->addAction(actionMove);
        mainToolBar->addAction(actionRotate);
        mainToolBar->addAction(actionPen);
        mainToolBar->addAction(actionPolyLine);
        mainToolBar->addAction(actionCurveLine);
        mainToolBar->addAction(actionZoomIn);
        mainToolBar->addAction(actionZoomOut);
        mainToolBar->addAction(actionResume);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionPen->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224", 0));
#ifndef QT_NO_TOOLTIP
        actionPen->setToolTip(QApplication::translate("MainWindow", "\347\224\273\347\254\224", 0));
#endif // QT_NO_TOOLTIP
        actionPen->setShortcut(QApplication::translate("MainWindow", "5", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        actionOpen->setIconText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\237\242\351\207\217\345\233\276", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+N", 0));
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", 0));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", 0));
        actionSaveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionZoomIn->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomIn->setToolTip(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
#endif // QT_NO_TOOLTIP
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomOut->setToolTip(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
#endif // QT_NO_TOOLTIP
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        actionRotate->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate->setToolTip(QApplication::translate("MainWindow", "\346\227\213\350\275\254", 0));
#endif // QT_NO_TOOLTIP
        actionRotate->setShortcut(QApplication::translate("MainWindow", "4", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215", 0));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("MainWindow", "\346\201\242\345\244\215", 0));
#endif // QT_NO_TOOLTIP
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        actionChoose->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", 0));
#ifndef QT_NO_TOOLTIP
        actionChoose->setToolTip(QApplication::translate("MainWindow", "\351\200\211\346\213\251", 0));
#endif // QT_NO_TOOLTIP
        actionChoose->setShortcut(QApplication::translate("MainWindow", "1", 0));
        actionMove->setText(QApplication::translate("MainWindow", "\347\247\273\345\212\250", 0));
#ifndef QT_NO_TOOLTIP
        actionMove->setToolTip(QApplication::translate("MainWindow", "\347\247\273\345\212\250", 0));
#endif // QT_NO_TOOLTIP
        actionMove->setShortcut(QApplication::translate("MainWindow", "3", 0));
        actionResume->setText(QApplication::translate("MainWindow", "\350\277\230\345\216\237", 0));
#ifndef QT_NO_TOOLTIP
        actionResume->setToolTip(QApplication::translate("MainWindow", "\350\277\230\345\216\237", 0));
#endif // QT_NO_TOOLTIP
        actionResume->setShortcut(QApplication::translate("MainWindow", "0", 0));
        actionCanvasSize->setText(QApplication::translate("MainWindow", "\347\224\273\345\270\203\345\244\247\345\260\217", 0));
        actionCanvasSize->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+C", 0));
        actionShapeSize->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\247\345\260\217", 0));
        actionShapeSize->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+I", 0));
        actionBreakUp->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210\347\273\204\345\220\210", 0));
#ifndef QT_NO_TOOLTIP
        actionBreakUp->setToolTip(QApplication::translate("MainWindow", "\345\217\226\346\266\210\347\273\204\345\220\210", 0));
#endif // QT_NO_TOOLTIP
        actionBreakUp->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0));
        actionReloadPlugon->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\212\240\350\275\275\346\217\222\344\273\266", 0));
        actionLoadExPlugin->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\345\244\226\351\203\250\346\217\222\344\273\266", 0));
        actionAntialiasing->setText(QApplication::translate("MainWindow", "\345\217\215\350\265\260\346\240\267", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244", 0));
#endif // QT_NO_TOOLTIP
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", 0));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", 0));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionGroup->setText(QApplication::translate("MainWindow", "\347\273\204\345\220\210", 0));
#ifndef QT_NO_TOOLTIP
        actionGroup->setToolTip(QApplication::translate("MainWindow", "\347\273\204\345\220\210", 0));
#endif // QT_NO_TOOLTIP
        actionGroup->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0));
        actionSelectAll->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", 0));
        actionSelectAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actionPenColor->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\234\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        actionPenColor->setToolTip(QApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\234\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        actionBrushColor->setText(QApplication::translate("MainWindow", "\345\241\253\345\205\205\351\242\234\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        actionBrushColor->setToolTip(QApplication::translate("MainWindow", "\345\241\253\345\205\205\351\242\234\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        actionPenStyle->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        actionPenStyle->setToolTip(QApplication::translate("MainWindow", "\347\272\277\346\235\241\350\256\276\347\275\256", 0));
#endif // QT_NO_TOOLTIP
        actionCurveLine->setText(QApplication::translate("MainWindow", "\346\233\262\347\272\277", 0));
        actionPolyLine->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216&VIPainter", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", 0));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainWindow", "\346\222\244\351\224\200", 0));
#endif // QT_NO_TOOLTIP
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionForceGroup->setText(QApplication::translate("MainWindow", "\345\274\272\347\273\204\345\220\210", 0));
#ifndef QT_NO_TOOLTIP
        actionForceGroup->setToolTip(QApplication::translate("MainWindow", "\345\274\272\347\273\204\345\220\210", 0));
#endif // QT_NO_TOOLTIP
        actionForceGroup->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+G", 0));
        actionTest->setText(QApplication::translate("MainWindow", "test", 0));
        actionNewImage->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\224\273\345\233\276", 0));
#ifndef QT_NO_TOOLTIP
        actionNewImage->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\224\273\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        actionNewImage->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionMarquee->setText(QApplication::translate("MainWindow", "\351\200\211\346\241\206", 0));
#ifndef QT_NO_TOOLTIP
        actionMarquee->setToolTip(QApplication::translate("MainWindow", "\351\200\211\346\241\206", 0));
#endif // QT_NO_TOOLTIP
        actionMarquee->setShortcut(QApplication::translate("MainWindow", "2", 0));
#ifndef QT_NO_TOOLTIP
        menuBar->setToolTip(QApplication::translate("MainWindow", "\350\217\234\345\215\225", 0));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217", 0));
        menuLineStyle->setTitle(QApplication::translate("MainWindow", "\347\272\277\346\235\241\346\240\267\345\274\217", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\217\222\344\273\266", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "\346\216\247\344\273\266", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
#ifndef QT_NO_TOOLTIP
        mainToolBar->setToolTip(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
#endif // QT_NO_TOOLTIP
        shapeBar->setWindowTitle(QApplication::translate("MainWindow", "\346\217\222\344\273\266\346\240\217", 0));
#ifndef QT_NO_TOOLTIP
        shapeBar->setToolTip(QApplication::translate("MainWindow", "\346\217\222\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        shapesDock->setToolTip(QApplication::translate("MainWindow", "\345\275\242\347\212\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        shapesDock->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        shapesDock->setWindowTitle(QApplication::translate("MainWindow", "\345\244\232\345\212\237\350\203\275\346\240\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

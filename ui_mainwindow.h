/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Close;
    QAction *action_Save;
    QAction *action_SaveAs;
    QAction *action_Exit;
    QAction *action_Undo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Paste;
    QAction *action_Find;
    QAction *actiontest;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *titletabWidget;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menujhkjhk;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(550, 401);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/wintitle.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/e/icon/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon1);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/e/icon/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon2);
        action_Close = new QAction(MainWindow);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/e/icon/gtk-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Close->setIcon(icon3);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/e/icon/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon4);
        action_SaveAs = new QAction(MainWindow);
        action_SaveAs->setObjectName(QStringLiteral("action_SaveAs"));
        QIcon icon5;
        QString iconThemeName = QStringLiteral("save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QStringLiteral(":/e/icon/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        action_SaveAs->setIcon(icon5);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/e/icon/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon6);
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/e/icon/edit-redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Undo->setIcon(icon7);
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/e/icon/edit-cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon8);
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/e/icon/edit-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Copy->setIcon(icon9);
        action_Paste = new QAction(MainWindow);
        action_Paste->setObjectName(QStringLiteral("action_Paste"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/e/icon/edit-paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Paste->setIcon(icon10);
        action_Find = new QAction(MainWindow);
        action_Find->setObjectName(QStringLiteral("action_Find"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/e/icon/edit-find.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Find->setIcon(icon11);
        actiontest = new QAction(MainWindow);
        actiontest->setObjectName(QStringLiteral("actiontest"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titletabWidget = new QTabWidget(centralWidget);
        titletabWidget->setObjectName(QStringLiteral("titletabWidget"));
        titletabWidget->setTabsClosable(true);
        titletabWidget->setMovable(true);
        titletabWidget->setTabBarAutoHide(false);

        verticalLayout->addWidget(titletabWidget);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menujhkjhk = new QMenu(menuBar);
        menujhkjhk->setObjectName(QStringLiteral("menujhkjhk"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menujhkjhk->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(action_New);
        menu_F->addAction(action_Open);
        menu_F->addAction(action_Close);
        menu_F->addSeparator();
        menu_F->addAction(action_Save);
        menu_F->addAction(action_SaveAs);
        menu_F->addSeparator();
        menu_F->addAction(action_Exit);
        menujhkjhk->addAction(action_Undo);
        menujhkjhk->addSeparator();
        menujhkjhk->addAction(action_Cut);
        menujhkjhk->addAction(action_Copy);
        menujhkjhk->addAction(action_Paste);
        menujhkjhk->addSeparator();
        menujhkjhk->addAction(action_Find);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Undo);
        mainToolBar->addAction(action_Cut);
        mainToolBar->addAction(action_Copy);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Find);

        retranslateUi(MainWindow);

        titletabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_New->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_New->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", Q_NULLPTR));
        action_Close->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", Q_NULLPTR));
        action_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", Q_NULLPTR));
        action_SaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", Q_NULLPTR));
        action_Exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", Q_NULLPTR));
        action_Undo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&Z)", Q_NULLPTR));
        action_Cut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&X)", Q_NULLPTR));
        action_Copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", Q_NULLPTR));
        action_Paste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&V)", Q_NULLPTR));
        action_Find->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276(&F)", Q_NULLPTR));
        actiontest->setText(QApplication::translate("MainWindow", "test", Q_NULLPTR));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menujhkjhk->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251\357\274\210&H\357\274\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *gB_AvailablePlayers;
    QTableWidget *tW_availablePlayers;
    QPushButton *pB_requestNewGame;
    QPushButton *pB_logout;
    QGroupBox *gB_board;
    QPushButton *pB_resign;
    QLCDNumber *lcd_time;
    QFrame *line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 900);
        MainWindow->setMinimumSize(QSize(1920, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gB_AvailablePlayers = new QGroupBox(centralWidget);
        gB_AvailablePlayers->setObjectName(QStringLiteral("gB_AvailablePlayers"));
        gB_AvailablePlayers->setGeometry(QRect(1660, 40, 250, 800));
        tW_availablePlayers = new QTableWidget(gB_AvailablePlayers);
        tW_availablePlayers->setObjectName(QStringLiteral("tW_availablePlayers"));
        tW_availablePlayers->setGeometry(QRect(10, 30, 230, 711));
        tW_availablePlayers->setFocusPolicy(Qt::NoFocus);
        tW_availablePlayers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tW_availablePlayers->setSelectionMode(QAbstractItemView::SingleSelection);
        tW_availablePlayers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tW_availablePlayers->setSortingEnabled(true);
        tW_availablePlayers->horizontalHeader()->setCascadingSectionResizes(true);
        tW_availablePlayers->horizontalHeader()->setDefaultSectionSize(115);
        pB_requestNewGame = new QPushButton(gB_AvailablePlayers);
        pB_requestNewGame->setObjectName(QStringLiteral("pB_requestNewGame"));
        pB_requestNewGame->setGeometry(QRect(10, 750, 221, 22));
        pB_logout = new QPushButton(centralWidget);
        pB_logout->setObjectName(QStringLiteral("pB_logout"));
        pB_logout->setGeometry(QRect(1660, 10, 251, 22));
        gB_board = new QGroupBox(centralWidget);
        gB_board->setObjectName(QStringLiteral("gB_board"));
        gB_board->setEnabled(false);
        gB_board->setGeometry(QRect(10, 0, 1641, 841));
        pB_resign = new QPushButton(gB_board);
        pB_resign->setObjectName(QStringLiteral("pB_resign"));
        pB_resign->setGeometry(QRect(1250, 30, 241, 31));
        lcd_time = new QLCDNumber(gB_board);
        lcd_time->setObjectName(QStringLiteral("lcd_time"));
        lcd_time->setGeometry(QRect(1500, 30, 121, 31));
        line = new QFrame(gB_board);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(17, 60, 1611, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        gB_AvailablePlayers->setTitle(QApplication::translate("MainWindow", "List of available users", Q_NULLPTR));
        pB_requestNewGame->setText(QApplication::translate("MainWindow", "Request New Game", Q_NULLPTR));
        pB_logout->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        gB_board->setTitle(QString());
        pB_resign->setText(QApplication::translate("MainWindow", "Resign", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

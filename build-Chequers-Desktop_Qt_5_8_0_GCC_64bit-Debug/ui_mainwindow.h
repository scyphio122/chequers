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
    QFrame *line;
    QTableWidget *tW_board;
    QLCDNumber *lcd_time;
    QPushButton *pB_resign;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1090, 900);
        MainWindow->setMinimumSize(QSize(1090, 900));
        MainWindow->setMaximumSize(QSize(1090, 900));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gB_AvailablePlayers = new QGroupBox(centralWidget);
        gB_AvailablePlayers->setObjectName(QStringLiteral("gB_AvailablePlayers"));
        gB_AvailablePlayers->setGeometry(QRect(830, 40, 250, 800));
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
        pB_logout->setGeometry(QRect(830, 10, 251, 22));
        gB_board = new QGroupBox(centralWidget);
        gB_board->setObjectName(QStringLiteral("gB_board"));
        gB_board->setEnabled(false);
        gB_board->setGeometry(QRect(10, 0, 811, 841));
        line = new QFrame(gB_board);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(7, 60, 791, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tW_board = new QTableWidget(gB_board);
        if (tW_board->columnCount() < 8)
            tW_board->setColumnCount(8);
        if (tW_board->rowCount() < 8)
            tW_board->setRowCount(8);
        tW_board->setObjectName(QStringLiteral("tW_board"));
        tW_board->setGeometry(QRect(30, 80, 744, 744));
        tW_board->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tW_board->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tW_board->setAutoScroll(false);
        tW_board->setAutoScrollMargin(0);
        tW_board->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tW_board->setSelectionMode(QAbstractItemView::SingleSelection);
        tW_board->setShowGrid(true);
        tW_board->setWordWrap(true);
        tW_board->setRowCount(8);
        tW_board->setColumnCount(8);
        tW_board->horizontalHeader()->setVisible(false);
        tW_board->horizontalHeader()->setCascadingSectionResizes(false);
        tW_board->horizontalHeader()->setDefaultSectionSize(93);
        tW_board->horizontalHeader()->setMinimumSectionSize(0);
        tW_board->verticalHeader()->setVisible(false);
        tW_board->verticalHeader()->setDefaultSectionSize(93);
        tW_board->verticalHeader()->setHighlightSections(true);
        tW_board->verticalHeader()->setMinimumSectionSize(80);
        lcd_time = new QLCDNumber(gB_board);
        lcd_time->setObjectName(QStringLiteral("lcd_time"));
        lcd_time->setGeometry(QRect(670, 30, 121, 31));
        pB_resign = new QPushButton(gB_board);
        pB_resign->setObjectName(QStringLiteral("pB_resign"));
        pB_resign->setGeometry(QRect(420, 30, 241, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1090, 19));
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

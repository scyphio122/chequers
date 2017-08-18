/********************************************************************************
** Form generated from reading UI file 'serverconnectform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERCONNECTFORM_H
#define UI_SERVERCONNECTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CServerConnectForm
{
public:
    QPushButton *pB_connect;
    QLabel *lB_serverIp;
    QLineEdit *lE_serverIp;

    void setupUi(QDialog *CServerConnectForm)
    {
        if (CServerConnectForm->objectName().isEmpty())
            CServerConnectForm->setObjectName(QStringLiteral("CServerConnectForm"));
        CServerConnectForm->resize(200, 100);
        CServerConnectForm->setMinimumSize(QSize(200, 100));
        CServerConnectForm->setMaximumSize(QSize(200, 100));
        pB_connect = new QPushButton(CServerConnectForm);
        pB_connect->setObjectName(QStringLiteral("pB_connect"));
        pB_connect->setGeometry(QRect(60, 60, 80, 22));
        lB_serverIp = new QLabel(CServerConnectForm);
        lB_serverIp->setObjectName(QStringLiteral("lB_serverIp"));
        lB_serverIp->setGeometry(QRect(10, 10, 121, 16));
        lE_serverIp = new QLineEdit(CServerConnectForm);
        lE_serverIp->setObjectName(QStringLiteral("lE_serverIp"));
        lE_serverIp->setGeometry(QRect(20, 30, 161, 22));

        retranslateUi(CServerConnectForm);

        QMetaObject::connectSlotsByName(CServerConnectForm);
    } // setupUi

    void retranslateUi(QDialog *CServerConnectForm)
    {
        CServerConnectForm->setWindowTitle(QApplication::translate("CServerConnectForm", "Dialog", Q_NULLPTR));
        pB_connect->setText(QApplication::translate("CServerConnectForm", "Connect", Q_NULLPTR));
        lB_serverIp->setText(QApplication::translate("CServerConnectForm", "Server's IP address:", Q_NULLPTR));
        lE_serverIp->setText(QApplication::translate("CServerConnectForm", "127.0.0.1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CServerConnectForm: public Ui_CServerConnectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCONNECTFORM_H

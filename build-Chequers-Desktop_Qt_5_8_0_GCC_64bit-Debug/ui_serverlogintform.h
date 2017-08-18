/********************************************************************************
** Form generated from reading UI file 'serverlogintform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERLOGINTFORM_H
#define UI_SERVERLOGINTFORM_H

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

class Ui_CServerLoginForm
{
public:
    QLineEdit *lE_serverIP;
    QLabel *lB_serverIP;
    QPushButton *pushButton;

    void setupUi(QDialog *CServerLoginForm)
    {
        if (CServerLoginForm->objectName().isEmpty())
            CServerLoginForm->setObjectName(QStringLiteral("CServerLoginForm"));
        CServerLoginForm->resize(202, 107);
        lE_serverIP = new QLineEdit(CServerLoginForm);
        lE_serverIP->setObjectName(QStringLiteral("lE_serverIP"));
        lE_serverIP->setGeometry(QRect(20, 40, 150, 22));
        lE_serverIP->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lB_serverIP = new QLabel(CServerLoginForm);
        lB_serverIP->setObjectName(QStringLiteral("lB_serverIP"));
        lB_serverIP->setGeometry(QRect(10, 20, 131, 16));
        pushButton = new QPushButton(CServerLoginForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 70, 80, 22));

        retranslateUi(CServerLoginForm);

        QMetaObject::connectSlotsByName(CServerLoginForm);
    } // setupUi

    void retranslateUi(QDialog *CServerLoginForm)
    {
        CServerLoginForm->setWindowTitle(QApplication::translate("CServerLoginForm", "Dialog", Q_NULLPTR));
        lE_serverIP->setText(QApplication::translate("CServerLoginForm", "127.0.0.1", Q_NULLPTR));
        lB_serverIP->setText(QApplication::translate("CServerLoginForm", "Server's IP Address:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CServerLoginForm", "Connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CServerLoginForm: public Ui_CServerLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERLOGINTFORM_H

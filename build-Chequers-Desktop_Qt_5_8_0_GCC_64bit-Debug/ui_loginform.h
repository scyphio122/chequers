/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

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

class Ui_CLoginForm
{
public:
    QLineEdit *lE_userName;
    QLineEdit *lE_password;
    QLabel *lB_userName;
    QLabel *lB_password;
    QPushButton *pB_login;
    QPushButton *pB_registerUser;
    QLabel *lB_userAvatar;

    void setupUi(QDialog *CLoginForm)
    {
        if (CLoginForm->objectName().isEmpty())
            CLoginForm->setObjectName(QStringLiteral("CLoginForm"));
        CLoginForm->resize(400, 300);
        CLoginForm->setMinimumSize(QSize(400, 300));
        CLoginForm->setMaximumSize(QSize(400, 300));
        lE_userName = new QLineEdit(CLoginForm);
        lE_userName->setObjectName(QStringLiteral("lE_userName"));
        lE_userName->setGeometry(QRect(50, 160, 291, 22));
        lE_password = new QLineEdit(CLoginForm);
        lE_password->setObjectName(QStringLiteral("lE_password"));
        lE_password->setGeometry(QRect(50, 210, 291, 22));
        lE_password->setEchoMode(QLineEdit::Password);
        lB_userName = new QLabel(CLoginForm);
        lB_userName->setObjectName(QStringLiteral("lB_userName"));
        lB_userName->setGeometry(QRect(50, 140, 81, 16));
        lB_password = new QLabel(CLoginForm);
        lB_password->setObjectName(QStringLiteral("lB_password"));
        lB_password->setGeometry(QRect(50, 190, 71, 16));
        pB_login = new QPushButton(CLoginForm);
        pB_login->setObjectName(QStringLiteral("pB_login"));
        pB_login->setGeometry(QRect(50, 250, 121, 22));
        pB_login->setFocusPolicy(Qt::NoFocus);
        pB_registerUser = new QPushButton(CLoginForm);
        pB_registerUser->setObjectName(QStringLiteral("pB_registerUser"));
        pB_registerUser->setGeometry(QRect(220, 250, 121, 22));
        pB_registerUser->setFocusPolicy(Qt::NoFocus);
        lB_userAvatar = new QLabel(CLoginForm);
        lB_userAvatar->setObjectName(QStringLiteral("lB_userAvatar"));
        lB_userAvatar->setGeometry(QRect(150, 20, 100, 100));
        lB_userAvatar->setStyleSheet(QLatin1String("border: solid;\n"
"border-width: 1px;"));

        retranslateUi(CLoginForm);

        QMetaObject::connectSlotsByName(CLoginForm);
    } // setupUi

    void retranslateUi(QDialog *CLoginForm)
    {
        CLoginForm->setWindowTitle(QApplication::translate("CLoginForm", "Dialog", Q_NULLPTR));
        lB_userName->setText(QApplication::translate("CLoginForm", "User Name:", Q_NULLPTR));
        lB_password->setText(QApplication::translate("CLoginForm", "Password:", Q_NULLPTR));
        pB_login->setText(QApplication::translate("CLoginForm", "Login", Q_NULLPTR));
        pB_registerUser->setText(QApplication::translate("CLoginForm", "Register User", Q_NULLPTR));
        lB_userAvatar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CLoginForm: public Ui_CLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H

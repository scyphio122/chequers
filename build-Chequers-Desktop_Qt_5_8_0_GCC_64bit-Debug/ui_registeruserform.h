/********************************************************************************
** Form generated from reading UI file 'registeruserform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSERFORM_H
#define UI_REGISTERUSERFORM_H

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

class Ui_CRegisterUserForm
{
public:
    QLineEdit *lE_userName;
    QLineEdit *lE_password;
    QLabel *lB_password;
    QLabel *lB_userName;
    QLineEdit *lE_passwordRepeat;
    QLabel *lB_passwordRepeat;
    QPushButton *pB_submit;
    QPushButton *pB_cancel;

    void setupUi(QDialog *CRegisterUserForm)
    {
        if (CRegisterUserForm->objectName().isEmpty())
            CRegisterUserForm->setObjectName(QStringLiteral("CRegisterUserForm"));
        CRegisterUserForm->resize(400, 300);
        lE_userName = new QLineEdit(CRegisterUserForm);
        lE_userName->setObjectName(QStringLiteral("lE_userName"));
        lE_userName->setGeometry(QRect(50, 70, 291, 22));
        lE_password = new QLineEdit(CRegisterUserForm);
        lE_password->setObjectName(QStringLiteral("lE_password"));
        lE_password->setGeometry(QRect(50, 120, 291, 22));
        lE_password->setEchoMode(QLineEdit::Password);
        lB_password = new QLabel(CRegisterUserForm);
        lB_password->setObjectName(QStringLiteral("lB_password"));
        lB_password->setGeometry(QRect(50, 100, 71, 16));
        lB_userName = new QLabel(CRegisterUserForm);
        lB_userName->setObjectName(QStringLiteral("lB_userName"));
        lB_userName->setGeometry(QRect(50, 50, 81, 16));
        lE_passwordRepeat = new QLineEdit(CRegisterUserForm);
        lE_passwordRepeat->setObjectName(QStringLiteral("lE_passwordRepeat"));
        lE_passwordRepeat->setGeometry(QRect(50, 170, 291, 22));
        lE_passwordRepeat->setEchoMode(QLineEdit::Password);
        lB_passwordRepeat = new QLabel(CRegisterUserForm);
        lB_passwordRepeat->setObjectName(QStringLiteral("lB_passwordRepeat"));
        lB_passwordRepeat->setGeometry(QRect(50, 150, 121, 16));
        pB_submit = new QPushButton(CRegisterUserForm);
        pB_submit->setObjectName(QStringLiteral("pB_submit"));
        pB_submit->setGeometry(QRect(50, 210, 291, 22));
        pB_submit->setFocusPolicy(Qt::NoFocus);
        pB_cancel = new QPushButton(CRegisterUserForm);
        pB_cancel->setObjectName(QStringLiteral("pB_cancel"));
        pB_cancel->setGeometry(QRect(50, 240, 291, 22));
        pB_cancel->setFocusPolicy(Qt::NoFocus);

        retranslateUi(CRegisterUserForm);

        QMetaObject::connectSlotsByName(CRegisterUserForm);
    } // setupUi

    void retranslateUi(QDialog *CRegisterUserForm)
    {
        CRegisterUserForm->setWindowTitle(QApplication::translate("CRegisterUserForm", "Dialog", Q_NULLPTR));
        lB_password->setText(QApplication::translate("CRegisterUserForm", "Password:", Q_NULLPTR));
        lB_userName->setText(QApplication::translate("CRegisterUserForm", "User Name:", Q_NULLPTR));
        lB_passwordRepeat->setText(QApplication::translate("CRegisterUserForm", "Repeat Password:", Q_NULLPTR));
        pB_submit->setText(QApplication::translate("CRegisterUserForm", "Submit", Q_NULLPTR));
        pB_cancel->setText(QApplication::translate("CRegisterUserForm", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CRegisterUserForm: public Ui_CRegisterUserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSERFORM_H

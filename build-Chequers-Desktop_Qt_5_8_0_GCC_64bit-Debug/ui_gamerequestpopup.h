/********************************************************************************
** Form generated from reading UI file 'gamerequestpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEREQUESTPOPUP_H
#define UI_GAMEREQUESTPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CGameRequestPopup
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lB_Text;

    void setupUi(QDialog *CGameRequestPopup)
    {
        if (CGameRequestPopup->objectName().isEmpty())
            CGameRequestPopup->setObjectName(QStringLiteral("CGameRequestPopup"));
        CGameRequestPopup->resize(400, 104);
        buttonBox = new QDialogButtonBox(CGameRequestPopup);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 60, 321, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);
        buttonBox->setCenterButtons(true);
        lB_Text = new QLabel(CGameRequestPopup);
        lB_Text->setObjectName(QStringLiteral("lB_Text"));
        lB_Text->setGeometry(QRect(40, 20, 331, 31));

        retranslateUi(CGameRequestPopup);
        QObject::connect(buttonBox, SIGNAL(accepted()), CGameRequestPopup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CGameRequestPopup, SLOT(reject()));

        QMetaObject::connectSlotsByName(CGameRequestPopup);
    } // setupUi

    void retranslateUi(QDialog *CGameRequestPopup)
    {
        CGameRequestPopup->setWindowTitle(QApplication::translate("CGameRequestPopup", "Dialog", Q_NULLPTR));
        lB_Text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CGameRequestPopup: public Ui_CGameRequestPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEREQUESTPOPUP_H

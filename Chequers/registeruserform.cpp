#include "registeruserform.h"
#include "ui_registeruserform.h"
#include "game.h"
#include <QMessageBox>

CRegisterUserForm::CRegisterUserForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRegisterUserForm)
{
    ui->setupUi(this);
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalRegisterRetval(bool)), this, SLOT(onUserRegistrationResponse(bool)));
    this->setWindowTitle("Register User");
}

CRegisterUserForm::~CRegisterUserForm()
{
    delete ui;
}

void CRegisterUserForm::onUserRegistrationResponse(bool response)
{
    QApplication::restoreOverrideCursor();
    if (response)
    {
        emit signalUserRegistered(m_userName, m_password);
        this->close();
    }
    else
    {
        QMessageBox box;
        box.setText("User exists");
        box.setIcon(QMessageBox::Icon::Warning);
        box.exec();

        ui->lE_userName->setFocus();
        ui->lE_userName->selectAll();
    }
}

void CRegisterUserForm::on_lE_userName_returnPressed()
{
    ui->lE_password->setFocus();
    ui->lE_password->selectAll();
}

void CRegisterUserForm::on_lE_password_returnPressed()
{
    ui->lE_passwordRepeat->setFocus();
    ui->lE_passwordRepeat->selectAll();
}

void CRegisterUserForm::on_lE_passwordRepeat_returnPressed()
{
    ui->pB_submit->click();
}

void CRegisterUserForm::on_pB_submit_clicked()
{
    m_userName = ui->lE_userName->text().toStdString();

    if (ui->lE_password->text() == ui->lE_passwordRepeat->text())
    {
       m_password = ui->lE_password->text().toStdString();
    }
    else
    {
        QMessageBox box;
        box.setText("Password does not match. Try again.");
        box.setIcon(QMessageBox::Icon::Warning);
        box.exec();

        ui->lE_password->setFocus();
        ui->lE_password->selectAll();
        return;
    }

    if (m_userName.empty())
    {
        QMessageBox box;
        box.setText("Username is empty. Please fill it.");
        box.setIcon(QMessageBox::Icon::Critical);
        box.exec();
        ui->lE_userName->setFocus();
        ui->lE_userName->selectAll();
        return;
    }

    if (m_password.empty())
    {
        QMessageBox box;
        box.setText("Password is empty. Please fill it.");
        box.setIcon(QMessageBox::Icon::Critical);
        box.exec();

        ui->lE_password->setFocus();
        ui->lE_password->selectAll();
        return;
    }

    if (CGame::GetInstance()->RegisterUser(m_userName, m_password))
    {
        QApplication::setOverrideCursor(Qt::WaitCursor);
    }
}

void CRegisterUserForm::on_pB_cancel_pressed()
{
    this->close();
}

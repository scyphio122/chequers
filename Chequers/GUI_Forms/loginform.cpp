#include "loginform.h"
#include "ui_loginform.h"
#include "game.h"
#include <string>
#include "mainwindow.h"
#include <QMessageBox>


CLoginForm::CLoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CLoginForm)
{
    ui->setupUi(this);

    this->setWindowTitle("Login");

    m_userAvatarPixmap = new QPixmap("Login_avatar.png");
    ui->lB_userAvatar->setPixmap(*m_userAvatarPixmap);
    ui->lB_userAvatar->setScaledContents( true );
    ui->lB_userAvatar->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalLoginRetval(bool)), this, SLOT(onLoginResponse(bool)));

    ui->pB_login->clearFocus();
    ui->pB_registerUser->clearFocus();
}

CLoginForm::~CLoginForm()
{
    delete m_userAvatarPixmap;
    delete ui;
}

void CLoginForm::SetMainWindow(MainWindow* m)
{
    m_pMainwindow = m;
}

void CLoginForm::m_login(std::__cxx11::string userName, std::__cxx11::string password)
{
    if (userName.empty())
    {
        QMessageBox box;
        box.setText("Username is empty. Please fill it.");
        box.setIcon(QMessageBox::Icon::Critical);
        box.exec();

        ui->lE_userName->setFocus();
        ui->lE_userName->selectAll();
        return;
    }

    if (password.empty())
    {
        QMessageBox box;
        box.setText("Password is empty. Please fill it.");
        box.setIcon(QMessageBox::Icon::Critical);
        box.exec();

        ui->lE_password->setFocus();
        ui->lE_password->selectAll();
        return;
    }

    ui->lE_userName->setEnabled(false);
    ui->lE_password->setEnabled(false);
    ui->pB_login->setEnabled(false);
    ui->pB_registerUser->setEnabled(false);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    CGame::GetInstance()->Login(userName, password);
}

void CLoginForm::onLoginResponse(bool response)
{
    QApplication::restoreOverrideCursor();

    ui->lE_userName->setEnabled(true);
    ui->lE_password->setEnabled(true);
    ui->pB_login->setEnabled(true);
    ui->pB_registerUser->setEnabled(true);

    if (response == true)
    {
        this->hide();
        m_pMainwindow->show();
    }
    else
    {
        QMessageBox box;
        box.setText("Username or password is invalid");
        box.setIcon(QMessageBox::Icon::Warning);
        box.exec();

        ui->lE_userName->setFocus();
        ui->lE_userName->selectAll();
    }
}

void CLoginForm::onUserRegistered(std::__cxx11::string userName, std::__cxx11::string password)
{
    m_login(userName, password);
}


void CLoginForm::on_lE_userName_returnPressed()
{
    ui->lE_password->setFocus();
    ui->lE_password->selectAll();
}

void CLoginForm::on_lE_password_returnPressed()
{
    ui->pB_login->click();
}

void CLoginForm::on_pB_login_clicked()
{
    std::string userName = ui->lE_userName->text().toStdString();
    std::string password = ui->lE_password->text().toStdString();

    m_login(userName, password);
}

void CLoginForm::on_pB_registerUser_pressed()
{
    m_pRegisterUserForm = new CRegisterUserForm();
    connect(m_pRegisterUserForm, SIGNAL(signalUserRegistered(std::string,std::string)), this, SLOT(onUserRegistered(std::string,std::string)));
    m_pRegisterUserForm->exec();

    delete m_pRegisterUserForm;
}

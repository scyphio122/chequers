#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include "mainwindow.h"
#include "registeruserform.h"

namespace Ui {
class CLoginForm;
}

class CLoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit CLoginForm(QWidget *parent = 0);

    ~CLoginForm();

    void SetMainWindow(MainWindow* m);

public slots:
    void onLoginResponse(bool response);

    void onUserRegistered(std::string userName, std::string password);

private slots:
    void on_lE_userName_returnPressed();

    void on_lE_password_returnPressed();

    void on_pB_login_clicked();

    void on_pB_registerUser_pressed();

private:

    void m_login(std::string userName, std::string password);

    Ui::CLoginForm *ui;

    MainWindow* m_pMainwindow;

    CRegisterUserForm* m_pRegisterUserForm;
};

#endif // LOGINFORM_H

#ifndef REGISTERUSERFORM_H
#define REGISTERUSERFORM_H

#include <QDialog>

namespace Ui {
class CRegisterUserForm;
}

class CRegisterUserForm : public QDialog
{
    Q_OBJECT

public:
    explicit CRegisterUserForm(QWidget *parent = 0);
    ~CRegisterUserForm();

public slots:
    void onUserRegistrationResponse(bool response);

private slots:
    void on_lE_userName_returnPressed();

    void on_lE_password_returnPressed();

    void on_lE_passwordRepeat_returnPressed();

    void on_pB_submit_clicked();

    void on_pB_cancel_pressed();

signals:
    void signalUserRegistered(std::string userName, std::string password);

private:
    Ui::CRegisterUserForm *ui;

    std::string m_userName;

    std::string m_password;
};

#endif // REGISTERUSERFORM_H

#ifndef REGISTERUSERFORM_H
#define REGISTERUSERFORM_H

#include <QDialog>

namespace Ui {
class CRegisterUserForm;
}

/**
 * @brief The CRegisterUserForm class - Class managing the register form
 */
class CRegisterUserForm : public QDialog
{
    Q_OBJECT

public:
    explicit CRegisterUserForm(QWidget *parent = 0);
    ~CRegisterUserForm();

public slots:
    /**
     * @brief onUserRegistrationResponse - Callback for registration response from the server
     * @param response - true if user registered, false otherwise
     */
    void onUserRegistrationResponse(bool response);

private slots:
    /**
     * @brief on_lE_userName_returnPressed - Callback for pressing enter on the username line edit
     */
    void on_lE_userName_returnPressed();

    /**
     * @brief on_lE_password_returnPressed - Callback for pressing enter on the password line edit
     */
    void on_lE_password_returnPressed();

    /**
     * @brief on_lE_passwordRepeat_returnPressed - Callback for pressing enter on the second password line edit
     */
    void on_lE_passwordRepeat_returnPressed();

    /**
     * @brief on_pB_submit_clicked - Callback for pressing Submit button
     */
    void on_pB_submit_clicked();

    /**
     * @brief on_pB_cancel_pressed - Callback for presing Cancel button
     */
    void on_pB_cancel_pressed();

signals:
    /**
     * @brief signalUserRegistered - signal emitted when the user is registered
     * @param userName - username which was registered
     * @param password - password which was registered
     */
    void signalUserRegistered(std::string userName, std::string password);

private:
    /**
     * @brief ui - pointer to the Register Form low level graphic manager
     */
    Ui::CRegisterUserForm *ui;

    /**
     * @brief m_userName - username which was registered
     */
    std::string m_userName;

    /**
     * @brief m_password - password of the user which was registered
     */
    std::string m_password;
};

#endif // REGISTERUSERFORM_H

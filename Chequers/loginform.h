#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include "mainwindow.h"
#include "registeruserform.h"
#include <QPixmap>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class CLoginForm;
}

/**
 * @brief The CLoginForm class - Class managing log in window
 */
class CLoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit CLoginForm(QWidget *parent = 0);

    ~CLoginForm();

    /**
     * @brief SetMainWindow
     * @param m - pointer to the MainWindow class
     */
    void SetMainWindow(MainWindow* m);

public slots:
    /**
     * @brief onLoginResponse - Callback for login response from serve. Depending on reponse, MainWindow is shown or login retry happens
     * @param response - true if successfully logged in, false otherwise
     */
    void onLoginResponse(bool response);

    /**
     * @brief onUserRegistered - Callback for user registration response from server. Used to automatically log in as the new registered user
     * @param userName - username which was just registered
     * @param password
     */
    void onUserRegistered(std::string userName, std::string password);

private slots:
    /**
     * @brief on_lE_userName_returnPressed - Callback for pressing enter on username line edit
     */
    void on_lE_userName_returnPressed();

    /**
     * @brief on_lE_password_returnPressed - Callback for pressing enter on password line edit
     */
    void on_lE_password_returnPressed();

    /**
     * @brief on_pB_login_clicked - Callback for pressing 'Login' button
     */
    void on_pB_login_clicked();

    /**
     * @brief on_pB_registerUser_pressed - Callback for pressing 'Register user' button
     */
    void on_pB_registerUser_pressed();

private:

    /**
     * @brief m_login - Function which calls the @fn CGame::Login function
     * @param userName - username to be logged in
     * @param password
     */
    void m_login(std::string userName, std::string password);

    /**
     * @brief ui - pointer to the low level graphic manager
     */
    Ui::CLoginForm *ui;

    /**
     * @brief m_pMainwindow - Pointer to the @class MainWindow object. Needed to show after successfull log-in
     */
    MainWindow* m_pMainwindow;

    /**
     * @brief m_pRegisterUserForm - Pointer to @class CRegisterUserForm object. Needed to show after pressing 'Register user' button
     */
    CRegisterUserForm* m_pRegisterUserForm;

    /**
     * @brief m_userAvatarPixmap - pointer to the pixmap which holds the user login avatar
     */
    QPixmap* m_userAvatarPixmap;
};

#endif // LOGINFORM_H

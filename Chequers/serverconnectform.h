#ifndef SERVERCONNECTFORM_H
#define SERVERCONNECTFORM_H

#include <QDialog>
#include "loginform.h"

namespace Ui {
class CServerConnectForm;
}

/**
 * @brief The CServerConnectForm class - Class which manages the server connect form
 */
class CServerConnectForm : public QDialog
{
    Q_OBJECT

public:
    explicit CServerConnectForm(QWidget *parent = 0);
    ~CServerConnectForm();

    /**
     * @brief SetLoginForm - setter for the login form
     * @param form - pointer to the login form
     */
    void SetLoginForm(CLoginForm* form);

private slots:
    /**
     * @brief on_pB_connect_pressed - Callback for pressing connect button
     */
    void on_pB_connect_pressed();

    /**
     * @brief on_lE_serverIp_returnPressed - Callback for pressing enter on the server ip line edit
     */
    void on_lE_serverIp_returnPressed();

private:
    /**
     * @brief m_connect - function which connects to the server
     */
    void m_connect();

    /**
     * @brief ui - pointer to the low level graphic server connect form manager
     */
    Ui::CServerConnectForm *ui;

    /**
     * @brief m_loginForm - pointer to the login form
     */
    CLoginForm* m_loginForm;
};

#endif // SERVERCONNECTFORM_H

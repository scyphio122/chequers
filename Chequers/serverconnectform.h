#ifndef SERVERCONNECTFORM_H
#define SERVERCONNECTFORM_H

#include <QDialog>
#include "loginform.h"

namespace Ui {
class CServerConnectForm;
}

class CServerConnectForm : public QDialog
{
    Q_OBJECT

public:
    explicit CServerConnectForm(QWidget *parent = 0);
    ~CServerConnectForm();

    void SetLoginForm(CLoginForm* form);

private slots:
    void on_pB_connect_pressed();

    void on_lE_serverIp_returnPressed();

private:
    void m_connect();

    Ui::CServerConnectForm *ui;

    CLoginForm* m_loginForm;
};

#endif // SERVERCONNECTFORM_H

#include "serverconnectform.h"
#include "ui_serverconnectform.h"
#include "webmanager.h"
#include "logger.h"

CServerConnectForm::CServerConnectForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CServerConnectForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Connect to Chequers server");
}

CServerConnectForm::~CServerConnectForm()
{
    delete ui;
}

void CServerConnectForm::SetLoginForm(CLoginForm *form)
{
    m_loginForm = form;
}

void CServerConnectForm::m_connect()
{
    std::string ip = "127.0.0.1";

    if (ui->lE_serverIp->text().toStdString().empty())
    {
        ui->lE_serverIp->setText("127.0.0.1");
    }
    LOG_DBG("Connecting to IP: %s", ip.c_str());
    ip = ui->lE_serverIp->text().toStdString();

    if (!CWebManager::GetInstance()->Connect(ip))
    {
        LOG_CRITICAL("Could not connect. Aborting...");
        exit(0);
    }

    this->hide();
    m_loginForm->show();
}

void CServerConnectForm::on_pB_connect_pressed()
{
    m_connect();
}

void CServerConnectForm::on_lE_serverIp_returnPressed()
{
    m_connect();
}

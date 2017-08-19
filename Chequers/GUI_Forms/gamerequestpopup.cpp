#include "gamerequestpopup.h"
#include "ui_gamerequestpopup.h"
#include "game.h"

CGameRequestPopup::CGameRequestPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CGameRequestPopup)
{
    ui->setupUi(this);
}

CGameRequestPopup::~CGameRequestPopup()
{
    delete ui;
}

void CGameRequestPopup::SetText(QString text)
{
    ui->lB_Text->setText(text);
}

void CGameRequestPopup::on_buttonBox_accepted()
{
    CGame::GetInstance()->RespondToGameInvitation(true);
    this->close();
}

void CGameRequestPopup::on_buttonBox_rejected()
{
    CGame::GetInstance()->RespondToGameInvitation(false);
    this->close();
}

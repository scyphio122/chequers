#ifndef GAMEREQUESTPOPUP_H
#define GAMEREQUESTPOPUP_H

#include <QDialog>

namespace Ui {
class CGameRequestPopup;
}

class CGameRequestPopup : public QDialog
{
    Q_OBJECT

public:
    explicit CGameRequestPopup(QWidget *parent = 0);
    ~CGameRequestPopup();

    void SetText(QString text);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CGameRequestPopup *ui;
};

#endif // GAMEREQUESTPOPUP_H

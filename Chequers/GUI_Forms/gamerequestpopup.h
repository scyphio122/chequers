#ifndef GAMEREQUESTPOPUP_H
#define GAMEREQUESTPOPUP_H

#include <QDialog>

namespace Ui {


class CGameRequestPopup;
}

/**
 * @brief The CGameRequestPopup - Class which manages the pop-up window when someone invites user to play.
 */
class CGameRequestPopup : public QDialog
{
    Q_OBJECT

public:
    explicit CGameRequestPopup(QWidget *parent = 0);
    ~CGameRequestPopup();

    /**
     * @brief SetText - Set text displayed in the pop-up
     * @param text - text which should be displayed inside the pop-up
     */
    void SetText(QString text);
private slots:
    /**
     * @brief on_buttonBox_accepted - Callback for pressing the 'Accept' button
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_buttonBox_rejected - Callback for pressing the 'Reject' button
     */
    void on_buttonBox_rejected();

private:
    /**
     * @brief ui - pointer to the low level window graphic manager
     */
    Ui::CGameRequestPopup *ui;
};

#endif // GAMEREQUESTPOPUP_H

#ifndef APP_BANK_WINDOW_H
#define APP_BANK_WINDOW_H

#include <QMainWindow>
#include "icont.h"
#include "RequestFactory.h"
#include "factorytranzactie.h"
#include"factoryhandler.h"
#include "historytranzaction.h"
#include<QString>
#include <QMessageBox>
#define EURO 4.95
#define USD 4.63

class App_Bank_Window;

namespace Ui {
class App_Bank_Window;
}

class App_Bank_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit App_Bank_Window(QWidget *parent = nullptr);
    ~App_Bank_Window();
    App_Bank_Window(ICont *cont, QWidget *parent = nullptr);
    void addItemsToComboBox();
    void makePaymentPOS();
    void hideAll();
    QString makeChange(QString type_change,QString field_change);
    int searchInHistory(QString nume_destinatar);

private slots:
    void on_ExitButton_clicked();

    void on_transfer_box_activated(int index);

    void on_IstoricTranzButton_clicked();

    void on_SchimbareNumeButton_clicked();

    void on_CreareCardButton_clicked();

    void on_SchimbareAdresaButton_clicked();

    void on_ActivareCardButton_clicked();

    void on_SchimbareNrTelButton_clicked();

    void on_SchimbareEmailButton_clicked();

    void on_BlocareCardButton_clicked();

    void on_StergeCardButton_clicked();

    void on_SettingsButton_clicked();

    void on_WidrawButton_clicked();

    void on_DepositButton_clicked();

    void on_cards_box_activated(int index);

    void on_retragereButton_clicked();

    void on_depozitButton_clicked();

    void on_send_button_clicked();

    void on_sendButton2_clicked();

    void on_currency_box_activated(int index);

    void on_continueButton_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_ok_clicked();

    void on_sendNumeButton_clicked();

    void on_sendAdresaButton_clicked();

    void on_sendNrTelefonButton_clicked();

    void on_sendEmailButton_clicked();

    void on_history_box_activated(int index);

private:
    Ui::App_Bank_Window *ui;
    ICont * m_cont_utilizator;
    IHandler* m_handler;
    std::vector<HistoryTranzaction*> m_history;
};

#endif // APP_BANK_WINDOW_H

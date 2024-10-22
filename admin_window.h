#ifndef ADMIN_WINDOW_H
#define ADMIN_WINDOW_H
#include <QMainWindow>
#include"icont.h"
#include "RequestFactory.h"
#include "ResponseFactory.h"
#include"factoryhandler.h"
#include "sconnect_to_server_admin.h"

class MainWindow;

namespace Ui {
class Admin_Window;
}

class Admin_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin_Window(QWidget *parent = nullptr);
    Admin_Window(ICont *cont, QWidget *parent = nullptr);
    ~Admin_Window();

private slots:
    void receiveRequestFromServer(const QByteArray &requestData);

    void on_LogoutButton_clicked();

    void on_NotificationsButton_clicked();

    void on_choice_button_accepted();

    void on_choice_button_rejected();

private:
    Ui::Admin_Window *ui;
    ICont* m_cont_admin;
    IHandler* m_handler;

};

#endif // ADMIN_WINDOW_H

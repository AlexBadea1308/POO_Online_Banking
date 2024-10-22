#ifndef SECURITY_QUESTIONS_WINDOW_H
#define SECURITY_QUESTIONS_WINDOW_H

#include <QMainWindow>
#include "ihandler.h"

class ForgotPassWordWindow;
class MainWindow;
namespace Ui {
class Security_Questions_Window;
}

class Security_Questions_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Security_Questions_Window(QWidget *parent = nullptr);
    ~Security_Questions_Window();

private slots:
    void on_confirm_security_Button_clicked();
    void on_backButton_clicked();
    void on_confirm_password_Button_clicked();
    void on_hidebox2_clicked();

private:
    Ui::Security_Questions_Window *ui;
    IHandler* m_handler=nullptr;
};

#endif // SECURITY_QUESTIONS_WINDOW_H

#ifndef SIGNUP_WINDOW_H
#define SIGNUP_WINDOW_H

#include <QMainWindow>
#include"RequestFactory.h"
#include "utils.h"
#include "SignUpResponse.h"
#include "factoryhandler.h"

#include<QMessageBox>
class MainWindow;

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();
    bool isAllFieldsComplete();

private slots:
    void on_back_button_clicked();
    void on_pushButton_clicked();

private:
    Ui::SignUpWindow *ui;
    IHandler * m_handler;
};

#endif // SIGNUP_WINDOW_H

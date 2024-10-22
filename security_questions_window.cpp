#include "security_questions_window.h"
#include "ui_security_questions_window.h"
#include "loginwindow.h"

Security_Questions_Window::Security_Questions_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Security_Questions_Window)
{
    ui->setupUi(this);
    ui->SecurityBox->show();
    ui->NewPasswordBox->hide();
    ui->lineEdit_confirmPassword->setEchoMode(QLineEdit::Password);
    ui->lineEdit_fraza_securitate->setEchoMode(QLineEdit::Password);
    ui->lineEdit_rasp_intre_sec->setEchoMode(QLineEdit::Password);
    ui->lineEdit_username_security->setClearButtonEnabled(true);
    ui->lineEdit_username->setClearButtonEnabled(true);
    ui->lineEdit_fraza_securitate->setClearButtonEnabled(true);
    ui->lineEdit_rasp_intre_sec->setClearButtonEnabled(true);
    ui->lineEdit_confirmPassword->setClearButtonEnabled(true);
}

Security_Questions_Window::~Security_Questions_Window()
{
    delete ui;
}

void Security_Questions_Window::on_confirm_security_Button_clicked()
{
    m_handler=FactoryHandler::createVerifySecurityHandler();

    IRequest* securityRequest=RequestFactory::createVerifySecurityRequestP("Users",ui->lineEdit_username_security->text().toStdString(),
                                                                                ui->lineEdit_fraza_securitate->text().toStdString(),ui->lineEdit_rasp_intre_sec->text().toStdString());
    QByteArray dataByte=m_handler->sendRequest(securityRequest);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        QMessageBox::information(this,tr("Verificare securitate"),QString::fromStdString(response->getMessage()));
        ui->SecurityBox->hide();
        ui->NewPasswordBox->show();
        ui->lineEdit_username_security->clear();
        ui->lineEdit_fraza_securitate->clear();
        ui->lineEdit_rasp_intre_sec->clear();
    }
    else
        QMessageBox::warning(this,tr("Verificare securitate esuata!"),QString::fromStdString(response->getMessage()));
    delete m_handler;
}


void Security_Questions_Window::on_backButton_clicked()
{
    MainWindow *mainWindow= new MainWindow();
    this->close();
    mainWindow->show();
    this->~Security_Questions_Window();
}


void Security_Questions_Window::on_confirm_password_Button_clicked()
{
    m_handler=FactoryHandler::createPasswordHandler();
    if(m_handler->verifyConstraints(ui->lineEdit_confirmPassword->text(),"Password")==-1)
    {
        QMessageBox::warning(this,tr("Parola invalida:"),tr("Parola nu respecta constrangerile!"));
        return;
    }
    QByteArray hashedPassword = QCryptographicHash::hash(ui->lineEdit_confirmPassword->text().toUtf8(), QCryptographicHash::Sha256);
    IRequest* passwordRequest=RequestFactory::createChangePasswordRequestP("Users",ui->lineEdit_username->text().toStdString(),
                                                                             hashedPassword.toHex().toStdString());
    QByteArray dataByte=m_handler->sendRequest(passwordRequest);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        QMessageBox::information(this,tr("Schimbare parola:"),QString::fromStdString(response->getMessage()));
        ui->SecurityBox->hide();
        ui->NewPasswordBox->hide();
        ui->lineEdit_username->clear();
        ui->lineEdit_confirmPassword->clear();
    }
    else
    {
        QMessageBox::warning(this,tr("Schimbare parola esuata!"),QString::fromStdString(response->getMessage()));
    }
    delete m_handler;
}

void Security_Questions_Window::on_hidebox2_clicked()
{
        if(!ui->hidebox2->isChecked())
            ui->lineEdit_confirmPassword->setEchoMode(QLineEdit::Password);
        else
        {
            ui->lineEdit_confirmPassword->setEchoMode(QLineEdit::Normal);
            emit ui->hidebox2->stateChanged(false);
        }
}


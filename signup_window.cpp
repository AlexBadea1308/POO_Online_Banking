#include "signup_window.h"
#include "ui_signupwindow.h"
#include "loginwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    ui->lineEdit_nume->setClearButtonEnabled(true);
    ui->lineEdit_adresa->setClearButtonEnabled(true);
    ui->lineEdit_CNP->setClearButtonEnabled(true);
    ui->lineEdit_NrTel->setClearButtonEnabled(true);
    ui->lineEdit_email->setClearButtonEnabled(true);
    ui->lineEdit_fraza_securitate->setClearButtonEnabled(true);
    ui->lineEdit_intrebare_securitate->setClearButtonEnabled(true);
    ui->lineEdit_username->setClearButtonEnabled(true);
    ui->lineEdit_password->setClearButtonEnabled(true);
    ui->lineEdit_CNP->setMaxLength(13);
    ui->lineEdit_password->setMaxLength(16);
    ui->lineEdit_NrTel->setMaxLength(10);
    ui->lineEdit_email->setMaxLength(30);
    ui->lineEdit_fraza_securitate->setMaxLength(30);
    ui->lineEdit_intrebare_securitate->setMaxLength(30);
    ui->lineEdit_adresa->setMaxLength(30);
    ui->lineEdit_username->setMaxLength(16);
    ui->lineEdit_nume->setMaxLength(20);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

bool SignUpWindow::isAllFieldsComplete()
{
    if(ui->lineEdit_nume->text()==""||ui->lineEdit_adresa->text()==""||ui->lineEdit_CNP->text()==""||ui->lineEdit_NrTel->text()==""||ui->lineEdit_email->text()==""
                                               ||ui->lineEdit_fraza_securitate->text()==""||ui->lineEdit_intrebare_securitate->text()==""
                                               ||ui->intrebare_securitate_box->currentText()==""||ui->intrebare_securitate_box->currentText()=="Intrebare de securitate")
        return false;
    return true;
}


void SignUpWindow::on_back_button_clicked()
{
    this->close();
    MainWindow* mainWindow= new MainWindow();
    mainWindow->show();
    this->~SignUpWindow();
}



void SignUpWindow::on_pushButton_clicked()
{
    if(isAllFieldsComplete()==false)
        QMessageBox::warning(this,tr("Atentie camp necompletat"),tr("Ai omis completarea unui camp!"));
   else
    {
        m_handler=FactoryHandler::createSignUpHandler();
        if(m_handler->verifyConstraints(ui->lineEdit_NrTel->text(),"phone")==3)
        {
            QMessageBox::warning(this, tr("Creare cont!"), tr("Numar de telefon invalid!!"));
            return;
        }
        else
            if(m_handler->verifyConstraints(ui->lineEdit_email->text(),"email")==1)
            {
                QMessageBox::warning(this, tr("Creare cont!"), tr("Email invalid!!"));
                return;
            }
            else
                if(m_handler->verifyConstraints(ui->lineEdit_CNP->text(),"cnp")==2)
                {
                    QMessageBox::warning(this, tr("Creare cont!"), tr("CNP invalid!!"));
                    return;
                }
                else
                    if(m_handler->verifyConstraints(ui->lineEdit_password->text(),"password")==0)
                    {
                        QMessageBox::warning(this, tr("Creare cont!"), tr("Parola nu corespunde constrangerilor!!"));
                        return;
                    }

        securityPhares phrases=dynamic_cast<SignUpHandler*>(m_handler)->createPhrases(ui->lineEdit_fraza_securitate->text(),ui->intrebare_securitate_box->currentText(),ui->lineEdit_intrebare_securitate->text());

            QByteArray hashedPassword = QCryptographicHash::hash(ui->lineEdit_password->text().toUtf8(), QCryptographicHash::Sha256);
            IRequest * signInRequest = RequestFactory::createSignUpRequestP(ui->lineEdit_nume->text().toStdString(),ui->lineEdit_adresa->text().toStdString()
                                                                           ,ui->lineEdit_NrTel->text().toStdString(),ui->lineEdit_username->text().toStdString()
                                                                           ,hashedPassword.toHex().toStdString(),ui->lineEdit_email->text().toStdString(),
                                                                           ui->lineEdit_CNP->text().toStdString(),phrases);
            QByteArray dataByte=m_handler->sendRequest(signInRequest);
            json responseJson=m_handler->receiveJson(dataByte);
            IResponse *  response =m_handler->parseResponse(responseJson);

            if(response->getResult()==false)
            {
                QMessageBox::warning(this, tr("Creare cont!"), tr("Contul nu a putut fi creat!"));
            }
            else
            {
                QMessageBox::information(this, tr("Eroare creare cont!"), tr("Contul a fost creat cu succes!"));

            }
     }
}


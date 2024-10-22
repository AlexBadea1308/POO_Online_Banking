#include "app_bank_window.h"
#include "ui_app_bank_window.h"
#include "loginwindow.h"
#include<stdio.h>


App_Bank_Window::App_Bank_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App_Bank_Window)
{
    ui->setupUi(this);
    ui->card_detail->hide();
    ui->transfer_cont_propriu->hide();
    ui->transfer_interbancar->hide();
    ui->depozit->hide();
    ui->retragere->hide();
    ui->settings->hide();
    ui->istoric_tranzactii->hide();
}

App_Bank_Window::~App_Bank_Window()
{
    delete ui;
}

App_Bank_Window::App_Bank_Window(ICont *cont, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App_Bank_Window), m_cont_utilizator(cont)
{
    ui->setupUi(this);
    m_handler=nullptr;
    hideAll();

    addItemsToComboBox();

    ui->lineEditPin->setEchoMode(QLineEdit::Password);

    ui->lineEdit_IBAN->setReadOnly(true);
    ui->lineEdit_detinator->setReadOnly(true);
    ui->lineEdit_dataExp->setReadOnly(true);
    ui->lineEdit__sold->setReadOnly(true);
    ui->lineEditPin->setReadOnly(true);

    ui->lineEdit_IBAN_dest->setClearButtonEnabled(true);
    ui->lineEdit_IBAN_dest_2->setClearButtonEnabled(true);
    ui->lineEdit_IBAN->setClearButtonEnabled(true);
    ui->lineEdit_destinatar_pos->setClearButtonEnabled(true);
    ui->lineEdit_nume_destinatar->setClearButtonEnabled(true);
    ui->lineEdit_EmailNou->setClearButtonEnabled(true);
    ui->lineEdit_numeNou->setClearButtonEnabled(true);
    ui->lineEdit_NrTelefonNou->setClearButtonEnabled(true);
    ui->lineEdit_adresaNoua->setClearButtonEnabled(true);

    ui->lineEditPin->setMaxLength(4);
    ui->lineEdit_IBAN->setMaxLength(15);
    ui->lineEdit_IBAN_dest->setMaxLength(15);
    ui->lineEdit_IBAN_dest_2->setMaxLength(15);
    ui->lineEdit_EmailNou->setMaxLength(30);
    ui->lineEdit_numeNou->setMaxLength(20);
    ui->lineEdit_NrTelefonNou->setMaxLength(10);
    ui->lineEdit_adresaNoua->setMaxLength(30);

    ui->nume_utilizator_label->setText("Welcome "+m_cont_utilizator->getPersoana()->getNume());
    setFixedSize(1122, 676);
}


void App_Bank_Window::on_ExitButton_clicked()
{
    std::string exit_string="Logout~"+m_cont_utilizator->getPersoana()->getUsername().toStdString();
    QByteArray byte_exit=QByteArray::fromStdString(exit_string);
    QByteArray responseByte =SConnectToServer::GetInstance().connectServer(byte_exit);
    std::string responseString = responseByte.toStdString();
    if (responseString.compare("OK\000"))
    {
        this->close();
        MainWindow *mainWindow= new MainWindow();
        mainWindow->show();
        this->~App_Bank_Window();
    }
    else
    {
        QMessageBox::warning(this,tr("Logout unsuccsessfull!"),tr("Nu te ai putut deconecta cu succes!"));
    }
}

void App_Bank_Window::addItemsToComboBox()
{
    m_handler=FactoryHandler::createDetailsCardHandler();

        ui->cards_box->clear();
        // Parcurge vectorul de carduri si adauga fiecare card in cardsbox
        if(m_cont_utilizator->getCards().size()==0)
            throw MyException("Utilizatorul nu are niciun card in cont!");
        for (size_t i = 0; i < m_cont_utilizator->getCards().size();i++)
        {
            QString cardName = "Card" + QString::number(m_cont_utilizator->getCards()[i]->getCardID());
            ui->cards_box->addItem(cardName);
            if(m_cont_utilizator->getCards()[i]->getCardID()<0)
                throw MyException("Cardul nu are un ID corespunzator!");

            IRequest* detailsCards=RequestFactory::createGetDetailsContRequestP(m_cont_utilizator->getPersoana()->getUsername().toStdString(),std::string("Utilizator"),
                                                                                  m_cont_utilizator->getPersoana()->getID(),
                                                                                  m_cont_utilizator->getCards()[i]->getCardID());

            QByteArray dataByte=m_handler->sendRequest(detailsCards);
            json responseJson=m_handler->receiveJson(dataByte);
            IResponse* response=m_handler->parseResponse(responseJson);

            m_cont_utilizator->getCards()[i]->initializeCard(QString::fromStdString(response->getDetailsCard()));
            ui->card_selected_label->setText(ui->cards_box->currentText());
        }
        delete m_handler;
}

void App_Bank_Window::makePaymentPOS()
{
    IRequestTranzactie* POS=RequestFactoryTranzactie::createRequestTransferPOSP(m_cont_utilizator->getPersoana()->getID(),ui->lineEdit_sumaPOS->text().toFloat(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN().toStdString(),ui->lineEdit_destinatar_pos->text().toStdString());
    QByteArray dataByte=m_handler->sendRequestTranzactie(POS);
    json responseJson=m_handler->receiveJson(dataByte);
    ResponseTranzactie* response=m_handler->parseResponseTranzactie(responseJson);

    if(response->getResult()==true)
    {
        ITranzactie* tranzactie=FactoryTranzactie::createPOS_Transfer(m_cont_utilizator->getPersoana()->getUsername(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN(),ui->lineEdit_sumaPOS->text().toFloat(),ui->lineEdit_destinatar_pos->text());
        m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->addTranzactie(tranzactie);
        m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->setNewSold(response->m_new_soldSursa);
        QMessageBox::information(this,tr("Transfer reusit!"),QString::fromStdString(response->getMessage()));
    }
    else
          QMessageBox::warning(this,tr("Transfer nereusit!"),QString::fromStdString(response->getMessage()));
    delete m_handler;
    ui->lineEditPin->clear();
    ui->lineEdit_destinatar_pos->clear();
    ui->lineEdit_sumaPOS->clear();
    ui->pin_box->hide();
    ui->POS_box->show();
    ui->detalii_plata_pos_box->show();
}

void App_Bank_Window::hideAll()
{
    ui->card_detail->hide();
    ui->transfer_cont_propriu->hide();
    ui->transfer_interbancar->hide();
    ui->depozit->hide();
    ui->retragere->hide();
    ui->settings->hide();
    ui->istoric_tranzactii->hide();
    ui->POS_box->hide();
    ui->pin_box->hide();
    ui->detalii_plata_pos_box->hide();
    ui->Schimbare_Adresa_box->hide();
    ui->Schimbare_Email_box->hide();
    ui->Schimbare_NrTel_box->hide();
    ui->Schimbare_Nume_box->hide();
    ui->POS_box->hide();
    ui->history_box->hide();
}

QString App_Bank_Window::makeChange(QString type_change,QString field_change)
{
    m_handler=FactoryHandler::createChangeFieldHandler();

    if(type_change.compare("Phone")==false||type_change.compare("Email")==false)
        if(m_handler->verifyConstraints(field_change,type_change)!=2)
            return "";

    IRequest* changeRequest= RequestFactory::createChangeFieldP("Utilizator",m_cont_utilizator->getPersoana()->getUsername().toStdString(),
                                                                 m_cont_utilizator->getPersoana()->getPassword().toStdString(), field_change.toStdString(),
                                                                 type_change.toStdString());
    QByteArray dataByte=m_handler->sendRequest(changeRequest);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        QMessageBox::information(this,tr("Modificare Adresa:"),QString::fromStdString(response->getMessage()));
        return QString::fromStdString(response->getNewField());
    }
    else
    {
        QMessageBox::warning(this,tr("Modificare Adresa:"),QString::fromStdString(response->getMessage()));
        return "";
    }
}

int App_Bank_Window::searchInHistory(QString nume_destinatar)
{
    if(m_history.size()>0)
        for(int i=0;i<m_history.size();i++)
            if(m_history[i]->getNumeDestinatar().compare(nume_destinatar)==false)
                return i;
    return -1;
}


void App_Bank_Window::on_transfer_box_activated(int index)
{
    hideAll();
    if(index==0)
    { ui->transfer_cont_propriu->show();
      ui->history_box->show();
    }
    else
        if(index==1)
    {
        ui->transfer_interbancar->show();
        ui->history_box->show();
    }
    else
        if(index==2)
    {
        ui->POS_box->show();
        ui->detalii_plata_pos_box->show();
    }
}

void App_Bank_Window::on_IstoricTranzButton_clicked()
{
    hideAll();
    ui->list_istoric_tranzactii->clear();
    auto transactions = m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getTranzactii();
    if(transactions.size()==0)
        QMessageBox::warning(this,tr("Istoric tranzactii gol!"),tr("In Login ul curent nu ai efectuat nicio tranzactie!"));
    else
    {
        for (std::vector<ITranzactie*>::iterator it = transactions.begin(); it != transactions.end();it++)
        {
            QListWidgetItem *item=new QListWidgetItem();
            if((*it)->getType()=="Depunere")
            {
                item->setText((*it)->getUsername() + " ->  +" + QString::number((*it)->getSuma())+" DEPUNERE");
                item->setForeground(Qt::green);
                //seteaza culoarea verde
            }
            else
              if((*it)->getType()=="Retragere")
            {
                item->setText((*it)->getUsername() + " ->  -" + QString::number((*it)->getSuma())+"  RETRAGERE");
                item->setForeground(Qt::red);
                //seteaza culoarea rosu
            }
            else
                if((*it)->getType()=="Transfer cont propriu")
            {
                item->setText((*it)->getUsername() + " ->  -" + QString::number((*it)->getSuma())+" in contul cu IBAN ul "+(*it)->getIBANDestinatie());
                item->setForeground(Qt::red);
            }
            else
                if((*it)->getType()=="Transfer multibank")
            {
                item->setText((*it)->getUsername() + " ->  -" + QString::number((*it)->getSuma())+" in contul cu numele "+(*it)->getNumeDestinatar());
                item->setForeground(Qt::red);
            }
            else
            {
                item->setText((*it)->getUsername() + " ->  -" + QString::number((*it)->getSuma())+" in contul cu numele "+(*it)->getNumeDestinatar()+ "POS");
                item->setForeground(Qt::red);
            }
            ui->list_istoric_tranzactii->addItem(item);
        }
        ui->istoric_tranzactii->show();
    }
}

void App_Bank_Window::on_SchimbareEmailButton_clicked()
{
    hideAll();
    ui->Schimbare_Email_box->show();
}

void App_Bank_Window::on_SchimbareNumeButton_clicked()
{
    hideAll();
    ui->Schimbare_Nume_box->show();
}

void App_Bank_Window::on_SchimbareNrTelButton_clicked()
{
    hideAll();
    ui->Schimbare_NrTel_box->show();
}

void App_Bank_Window::on_SchimbareAdresaButton_clicked()
{
    hideAll();
    ui->Schimbare_Adresa_box->show();
}

void App_Bank_Window::on_StergeCardButton_clicked()
{
    m_handler=FactoryHandler::createGestionareCardHandler();
    IRequest* creare_Card=RequestFactory::createGestionareCardP("Utilizator",m_cont_utilizator->getPersoana()->getUsername().toStdString(),
                                                                  m_cont_utilizator->getPersoana()->getPassword().toStdString(),"Stergere Card"
                                                                  ,m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getCardID());
    QByteArray dataByte=m_handler->sendRequest(creare_Card);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        QMessageBox::information(this, tr("Stergere Card!"), QString::fromStdString(response->getMessage()));
        if(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]!=NULL)
        {   m_cont_utilizator->getCards().erase(m_cont_utilizator->getCards().begin() + ui->cards_box->currentIndex());
            ui->cards_box->removeItem(ui->cards_box->currentIndex());
            if(ui->cards_box->count()>0)
            ui->card_selected_label->setText(ui->cards_box[0].currentText());
            else
                QMessageBox::warning(this,tr("No card found:"),tr("Nu mai ai niciun card!"));
        }
        delete m_handler;
    }
    else
    {
        QMessageBox::warning(this, tr("Stergere Card!"), QString::fromStdString(response->getMessage()));
    }
}


void App_Bank_Window::on_CreareCardButton_clicked()
{
   m_handler=FactoryHandler::createGestionareCardHandler();
    IRequest* creare_Card=RequestFactory::createGestionareCardP("Utilizator",m_cont_utilizator->getPersoana()->getUsername().toStdString(),
                                                                  m_cont_utilizator->getPersoana()->getPassword().toStdString(),"Creare Card",-1);
    QByteArray dataByte=m_handler->sendRequest(creare_Card);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        QMessageBox::information(this, tr("Creare Card!"), QString::fromStdString(response->getMessage()));
        m_cont_utilizator->addCard(new Card(response->getCardID()));
        ui->cards_box->addItem("Card"+QString::number(m_cont_utilizator->getCards()[m_cont_utilizator->getCards().size()-1]->getCardID()));
    }
    else
    {
        QMessageBox::warning(this, tr("Creare Card!"), QString::fromStdString(response->getMessage()));
    }
       delete m_handler;
}

void App_Bank_Window::on_ActivareCardButton_clicked()
{
   m_handler=FactoryHandler::createGestionareCardHandler();
    IRequest* creare_Card=RequestFactory::createGestionareCardP("Utilizator",m_cont_utilizator->getPersoana()->getUsername().toStdString(),
                                                                  m_cont_utilizator->getPersoana()->getPassword().toStdString(),"Activare Card",
                                                                  m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getCardID());
    QByteArray dataByte=m_handler->sendRequest(creare_Card);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        QMessageBox::information(this, tr("Activare Card!"), QString::fromStdString(response->getMessage()));
        m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->setStareCard("Activat");
        delete m_handler;
    }
    else
    {
        QMessageBox::warning(this, tr("Activare Card!"), QString::fromStdString(response->getMessage()));
    }
}

void App_Bank_Window::on_BlocareCardButton_clicked()
{
   m_handler=FactoryHandler::createGestionareCardHandler();
    IRequest* creare_Card=RequestFactory::createGestionareCardP("Utilizator",m_cont_utilizator->getPersoana()->getUsername().toStdString(),
                                                                  m_cont_utilizator->getPersoana()->getPassword().toStdString(),"Blocare Card",
                                                                  m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getCardID());
    QByteArray dataByte=m_handler->sendRequest(creare_Card);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        QMessageBox::information(this, tr("Blocare Card!"), QString::fromStdString(response->getMessage()));
        m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->setStareCard("Blocat");
        delete m_handler;
    }
    else
    {
        QMessageBox::warning(this, tr("Blocare Card!"), QString::fromStdString(response->getMessage()));
    }
}


void App_Bank_Window::on_SettingsButton_clicked()
{
    hideAll();
    ui->settings->show();
}


void App_Bank_Window::on_WidrawButton_clicked()
{
    hideAll();
    ui->retragere->show();
}


void App_Bank_Window::on_DepositButton_clicked()
{
    hideAll();
    ui->depozit->show();
}


void App_Bank_Window::on_cards_box_activated(int index)
{
    ui->card_selected_label->setText(ui->cards_box->currentText());
    m_handler=FactoryHandler::createDetailsCardHandler();

    hideAll();

    IRequest* detailsCards=RequestFactory::createGetDetailsContRequestP(m_cont_utilizator->getPersoana()->getUsername().toStdString(),std::string("Utilizator"),
                                                                          m_cont_utilizator->getPersoana()->getID(),m_cont_utilizator->getCards()[index]->getCardID());
    QByteArray dataByte=m_handler->sendRequest(detailsCards);
    json responseJson=m_handler->receiveJson(dataByte);
    IResponse* response=m_handler->parseResponse(responseJson);

    if(response->getResult()==true)
    {
        m_cont_utilizator->getCards()[index]->initializeCard(QString::fromStdString(response->getDetailsCard()));
        ui->lineEdit__sold->setText(QString::number(m_cont_utilizator->getCards()[index]->getSold()));
        ui->lineEdit_dataExp->setText(m_cont_utilizator->getCards()[index]->getDataExpirare());
        ui->lineEdit_detinator->setText(m_cont_utilizator->getPersoana()->getNume());
        ui->lineEdit_IBAN->setText(m_cont_utilizator->getCards()[index]->getIBAN());
        ui->card_detail->show();
    }
    else
        QMessageBox::warning(this,tr("Detalii CARD!"),QString::fromStdString(response->getMessage()));
    delete m_handler;
}


void App_Bank_Window::on_retragereButton_clicked()
{  if(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getStareCard().compare("Activat")==1)
    {
        m_handler=FactoryHandler::createRetragereHandler();
        IRequestTranzactie* retragere=RequestFactoryTranzactie::createRequestRetragereP(m_cont_utilizator->getPersoana()->getID(),ui->lineEdit_sum_retragere->text().toFloat(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN().toStdString());
        QByteArray dataByte=m_handler->sendRequestTranzactie(retragere);
        json responseJson=m_handler->receiveJson(dataByte);
        ResponseTranzactie* response=m_handler->parseResponseTranzactie(responseJson);

        if(response->getResult()==true)
        {
            ITranzactie* tranzactie=FactoryTranzactie::createRetragere(m_cont_utilizator->getPersoana()->getUsername(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN(),ui->lineEdit_sum_retragere->text().toFloat());
            m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->addTranzactie(tranzactie);
            m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->setNewSold(response->m_new_soldSursa);
            QMessageBox::information(this,tr("Transfer reusit!"),QString::fromStdString(response->getMessage()));
        }
        else
            QMessageBox::information(this,tr("Transfer nereusit!"),QString::fromStdString(response->getMessage()));
        delete m_handler;
    }
else
    {
        QMessageBox::warning(this,tr("Card Blocat"),tr("Cardul selectat este Blocat!"));
    }
    ui->lineEdit_sum_retragere->clear();
}

void App_Bank_Window::on_depozitButton_clicked()
{
    if(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getStareCard().compare("Activat")==1)
    {
        m_handler=FactoryHandler::createDepunereHandler();

        IRequestTranzactie* depunere=RequestFactoryTranzactie::createRequestDepunereP(m_cont_utilizator->getPersoana()->getID(),ui->lineEdit_sum_depozit->text().toFloat(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN().toStdString());
        QByteArray dataByte=m_handler->sendRequestTranzactie(depunere);
        json responseJson=m_handler->receiveJson(dataByte);
        ResponseTranzactie* response=m_handler->parseResponseTranzactie(responseJson);

        if(response->getResult()==true)
        {
            ITranzactie* tranzactie=FactoryTranzactie::createDepunere(m_cont_utilizator->getPersoana()->getUsername(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN(),ui->lineEdit_sum_depozit->text().toFloat());
            m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->addTranzactie(tranzactie);
            m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->setNewSold(response->m_new_soldSursa);
            QMessageBox::information(this,tr("Transfer reusit!"),QString::fromStdString(response->getMessage()));
        }
        else
            QMessageBox::information(this,tr("Transfer nereusit!"),QString::fromStdString(response->getMessage()));


        delete m_handler;
    }

        else
        {
            QMessageBox::warning(this,tr("Card Blocat"),tr("Cardul selectat este Blocat!"));
        }
    ui->lineEdit_sum_depozit->clear();
}


void App_Bank_Window::on_send_button_clicked()
{   //Transfer Cont Propriu
    if(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getStareCard().compare("Activat")==1)
    {
        m_handler=FactoryHandler::createTransferHandler();
        if(m_handler->verifySoldCheck(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getSold(),ui->lineEdit_sumaTrans->text().toFloat())==false)
        {
            QMessageBox::warning(this,tr("Transfer nereusit!"),tr("Suma tranzactionata depaseste SOLD-UL curent!"));
            return;
        }
        if(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN()== ui->lineEdit_IBAN_dest->text())
        {
            //verificam daca IBAN ul introdus nu este acelasi cu IBAN ul cardului de pe care se face transferul
            QMessageBox::warning(this,tr("Transfer nereusit!"),tr(" IBAN ul introdus coincide cu cel de pe care se efectueaza plata!"));
            return;
        }
        if(m_cont_utilizator->searchCardByIBAN(ui->lineEdit_IBAN_dest->text())==-1)
        {
            QMessageBox::warning(this,tr("Transfer cont propriu:"),tr("Incerci sa transferi bani intr un card care nu iti apartine!"));
            return;
        }

            IRequestTranzactie* transfer=RequestFactoryTranzactie::createRequestTransferP(m_cont_utilizator->getPersoana()->getID(),ui->lineEdit_sumaTrans->text().toFloat(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN().toStdString(),ui->lineEdit_IBAN_dest->text().toStdString());
            QByteArray dataByte=m_handler->sendRequestTranzactie(transfer);
            json responseJson=m_handler->receiveJson(dataByte);
            ResponseTranzactie* response=m_handler->parseResponseTranzactie(responseJson);

            if(response->getResult()==true)
            {
                ITranzactie* tranzactie=FactoryTranzactie::createTransfer(m_cont_utilizator->getPersoana()->getUsername(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN(),ui->lineEdit_sumaTrans->text().toFloat(),ui->lineEdit_IBAN_dest->text());
                m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->addTranzactie(tranzactie);
                m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->setNewSold(response->m_new_soldSursa);
                if(m_cont_utilizator->searchCardByIBAN(ui->lineEdit_IBAN_dest->text())!=-1)
                {
                    m_cont_utilizator->getCards()[m_cont_utilizator->searchCardByIBAN(ui->lineEdit_IBAN_dest->text())]->setNewSold(response->m_new_soldDestinatie);
                }
                if(searchInHistory(ui->cards_box->currentText())==-1||m_history.size()==0)
                {
                    m_history.push_back(std::move(new HistoryTranzaction(ui->cards_box->currentText(),ui->lineEdit_IBAN_dest->text(),"Cont propriu")));
                    ui->history_box->addItem(ui->cards_box->itemText(m_cont_utilizator->searchCardByIBAN(ui->lineEdit_IBAN_dest->text())));
                    QMessageBox::information(this,tr("Transfer reusit!"),QString::fromStdString(response->getMessage()));
                }
            }
            else
                 QMessageBox::information(this,tr("Transfer nereusit!"),QString::fromStdString(response->getMessage()));

            ui->lineEdit_sumaTrans->clear();
            ui->lineEdit_IBAN_dest->clear();
        delete m_handler;
    }
    else
    {
        QMessageBox::warning(this,tr("Card Blocat"),tr("Cardul selectat este Blocat!"));
        ui->lineEdit_sumaTrans->clear();
    }
}


void App_Bank_Window::on_sendButton2_clicked()
{
    //Transfer Multibank
    if(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getStareCard().compare("Activat")==1)
    {
        m_handler=FactoryHandler::createTransferHandler();
        if(m_handler->verifySoldCheck(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getSold(),ui->lineEdit_suma_trans_inter->text().toFloat())==false)
        {
            QMessageBox::warning(this,tr("Transfer nereusit!"),tr("Suma tranzactionata depaseste SOLD-UL curent!"));
            return;
        }
        if(m_handler->verifyConstraints(ui->lineEdit_IBAN_dest_2->text(),"IBAN")==0)
        {
            QMessageBox::warning(this,tr("Transfer nereusit!"),tr(" IBAN ul introdus este invalid!"));
            return;
        }

            IRequestTranzactie* transfer_multibank=RequestFactoryTranzactie::createRequestTransferMultibankP(m_cont_utilizator->getPersoana()->getID(),ui->lineEdit_suma_trans_inter->text().toFloat(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN().toStdString(),ui->lineEdit_IBAN_dest_2->text().toStdString(),ui->lineEdit_nume_destinatar->text().toStdString());
            QByteArray dataByte=m_handler->sendRequestTranzactie(transfer_multibank);
            json responseJson=m_handler->receiveJson(dataByte);
            ResponseTranzactie* response=m_handler->parseResponseTranzactie(responseJson);

            if(response->getResult()==true)
            {
                ITranzactie* tranzactie_multibank=FactoryTranzactie::createTransferMultibank(m_cont_utilizator->getPersoana()->getUsername(),m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getIBAN(),ui->lineEdit_suma_trans_inter->text().toFloat(),ui->lineEdit_IBAN_dest_2->text(),ui->lineEdit_nume_destinatar->text());
                m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->addTranzactie(tranzactie_multibank);
                m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->setNewSold(response->m_new_soldSursa);
                if(searchInHistory(ui->lineEdit_nume_destinatar->text())==-1||m_history.size()==0)
                {
                    m_history.push_back(std::move(new HistoryTranzaction(ui->lineEdit_nume_destinatar->text(),ui->lineEdit_IBAN_dest_2->text(),"Multibank")));
                    ui->history_box->addItem(ui->lineEdit_nume_destinatar->text());
                    QMessageBox::information(this,tr("Transfer reusit!"),QString::fromStdString(response->getMessage()));
                }
            }
            else
                 QMessageBox::information(this,tr("Transfer nereusit!"),QString::fromStdString(response->getMessage()));

            ui->lineEdit_IBAN_dest_2->clear();
            ui->lineEdit_nume_destinatar->clear();
            ui->lineEdit_suma_trans_inter->clear();

        delete m_handler;
    }
     else
    {
      QMessageBox::warning(this,tr("Card Blocat"),tr("Cardul selectat este Blocat!"));
      ui->lineEdit_suma_trans_inter->clear();
    }
}

void App_Bank_Window::on_currency_box_activated(int index)
{
    if(index==1)
        ui->lineEdit__sold->setText(QString::number(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getSold()/EURO));
    else
        if(index==2)
            ui->lineEdit__sold->setText(QString::number(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getSold()/USD));
    else
        if(index==0)
    {
        ui->lineEdit__sold->setText(QString::number(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getSold()));
    }
}


void App_Bank_Window::on_continueButton_clicked()
{
    //Plata POS
   if(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getStareCard().compare("Activat")==1)
    {
        m_handler=FactoryHandler::createPlatPosHandler();
        if(m_handler->verifySoldCheck(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getSold(),ui->lineEdit_sumaPOS->text().toFloat())==true)
        {
            if(ui->lineEdit_sumaPOS->text().toFloat()>100)
            {
                ui->detalii_plata_pos_box->hide();
                ui->pin_box->show();
            }
            else
            {
                makePaymentPOS();
            }
        }
    }
    else
        QMessageBox::warning(this,tr("Card blocat!"),tr("Cardul este blocat!"));
}

void App_Bank_Window::on_pushButton_1_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "1";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_2_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "2";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_3_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "3";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_4_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "4";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_5_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "5";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_6_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "7";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_7_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "7";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_8_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "8";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_9_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "9";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_0_clicked()
{
    QString currentText = ui->lineEditPin->text();
    currentText += "0";
    ui->lineEditPin->setText(currentText);
}


void App_Bank_Window::on_pushButton_delete_clicked()
{
   ui->lineEditPin->backspace();
}


void App_Bank_Window::on_pushButton_ok_clicked()
{
    //Plata POS pentru plati mai mari de 100 RON
    if(m_handler->verifyConstraints(QString::number(m_cont_utilizator->getCards()[ui->cards_box->currentIndex()]->getPin()),ui->lineEditPin->text())==true)
    {
        makePaymentPOS();
    }
    else
    {
        QMessageBox::warning(this,tr("Plata POS refuzata!"),tr("Pinul introdus este gresit!"));
    }
}


void App_Bank_Window::on_sendNumeButton_clicked()
{
    if(!ui->lineEdit_numeNou->text().isEmpty())
    {
        QString response=makeChange("Name",ui->lineEdit_numeNou->text());
        if(response!="")
        {
            m_cont_utilizator->getPersoana()->setName(response);
            ui->nume_utilizator_label->setText("Welcome "+m_cont_utilizator->getPersoana()->getNume());
            ui->lineEdit_numeNou->clear();
        }
        delete m_handler;
    }
    else
        QMessageBox::warning(this,tr("Modificare Nume:"),tr("Campul pentru noul Nume este gol!"));
}


void App_Bank_Window::on_sendAdresaButton_clicked()
{
    if(!ui->lineEdit_adresaNoua->text().isEmpty())
    {
        QString response=makeChange("Adress",ui->lineEdit_adresaNoua->text());
        if(response!="")
        {
            m_cont_utilizator->getPersoana()->setAdress(response);
            ui->lineEdit_adresaNoua->clear();
        }
        delete m_handler;
    }
    else
        QMessageBox::warning(this,tr("Modificare Adresa:"),tr("Campul pentru noua Adresa este gol!"));
}


void App_Bank_Window::on_sendNrTelefonButton_clicked()
{
    if(!ui->lineEdit_NrTelefonNou->text().isEmpty())
    {
        QString response=makeChange("Phone",ui->lineEdit_NrTelefonNou->text());
        if(response!="")
        {
            m_cont_utilizator->getPersoana()->setPhone(response);
            ui->lineEdit_NrTelefonNou->clear();
        }
        else
            QMessageBox::warning(this,tr("Modificare Numar telefon:"),tr("Numarul de telefon nu respecta formatul!"));
        delete m_handler;
    }
    else
        QMessageBox::warning(this,tr("Modificare Numar Telefon:"),tr("Campul pentru noul Numar de Telefon este gol!"));
}


void App_Bank_Window::on_sendEmailButton_clicked()
{
    if(!ui->lineEdit_EmailNou->text().isEmpty())
    {
        QString response=makeChange("Email",ui->lineEdit_EmailNou->text());
        if(response!="")
        {
            m_cont_utilizator->getPersoana()->setEmail(response);
            ui->lineEdit_EmailNou->clear();
        }
        else
            QMessageBox::warning(this,tr("Modificare Email:"),tr("Emailul nu respecta formatul!"));
        delete m_handler;
    }
    else
        QMessageBox::warning(this,tr("Modificare Email:"),tr("Campul pentru noul Email este gol!"));
}


void App_Bank_Window::on_history_box_activated(int index)
{
    if(ui->transfer_box->currentIndex()==0&&m_history[index]->getTipTranzactie().compare("Cont propriu")==false)
    {
        ui->lineEdit_IBAN_dest->setText(m_history[index]->getIBAN_Destinatie());
    }
    else
        if(ui->transfer_box->currentIndex()==1&&m_history[index]->getTipTranzactie().compare("Multibank")==false)
    {
        ui->lineEdit_nume_destinatar->setText(m_history[index]->getNumeDestinatar());
        ui->lineEdit_IBAN_dest_2->setText(m_history[index]->getIBAN_Destinatie());
    }
    else
        QMessageBox::warning(this,tr("Cont refuzat:"),tr("Contul din history nu respecta tipul tranzactiei!"));
}


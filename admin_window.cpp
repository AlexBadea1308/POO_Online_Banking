#include "admin_window.h"
#include "ui_admin_window.h"
#include"loginwindow.h"

Admin_Window::Admin_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin_Window)
{
    ui->setupUi(this);
    ui->Notifications->hide();
    ui->info_box->hide();
    setFixedSize(1122, 676);
}

Admin_Window::Admin_Window(ICont *cont, QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::Admin_Window), m_cont_admin(cont)
{
    ui->setupUi(this);
    m_handler=nullptr;
    ui->Notifications->hide();
    connect(&SConnectToServerAdmin::GetInstance(), &SConnectToServerAdmin::requestReceived, this, &Admin_Window::receiveRequestFromServer);
    setFixedSize(1122, 676);
}

Admin_Window::~Admin_Window()
{
    delete ui;
}

void Admin_Window::on_LogoutButton_clicked()
{
    std::string exit_string="Logout~" + m_cont_admin->getPersoana()->getUsername().toStdString();
    QByteArray byte_exit=QByteArray::fromStdString(exit_string);
    QByteArray responseByte =SConnectToServerAdmin::GetInstance().connectServer(byte_exit);
    std::string responseString = responseByte.toStdString();
    if (responseString.compare("OK\000"))
    {
        this->close();
        MainWindow *mainWindow= new MainWindow();
        mainWindow->show();
        this->~Admin_Window();
    }
    else
    {
        QMessageBox::warning(this,tr("Logout unsuccsessfull!"),tr("Nu te ai putut deconecta cu succes!"));
    }
}


void Admin_Window::on_NotificationsButton_clicked()
{
    SConnectToServerAdmin::GetInstance().receiveRequestFromServer();
    if(m_cont_admin->getRequests().size()>0)
    {
        ui->info_request->setText(QString::fromStdString(m_cont_admin->getRequests()[0]->getUsername()+
                                                         " a solicitat cererea de " + m_cont_admin->getRequests()[0]->getTip()));
        ui->Notifications->show();
        ui->info_box->show();
    }
    else
    {
        ui->Notifications->hide();
        ui->info_box->hide();
        QMessageBox::warning(this,tr("Notificari"),tr("Nu ai niciun request!"));
    }
}


void Admin_Window::on_choice_button_accepted()
{
    if (ui->info_request->toPlainText().isEmpty())
    {
        QMessageBox::information(this, tr("Atentie"), tr("Continutul este gol!"));
        return;
    }
     auto& requests = m_cont_admin->getRequests();

    IRequest* Request_confirmation=RequestFactory::createGestionareCardAdminP("Admin",requests[0]->getUsername(),requests[0]->getPassword(),
                                                                              requests[0]->getTip(),
                                                                              requests[0]->getIDCard());

    Request_confirmation->setIsAllowed(true);
    QByteArray confirmation=m_handler->sendRequest(Request_confirmation);
    SConnectToServerAdmin::GetInstance().sendRequestToServer(confirmation);
    // Verificam daca vectorul nu este gol
    if (!requests.empty())
    {
        requests.erase(requests.begin());
        ui->info_request->clear();
        ui->info_box->hide();
        ui->Notifications->hide();
    }
    else
        if(m_handler!=nullptr)
            delete m_handler;
}


void Admin_Window::on_choice_button_rejected()
{
    if (ui->info_request->toPlainText().isEmpty())
    {
        QMessageBox::information(this, tr("Atentie"), tr("Continutul este gol!"));
        return;
    }
    auto& requests = m_cont_admin->getRequests();

    IRequest* Request_confirmation=RequestFactory::createGestionareCardAdminP("Admin",requests[0]->getUsername(),requests[0]->getPassword(),
                                                                               requests[0]->getTip(),
                                                                               requests[0]->getIDCard());
    Request_confirmation->setIsAllowed(false);

    QByteArray confirmation=m_handler->sendRequest(Request_confirmation);
    SConnectToServerAdmin::GetInstance().sendRequestToServer(confirmation);
    // Verificam daca vectorul nu este gol
    if (!requests.empty())
    {
        requests.erase(requests.begin());
        ui->info_request->clear();
        ui->info_box->hide();
        ui->Notifications->hide();
    }
    else
        if(m_handler!=nullptr)
          delete m_handler;
}

void Admin_Window::receiveRequestFromServer(const QByteArray &requestData)
{
    m_handler=FactoryHandler::createGestionareCardHandler();
    IRequest* request=new RequestGestionareCard();
    json responseJson=json::parse(requestData);
    request->deserialize(responseJson);
    m_cont_admin->addRequests(request);
}




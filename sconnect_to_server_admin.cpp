#include "sconnect_to_server_admin.h"

SConnectToServerAdmin& SConnectToServerAdmin::GetInstance()
{
    if(mp_instance==NULL)
        mp_instance=new SConnectToServerAdmin();
    return *mp_instance;
}

SConnectToServerAdmin::SConnectToServerAdmin(QObject *parent) : QObject(parent)
{
    m_socket.connectToHost("25.12.178.33",12975);
    m_socket.waitForConnected();
}

QByteArray SConnectToServerAdmin::connectServer(const QByteArray &sendbuff)
{
    if (!m_socket.isValid())
    {
        return "0";
    }

    m_socket.write(sendbuff);
    m_socket.waitForBytesWritten();
    m_socket.waitForReadyRead();
    QByteArray response = m_socket.readAll();

    return response;
}

void SConnectToServerAdmin::receiveRequestFromServer()
{
    int ok=1;
    while(ok!=0)
    {
        if(m_socket.isValid())
        {
            // Citirea request-ului de la server
            QByteArray requestData = m_socket.readAll();
            // Emite semnalul pentru a transmite request-ul primit
            if(!requestData.isEmpty() && requestData.size() > 30)
                emit requestReceived(requestData);
            else
                ok=0;
        }
    }
}

void SConnectToServerAdmin::sendRequestToServer(const QByteArray &requestData)
{
    // Verificam dacă socket-ul este valid
    if (!m_socket.isValid())
    {
        qDebug() << "Socket is not valid.";
        return;
    }

    // Trimiterea request-ului catre server
    m_socket.write(requestData);
    m_socket.waitForBytesWritten();
}


void SConnectToServerAdmin::DestroyInstance()
{
    if(mp_instance!=NULL)
       delete mp_instance;
     mp_instance=NULL;
}



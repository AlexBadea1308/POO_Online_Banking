#include "sconnect_to_server.h"

SConnectToServer& SConnectToServer::GetInstance()
{
    if(mp_instance==NULL)
        mp_instance=new SConnectToServer();
    return *mp_instance;
}

void SConnectToServer::closeSocket()
{
    m_socket.close();
}

SConnectToServer::SConnectToServer(QObject *parent) : QObject(parent)
{
    m_socket.connectToHost("25.12.178.33",12975);
    m_socket.waitForConnected();
}

QByteArray SConnectToServer::connectServer(const QByteArray &sendbuff)
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


void SConnectToServer::DestroyInstance()
{
    if(mp_instance!=NULL)
       delete mp_instance;
     mp_instance=NULL;
}



#ifndef SCONNECT_TO_SERVER_ADMIN_H
#define SCONNECT_TO_SERVER_ADMIN_H

#include <QTcpSocket>
#include <QObject>
#include <QString>
#include <json.hpp>

class SConnectToServerAdmin : public QObject
{
    Q_OBJECT

private:
    SConnectToServerAdmin(QObject *parent = nullptr);
    SConnectToServerAdmin(const SConnectToServerAdmin&) = delete;
    SConnectToServerAdmin& operator=(const SConnectToServerAdmin&) = delete;
    static SConnectToServerAdmin *mp_instance;
    QTcpSocket m_socket;
signals:
    void requestReceived(const QByteArray &requestData);
public:
    static SConnectToServerAdmin& GetInstance();
    void DestroyInstance();
    QByteArray connectServer(const QByteArray &sendbuff);
    void receiveRequestFromServer();
    void sendRequestToServer(const QByteArray &requestData);
};

#endif SCONNECT_TO_SERVER_ADMIN_H

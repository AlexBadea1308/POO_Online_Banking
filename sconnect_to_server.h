#ifndef SCONNECT_TO_SERVER_H
#define SCONNECT_TO_SERVER_H

#include <QTcpSocket>
#include <QObject>
#include <QString>
#include <json.hpp>

class SConnectToServer : public QObject
{
    Q_OBJECT

private:
    SConnectToServer(QObject *parent = nullptr);
    SConnectToServer(const SConnectToServer&) = delete;
    SConnectToServer& operator=(const SConnectToServer&) = delete;
    static SConnectToServer *mp_instance;
    QTcpSocket m_socket;
public:
    static SConnectToServer& GetInstance();
    void closeSocket();
    void DestroyInstance();
    QByteArray connectServer(const QByteArray &sendbuff);
};

#endif SCONNECT_TO_SERVER_H



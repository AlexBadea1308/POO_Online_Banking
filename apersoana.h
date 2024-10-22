#ifndef APERSOANA_H
#define APERSOANA_H
#include<Qstring>
#include "ipersoana.h"

class APersoana:public IPersoana
{
protected:
    QString m_username;
    QString m_password;
    int m_ID;
public:
    APersoana();
    APersoana(QString username,QString password);
    QString getUsername() override;
    QString getPassword() override;
    void setUsername(QString username)override;
    void setPassword(QString password)override;
    int getID()override;
    void setID(int id)override;
    void setName(QString name) override;
    void setAdress(QString adress)override;
    void setPhone(QString phone)override;
    void setEmail(QString email)override;
    void setCNP(QString cnp)override;
    void setSecurityPhrases(securityPhares phrases)override;
    QString getNume() override;
};

#endif // APERSOANA_H

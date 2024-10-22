#ifndef CLIENT_H
#define CLIENT_H
#include "apersoana.h"
#include "utils.h"

class Client: public APersoana
{
private:
    QString m_nume;
    QString m_adresa;
    QString m_phone;
    QString m_email;
    QString m_cnp;
    securityPhares m_phrases;
public:
    Client();
    Client(QString nume,QString adresa,QString phone,QString username,QString password,QString email,QString cnp,securityPhares phrases);
    void setName(QString name) override;
    void setAdress(QString adress)override;
    void setPhone(QString phone)override;
    void setEmail(QString email)override;
    void setCNP(QString cnp)override;
    void setCodAdmin(int codAdmin)override;
    void setSecurityPhrases(securityPhares phrases)override;
    QString getNume()override;
};


#endif // CLIENT_H

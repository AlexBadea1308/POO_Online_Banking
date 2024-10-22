#include "client.h"

Client::Client() {}

Client::Client(QString nume,QString adresa,QString phone,QString username,QString password,QString email,QString cnp,securityPhares phrases):APersoana(username,password)
{
    m_nume=nume;
    m_adresa=adresa;
    m_cnp=cnp;
    m_email=email;
    m_phone=phone;
    m_phrases=phrases;
}

void Client::setName(QString name)
{
    m_nume=name;
}

void Client::setAdress(QString adress)
{
    m_adresa=adress;
}

void Client::setPhone(QString phone)
{
    m_phone=phone;
}

void Client::setEmail(QString email)
{
    m_email=email;
}

void Client::setCNP(QString cnp)
{
    m_cnp=cnp;
}

void Client::setCodAdmin(int codAdmin)
{
    throw MyException("Functia setCodAdmin() innacesibila pentru Client!");
}

void Client::setSecurityPhrases(securityPhares phrases)
{
    m_phrases=phrases;
}

QString Client::getNume()
{
    return m_nume;
}



#include "apersoana.h"

APersoana::APersoana() {}

APersoana:: APersoana(QString username,QString password)
{
    m_username=username;
    m_password=password;
}

QString APersoana::getUsername()
{
    return m_username;
}

QString APersoana::getPassword()
{
    return m_password;
}

void APersoana::setUsername(QString username)
{
    m_username=username;
}

void APersoana::setPassword(QString password)
{
    m_password=password;
}

int APersoana::getID()
{
    return m_ID;
}

void APersoana::setID(int id)
{
    m_ID=id;
}

void  APersoana::setName(QString name)
{
    throw MyException("Funcția setName() inaccesibilă pentru ADMIN!");
}

void  APersoana::setAdress(QString adress)
{
    throw MyException("Funcția setAdress() inaccesibilă pentru ADMIN!");
}

void  APersoana::setPhone(QString phone)
{
    throw MyException("Funcția setPhone() inaccesibilă pentru ADMIN!");
}

void  APersoana::setEmail(QString email)
{
    throw MyException("Funcția setEmail() inaccesibilă pentru ADMIN!");
}

void  APersoana::setCNP(QString cnp)
{
    throw MyException("Funcția setCNP() inaccesibilă pentru ADMIN!");
}


void  APersoana::setSecurityPhrases(securityPhares phrases)
{
    throw MyException("Funcția setSecurityPhrases() inaccesibilă pentru ADMIN!");
}

QString  APersoana::getNume()
{
    throw MyException("Functia getNume() inaccesibila pentru Admin!");
}

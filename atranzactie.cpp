#include "atranzactie.h"

ATranzactie::ATranzactie() {}

ATranzactie::ATranzactie(QString username, QString iban_sursa, float suma_tranzactionata)
{
    m_username=username;
    m_IBAN_sursa=iban_sursa;
    m_suma_tranzactionata=suma_tranzactionata;
}

ATranzactie::~ATranzactie()
{

}

void ATranzactie::setUsername(QString username)
{
    m_username=username;
}

void ATranzactie::setIBANsursa(QString iban_sursa)
{
    m_IBAN_sursa=iban_sursa;
}

void ATranzactie::SetSuma(float suma)
{
    m_suma_tranzactionata=suma;
}

QString ATranzactie::getUsername()
{
    return m_username;
}

QString ATranzactie::getIBANsursa()
{
    return m_IBAN_sursa;
}

float ATranzactie::getSuma()
{
    return m_suma_tranzactionata;
}

QString ATranzactie::getType()
{
    return m_tip_tranzactie;
}

QString ATranzactie::getNumeDestinatar()
{
    throw MyException("Functia getNumeDestinatar este inaccesibila pentru acest tip de obiect!");
}

QString ATranzactie::getIBANDestinatie()
{
    throw MyException("Functia getIBANDestinatar este inaccesibila pentru acest tip de obiect!");
}

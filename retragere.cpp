#include "retragere.h"

Retragere::Retragere()
{
    m_tip_tranzactie="Retragere";
    m_suma_tranzactionata=0;
}

Retragere::Retragere(QString username, QString iban_sursa,float suma_tranzactionata):ATranzactie(username,iban_sursa,suma_tranzactionata)
{
    m_tip_tranzactie="Retragere";
}

Retragere::~Retragere()
{
    m_suma_tranzactionata=0;
}

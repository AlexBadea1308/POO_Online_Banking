#include "depunere.h"

Depunere::Depunere()
{
    m_tip_tranzactie="Depunere";
    m_suma_tranzactionata=0;
}

Depunere::Depunere(QString username, QString iban_sursa,float suma_tranzactionata):ATranzactie(username,iban_sursa,suma_tranzactionata)
{
    m_tip_tranzactie="Depunere";
}

Depunere::~Depunere()
{
    m_suma_tranzactionata=0;
}

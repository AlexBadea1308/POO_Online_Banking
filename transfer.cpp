#include "transfer.h"

Transfer::Transfer()
{
    m_suma_tranzactionata=0;
    m_tip_tranzactie="Transfer cont propriu";
}

Transfer::Transfer(QString username, QString iban_sursa, float suma_tranzactionata, QString iban_destinatie):ATranzactie(username,iban_sursa,suma_tranzactionata)
{
    m_IBAN_destinatie=iban_destinatie;
    m_tip_tranzactie="Transfer cont propriu";
}

QString Transfer::getIBANDestinatie()
{
    return m_IBAN_destinatie;
}

Transfer::~Transfer()
{
    m_suma_tranzactionata=0;
}

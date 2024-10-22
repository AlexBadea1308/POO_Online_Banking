#include "transfermultibank.h"

TransferMultibank::TransferMultibank()
{
    m_suma_tranzactionata=0;
    m_tip_tranzactie="Transfer multibank";
}

TransferMultibank::TransferMultibank(QString username, QString iban_sursa, float suma_tranzactionata, QString iban_destinatie, QString nume_destinatar):Transfer(username,iban_sursa,suma_tranzactionata,iban_destinatie)
{
    m_nume_destinatar=nume_destinatar;
    m_tip_tranzactie="Transfer Multibank";
}

QString TransferMultibank::getNumeDestinatar()
{
    return m_nume_destinatar;
}

TransferMultibank::~TransferMultibank()
{
    m_suma_tranzactionata=0;
}

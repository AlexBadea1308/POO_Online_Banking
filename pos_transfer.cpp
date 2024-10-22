#include "pos_transfer.h"

POS_Transfer::POS_Transfer()
{
    m_nume_destinatar="";
}

POS_Transfer::POS_Transfer(QString username, QString iban_sursa, float suma_tranzactionata, QString nume_destinatar):ATranzactie(username,iban_sursa,suma_tranzactionata)
{
    m_nume_destinatar=nume_destinatar;
}

POS_Transfer::~POS_Transfer() { m_nume_destinatar = "";}

QString POS_Transfer::getNumeDestinatar()
{
    return m_nume_destinatar;
}

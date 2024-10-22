#include "card.h"

Card::Card() {}

Card::Card(int id)
{
    m_id=id;
    m_sold=0;
    m_pin=0;
    m_cod_cvv=0;
    m_stare="";
}

Card:: Card(QString iban,QString nrCard, int pin, QString data_expirare,double sold,int cod_cvv,int id)
{
    m_iban=iban;
    m_nrCard=nrCard;
    m_pin=pin;
    m_data_expirare=data_expirare;
    m_sold=sold;
    m_cod_cvv=cod_cvv;
    m_id=id;
    m_stare="Activat";
}

int Card::getCardID()
{
    return m_id;
}

int Card::getPin()
{
    return m_pin;
}

void Card::setNewSold(double sold)
{
    m_sold=sold;
}

void Card::setIBAN(QString iban)
{
   m_iban=iban;
}

void Card::setNrCard(QString nrCard)
{
    m_nrCard=nrCard;
}

void Card::setCVV(int cvv)
{
    m_cod_cvv=cvv;
}

void Card::setDataExpirare(QString data_expirare)
{
    m_data_expirare=data_expirare;
}

void Card::setPIN(int pin)
{
    m_pin=pin;
}

QString Card::getStareCard()
{
    return m_stare;
}

void Card::setStareCard(QString stare_card)
{
    m_stare=stare_card;
}

QString Card::getIBAN()
{
    return m_iban;
}

QString Card::getDataExpirare()
{
    return m_data_expirare;
}

void Card::addTranzactie(ITranzactie *tranz)
{
    m_tranzactii.push_back(tranz);
}

std::vector<ITranzactie *> &Card::getTranzactii()
{
    return m_tranzactii;
}

double Card::getSold()
{
    return m_sold;
}

void Card::setCardID(int id)
{
    m_id=id;
}

void Card::initializeCard(QString card_details)
{
    QStringList parts = card_details.split("~");
    m_nrCard=parts[0];
    m_iban=parts[1];
    m_sold=parts[2].toDouble();
    m_data_expirare=parts[3];
    m_cod_cvv=parts[4].toInt();
    m_pin=parts[5].toInt();
    if(parts[6].toInt()==0)
        m_stare="Activat";
    else
        m_stare="Blocat";
}


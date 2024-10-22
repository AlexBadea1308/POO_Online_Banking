#include "acont.h"

ACont::ACont() {}

ACont::  ACont(IPersoana *persoana)
{
    m_persoana=persoana;
}

ACont::~ACont()
{
    delete m_persoana;
}

IPersoana *ACont::getPersoana()
{
    return m_persoana;
}

int ACont::searchCardByIBAN(QString iban)
{
    throw MyException("Functia searchCardByIBAN este inaccesibila pentru acest tip de obiect!");
}

std::vector<IRequest *> &ACont::getRequests()
{
    throw MyException("Functia getRequests este inaccesibila pentru acest tip de obiect!");
}

void ACont::addRequests(IRequest *request)
{
    throw MyException("Functia addRequests este inaccesibila pentru acest tip de obiect!");
}

void ACont::addCard(Card *new_card)
{
     throw MyException("Functia addCard este inaccesibila pentru acest tip de obiect!");
}

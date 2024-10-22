#include "cont_admin.h"

Cont_Admin::Cont_Admin() {m_persoana=new Admin();}

Cont_Admin:: Cont_Admin(IPersoana* persoana):ACont(persoana){}

std::vector<Card *> &Cont_Admin::getCards()
{
    throw MyException("Functia getCards() inaccesibila pentru Cont_Admin");
}

void Cont_Admin::initializeCont(QString cont_details)
{
    if(cont_details!=nullptr)
    m_persoana->setCodAdmin(cont_details.toInt());
    else
        throw MyException("Adminul nu a primit codul!");
}

void Cont_Admin::addRequests(IRequest*request)
{
    m_requests.push_back(request);
}

std::vector<IRequest*> &Cont_Admin::getRequests()
{
    return m_requests;
}



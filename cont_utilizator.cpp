#include "cont_utilizator.h"

Cont_Utilizator::Cont_Utilizator() {m_persoana= new Client();}


std::vector<Card *> &Cont_Utilizator::getCards()
{
        return m_carduri;
}

void Cont_Utilizator::initializeCont(QString cont_details)
{
     QStringList parts = cont_details.split("~");
     m_persoana->setName(parts[0]);
     m_persoana->setAdress(parts[1]);
     m_persoana->setPhone(parts[2]);
     m_persoana->setEmail(parts[3]);
     m_persoana->setCNP(parts[4]);

     securityPhares temp_phrases;
     temp_phrases.fraza_securitate=parts[5].toStdString();
     temp_phrases.intrebare_securitate.first=parts[6].toStdString();
     temp_phrases.intrebare_securitate.second=parts[7].toStdString();
     m_persoana->setSecurityPhrases(temp_phrases);
     int j=9;
     for(int i=0;i<parts[8].toInt();i++)
     {
         m_carduri.push_back(std::move(new Card(parts[j].toInt())));
         j++;
     }
}

int Cont_Utilizator::searchCardByIBAN(QString iban)
{
     for (size_t i = 0; i <m_carduri.size();i++)
    {
        if(iban.compare(m_carduri[i]->getIBAN())==0)
             return i;
    }
     return -1;
}

void Cont_Utilizator::addCard(Card *new_card)
{
    m_carduri.push_back(std::move(new_card));
}

Cont_Utilizator::Cont_Utilizator(IPersoana *persoana):ACont(persoana){}

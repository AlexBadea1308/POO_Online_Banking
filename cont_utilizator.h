#ifndef CONT_UTILIZATOR_H
#define CONT_UTILIZATOR_H
#include"acont.h"
#include"client.h"

class Cont_Utilizator: public ACont
{
private:
    std::vector<Card*> m_carduri;
public:
    Cont_Utilizator(IPersoana *persoana);
    Cont_Utilizator();
    std::vector<Card*>& getCards() override;
    void initializeCont(QString cont_details) override;
    int searchCardByIBAN(QString iban)override;
    void addCard(Card* new_card)override;
};

#endif // CONT_UTILIZATOR_H

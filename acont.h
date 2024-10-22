#ifndef ACONT_H
#define ACONT_H
#include "icont.h"
#include<vector>

class ACont:public ICont
{
protected:
    IPersoana* m_persoana;
public:
    ACont();
    ACont(IPersoana *persoana);
    virtual ~ACont();
    IPersoana* getPersoana() override;
    virtual int searchCardByIBAN(QString iban)override;
    virtual std::vector<IRequest*>& getRequests()override;
    virtual void addRequests(IRequest* request)override;
    virtual void addCard(Card* new_card)override;
};

#endif // ACONT_H

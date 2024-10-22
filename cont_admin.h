#ifndef CONT_ADMIN_H
#define CONT_ADMIN_H
#include"acont.h"
class Cont_Admin: public ACont
{
private:
    std::vector<IRequest*> m_requests;
public:
    Cont_Admin();
    Cont_Admin(IPersoana* persoana);
    std::vector<Card*>& getCards() override;
    void initializeCont(QString cont_details)override;
    void addRequests(IRequest* request)override;
    std::vector<IRequest*>& getRequests()override;
};

#endif // CONT_ADMIN_H

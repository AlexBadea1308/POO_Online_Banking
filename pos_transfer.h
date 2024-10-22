#ifndef POS_TRANSFER_H
#define POS_TRANSFER_H
#include "atranzactie.h"

class POS_Transfer:public ATranzactie
{
private:
    QString m_nume_destinatar;
public:
   POS_Transfer();
   POS_Transfer(QString username,QString iban_sursa,float suma_tranzactionata,QString nume_destinatar);
    ~POS_Transfer();
   QString getNumeDestinatar()override;
};

#endif // POS_TRANSFER_H

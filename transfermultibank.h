#ifndef TRANSFERMULTIBANK_H
#define TRANSFERMULTIBANK_H

#include "transfer.h"

class TransferMultibank : public Transfer
{
protected:
    QString m_nume_destinatar;
public:
    TransferMultibank();
    TransferMultibank(QString username,QString iban_sursa,float suma_tranzactionata,QString iban_destinatie,QString nume_destinatar);
    QString getNumeDestinatar()override;
    ~TransferMultibank();
};

#endif // TRANSFERMULTIBANK_H

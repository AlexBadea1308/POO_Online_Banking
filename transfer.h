#ifndef TRANSFER_H
#define TRANSFER_H

#include "atranzactie.h"

class Transfer : public ATranzactie
{
protected:
    QString m_IBAN_destinatie;
public:
    Transfer();
    Transfer(QString username,QString iban_sursa,float suma_tranzactionata,QString iban_destinatie);
    QString getIBANDestinatie()override;
    ~Transfer();
};

#endif // TRANSFER_H

#ifndef FACTORYTRANZACTIE_H
#define FACTORYTRANZACTIE_H

#include "depunere.h"
#include "retragere.h"
#include "transfermultibank.h"
#include"pos_transfer.h"

class FactoryTranzactie
{
public:
    static Depunere* createDepunere(QString username,QString iban_sursa,float suma_tranzactionata);
    static Retragere* createRetragere(QString username,QString iban_sursa,float suma_tranzactionata);
    static POS_Transfer* createPOS_Transfer(QString username,QString iban_sursa,float suma_tranzactionata,QString nume_destinatar);
    static Transfer* createTransfer(QString username,QString iban_sursa,float suma_tranzactionata,QString iban_destinatie);
    static TransferMultibank* createTransferMultibank(QString username,QString iban_sursa,float suma_tranzactionata,QString iban_destinatie,QString nume_destinatar);
};

#endif // FACTORYTRANZACTIE_H

#include "factorytranzactie.h"

Depunere *FactoryTranzactie::createDepunere(QString username, QString iban_sursa, float suma_tranzactionata)
{
    return new Depunere(username,iban_sursa,suma_tranzactionata);
}

Retragere *FactoryTranzactie::createRetragere(QString username, QString iban_sursa, float suma_tranzactionata)
{
    return new Retragere(username,iban_sursa,suma_tranzactionata);
}

POS_Transfer *FactoryTranzactie::createPOS_Transfer(QString username, QString iban_sursa, float suma_tranzactionata, QString nume_destinatar)
{
    return new POS_Transfer(username,iban_sursa,suma_tranzactionata,nume_destinatar);
}

Transfer *FactoryTranzactie::createTransfer(QString username, QString iban_sursa, float suma_tranzactionata, QString iban_destinatie)
{
    return new Transfer(username,iban_sursa,suma_tranzactionata,iban_destinatie);
}

TransferMultibank *FactoryTranzactie::createTransferMultibank(QString username, QString iban_sursa, float suma_tranzactionata, QString iban_destinatie, QString nume_destinatar)
{
    return new TransferMultibank(username,iban_sursa,suma_tranzactionata,iban_destinatie,nume_destinatar);
}

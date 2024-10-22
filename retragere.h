#ifndef RETRAGERE_H
#define RETRAGERE_H

#include "atranzactie.h"

class Retragere : public ATranzactie
{
public:
    Retragere();
    Retragere(QString username,QString iban_sursa,float suma_tranzactionata);
    ~Retragere();
};

#endif // RETRAGERE_H

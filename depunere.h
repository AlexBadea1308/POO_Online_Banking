#ifndef DEPUNERE_H
#define DEPUNERE_H

#include "atranzactie.h"

class Depunere : public ATranzactie
{
public:
    Depunere();
    Depunere(QString username,QString iban_sursa,float suma_tranzactionata);
    ~Depunere();
};

#endif // DEPUNERE_H

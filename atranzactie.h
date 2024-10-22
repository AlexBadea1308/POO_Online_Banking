#ifndef ATRANZACTIE_H
#define ATRANZACTIE_H

#include "itranzactie.h"

class ATranzactie : public ITranzactie
{
protected:
    QString m_username;
    QString m_IBAN_sursa;
    float m_suma_tranzactionata;
    QString m_tip_tranzactie;
public:
    ATranzactie();
    ATranzactie(QString username,QString iban_sursa,float suma_tranzactionata);
    virtual ~ATranzactie();
    void setUsername(QString username)override;
    void setIBANsursa(QString iban_sursa)override;
    void SetSuma(float suma)override;
    QString getUsername()override;
    QString getIBANsursa()override;
    float getSuma()override;
    virtual QString getType()override;
    virtual QString getNumeDestinatar()override;
    virtual QString getIBANDestinatie()override;
};

#endif // ATRANZACTIE_H

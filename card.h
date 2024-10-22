#ifndef CARD_H
#define CARD_H
#include<QString>
#include<QStringList>
#include "itranzactie.h"

class Card
{
private:
    QString m_iban;
    QString m_nrCard;
    double m_sold;
    int m_pin;
    QString m_data_expirare;
    int m_cod_cvv;
    int m_id;
    QString m_stare;
    std::vector<ITranzactie*> m_tranzactii;
public:
    Card();
    Card(int id);
    Card(QString iban,QString nrCard, int pin, QString data_expirare,double sold,int cod_cvv,int id);
    int getCardID();
    int getPin();
    double getSold();
    void initializeCard(QString card_details);
    void setCardID(int id);
    void setNewSold(double sold);
    void setIBAN(QString iban);
    void setNrCard(QString nrCard);
    void setCVV(int cvv);
    void setDataExpirare(QString data_expirare);
    void setPIN(int pin);
    QString getStareCard();
    void setStareCard(QString stare_card);
    QString getIBAN();
    QString getDataExpirare();
    void addTranzactie(ITranzactie* tranz);
    std::vector<ITranzactie*>& getTranzactii();
};

#endif // CARD_H

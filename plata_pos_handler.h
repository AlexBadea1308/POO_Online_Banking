#ifndef PLATA_POS_HANDLER_H
#define PLATA_POS_HANDLER_H

#include "ahandler.h"

class Plata_POS_Handler : public AHandler
{
public:
    Plata_POS_Handler();
    int verifyConstraints(QString data,QString type)override;
    bool verifySoldCheck(float sold_sursa,float sold_introdus)override;
    ResponseTranzactie* parseResponseTranzactie(json &json_object)override;
    QByteArray sendRequestTranzactie(IRequestTranzactie *request)override;
};

#endif // PLATA_POS_HANDLER_H

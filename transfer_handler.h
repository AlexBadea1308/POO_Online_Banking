#ifndef TRANSFER_HANDLER_H
#define TRANSFER_HANDLER_H

#include "ahandler.h"

class Transfer_Handler : public AHandler
{
public:
    Transfer_Handler();
    ResponseTranzactie* parseResponseTranzactie(json &json_object)override;
    QByteArray sendRequestTranzactie(IRequestTranzactie *request)override;
    int verifyConstraints(QString data,QString type)override;
    bool verifySoldCheck(float sold_sursa,float sold_introdus)override;
};

#endif // TRANSFER_HANDLER_H

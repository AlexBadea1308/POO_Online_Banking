#ifndef RETRAGEREHANDLER_H
#define RETRAGEREHANDLER_H

#include "ahandler.h"

class RetragereHandler : public AHandler
{
public:
    explicit RetragereHandler(QObject *parent = nullptr);
    ResponseTranzactie* parseResponseTranzactie(json &json_object)override;
    QByteArray sendRequestTranzactie(IRequestTranzactie *request)override;
    bool verifySoldCheck(float sold_sursa,float sold_introdus)override;
};

#endif // RETRAGEREHANDLER_H

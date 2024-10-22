#ifndef DEPUNEREHANDLER_H
#define DEPUNEREHANDLER_H

#include "ahandler.h"

class DepunereHandler : public AHandler
{
public:
    DepunereHandler();
    ResponseTranzactie* parseResponseTranzactie(json &json_object)override;
    QByteArray sendRequestTranzactie(IRequestTranzactie *request)override;
};

#endif // DEPUNEREHANDLER_H

#ifndef VERIFYSECURITYHANDLER_H
#define VERIFYSECURITYHANDLER_H

#include "ahandler.h"

class VerifySecurityHandler : public AHandler
{
public:
    explicit VerifySecurityHandler(QObject *parent = nullptr);
    IResponse* parseResponse(json &json_object) override;
};

#endif // VERIFYSECURITYHANDLER_H

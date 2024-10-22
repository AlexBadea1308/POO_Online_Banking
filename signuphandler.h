#ifndef SIGNUPHANDLER_H
#define SIGNUPHANDLER_H

#include "ahandler.h"
#include "SignUpResponse.h"
#include "utils.h"


class SignUpHandler : public AHandler
{
public:
    explicit SignUpHandler(QObject *parent = nullptr);
    int verifyConstraints(QString data,QString type) override;
    IResponse* parseResponse(json &json_object) override;
    securityPhares createPhrases(QString frazaSecuritate,QString intrebareSecuritate,QString raspuns);
};

#endif // SIGNUPHANDLER_H

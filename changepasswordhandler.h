#ifndef CHANGEPASSWORDHANDLER_H
#define CHANGEPASSWORDHANDLER_H

#include "ahandler.h"

class ChangePasswordHandler : public AHandler
{
public:
    explicit ChangePasswordHandler(QObject *parent = nullptr);
    int verifyConstraints(QString data,QString type) override;
    IResponse* parseResponse(json &json_object) override;
};

#endif // CHANGEPASSWORDHANDLER_H

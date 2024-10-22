#ifndef CHANGEFIELDHANDLER_H
#define CHANGEFIELDHANDLER_H

#include "ahandler.h"

class ChangeFieldHandler : public AHandler
{
public:
    explicit ChangeFieldHandler(QObject *parent = nullptr);
    IResponse* parseResponse(json &json_object) override;
    int verifyConstraints(QString data, QString type)override;
};

#endif // CHANGEFIELDHANDLER_H

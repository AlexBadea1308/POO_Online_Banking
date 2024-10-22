#ifndef DETAILSCARDHANDLER_H
#define DETAILSCARDHANDLER_H

#include "ahandler.h"
#include"GetDetailsCardResponse.h"

class DetailsCardHandler : public AHandler
{
public:
    explicit DetailsCardHandler(QObject *parent = nullptr);
    ~DetailsCardHandler();
    int verifyConstraints(QString data,QString type) override;
    IResponse* parseResponse(json &json_object) override;
};

#endif // DETAILSCARDHANDLER_H

#ifndef AHANDLER_H
#define AHANDLER_H

#include "ihandler.h"
#include <QObject>

class AHandler : public IHandler
{
public:
    AHandler(QObject *parent = nullptr);
    virtual ~AHandler() {}
    QByteArray sendRequest(IRequest* request) override;
    json receiveJson(QByteArray byte_array) override;
    virtual ResponseTranzactie* parseResponseTranzactie(json &json_object)override;
    virtual IResponse* parseResponse(json &json_object)override;
    virtual int verifyConstraints(QString data,QString type)override;
    virtual QByteArray sendRequestTranzactie(IRequestTranzactie *request)override;
    virtual bool verifySoldCheck(float sold_sursa,float sold_introdus)override;
};

#endif

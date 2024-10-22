#include "retragerehandler.h"

RetragereHandler::RetragereHandler(QObject *parent)
    : AHandler{parent}
{}

ResponseTranzactie *RetragereHandler::parseResponseTranzactie(json &json_object)
{
    ResponseTranzactie* response=ResponseFactory::createTranzactieResponse();
    response->fromJson(json_object);
    return response;
}

QByteArray RetragereHandler::sendRequestTranzactie(IRequestTranzactie *request)
{
    json data=request->serialize();
    std::string jsonStr = data.dump();
    QByteArray dataByte = QByteArray::fromStdString(jsonStr);
    delete request;
    return dataByte;
}

bool RetragereHandler::verifySoldCheck(float sold_sursa, float sold_introdus)
{
    if(sold_sursa>=sold_introdus)
        return true;
    else
        return false;
}

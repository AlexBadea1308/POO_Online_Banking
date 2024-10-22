#include "depunerehandler.h"

DepunereHandler::DepunereHandler() {}

ResponseTranzactie *DepunereHandler::parseResponseTranzactie(json &json_object)
{
    ResponseTranzactie* response=ResponseFactory::createTranzactieResponse();
    response->fromJson(json_object);
    return response;
}

QByteArray DepunereHandler::sendRequestTranzactie(IRequestTranzactie *request)
{
    json data=request->serialize();
    std::string jsonStr = data.dump();
    QByteArray dataByte = QByteArray::fromStdString(jsonStr);
    delete request;
    return dataByte;
}

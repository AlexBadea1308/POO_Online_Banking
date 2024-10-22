#include "ahandler.h"


AHandler::AHandler(QObject *parent){}

QByteArray AHandler::sendRequest(IRequest* request)
{
    json data=request->serialize();
    std::string jsonStr = data.dump();
    QByteArray dataByte = QByteArray::fromStdString(jsonStr);
    delete request;
    return dataByte;
}

json AHandler::receiveJson(QByteArray byte_array)
{
    QByteArray responseByte =SConnectToServer::GetInstance().connectServer(byte_array);
    json responsejson  = json::parse(responseByte);
    return responsejson;
}

ResponseTranzactie *AHandler::parseResponseTranzactie(json &json_object)
{
    throw MyException("Functia parseResponseTranzactie este inaccesibila pentru acest tip de obiect!");
}

IResponse *AHandler::parseResponse(json &json_object)
{
    throw MyException("Functia parseResponse este inaccesibila pentru acest tip de obiect!");
}

int AHandler::verifyConstraints(QString data, QString type)
{
    throw MyException("Functia verifyConstraints este inaccesibila pentru acest tip de obiect!");
}

QByteArray AHandler::sendRequestTranzactie(IRequestTranzactie *request)
{
    throw MyException("Functia sendRequestTransfer este inaccesibila pentru acest tip de obiect!");
}

bool AHandler::verifySoldCheck(float sold_sursa, float sold_introdus)
{
    throw  MyException("Functia verifySoldCheck este inaccesibila pentru acest tip de obiect!");
}



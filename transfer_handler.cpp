#include "transfer_handler.h"

Transfer_Handler::Transfer_Handler() {}

ResponseTranzactie *Transfer_Handler::parseResponseTranzactie(json &json_object)
{
    ResponseTranzactie* response=ResponseFactory::createTranzactieResponse();
    response->fromJson(json_object);
    return response;
}

QByteArray Transfer_Handler::sendRequestTranzactie(IRequestTranzactie *request)
{
    json data=request->serialize();
    std::string jsonStr = data.dump();
    QByteArray dataByte = QByteArray::fromStdString(jsonStr);
    delete request;
    return dataByte;
}

int Transfer_Handler::verifyConstraints(QString data, QString type)
{
    if (type == "IBAN")
    {
        QRegularExpression regex("^RO\\d{13}$");
        if (regex.match(data).hasMatch())
        {
            return 1; //IBAN valid
        } else
        {
            return 0;  //IBAN invalid
        }
    }
    return 0; //in cazul in care type nu este IBAN
}

bool Transfer_Handler::verifySoldCheck(float sold_sursa, float sold_introdus)
{
    if(sold_sursa>=sold_introdus)
        return true;
    else
        return false;
}


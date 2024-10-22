#include "detailscardhandler.h"

DetailsCardHandler::DetailsCardHandler(QObject *parent)
    : AHandler{parent}
{}

DetailsCardHandler::~DetailsCardHandler(){}

int DetailsCardHandler::verifyConstraints(QString data, QString type)
{
    if(type=="userID"&&data=="-1")
        return 0;
    else
        if(type=="cardID"&&data=="-1")   // verificam daca userID sau cardID sunt valide pentru a trimite mai departe requestul
        return 1;
    return 2;
}

IResponse *DetailsCardHandler::parseResponse(json &json_object)
{
    IResponse* response=new GetDetailsCardResponse();
    response->fromJson(json_object);
    return response;
}




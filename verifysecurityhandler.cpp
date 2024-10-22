#include "verifysecurityhandler.h"

VerifySecurityHandler::VerifySecurityHandler(QObject *parent)
    : AHandler{parent}
{}

IResponse *VerifySecurityHandler::parseResponse(json &json_object)
{
    IResponse* response=ResponseFactory::createChangePasswordResponse();
    response->fromJson(json_object);
    return response;
}

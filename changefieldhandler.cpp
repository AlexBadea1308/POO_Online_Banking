#include "changefieldhandler.h"

ChangeFieldHandler::ChangeFieldHandler(QObject *parent)
    : AHandler{parent}
{}

IResponse*ChangeFieldHandler::parseResponse(json &json_object)
{
    IResponse* response=ResponseFactory::createChangeFieldResponse();
    response->fromJson(json_object);
    return response;
}

int ChangeFieldHandler::verifyConstraints(QString data, QString type)
{
    QRegularExpression regex;

    if (type == "Email") {
        regex = QRegularExpression("^\\b[A-Za-z0-9._]+@gmail\\.com\\b$");
    } else
        if (type == "Phone") {
        regex = QRegularExpression("^07\\d{8}$");
    }
    bool isValid = regex.match(data).hasMatch();

    // Returneaza codul erorii
    if (isValid==0)
    {
        if (type == "Email") {
            return 0; // Email invalid
        } else if (type == "Phone") {
            return 1; // Numar de telefon invalid
        }
    }
    else
        return 2;
}

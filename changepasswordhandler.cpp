#include "changepasswordhandler.h"

ChangePasswordHandler::ChangePasswordHandler(QObject *parent)
    : AHandler{parent}
{}

int ChangePasswordHandler::verifyConstraints(QString data, QString type)
{
    QRegularExpression regex;

    if (type == "Password")
        regex = QRegularExpression("^(?=.*[A-Z])(?=.*[0-9])(?=.*[!._])[A-Za-z][A-Za-z0-9!._]{7,15}$");

    bool isValid = regex.match(data).hasMatch();

    if (isValid==0)
    {
        return -1; // Parola invalida
    }
    else
        return 1;
}

IResponse *ChangePasswordHandler::parseResponse(json &json_object)
{
    IResponse* response=ResponseFactory::createChangePasswordResponse();
    response->fromJson(json_object);
    return response;
}

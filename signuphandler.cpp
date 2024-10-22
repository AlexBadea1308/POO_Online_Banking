#include "signuphandler.h"

SignUpHandler::SignUpHandler(QObject *parent)
    : AHandler{parent}{}

  int SignUpHandler::verifyConstraints(QString data, QString type)
    {
        QRegularExpression regex;

        if (type == "password") {
            regex = QRegularExpression("^(?=.*[A-Z])(?=.*[0-9])(?=.*[!._])[A-Za-z][A-Za-z0-9!._]{7,15}$");
        } else if (type == "email") {
            regex = QRegularExpression("^\\b[A-Za-z0-9._]+@gmail\\.com\\b$");
        } else if (type == "cnp") {
            regex = QRegularExpression("^[12567]\\d{12}$|^([12567]\\d{2})(0[1-9]|1[0-2])(0[1-9]|[1-2][0-9]|3[0-1])\\d{7}$");
        } else if (type == "phone") {
            regex = QRegularExpression("^07\\d{8}$");
        }

        //Verificare utilizand regex-ul corespunzator
        bool isValid = regex.match(data).hasMatch();

        // Returneaza codul erorii
        if (isValid==0)
        {
            if (type == "password") {
                return 0; // Parola invalida
            } else if (type == "email") {
                return 1; // Email invalid
            } else if (type == "cnp") {
                return 2; // CNP invalid
            } else if (type == "phone") {
                return 3; // Numar de telefon invalid
            }
        }
        else
            return 4;
    }


IResponse *SignUpHandler::parseResponse(json &json_object)
{
    IResponse* response=new SignUpResponse();
    response->fromJson(json_object);
    return response;
}

securityPhares SignUpHandler::createPhrases(QString frazaSecuritate, QString intrebareSecuritate, QString raspuns)
{
    securityPhares p;
    p.fraza_securitate=frazaSecuritate.toStdString();
    p.intrebare_securitate.first=intrebareSecuritate.toStdString();
    p.intrebare_securitate.second=raspuns.toStdString();
    return p;
}

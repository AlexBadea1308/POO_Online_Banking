#include "factoryhandler.h"

LoginHandler *FactoryHandler::createLoginHandler()
{
    return new LoginHandler();
}

SignUpHandler *FactoryHandler::createSignUpHandler()
{
    return new SignUpHandler();
}

Transfer_Handler *FactoryHandler::createTransferHandler()
{
    return  new Transfer_Handler();
}

RetragereHandler *FactoryHandler::createRetragereHandler()
{
    return new RetragereHandler();
}

DepunereHandler *FactoryHandler::createDepunereHandler()
{
    return new DepunereHandler();
}

Plata_POS_Handler *FactoryHandler::createPlatPosHandler()
{
    return new Plata_POS_Handler();
}

DetailsCardHandler *FactoryHandler::createDetailsCardHandler()
{
    return new DetailsCardHandler();
}

GestionareCardHandler *FactoryHandler::createGestionareCardHandler()
{
    return new GestionareCardHandler();
}

ChangeFieldHandler *FactoryHandler::createChangeFieldHandler()
{
    return new ChangeFieldHandler();
}

VerifySecurityHandler *FactoryHandler::createVerifySecurityHandler()
{
    return new VerifySecurityHandler();
}

ChangePasswordHandler *FactoryHandler::createPasswordHandler()
{
    return new ChangePasswordHandler();
}

#ifndef FACTORYHANDLER_H
#define FACTORYHANDLER_H
#include"loginhandler.h"
#include "signuphandler.h"
#include"depunerehandler.h"
#include"retragerehandler.h"
#include "transfer_handler.h"
#include"plata_pos_handler.h"
#include "detailscardhandler.h"
#include "gestionarecardhandler.h"
#include "changefieldhandler.h"
#include "verifysecurityhandler.h"
#include "changepasswordhandler.h"

class FactoryHandler
{
public:
    static LoginHandler* createLoginHandler();
    static SignUpHandler* createSignUpHandler();
    static Transfer_Handler* createTransferHandler();
    static RetragereHandler* createRetragereHandler();
    static DepunereHandler* createDepunereHandler();
    static Plata_POS_Handler* createPlatPosHandler();
    static DetailsCardHandler* createDetailsCardHandler();
    static GestionareCardHandler* createGestionareCardHandler();
    static ChangeFieldHandler* createChangeFieldHandler();
    static VerifySecurityHandler* createVerifySecurityHandler();
    static ChangePasswordHandler* createPasswordHandler();
};

#endif // FACTORYHANDLER_H

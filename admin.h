#ifndef ADMIN_H
#define ADMIN_H
#include<QString>
#include "apersoana.h"

class Admin:public APersoana
{
private:
    int m_cod_admin;

public:
    Admin();
    Admin(QString username, QString password, int cod_admin);
    void setCodAdmin(int codAdmin)override;
};

#endif // ADMIN_H



#include "admin.h"

Admin::Admin() {}

Admin:: Admin(QString username, QString password, int cod_admin):APersoana(username,password)
{
    m_cod_admin=cod_admin;
}


void Admin::setCodAdmin(int codAdmin)
{
    m_cod_admin = codAdmin;
}

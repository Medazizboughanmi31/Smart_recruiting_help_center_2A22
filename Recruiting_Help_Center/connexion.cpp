#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("smart_recruiting_help_center");
db.setUserName("rayen");
db.setPassword("rayen");
if (db.open())
test=true;

    return  test;
}




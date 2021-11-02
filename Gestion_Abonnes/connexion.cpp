#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Gestion_Abonnes");
db.setUserName("system");
db.setPassword("f6m7n1a1");
if (db.open())
test=true;

    return  test;
}




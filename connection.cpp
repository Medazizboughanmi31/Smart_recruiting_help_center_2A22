#include "connection.h"
#include "QSqlDatabase"

connection::connection()
{

}
bool connection::createconnect(){

    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet");
    db.setUserName("rim");
    db.setPassword("rim");

    if(db.open())
        test=true;
    return test;


}

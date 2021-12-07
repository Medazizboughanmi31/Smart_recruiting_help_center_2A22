#include "mail.h"

#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

mail::mail()
{

  des="";
description="";
ob="";



}
mail::mail(QString a,QString b,QString d)
{

    des=a;
    ob=b;
    description=d;

}
bool mail::envoyer()
{

    QSqlQuery query;
     query.prepare("INSERT INTO CENTRE_MAIL(DESTINATAIRE,OBJET,DESCRIPTION) "
                   "VALUES (:des,:objet,:description)");

      query.bindValue(":des", des);//inserer le nom dans bd
      query.bindValue(":objet", ob);
      query.bindValue(":description", description);

     return query.exec();








}

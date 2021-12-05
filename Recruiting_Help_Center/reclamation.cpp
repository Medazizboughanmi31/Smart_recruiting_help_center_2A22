#include "reclamation.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
reclamation::reclamation()
{
centre_des="";
rec_des="";
}
reclamation::reclamation(QString a,QString b)
  {
      centre_des=a;
      rec_des=b;



  }
bool reclamation::envoyer_rec()
{

    QSqlQuery query;
     query.prepare("INSERT INTO RECLAMATION_REC(CENTRE_DES,RECLAMATION_DESC) "
                   "VALUES (:centre,:reclamation)");

      query.bindValue(":centre", centre_des);//inserer le nom dans bd
      query.bindValue(":reclamation", rec_des);

     return query.exec();







}






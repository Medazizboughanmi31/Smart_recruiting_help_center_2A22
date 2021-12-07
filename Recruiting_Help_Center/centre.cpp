#include "centre.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>





centre::centre(){//initialisation du conctructeur par defaut

nom="";
email="";
adresse="";
tel=0;
nbr=0;
ville="";

}
centre::centre(QString n,int t,QString e,QString a,int nb,QString v)//initialisation du conctructeur parametriques
{
tel= t;
    nom=n;
    email=e;
       adresse=a;
    nbr=nb;
ville=v;
}

bool centre::ajouter()
{



QString nbr_string=QString::number(nbr);
QString ID=QString::number(tel);
QSqlQuery query;
 query.prepare("INSERT INTO CENTRE (NOM_C,EMAIL_C,TEL_C,ADRESSE_C,NOMBRE_DES_RECRUTEUR,VILLE) "
               "VALUES (:nom,:email,:tel,:adresse,:nbr,:ville)");

  query.bindValue(":nom", nom);//inserer le nom dans bd
  query.bindValue(":email", email);
  query.bindValue(":adresse", adresse);
  query.bindValue(":nbr",nbr_string);
  query.bindValue(":tel",ID);
 query.bindValue(":ville",ville);
  return query.exec();

}

bool centre::Supprimer(QString nom)
{

    QSqlQuery query;
    query.prepare("Delete from CENTRE where NOM_C=:nom");//preparer la requette qui effacer les donnees a partir du nom
    query.bindValue(":nom", nom);//inserer le nom dans bd

    return query.exec();

}


QSqlQueryModel* centre::afficher()
{
QSqlQuery query;//requette sql qui va excuter a  partir du qt ;
    QSqlQueryModel* model= new QSqlQueryModel();

    query.prepare("SELECT * FROM CENTRE ");//preparer la model qui va selecter une table et l'afficher;
          query.exec();//executer
          model->setQuery(query);


   return model;

}
bool centre::update(QString nom)
{
QString id=QString::number(nbr);//transformation du int a qstring   ;
QString ids=QString::number(tel);
    QSqlQuery query;
       query.prepare(QString("update CENTRE set EMAIL_C=:email,TEL_C=:tel,ADRESSE_C=:adresse,NOMBRE_DES_RECRUTEUR=:nbr,VILLE=:ville where NOM_C=:nom"));
       query.bindValue(":tel", tel);
        query.bindValue(":nom", nom);
        query.bindValue(":email", email);
        query.bindValue(":adresse", adresse);
       query.bindValue(":nbr",id);//injection une valeur dans la requette de bd
       query.bindValue(":ville",ville);

     return  query.exec();
}
QSqlQueryModel* centre::nb_rec() //statistique
{
    QSqlQuery query;//requette sql qui va excuter a  partir du qt ;
        QSqlQueryModel* model= new QSqlQueryModel();

        query.prepare("SELECT NOM_C,NOMBRE_DES_RECRUTEUR FROM CENTRE order by NOMBRE_DES_RECRUTEUR DESC ");//preparer la model qui va selecter une table et l'afficher;
              query.exec();//executer
              model->setQuery(query);


       return model;


}

QSqlQueryModel* centre::recherche(QString nom)
{
    QSqlQuery query;//requette sql qui va excuter a  partir du qt ;
        QSqlQueryModel* model= new QSqlQueryModel(); // CREER UN TAB

        query.prepare("SELECT * FROM CENTRE Where NOM_C=:nom ");//preparer la model qui va selecter une table et l'afficher;
         query.bindValue(":nom", nom);
        query.exec();//executer
              model->setQuery(query);
return model;








}
QSqlQueryModel* centre::recherche_ville(QString ville)
{
    QSqlQuery query;//requette sql qui va excuter a  partir du qt ;
        QSqlQueryModel* model= new QSqlQueryModel(); // CREER UN TAB

        query.prepare("SELECT * FROM CENTRE Where VILLE=:ville ");//preparer la model qui va selecter une table et l'afficher;
         query.bindValue(":ville", ville);
        query.exec();//executer
              model->setQuery(query);
return model;
  }

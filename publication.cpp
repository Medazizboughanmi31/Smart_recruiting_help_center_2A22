#include "publication.h"
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QDebug>
#include <connection.h>
#include <QObject>
#include <QMessageBox>
#include <QDateTime>
#include <QSystemTrayIcon>
publication::publication()
{
id_pub=0; titre_pub=" " ; description_pub=" " ; type_pub=" ";CIN_A=0; date_pub=" ";tag_s=" ";;
}


publication::publication(QString titre_pub,int CIN_A,QString date_pub,int id_pub,QString type_pub,QString tag_s,QString description_pub)
{   this->titre_pub=titre_pub;
    this->CIN_A=CIN_A;
    this->date_pub=date_pub;
    this->id_pub=id_pub;
    this->type_pub=type_pub;
    this->tag_s=tag_s;
    this->description_pub=description_pub;


}
QString publication:: gettitre_pub(){return titre_pub;}
int publication::getid_pub(){return id_pub;}

QString publication:: getdescription_pub(){return description_pub;}
QString publication:: gettype_pub(){return type_pub;}
QString publication:: getdate_pub(){return date_pub;}
QString publication::gettag_s(){return tag_s;}


void publication::setid_pub(int id_pub) {this->id_pub=id_pub;}
void publication::settitre_pub(QString titre_pub){this->titre_pub=titre_pub;}
void publication::setdescription_pub(QString description_pub){this->description_pub=description_pub;}
void publication::settype_pub(QString type_pub){this->type_pub=type_pub;}
void publication::setdate_pub(QString date_pub){this->date_pub=date_pub;}


bool publication::ajouter()


{


    Connection c ;
    c.createconnect();

    QSqlQuery query;

   QString id_string=QString::number(id_pub);


    query.prepare("INSERT INTO publication ( titre_pub,CIN_A,date_pub,id_pub,type_pub,tag_s,description_pub) "
                 "VALUES (:titre_pub, :CIN_A, :date_pub,:id_pub,:type_pub,:tag_s,:description_pub)");


    query.bindValue(":titre_pub", titre_pub);
    query.bindValue(":CIN_A", CIN_A);
    query.bindValue(":date_pub", date_pub);
    query.bindValue(":id_pub", id_string);
    query.bindValue(":type_pub", type_pub);
          query.bindValue(":tag_s", tag_s);
     query.bindValue(":description_pub", description_pub);




   return query.exec();


}
bool publication::supprimer(int  )
{

    QSqlQuery query;


    query.prepare("Delete from publication where id_pub=:id_pub");
    query.bindValue(":id_pub", getid_pub());
    return query.exec();


}
QSqlQueryModel*publication::afficher()
{

    QSqlQueryModel*model =new QSqlQueryModel();


         model->setQuery("SELECT * FROM publication");





    return model;

}
bool publication::modifier(int id_pub)
{
    QSqlQuery query;

    query.prepare("Update  publication set titre_pub= :titre_pub,type_pub= :type_pub,description_pub= :description_pub,CIN_A= :CIN_A,date_pub= :date_pub,tag_s=:tag_s where id_pub=:id_pub");

   query.bindValue(":titre_pub", titre_pub);
    query.bindValue(":CIN_A", CIN_A);
    query.bindValue(":date_pub", date_pub);
    query.bindValue(":id_pub", id_pub);
    query.bindValue(":type_pub", type_pub);
      query.bindValue(":tag_s", tag_s);
    query.bindValue(":description_pub", description_pub);


    return query.exec();

}

 QSqlQueryModel*publication::recherche(QString type)
 {
     QSqlQueryModel*model1 =new QSqlQueryModel();
   model1->setQuery("SELECT * FROM  publication where type_pub like '%"+ type.toUpper() +"%'or type_pub like '%"+ type.toLower()+"%' ");



     return model1;

 }
 QStringList publication ::tag_societe()
 {
     QSqlQuery query;
     query.prepare("Select nom_s from societe;");
      query.exec();
         QStringList list;
         while (query.next()) {
             list << query.value(0).toString();
         }
         return list;
 }


 QSqlQueryModel * publication::trierdate()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM publication ORDER BY DATE_PUB");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PUB"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TITRE_PUB"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESCRIPTION_PUB"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_pub"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("CIN_A"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_PUB"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("TAG_S"));
     return model;
 }





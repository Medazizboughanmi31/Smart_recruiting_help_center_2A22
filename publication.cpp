#include "publication.h"
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QDebug>
#include <connection.h>
#include <QObject>
publication::publication()
{
id=0; titre=" " ; description=" " ; type=" ";;
}

publication::publication(int id,QString titre,QString description,QString type)
{
    this->id=id; this->titre=titre; this->description=description;this->type=type;
}
int publication::getid(){return id;}
QString publication:: gettitre(){return titre;}
QString publication:: getdescription(){return description;}
QString publication:: gettype(){return type;}

void publication::setid(int id) {this->id=id;}
void publication::settitre(QString titre){this->titre=titre;}
void publication::setdescription(QString description){this->description=description;}
void publication::settype(QString type){this->type=type;}


bool publication::ajouter()


{
    bool test=false;

    Connection c ;
    c.createconnect();
    QSqlQuery query;

   // QString id_string=QString::number(id);
    query.prepare("INSERT INTO publi (id, titre, type,description) "
                  "VALUES (:id, :titre, :type,:description)");
    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":type", type);
     query.bindValue(":description", description);

    query.exec();

    return test ;
}
bool publication::supprimer(int id )
{

    QSqlQuery query;

    query.prepare("Delete from publi where id=:id");
    query.bindValue(":id", id);
    return query.exec();


}
QSqlQueryModel*publication::afficher()
{

    QSqlQueryModel*model =new QSqlQueryModel();


         model->setQuery("SELECT * FROM publi");
         model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));




    return model;

}
bool publication::modifier(int id )
{
    QSqlQuery query;

    query.prepare("Update  publi set titre= :titre,type= :type,description= :description where id=:id");


    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":type", type);
     query.bindValue(":description", description);

    return query.exec();

}


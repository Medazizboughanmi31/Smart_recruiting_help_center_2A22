#include "entretien.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QFileDialog>
#include <QTextDocument>
#include <QObject>
#include<QDate>
entretien::entretien()
{

   CIN_A=0;
   ID_offre=0;
   NOM_C="";
   Heures="";
   Type="";

}

entretien::entretien(int CIN_A,int ID_offre,QString NOM_C,QDate DateE,QString Heures,QString Type)
{
    this->CIN_A=CIN_A;
    this->ID_offre=ID_offre;
    this->NOM_C=NOM_C;
    this->DateE=DateE;
    this->Heures=Heures;
    this->Type=Type;
  //  this->Num=Num;

}
int entretien::getCIN_A(){return CIN_A;}
int entretien::getID_offre(){return ID_offre;}
QString entretien::getNOM_C(){return NOM_C;}
//int entretien::getNum(){return Num;}
QDate entretien::getDateE(){return DateE;}
QString entretien::getHeures(){return Heures;}
QString entretien::getType(){return Type;}
void entretien::setCIN_A(int a){this->CIN_A=a;}
void entretien::setID_offre(int b){this->ID_offre=b;}
void entretien::setNOM_C(QString c){this->NOM_C=c;}
//void entretien::setNum(int d){this->Num=d;}
void entretien::setDateE(QDate e){this->DateE=e;}
void entretien::setHeures(QString f){this->Heures=f;}
void entretien::setType(QString j){this->Type=j;}




QStringList entretien::lister(){
    QSqlQuery query;
query.prepare("Select NOM_C from centre;");


 query.exec();
    QStringList list;
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}
QStringList entretien::lister2(){
    QSqlQuery query;
query.prepare("Select ID_RDV from entretien;");


 query.exec();
    QStringList list;
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}
bool entretien::Ajouter()
{
    QSqlQuery query;

  QString cina= QString ::number(CIN_A);
  QString idoffre= QString ::number(ID_offre);
    query.prepare("insert into ENTRETIEN(ID_RDV,DATE_RDV,HEURE_RDV,TYPE_RDV,CIN_AB,ID_O,NOM_C) values(ENTRETIEN_SEQ.nextval, :DateE , :Heures, :Type, :CIN_A, :ID_offre, :NOM_C)");
    query.bindValue(":CIN_A",cina);
   query.bindValue(":ID_offre",idoffre);
    query.bindValue(":NOM_C",NOM_C);
      query.bindValue(":DateE",DateE);
      query.bindValue(":Heures",Heures);

     query.bindValue(":Type",Type);

 return query.exec();

}
QSqlQueryModel * entretien::Afficher( )
{
  QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select entretien.ID_RDV,entretien.ID_O ,entretien.DATE_RDV,entretien.HEURE_RDV,entretien.TYPE_RDV,entretien.NOM_C, societe.NOM_S ,abonne.Nom_A ,abonne.PRENOM_A ,abonne.EMAIL_A from entretien ,offre,societe,abonne where  entretien.ID_O=OFFRE.ID and OFFRE.ID_ENTREPRISE=SOCIETE.ID_S and entretien.CIN_AB=abonne.CIN ; ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("offre"));
       model->setHeaderData(2, Qt::Horizontal,QObject:: tr("date"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure"));
       model->setHeaderData(4, Qt::Horizontal,QObject:: tr("type"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("centre"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Societe"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOM"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("EMAIL"));
return model;

}
QSqlQueryModel * entretien::rechercher(QString id)

{

QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select entretien.ID_RDV,entretien.ID_O ,entretien.DATE_RDV,entretien.HEURE_RDV,entretien.TYPE_RDV,entretien.NOM_C, societe.NOM_S ,abonne.Nom_A ,abonne.PRENOM_A ,abonne.EMAIL_A from entretien ,offre,societe,abonne where  entretien.ID_O=OFFRE.ID and OFFRE.ID_ENTREPRISE=SOCIETE.ID_S and entretien.CIN_AB=abonne.CIN and entretien.ID_O  like '"+id+"%'; ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("offre"));
model->setHeaderData(2, Qt::Horizontal,QObject:: tr("date"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure"));
model->setHeaderData(4, Qt::Horizontal,QObject:: tr("type"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("centre"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Societe"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("EMAIL"));
return model;
}
QSqlQueryModel * entretien::rechercher_A(QString id)

{

QSqlQueryModel * model= new QSqlQueryModel();
QSqlQueryModel * model2= new QSqlQueryModel();
model->setQuery("select entretien.ID_RDV,entretien.ID_O ,entretien.DATE_RDV,entretien.HEURE_RDV,entretien.TYPE_RDV,entretien.NOM_C, societe.NOM_S ,abonne.Nom_A ,abonne.PRENOM_A ,abonne.EMAIL_A from entretien ,offre,societe,abonne where  entretien.ID_O=OFFRE.ID and OFFRE.ID_ENTREPRISE=SOCIETE.ID_S and entretien.CIN_AB=abonne.CIN and entretien.ID_RDV like '"+id+"%'; ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("offre"));
model->setHeaderData(2, Qt::Horizontal,QObject:: tr("date"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure"));
model->setHeaderData(4, Qt::Horizontal,QObject:: tr("type"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("centre"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Societe"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("EMAIL"));
return model;
}

bool entretien::Verfi(int id)
{
     QSqlQuery query;
     QString id_string=QString::number(id);
     query.prepare("select ID_RDV from entretien  where  ID_RDV= :id ");


}
bool entretien::Supprimer(int id)
 {   QSqlQuery query;
     QString id_string=QString::number(id);
     query.prepare("Delete from entretien where ID_RDV= :id " );
     query.bindValue(":id",id_string);

     return query.exec();

 }

bool entretien::modifier(int id,QString Type ,QDate date,QString temps)
 {
   QSqlQuery query;
   QString id_string=QString::number(id);

query.prepare("UPDATE entretien SET  TYPE_RDV= :Type , DATE_RDV= :date , HEURE_RDV= :temps  WHERE ID_RDV= :id ");
query.bindValue(":id",id);
query.bindValue(":Type",Type);
query.bindValue(":date",date);
query.bindValue(":temps",temps);

return query.exec();
 }

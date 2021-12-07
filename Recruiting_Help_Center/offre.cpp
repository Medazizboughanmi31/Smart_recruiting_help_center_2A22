#include "offre.h"
#include<QDebug>
#include<QObject>
offre::offre(){}

offre::offre(int i){id=i;}

offre::offre(int idv,QDate datepubv,QString domainev="",QString competancev=""
             ,QString niveauv="",int experiencev=0,int NHeuresv=0,char sexev='o',int age_maxv=0
        ,int salairev=0,int NJcongev=0,char etatv='o'){
    id=idv;
    datepub= datepubv ;
    domaine=domainev;
    competance=competancev ;
    niveau=niveauv ;
experience=experiencev;
NHeures=NHeuresv;
sexe=sexev;
age_max=age_maxv;
salaire=salairev;
NJconge=NJcongev;
etat=etatv;
}
int offre::get_id(){
    return id;
}
int offre::get_experience(){
    return experience;
}
int offre::get_NHeures(){
    return NHeures;
}

int offre::get_age_max(){
    return age_max;
}
int offre::get_salaire(){
    return salaire;
}
int offre::get_NJconge(){
    return NJconge;
}

QDate offre::get_datepub(){
    return datepub;
}
char offre::get_sexe(){
    return sexe;
}
char offre::get_etat(){
    return etat;
}

QString offre::get_domaine(){
    return domaine;
}
QString offre::get_competance(){
    return competance;
}
QString offre::get_niveau(){
    return niveau;
}

void offre::set_id(int x){
    id=x;
}
void offre::set_experience(int x){
    experience=x;
}
void offre::set_NHeures(int x){
    NHeures=x;
}

void offre::set_age_max(int x){
    age_max=x;
}
void offre::set_salaire(int x){
    salaire=x;
}
void offre::set_NJconge(int x){
    NJconge=x;
}

void offre::set_datepub(QDate x){
    datepub=x;
}
void offre::set_sexe(char x){
    sexe=x;
}
void offre::set_etat(char x){
    etat=x;
}

void offre::set_domaine(QString x){
    domaine=x;
}
void offre::set_competance(QString x){
    competance=x;
}
void offre::set_niveau(QString x){
    niveau=x;
}

bool offre::ajouter(QString s){
  QString forma ="dd/MM/yyyy";
QSqlQuery query,q;
QString resc =QString::number(experience);
QString resh =QString::number(NHeures);
QString resa =QString::number(age_max);
QString ress =QString::number(salaire);
QString resnj =QString::number(NJconge);
query.prepare("insert into offre(DATEPUB,DOMAINE,COMPETANCE,NIVEAU,EXPERIENCE,NHEURES,SEXE,AGE_MAX,SALAIRE,NJCONGE,ETAT,id_entreprise) values(TO_DATE(:datepub, 'DD/MM/YYYY'), :domaine, :competance, :niveau, :experience, :NHeures, :sexe, :age_max, :salaire, :NJconge, :etat,'"+s+"')");
//
//
//query.prepare("insert into offre values(:id, :salaire, :NJconge, :etat)");

//query.bindValue(":id",res);
query.bindValue(":datepub",datepub.toString(forma));//
query.bindValue(":domaine",domaine);

query.bindValue(":competance",competance);
query.bindValue(":niveau",niveau);
query.bindValue(":experience",resc);

query.bindValue(":NHeures",resh);
QString ch;
ch[0]=sexe;
query.bindValue(":sexe",ch);
query.bindValue(":age_max",resa);

query.bindValue(":salaire",ress);
query.bindValue(":NJconge",resnj);
ch[0]=etat;
query.bindValue(":etat",ch);

return query.exec();
}

QSqlQueryModel * offre::afficher(QString ch,bool check,QString c){

   QSqlQueryModel *model = new QSqlQueryModel();
if(check){
    model->setQuery("SELECT * FROM offre WHERE "+c+" LIKE '"+ch+"%'AND ETAT='o' ORDER BY ID;");
}else{
    model->setQuery("SELECT * FROM offre WHERE "+c+" LIKE '"+ch+"%'ORDER BY ID;");
}
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date de expiration"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Domaine"));

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("competance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("niveau"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("experience par annnée"));

    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Nombre des heures par jour"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("age maximale"));

    model->setHeaderData(9,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("nombre des jours de conge"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("sociéte"));
    model->setHeaderData(12,Qt::Horizontal,QObject::tr("Etat"));

    return model;
}
bool offre::supprimer(int id)
{    QSqlQuery query;

  QString   rec=QString::number(id);
     query.prepare("DELETE FROM offre WHERE ID =:id ;");
query.bindValue(0,id);


    return  query.exec();
}
QStringList offre::recherche_id(){
    QSqlQuery query;
query.prepare("Select ID from offre;");


 query.exec();
    QStringList list;
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}
bool offre::modifier(){
   QSqlQuery query;
   // :domaine, :competance, :niveau, :experience, :NHeures, :sexe, :age_max, :salaire, :NJconge, :etat
 query.prepare(" UPDATE offre SET DOMAINE = :domaine, COMPETANCE = :competance, NIVEAU = '"+niveau+"', EXPERIENCE = :experience, NHEURES = :NHeures, SEXE = :sexe, AGE_MAX = :age_max, SALAIRE = :salaire, NJCONGE = :NJconge WHERE ID= :id;");
query.bindValue(":domaine",domaine);
query.bindValue(":competance",competance);
QString ch;
ch[0]=sexe;
QString res =QString::number(id);
QString resc =QString::number(experience);
QString resh =QString::number(NHeures);
QString resa =QString::number(age_max);
QString ress =QString::number(salaire);
QString resnj =QString::number(NJconge);
query.bindValue(":experience",resc);

query.bindValue(":NHeures",resh);
query.bindValue(":sexe",ch);
query.bindValue(":age_max",resa);

query.bindValue(":salaire",ress);
query.bindValue(":NJconge",resnj);

query.bindValue(":id",res);

return query.exec();
}

bool offre::expirer(int id){
    QSqlQuery query,query2;
query.prepare("Select ETAT from offre WHERE ID= :id;");

QString res =QString::number(id);
query.bindValue(":id",res);

 QString ett;
 query.exec();
   while(query.next())
    ett=query.value(0).toString();

 query2.prepare(" UPDATE offre SET ETAT= :etat WHERE ID= :id;");

query2.bindValue(":id",res);
 if( ett=="o")
 {    query2.bindValue(":etat","f");
query2.exec();
return false;
}
 else{
      query2.bindValue(":etat","o");
 query2.exec();
 return true;
 }

}
////exemple@autreexemple.exemple
QStringList offre::find_societe(){
    QSqlQuery query;
query.prepare("Select nom_s from societe;");


 query.exec();
    QStringList list;
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}

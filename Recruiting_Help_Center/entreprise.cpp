#include "entreprise.h"

entreprise::entreprise()
{
id= "";
nom="";
adresse="";
mail="";
tel="";
fax="";
}
entreprise::entreprise(QString i, QString n,QString a, QString m ,QString t,QString f)
{
    id=i;
    nom=n;
    adresse=a;
    mail=m;
    tel=t;
    fax=f;
}
bool entreprise::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO societe (id,nom, adresse, mail,tel,fax)"
                  "VALUES(:id, :nom, :adresse, :mail, :tel, :fax)");
    //prepare our data base for writing

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":mail",mail);
    query.bindValue(":tel",tel);
    query.bindValue(":fax",fax);

//insertation du champ au tableau du base de donness
    //sq injection has security isssues,
    return query.exec();
}
QSqlQueryModel *entreprise::afficher(){
    //query model takes care of affichage

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from societe");
    //set query does
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));      //set header data
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("fax"));

    return model;
}
bool entreprise::supprimer(QString id){

    QSqlQuery query;
    query.prepare("delete from societe where id = :id");
    query.bindValue(":id",id);
    return query.exec();
}


bool entreprise::modifier(QString id){
    QSqlQuery query;
    query.prepare("update societe set  nom= :nom ,adresse= :adresse ,mail= :mail ,tel= :tel ,fax= :fax where id = :id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":adesse",adresse);
    query.bindValue(":mail",mail);
    query.bindValue(":tel",tel);
    query.bindValue(":fax",fax);
    return query.exec();


}
QSqlQueryModel *entreprise::trier() //ml A-Z lieu
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM documentcin order by nomc ASC");
           q->exec();
           model->setQuery(*q);
           return model;
     }
QSqlQueryModel *entreprise::trierdec() //ml Z-A
{

           QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * from societe order by nomc DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;
}
QSqlQueryModel *entreprise::recherche(QString id)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from societe where id LIKE '"+id+"%' or nom LIKE '"+id+"%' or adresse LIKE '"+id+"%'");


     model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal, QObject::tr("adresse"));

 return model;
}

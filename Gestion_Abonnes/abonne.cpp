#include "abonne.h"

Abonne::Abonne()
{
   CIN=0 ;
   TEL=0 ;
   AGE=0 ;
   NOM="" ;
   PRENOM="" ;
   EMAIL="" ;
   SEXE="" ;
   ADRESSE="" ;
   NIVEAU_ETUDE="" ;


}
Abonne::Abonne(int CIN,QString NOM,QString PRENOM,QString EMAIL,int AGE,QString SEXE,QString ADRESSE,QString NIVEAU_ETUDE,int TEL)
{
   this->CIN=CIN ;
   this->TEL=TEL ;
   this->AGE=AGE ;
   this->NOM=NOM ;
   this->PRENOM=PRENOM ;
   this->EMAIL=EMAIL ;
   this->SEXE=SEXE ;
   this->ADRESSE=ADRESSE ;
   this->NIVEAU_ETUDE=NIVEAU_ETUDE ;

}

void Abonne::setCIN(int CIN) {this->CIN=CIN ;}
void Abonne::setTEL(int TEL) {this->TEL=TEL ;}
void Abonne::setAGE(int AGE) {this->AGE=AGE ;}
void Abonne::setNOM(QString NOM) {this->NOM=NOM ;}
void Abonne::setPRENOM(QString PRENOM) {this->PRENOM=PRENOM ;}
void Abonne::setEMAIL(QString EMAIL) {this->EMAIL=EMAIL ;}
void Abonne::setSEXE(QString SEXE) {this->SEXE=SEXE ;}
void Abonne::setADRESSE(QString ADRESSE) {this->ADRESSE=ADRESSE ;}
void Abonne::setNIVEAU_ETUDE(QString NIVEAU_ETUDE) {this->NIVEAU_ETUDE=NIVEAU_ETUDE;}

int Abonne::getCIN(){return CIN ;}
int Abonne::getTEL(){return TEL ;}
int Abonne::getAGE(){return AGE ;}
QString Abonne::getNOM(){return NOM ;}
QString Abonne::getPRENOM(){return PRENOM ;}
QString Abonne::getEMAIL(){return EMAIL ;}
QString Abonne::getSEXE(){return SEXE ;}
QString Abonne::getADRESSE(){return ADRESSE ;}
QString Abonne::getNIVEAU_ETUDE(){return NIVEAU_ETUDE ;}

bool Abonne::Ajouter()
{

    QSqlQuery query;
    QString CIN_string=QString::number(CIN) ;
    QString TEL_string=QString::number(TEL) ;
    QString AGE_string=QString::number(AGE) ;
    query.prepare("INSERT INTO TABLE_ABONNES (CIN,NOM,PRENOM,EMAIL,AGE,SEXE,ADRESSE,NIVEAU_ETUDE,TEL) "
                  "VALUES (:CIN,:NOM,:PRENOM,:EMAIL,:AGE,:SEXE,:ADRESSE,:NIVEAU_ETUDE,:TEL)"); // ajouter les attributs au table apres l'insertion .
    query.bindValue(0, CIN_string);
    query.bindValue(8, TEL_string);
    query.bindValue(5, AGE_string);
    query.bindValue(1, NOM);
    query.bindValue(2, PRENOM);
    query.bindValue(3, EMAIL);
    query.bindValue(4, SEXE);
    query.bindValue(6, ADRESSE);
    query.bindValue(7, NIVEAU_ETUDE);
    return query.exec();


}

bool Abonne::Supprimer(int)
{
    QSqlQuery query;
    query.prepare(" Delete from TABLE_ABONNES where CIN=:CIN "); // supprimer les attributs du table d'apres Cin donneé .
    query.bindValue(0, CIN);
    return query.exec();
}

QSqlQueryModel * Abonne::Afficher()
{
         QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM TABLE_ABONNES"); //afficher tout les attributs du table
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN")); //donner le nom du colone a Afficher
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("NIVEAU D'ETUDE"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));


         return model ;
}



#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class entreprise
{
public:
    entreprise();
    entreprise(QString ,QString,QString,QString,QString,QString);
    QString getid(){return id;}
    QString getnom(){return nom;}
    QString getadresse(){return adresse;}
    QString getmail(){return mail;}
    QString gettel(){return tel;}
    QString getfax(){return fax;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * trierdec();
    QSqlQueryModel* recherche(QString);


private:

      QString  id,nom,adresse,mail,tel,fax ;
};


#endif // ENTREPRISE_H

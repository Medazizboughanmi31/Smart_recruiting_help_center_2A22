#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <QString>

#include <QSqlQueryModel>

class publication
{
public:
    publication();
    publication(QString,int,QString,int,QString,QString,QString);
    int getid_pub();
    QString gettitre_pub();
    QString getdescription_pub();
    QString gettype_pub();
     QString getdate_pub();
     QString gettag_s();

    void setid_pub(int);
    void settitre_pub(QString);
    void setdescription_pub(QString);
    void settype_pub(QString);
    void setdate_pub(QString);
    void settag_s(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
   QSqlQueryModel* recherche(QString);
   QStringList tag_societe();
    QSqlQueryModel * trierdate();




private:
    int id_pub,CIN_A;
    QString titre_pub,description_pub,type_pub,date_pub,tag_s;


};

#endif // PUBLICATION_H

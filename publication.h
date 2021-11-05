#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <QString>

#include <QSqlQueryModel>

class publication
{
public:
    publication();
    publication(int,QString,QString,QString);
    int getid();
    QString gettitre();
    QString getdescription();
    QString gettype();

    void setid(int);
    void settitre(QString);
    void setdescription(QString);
    void settype(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);

private:
    int id;
    QString titre,description,type;


};

#endif // PUBLICATION_H

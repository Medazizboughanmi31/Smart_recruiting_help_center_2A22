#ifndef CENTRE_H
#define CENTRE_H

#include<QString>
#include<QSqlQueryModel>

class centre
{
public:
    centre();
centre(QString n,int t,QString e,QString a,int nb,QString v);

void set_id(int);
void set_nom(QString );
void set_email(QString );
void set_adresse(QString );
void set_nbr();
int get_id();
QString get_nom();
QString get_email();
QString get_adresse();
int get_nbr();

bool ajouter();
QSqlQueryModel* afficher();
bool Supprimer(QString nom);
bool update(QString nom);
QSqlQueryModel* nb_rec();
QSqlQueryModel* recherche(QString nom);
QSqlQueryModel* recherche_ville(QString ville);





private :

    QString nom;
    QString email;
    QString adresse;
    int nbr;
    int tel;
QString ville;
};


#endif // CENTRE_H

#ifndef OFFRE_H
#define OFFRE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class offre
{
protected:
    int id,experience,NHeures,age_max,salaire,NJconge;
    QDate datepub;
    char sexe,etat;
   QString domaine,competance,niveau;


public:
    offre();
    offre(int);
    offre(int,QDate,QString,QString,QString,int,int,char,int,int,int,char);

    int get_id();
    int get_experience();
    int get_NHeures();

    int get_age_max();
    int get_salaire();
    int get_NJconge();

    QDate get_datepub();
    char get_sexe();
    char get_etat();

    QString get_domaine();
    QString get_competance();
    QString get_niveau();

    void set_id(int);
    void set_experience(int);
    void set_NHeures(int);

    void set_age_max(int);
    void set_salaire(int);
    void set_NJconge(int);

    void set_datepub(QDate);
    void set_sexe(char);
    void set_etat(char);

    void set_domaine(QString);
    void set_competance(QString);
    void set_niveau(QString);

    bool ajouter(QString);
    QSqlQueryModel *afficher(QString,bool,QString);
    bool supprimer(int);
    bool expirer(int);
    bool modifier();
    QStringList find_societe();
    QSqlQueryModel *serch_row();
    QStringList recherche_id();
};

#endif // OFFRE_H

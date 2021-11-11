#ifndef ENTRETIEN_H
#define ENTRETIEN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QStringList>
class entretien
{
private :
     QString NOM_C;
     int CIN_A;
     int ID_offre;
     QDate  DateE;
     QString  Heures;
     QString Type;
      //int Num;

public:

    entretien();
    entretien(int,int,QString,QDate,QString,QString);
    int getCIN_A();
    int getID_offre();
    QString getNOM_C();
    //int getNum();
    QDate getDateE();
    QString getHeures();
    QString getType();
    void setCIN_A(int );
    void setID_offre(int);
    void setNOM_C(QString );
    //void setNum(int);
    void setDateE(QDate);
    void setHeures(QString );
    void setType(QString);
    bool Ajouter();
 QStringList lister();
QSqlQueryModel * Afficher( );
QSqlQueryModel * rechercher(QString);
QSqlQueryModel * rechercher_A(QString);
bool Supprimer(int);
bool Verfi(int );
bool modifier(int,QString,QDate,QString);
QStringList lister2();

};

#endif // ENTRETIEN_H

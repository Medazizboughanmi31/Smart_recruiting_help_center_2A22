#ifndef ENTRETIEN_H
#define ENTRETIEN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QStringList>
#include <QSystemTrayIcon>


#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>

class entretien
{
private :
     QString NOM_C;
     int CIN_A;
     int ID_offre;
     QDate  DateE;
     QString  Heures;
     QString Type;


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
    void setHeures(QString);
    void setType(QString);
    bool Ajouter();
 QStringList lister();
QSqlQueryModel * Afficher( );
QSqlQueryModel * rechercher(QString);
QSqlQueryModel * rechercher_A(QString);
bool Supprimer(int);

bool modifier(int,QString,QDate,QString);
QStringList lister2();
QStringList lister3();
QStringList listerS();
QSqlQueryModel * TrieE();
int  statistique_EA(QString);
int  statistique_EO(QString);
int statistique_ET(QString);
void notifcation();
bool nbrE(int);
bool ajoutnbE(int);
};

#endif // ENTRETIEN_H

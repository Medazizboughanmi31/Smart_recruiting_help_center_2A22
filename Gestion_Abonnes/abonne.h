#ifndef ABONNE_H
#define ABONNE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtDebug>
#include<QObject>
/*#include <QtWidgets/QMainWindow>
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
#include <QtWidgets/QGridLayout>*/

class Abonne
{
public:
    Abonne();
    Abonne(int,QString,QString,QString,int,QString,QString,QString,int) ;
    void setCIN(int) ;
    void setTEL(int) ;
    void setAGE(int) ;
    void setNOM(QString) ;
    void setPRENOM(QString) ;
    void setEMAIL(QString) ;
    void setSEXE(QString) ;
    void setADRESSE(QString) ;
    void setNIVEAU_ETUDE(QString) ;

    int getCIN() ;
    int getTEL() ;
    int getAGE() ;
    QString getNOM() ;
    QString getPRENOM() ;
    QString getEMAIL() ;
    QString getSEXE() ;
    QString getADRESSE() ;
    QString getNIVEAU_ETUDE() ;

    bool Ajouter() ;
    QSqlQueryModel * Afficher() ;
    bool Supprimer(int) ;
    bool Modifier() ;
    QSqlQueryModel *Preference(QString );
    QSqlQueryModel * ClassificationAGEAsc() ;
    QSqlQueryModel * ClassificationAGEDesc() ;
    QSqlQueryModel * ClassificationNOM() ;
    QSqlQueryModel * ClassificationETUDEAsc() ;
    QSqlQueryModel * ClassificationETUDEDesc() ;






private:
    int CIN ;
    int TEL ;
    int AGE ;
    QString NOM ;
    QString PRENOM ;
    QString EMAIL ;
    QString SEXE ;
    QString ADRESSE ;
    QString NIVEAU_ETUDE ;


};

#endif // ABONNE_H

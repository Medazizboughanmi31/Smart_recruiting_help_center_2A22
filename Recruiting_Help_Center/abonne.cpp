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
    query.prepare("INSERT INTO ABONNE (CIN,NOM,PRENOM,EMAIL,AGE,SEXE,ADRESSE,NIVEAU_ETUDE,TEL) VALUES (:CIN,:NOM,:PRENOM,:EMAIL,:AGE,:SEXE,:ADRESSE,:NIVEAU_ETUDE,:TEL)"); // ajouter les attributs au table apres l'insertion .
    query.bindValue(0, CIN_string);
    query.bindValue(8, TEL_string);
    query.bindValue(4, AGE_string);
    query.bindValue(1, NOM);
    query.bindValue(2, PRENOM);
    query.bindValue(3, EMAIL);
    query.bindValue(5, SEXE);
    query.bindValue(6, ADRESSE);
    query.bindValue(7, NIVEAU_ETUDE);
    return query.exec();


}

bool Abonne::Supprimer(int CIN)
{
    QSqlQuery query;
    query.prepare(" Delete from ABONNE where CIN=:CIN "); // supprimer les attributs du table d'apres Cin donneé .
    query.bindValue(0, CIN);
    return query.exec();
}

QSqlQueryModel * Abonne::Afficher()
{
         QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM ABONNE"); //afficher tout les attributs du table
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN")); //donner le nom du colone a Afficher
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("NIVEAU D'ETUDE"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));


         return model ;
}

bool Abonne::Modifier()

{

         QSqlQuery query;
         query.prepare("UPDATE ABONNE set NOM=:NOM,PRENOM=:PRENOM,EMAIL=:EMAIL,AGE=:AGE,SEXE=:SEXE,ADRESSE=:ADRESSE,NIVEAU_ETUDE=:NIVEAU_ETUDE,TEL=:TEL where CIN=:CIN ");

         query.bindValue(":CIN", CIN);
         query.bindValue(":TEL", TEL);
         query.bindValue(":AGE", AGE);
         query.bindValue(":NOM", NOM);
         query.bindValue(":PRENOM", PRENOM);
         query.bindValue(":EMAIL", EMAIL);
         query.bindValue(":SEXE", SEXE);
         query.bindValue(":ADRESSE", ADRESSE);
         query.bindValue(":NIVEAU_ETUDE", NIVEAU_ETUDE);

        return query.exec();

}

QSqlQueryModel * Abonne::Preference(QString Prefer)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM ABONNE WHERE ADRESSE  LIKE'%"+Prefer+"%' or SEXE  LIKE'%"+Prefer+"%' or NIVEAU_ETUDE  LIKE'%"+Prefer+"%'  or  AGE  LIKE'%"+Prefer+"%'");
        return model;
}

QSqlQueryModel * Abonne::ClassificationAGEAsc()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM ABONNE order by AGE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NIVEAU D'ETUDE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));
    return  model;
}

QSqlQueryModel * Abonne::ClassificationAGEDesc()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM ABONNE order by AGE DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NIVEAU D'ETUDE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));
    return  model;
}

QSqlQueryModel * Abonne::ClassificationNOM()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM ABONNE order by NOM ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NIVEAU D'ETUDE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));
    return  model;
}

QSqlQueryModel * Abonne::ClassificationETUDEAsc()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM ABONNE order by NIVEAU_ETUDE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NIVEAU D'ETUDE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));
    return  model;
}

QSqlQueryModel * Abonne::ClassificationETUDEDesc()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM ABONNE order by NIVEAU_ETUDE DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("E-MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NIVEAU D'ETUDE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));
    return  model;
}

/*QChartView * Abonne::stat()
{


        // Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("duree");

        QVector <QString> duree;

        // Assign values for each bar

        QSqlQuery query,query2;
        query.prepare("select count(*) from inventaire group by date_inv");
        query.exec();

        query2.prepare("select date_inv from inventaire group by date_inv");
        query2.exec();


        QStringList categories;
        while(query.next())
          {
            *set0 << query.value(0).toInt();

          }
        while(query2.next())
          {
            categories << query2.value(0).toString();
          }


       // *set0 << 283 << 341 << 313 << 338 << 346 << 335;




        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
        series->append(set0);


        // Used to define the bar chart to display, title
        // legend,
        QChart *chart = new QChart();

        // Add the chart
        chart->addSeries(series);

        // Set title
        chart->setTitle("Seance avg by duree");

        // Define starting animation
        // NoAnimation, GridAxisAnimations, SeriesAnimations
        chart->setAnimationOptions(QChart::AllAnimations);

        // Holds the category titles


        // Adds categories to the axes
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();

        // 1. Bar chart
        chart->setAxisX(axis, series);

        // 2. Stacked Bar chart
        // chart->setAxisY(axis, series);

        // Define where the legend is displayed
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);



       return chartView;


}*/



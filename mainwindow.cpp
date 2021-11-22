#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"entretien.h"
#include "connection.h"
#include"historique.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include<QDebug>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ;
    ui->table_e->setModel(E.Afficher());
    ui->comboBox_C->addItems(E.lister());
    ui->comboBox_S->addItems(E.lister2());
    ui->comboBox_O->addItems(E.lister3());
    ui->comboBoxStat->addItems(E.listerS());
    ui->tri->setModel(E.TrieE());
    ui->view_histo->setModel(H.Afficher());
stat();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
connection c;
c.createconnection();
    int CIN_A=ui->cin_aj->text().toInt();
    //int ID_offre=ui->offre->text().toInt();
    int ID_offre =ui->comboBox_O->currentText().toInt();
    QString NOM_C=ui->comboBox_C->currentText();
    QDate DateE= ui->date_Aj->date();
    QString Heures= ui->time_aj->text();
    QString Type=ui->type->currentText();
    entretien e( CIN_A,ID_offre,NOM_C,DateE, Heures,Type);
    bool test=e.Ajouter();
   if(test)
   {

     QMessageBox ::information(nullptr,QObject::tr("OK"),
                               QObject::tr("Ajout effectue \n"
                                           "click cancel to exit,"),QMessageBox::Cancel);
     QString operation="Ajout";
     historique H(operation);
     H.Ajouter();
      ui->view_histo->setModel(H.Afficher());
      ui->table_e->setModel(E.Afficher());
      ui->tri->setModel(E.TrieE());
      ui->comboBox_S->addItems(E.lister2());


   }
   else
       QMessageBox ::information(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectue \n"
                                             "click cancel to exit,"),QMessageBox::Cancel);

   e.notifcation();

}







void MainWindow::on_offre_A_textChanged(const QString &arg1)
{
  entretien e;
     ui->tri->setModel( e.rechercher(arg1));

}

void MainWindow::on_num_A_textChanged(const QString &arg2)
{
    entretien e;
    ui->table_e->setModel( e.rechercher_A(arg2));

}

void MainWindow::on_Supprimer_clicked()
{
    connection c;
    c.createconnection();
    entretien E;
    historique H;
   // int id=ui->num_S->text().toInt();
      int id =ui->comboBox_S->currentText().toInt();
       bool test =E.Supprimer(id);
       QMessageBox msg ;
       if (test)
        {
       msg.setText("suppression avec succés");
       ui->table_e->setModel(E.Afficher());
       ui->tri->setModel(E.TrieE());
         ui->comboBox_S->clear();
       QString operation="Suppression";
       historique H(operation);
       H.Ajouter();
        ui->view_histo->setModel(H.Afficher());

       }
       else
       {
       msg.setText("Echec au niveau de la suppression ");
       }
       msg.exec();
}



void MainWindow::on_num_r_clicked()
{
     QSqlQuery query;
     query.prepare("select TYPE_RDV, DATE_RDV, HEURE_RDV from entretien where ID_RDV=?;");
     query.addBindValue(ui->num_M->text());
     if(query.exec())
        {
         while(query.next())
          {

     ui->date_M->setDate(query.value(1).toDate());
     ui->time_M->setTime(query.value(2).toTime());

      QString t=query.value(0).toString();
     ui->comboBox_M->setCurrentText(t);

             }
         }
}

void MainWindow::on_modifier_clicked()
{
    entretien E;
    int id=ui->num_M->text().toInt();
    QString Type=ui->comboBox_M->currentText();
    QDate date= ui->date_M->date();
    QString temps= ui->time_M->text();
   bool test= E.modifier(id,Type,date,temps);
    QMessageBox msg;
   if(test)
   { ui->table_e->setModel(E.Afficher());
                   msg.setText("modifie avec succés");
                  ui->table_e->setModel(E.Afficher());
                  QString operation="Modifier";
                  historique H(operation);
                  H.Ajouter();
                   ui->view_histo->setModel(H.Afficher());
                    ui->tri->setModel(E.TrieE());

                   }
                   else
                   {
                   msg.setText("Echec au niveau de la modif ");
                   }
                   msg.exec();

               ui->num_M->clear();
               ui->comboBox_M->clear();
               ui->date_M->clear();
               ui->time_M->clear();

}






void MainWindow::on_comboBoxStat_currentTextChanged(const QString &arg1)
{stat();
/*
    float SA=0,SO=0;
     int a =E.statistique_EA(ui->comboBoxStat->currentText());
    int o=E.statistique_EO(ui->comboBoxStat->currentText());
     int t=E.statistique_ET(ui->comboBoxStat->currentText());
     SA=(a*100)/t;
     SO=(o*100)/t;
     QBarSet *set0=new QBarSet("Accepté");
      QBarSet *set1=new QBarSet("Refusé");
     *set0<<SA;
      *set1<<SO;
      QBarSeries *series=new QBarSeries();
      series->append(set0);
      series->append(set1);
      QChart *chart=new QChart();
      chart->addSeries(series);
      chart->setTitle("statistique des entretiens");
      chart->setAnimationOptions(QChart::SeriesAnimations);
      QStringList categories;
      categories<<"entretien";
      QBarCategoryAxis *axis=new QBarCategoryAxis();
      axis->append(categories);
      chart->createDefaultAxes();
      chart->setAxisX(axis,series);
      QChartView *chartView=new QChartView(chart);
      chartView->setParent(ui->frame);
*/
}
void MainWindow::stat(){

    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    int SA=0,SO=0;
     int a =E.statistique_EA(ui->comboBoxStat->currentText());
    int o=E.statistique_EO(ui->comboBoxStat->currentText());
     int t=E.statistique_ET(ui->comboBoxStat->currentText());
     SA=(a*100)/t;
     SO=(o*100)/t;


 ui->progressBar->setValue(SA);
  ui->progressBar_2->setValue(SO);


}


void MainWindow::on_pushButton_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}

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
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
    //le slot update_label suite à la reception du signal readyRead (reception des données).
    ui->ent_table_e->setModel(E.Afficher());
    ui->ent_comboBox_C->addItems(E.lister());
    ui->ent_comboBox_S->addItems(E.lister2());
    ui->ent_comboBox_O->addItems(E.lister3());
    ui->ent_comboBoxStat->addItems(E.listerS());
    ui->ent_tri->setModel(E.TrieE());
    ui->ent_view_histo->setModel(H.Afficher());
stat();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ent_ajouter_clicked()
{entretien e;
connection c;
c.createconnection();

    int CIN_A=ui->ent_cin_aj->text().toInt();
    //int ID_offre=ui->offre->text().toInt();
   bool testnb=e.nbrE(CIN_A);
   if(testnb==false)
   {
       int ID_offre =ui->ent_comboBox_O->currentText().toInt();
       QString NOM_C=ui->ent_comboBox_C->currentText();

       QDate DateE= ui->ent_date_Aj->date();
       QString Heures= ui->ent_time_aj->text();
       QString Type=ui->ent_type->currentText();
       entretien e( CIN_A,ID_offre,NOM_C,DateE, Heures,Type);
       bool test=e.Ajouter();
      if(test)
      {
        A.write_to_arduino("0");
        QMessageBox ::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("Ajout effectue \n"
                                              "click cancel to exit,"),QMessageBox::Cancel);

        QSqlQuery query;
        query.prepare("UPDATE abonne SET NOMBRE_E = NOMBRE_E+1 where  CIN= :CIN_A ");
         query.bindValue(":CIN_A",CIN_A);
        // CIN=CIN_A;

        QString operation="Ajout";
        historique H(operation);
        H.Ajouter();
         ui->ent_view_histo->setModel(H.Afficher());
         ui->ent_table_e->setModel(E.Afficher());
         ui->ent_tri->setModel(E.TrieE());
         ui->ent_comboBox_S->addItems(E.lister2());

      }

      else
          QMessageBox ::information(nullptr,QObject::tr("Not OK"),
                                    QObject::tr("Ajout non effectue \n"
                                                "click cancel to exit,"),QMessageBox::Cancel);


   }else
   { A.write_to_arduino("1");
       QMessageBox ::information(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("vous n'avez plus le droit de prendre un nouveau rendez-vous "),QMessageBox::Cancel);

   }
 e.notifcation();

}

/*void MainWindow::update_label()
{entretien e;
    data=A.read_from_arduino();


             if(data=="2")
             {
                  e.ajoutnbE(CIN);
             }
     // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}*/







void MainWindow::on_ent_offre_A_textChanged(const QString &arg1)
{
  entretien e;
     ui->ent_tri->setModel( e.rechercher(arg1));

}

void MainWindow::on_ent_num_A_textChanged(const QString &arg2)
{
    entretien e;
    ui->ent_table_e->setModel( e.rechercher_A(arg2));

}

void MainWindow::on_ent_Supprimer_clicked()
{
    connection c;
    c.createconnection();
    entretien E;
    historique H;
   // int id=ui->num_S->text().toInt();
      int id =ui->ent_comboBox_S->currentText().toInt();
       bool test =E.Supprimer(id);
       QMessageBox msg ;
       if (test)
        {
       msg.setText("suppression avec succés");
       ui->ent_table_e->setModel(E.Afficher());
       ui->ent_tri->setModel(E.TrieE());
         ui->ent_comboBox_S->clear();
       QString operation="Suppression";
       historique H(operation);
       H.Ajouter();
        ui->ent_view_histo->setModel(H.Afficher());

       }
       else
       {
       msg.setText("Echec au niveau de la suppression ");
       }
       msg.exec();
}



void MainWindow::on_ent_num_r_clicked()
{
     QSqlQuery query;
     query.prepare("select TYPE_RDV, DATE_RDV, HEURE_RDV from entretien where ID_RDV=?;");
     query.addBindValue(ui->ent_num_M->text());
     if(query.exec())
        {
         while(query.next())
          {

     ui->ent_date_M->setDate(query.value(1).toDate());
     ui->ent_time_M->setTime(query.value(2).toTime());

      QString t=query.value(0).toString();
     ui->ent_comboBox_M->setCurrentText(t);

             }
         }
}

void MainWindow::on_ent_modifier_clicked()
{
    entretien E;
    int id=ui->ent_num_M->text().toInt();
    QString Type=ui->ent_comboBox_M->currentText();
    QDate date= ui->ent_date_M->date();
    QString temps= ui->ent_time_M->text();
   bool test= E.modifier(id,Type,date,temps);
    QMessageBox msg;
   if(test)
   { ui->ent_table_e->setModel(E.Afficher());
                   msg.setText("modifie avec succés");
                  ui->ent_table_e->setModel(E.Afficher());
                  QString operation="Modifier";
                  historique H(operation);
                  H.Ajouter();
                   ui->ent_view_histo->setModel(H.Afficher());
                    ui->ent_tri->setModel(E.TrieE());

                   }
                   else
                   {
                   msg.setText("Echec au niveau de la modif ");
                   }
                   msg.exec();

               ui->ent_num_M->clear();
               ui->ent_comboBox_M->clear();
               ui->ent_date_M->clear();
               ui->ent_time_M->clear();
                  E.notifcation();

}







void MainWindow::stat(){

    ui->ent_progressBar->setValue(0);
    ui->ent_progressBar_2->setValue(0);
    int SA=0,SO=0;
     int a =E.statistique_EA(ui->ent_comboBoxStat->currentText());
    int o=E.statistique_EO(ui->ent_comboBoxStat->currentText());
     int t=E.statistique_ET(ui->ent_comboBoxStat->currentText());
     SA=(a*100)/t;
     SO=(o*100)/t;


 ui->ent_progressBar->setValue(SA);
  ui->ent_progressBar_2->setValue(SO);


}


void MainWindow::on_ent_email_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}

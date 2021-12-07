#include "windowentretiens.h"
#include "ui_windowentretiens.h"
#include"entretien.h"

#include"historique.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include<QDebug>
#include <QDesktopServices>
#include <QUrl>

WindowEntretiens::WindowEntretiens(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowEntretiens)
{
    ui->setupUi(this);
  ui->ent_table_e->setModel(E.Afficher());
    ui->ent_comboBox_C->addItems(E.lister());
    ui->ent_comboBox_S->addItems(E.lister2());
    ui->ent_comboBox_O->addItems(E.lister3());
    ui->ent_comboBoxStat->addItems(E.listerS());
    ui->ent_tri->setModel(E.TrieE());
    ui->ent_view_histo->setModel(H.Afficher());
stat();

}

WindowEntretiens::~WindowEntretiens()
{
    delete ui;
}



void WindowEntretiens::on_ent_ajouter_clicked()
{

    int CIN_A=ui->ent_cin_aj->text().toInt();
    //int ID_offre=ui->offre->text().toInt();
    int ID_offre =ui->ent_comboBox_O->currentText().toInt();
    QString NOM_C=ui->ent_comboBox_C->currentText();
    QDate DateE= ui->ent_date_Aj->date();
    QString Heures= ui->ent_time_aj->text();
    QString Type=ui->ent_type->currentText();
    entretien e( CIN_A,ID_offre,NOM_C,DateE, Heures,Type);
    bool test=e.Ajouter();
   if(test)
   {

     QMessageBox ::information(nullptr,QObject::tr("OK"),
                               QObject::tr("Ajout effectue \n"
                                           "click cancel to exit,"),QMessageBox::Cancel);

     QSqlQuery query;
     query.prepare("UPDATE abonne SET NOMBRE_E = NOMBRE_E+1 where  CIN= :CIN_A ");
      query.bindValue(":CIN_A",CIN_A);
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

   e.notifcation();

}







void WindowEntretiens::on_ent_offre_A_textChanged(const QString &arg1)
{
  entretien e;
     ui->ent_tri->setModel( e.rechercher(arg1));

}

void WindowEntretiens::on_ent_num_A_textChanged(const QString &arg2)
{
    entretien e;
    ui->ent_table_e->setModel( e.rechercher_A(arg2));

}

void WindowEntretiens::on_ent_Supprimer_clicked()
{

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



void WindowEntretiens::on_ent_num_r_clicked()
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

void WindowEntretiens::on_ent_modifier_clicked()
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







void WindowEntretiens::stat(){

    ui->ent_progressBar->setValue(0);
    ui->ent_progressBar_2->setValue(0);
    int SA=0,SO=0;
    int a =E.statistique_EA(ui->ent_comboBoxStat->currentText());
    int o=E.statistique_EO(ui->ent_comboBoxStat->currentText());
     int t=E.statistique_ET(ui->ent_comboBoxStat->currentText());
   if(t!=0)
     {
     SA=(a*100)/t;
     SO=(o*100)/t;
}

 ui->ent_progressBar->setValue(SA);
  ui->ent_progressBar_2->setValue(SO);


}


void WindowEntretiens::on_ent_email_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}

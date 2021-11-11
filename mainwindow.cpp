#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"entretien.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_e->setModel(E.Afficher());
    ui->comboBox_C->addItems(E.lister());
    ui->comboBox_S->addItems(E.lister2());

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
    int ID_offre=ui->offre->text().toInt();
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
       ui->table_e->setModel(E.Afficher());

   }
   else
       QMessageBox ::information(nullptr,QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectue \n"
                                             "click cancel to exit,"),QMessageBox::Cancel);

}







void MainWindow::on_offre_A_textChanged(const QString &arg1)
{
  entretien e;
     ui->table_e->setModel( e.rechercher(arg1));

}

void MainWindow::on_num_A_textChanged(const QString &arg1)
{
    entretien e;
    ui->table_e->setModel( e.rechercher_A(arg1));

}

void MainWindow::on_Supprimer_clicked()
{
    entretien E;
   // int id=ui->num_S->text().toInt();
      int id =ui->comboBox_S->currentText().toInt();
       bool test =E.Supprimer(id);
       QMessageBox msg ;
       if (test)
        {

       msg.setText("suppression avec succés");
       ui->table_e->setModel(E.Afficher());
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
//if (t=="en ligne") {
     ui->comboBox_M->setCurrentText(t);

//}
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
   {
                   msg.setText("modifie avec succés");
                  ui->table_e->setModel(E.Afficher());
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

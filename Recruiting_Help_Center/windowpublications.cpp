#include "windowpublications.h"
#include "ui_windowpublications.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QRegExpValidator>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QPainter>
#define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
WindowPublications::WindowPublications(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowPublications)

{

    ui->setupUi(this);



ui->aj_tag->addItems(p.tag_societe());
ui->md_tag->addItems(p.tag_societe());
  ui->le_id_pub->setValidator(new QIntValidator(0, 9999999, this));
   ui->le_CIN_A_pub->setValidator(new QIntValidator(10000000, 99999999, this));
    ui->le_id_supp->setValidator(new QIntValidator(2, 9999999, this));
     ui->md_CIN_A_pub->setValidator(new QIntValidator(0, 99999999, this));
      ui->md_id_pub->setValidator(new QIntValidator(3, 9999999, this));
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->le_titre_pub->setValidator(valiNom);
    ui->le_type_pub->setValidator(valiNom);
    ui->md_titre_pub->setValidator(valiNom);
    ui->md_type_pub->setValidator(valiNom);
    ui->md_tag->setValidator(valiNom);
    ui->le_rech_type_pub->setValidator(valiNom);
ui->tab_publication->setModel(p.afficher());


QSqlQuery q,q1;
q.prepare("select count(publication.id_pub) as k,abonne.cin from abonne,publication where abonne.cin=publication.cin_a group by abonne.cin  order by  k desc;");
q.exec();
q.next();
ui->nombrepub_active->setText(q.value(0).toString());
q1.prepare("select nom_a,prenom_a from abonne where cin='"+q.value(1).toString()+"';");
q1.exec();
q1.next();
ui->cin_active->setText(q.value(1).toString());
ui->nom_active->setText(q1.value(0).toString());
ui->prenom_active->setText(q1.value(1).toString());
}

WindowPublications::~WindowPublications()
{
    delete ui;
}



void WindowPublications::on_pub_Ajouter_clicked()
{
    QString titre_pub=ui->le_titre_pub->text();
   int CIN_A=ui->le_CIN_A_pub->text().toInt();
   QDate date_pub=ui->aj_datetime->date();
  int id_pub=ui->le_id_pub->text().toInt();
   QString type_pub=ui->le_type_pub->currentText();
    QString tag_societe=ui->aj_tag->currentText();
    QString description_pub=ui->la_description_pub->toPlainText();
   publication p(titre_pub,CIN_A,date_pub.toString("yyyy/dd/MM"),id_pub,type_pub,tag_societe,description_pub);
 p.ajouter();

 bool test=p.ajouter();
 QMessageBox msgBox;
 if(test)

  msgBox.setText("echec d'ajout");

 else
 {
  msgBox.setText("Ajout avec succes.");
 ui->tab_publication->setModel(p.afficher());}



 msgBox.exec();
}



void WindowPublications::on_pub_pb_supprimer_clicked()
{
publication p1; p1.setid_pub(ui->le_id_supp->text().toInt());

bool test=p1.supprimer(p1.getid_pub());
QMessageBox msgbox;
if(test)
{
    ui->tab_publication->setModel(p1.afficher());
    msgbox.setText("suppression avec succes");
}
else
      msgbox.setText("echec de suppression.");
msgbox.exec();
}


void WindowPublications::on_pub_pb_modifier_clicked()
{
    QString titre_pub=ui->md_titre_pub->text();
     int CIN_A=ui->md_CIN_A_pub->text().toInt();
        QString date_pub=ui->md_datetime->text();
         int id_pub=ui->md_id_pub->text().toInt();
          QString type_pub=ui->md_type_pub->currentText();
         QString tag_s=ui->md_tag->currentText();
    QString description_pub=ui->md_description_pub->toPlainText();


   publication p(titre_pub,CIN_A,date_pub,id_pub,type_pub,tag_s,description_pub);

   bool test=p.modifier(id_pub);
   QMessageBox msgBox;
   if(test)
   {
    msgBox.setText("Modification avec succes.");
    ui->tab_publication->setModel(p.afficher());
   }
   else
       msgBox.setText("echec de modification");
   msgBox.exec();
}


void WindowPublications::on_pub_pushButton_2_clicked()
{
 publication p;
 QString type=ui->le_rech_type_pub->text();
ui->tab_rech->setModel(p.recherche(type));
}




void WindowPublications::on_pub_envoyer_mail_2_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
    QDesktopServices::openUrl(link);
}



void WindowPublications::on_trier_pub_clicked()
{
    ui->tab_publication->setModel(p.trierdate());

}



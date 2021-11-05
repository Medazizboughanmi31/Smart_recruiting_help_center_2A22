#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "publication.h"
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
ui->tab_publication->setModel(p.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString titre=ui->le_titre->text();
    QString type=ui->le_type->text();
    QString description=ui->la_description->toPlainText();


   publication p(id,titre,type,description);

   p.ajouter();

   bool test=p.ajouter();
   QMessageBox msgBox;
   if(test)
       msgBox.setText("Ajout avec succes.");
   else
       msgBox.setText("echec d'ajout");
   msgBox.exec();
}



void MainWindow::on_pb_supprimer_clicked()
{
publication p1; p1.setid(ui->le_id_supp->text().toInt());


bool test=p1.supprimer(p1.getid());
QMessageBox msgBox;
if(test)
{

    msgBox.setText("Suppression avec succes.");
    ui->tab_publication->setModel(p1.afficher());
}

else
    msgBox.setText("echec de suppression");
msgBox.exec();


}


void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->md_id->text().toInt();
    QString titre=ui->md_titre->text();
    QString type=ui->md_type->text();
    QString description=ui->md_description->toPlainText();

   publication p(id,titre,type,description);


   bool test=p.modifier(id);
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




#include "gestion.h"
#include "ui_gestion.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Gestion::Gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion)
{
    ui->setupUi(this);
}

Gestion::~Gestion()
{
    delete ui;
}



void Gestion::on_pushButton_changePoste_clicked()
{
    ChoixAgent* ch=new ChoixAgent() ;
    ch->show() ;
}


void Gestion::on_pushButton_changeCompte_clicked()
{
    LoggingIN* L=new LoggingIN() ;
    L->show() ;
}


void Gestion::on_lineEdit_Preference_textChanged(const QString &arg1)
{
    Abonne A ;
    ui->tab_preference->setModel(A.Preference(arg1));
}


void Gestion::on_radioButton_AGEASC_clicked()
{
    Abonne A ;
    ui->tab_classification->setModel(A.ClassificationAGEAsc());
}


void Gestion::on_radioButton_AGEDESC_clicked()
{
    Abonne A ;
    ui->tab_classification->setModel(A.ClassificationAGEDesc());
}


void Gestion::on_radioButton_ETUDEASC_clicked()
{
    Abonne A ;
    ui->tab_classification->setModel(A.ClassificationETUDEAsc());
}


void Gestion::on_radioButton_ETUDEDESC_clicked()
{
    Abonne A ;
    ui->tab_classification->setModel(A.ClassificationETUDEDesc());
}


void Gestion::on_radioButton_Nom_clicked()
{
    Abonne A ;
    ui->tab_classification->setModel(A.ClassificationNOM());
}




void Gestion::on_pushButton_EnvoyerReclamation_clicked()
{

    QSqlQuery query ;
    QString Reclamation=ui->textEdit_reclamation->toPlainText() ;
     QString ID_C=ui->lineEdit_ID_C->text() ;
    query.prepare("Select ID_C from ABONNE WHERE ID_C=:ID_C ");
    query.bindValue(":ID_C",ID_C) ;
    query.exec() ;

        bool alreadyExist = false ;
            alreadyExist = query.next();
            if(alreadyExist)
            {

                if(Reclamation.size()>0)
               {
                QMessageBox msgbox ;
                msgbox.setText("Reclamation Envoyée . \n") ;
                msgbox.exec() ;
                ui->textEdit_reclamation->setText("")  ;
                ui->lineEdit_ID_C->setText("") ;
               }
                else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                  QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);


            }
          else
                         {

                           ui->textEdit_reclamation->setText("")  ;
                           ui->lineEdit_ID_C->setText("") ;
                           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                  QObject::tr("CENTRE INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                         }





}


void Gestion::on_pushButton_AnnulerRec_clicked()
{
    ui->textEdit_reclamation->setText("")  ;
    ui->lineEdit_ID_C->setText("") ;
}










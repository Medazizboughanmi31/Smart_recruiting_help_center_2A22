#include "loggingin.h"
#include "ui_loggingin.h"

LoggingIN::LoggingIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoggingIN)
{
    ui->setupUi(this);
    ui->lineEdit_Motdepasse->setValidator(new QIntValidator(0 , 99999999 , this)) ;
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
 QRegularExpression rxNom(NOM_RX);
 QRegularExpressionValidator *valiNom= new QRegularExpressionValidator(rxNom,this);
 ui->lineEdit_Nom_Abonne->setValidator(valiNom);
#define NOM_RX2 "^([0-9]+[,.]?[ ]?|[0-9]+['-]?)+$"
 QRegularExpression rxNom2(NOM_RX2);
 QRegularExpressionValidator *valiNum= new QRegularExpressionValidator(rxNom2,this);
 ui->lineEdit_Motdepasse->setValidator(valiNum);
}

LoggingIN::~LoggingIN()
{
    delete ui;
}

void LoggingIN::on_pushButton_SeConnecter_clicked()
{

   QString Nom_Abonne=ui->lineEdit_Nom_Abonne->text();
   QString mdp=ui-> lineEdit_Motdepasse->text();
   QSqlQuery query;
   query.prepare("select * from ABONNE where NOM=:Nom_Abonne and CIN=:mdp");
   query.addBindValue(ui->lineEdit_Nom_Abonne->text());
   query.addBindValue(ui->lineEdit_Motdepasse->text());
   query.exec();
       bool alreadyExist = false;
       alreadyExist = query.next();
       if(alreadyExist)
       {

             ui->lineEdit_Nom_Abonne->setText("");
             ui->lineEdit_Motdepasse->setText("");
             close() ;
            QMessageBox msgbox ;
            msgbox.setText("Bienvenue "+Nom_Abonne+"") ;
            msgbox.exec() ;



       }
       else
           {
           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                            QObject::tr("NOM D'UTILISATEUR OU MOT DE PASSE INCORRECTE.\n" "Click Cancel to exit."), QMessageBox::Cancel);
           ui->lineEdit_Nom_Abonne->setText("");
           ui->lineEdit_Motdepasse->setText("");
            }



}

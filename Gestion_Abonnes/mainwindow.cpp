#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_CIN->setValidator(new QIntValidator(0 , 99999999 , this)) ;
    ui->lineEdit_TEL->setValidator(new QIntValidator(0 , 99999999 , this)) ;
    ui->lineEdit_AGE->setValidator(new QIntValidator(0 , 99 , this)) ;
    ui->tab_Abonnes->setModel(A.Afficher()) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked()
{
    int CIN=ui->lineEdit_CIN->text().toInt() ;
    int TEL=ui->lineEdit_TEL->text().toInt() ;
    int AGE=ui->lineEdit_AGE->text().toInt() ;
    QString NOM=ui->lineEdit_NOM->text() ;
    QString PRENOM=ui->lineEdit_PRENOM->text() ;
    QString EMAIL=ui->lineEdit_EMAIL->text() ;
    QString SEXE=ui->lineEdit_SEXE->text() ;
    QString ADRESSE=ui->lineEdit_ADRESSE->text() ;
    QString NIVEAU_ETUDE=ui->lineEdit_NIVEAUETUDE->text() ;
    Abonne A(CIN,NOM,PRENOM,EMAIL,AGE,SEXE,ADRESSE,NIVEAU_ETUDE,TEL) ;
    bool test=A.Ajouter() ;
    QMessageBox msgbox ;
    if(test)
    {
        msgbox.setText("Ajout avec succes") ;
        ui->tab_Abonnes->setModel(A.Afficher()) ;
    }
    else msgbox.setText("echec d'ajout !!") ;
    msgbox.exec() ;

}


void MainWindow::on_pushButton_Supprimer_clicked()
{
    Abonne A1 ;
    A1.setCIN(ui->lineEdit_CIN_Suprrimer->text().toInt()) ;
    bool test=A1.Supprimer(A1.getCIN()) ;
    QMessageBox msgbox ;
    if(test)
    {
        msgbox.setText("Suppresion avec succes") ;
        ui->tab_Abonnes->setModel(A.Afficher()) ;
    }
    else msgbox.setText("echec du suppression !!") ;
    msgbox.exec() ;
}


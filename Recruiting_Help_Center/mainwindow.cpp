#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_GestionAbonnes_clicked()
{
    ChoixAgent* ch=new ChoixAgent() ;
    ch->show() ;
}

void MainWindow::on_pushButton_GestionOffres_clicked()
{
    WindowOffres* O=new WindowOffres() ;
    O->show() ;
}

void MainWindow::on_pushButton_GestionEntretiens_clicked()
{
    WindowEntretiens* e=new WindowEntretiens() ;
    e->show() ;
    entretien E ;
    E.notifcation();

}

void MainWindow::on_pushButton_GestionCentres_clicked()
{
    WindowCentres* C=new WindowCentres() ;
    C->show() ;
}

void MainWindow::on_pushButton_GestionPublications_clicked()
{
    WindowPublications* P=new WindowPublications() ;
    P->show() ;
}

void MainWindow::on_pushButton_GestionEntreprises_clicked()
{
    WindowEntreprises* EP=new WindowEntreprises() ;
    EP->show() ;
}

#include "choixagent.h"
#include "ui_choixagent.h"

ChoixAgent::ChoixAgent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixAgent)
{
    ui->setupUi(this);
}

ChoixAgent::~ChoixAgent()
{
    delete ui;
}

void ChoixAgent::on_pushButton_A_acceuil_clicked()
{
    close() ;
    Gestion* G=new Gestion();
    G->show() ;
    LoggingIN* L=new LoggingIN() ;
    L->show() ;

}


void ChoixAgent::on_pushButton_Admin_clicked()
{
    close() ;
    MainWindow* w=new MainWindow();
    w->show() ;
}


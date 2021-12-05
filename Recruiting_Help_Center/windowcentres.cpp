#include "windowcentres.h"
#include "ui_windowcentres.h"
#include"centre.h"
#include"mail.h"
#include"reclamation.h"
#include <QQuickItem>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>



WindowCentres::WindowCentres(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowCentres)
{
    ui->setupUi(this);
    ui->c_telephone->setValidator(new QIntValidator(0,99999999,this));//controle de saisie sur le num tel        ajout
    ui->c_nomrecruteurs->setValidator(new QIntValidator(0,499,this)); // controle de saisie sur le nombre de recruteurs
    ui->c_telupdated->setValidator(new QIntValidator(0,99999999,this)); //                                        modifier
    ui->c_nbupdated->setValidator(new QIntValidator(0,501,this));

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/localisation.qml")));
    ui->quickWidget->show();
    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));

    emit setCenter(36.862869, 10.169963);

    QSqlQuery query;//requette sql qui va excuter a  partir du qt ;
          QSqlQueryModel* model= new QSqlQueryModel();




        // c_combo box supprimer

        query.prepare("SELECT NOM_C FROM CENTRE ");//preparer la model qui va selecter le nom de centre de table centre ;

        query.exec();//executer

        model->setQuery(query);

ui->c_comboBox->setModel(model);

// c_combo box modifier

ui->c_comboBox_2->setModel(model);
ui->c_comboBox_3->setModel(model);
ui->c_mailing->setModel(model);

ui->ville->addItem("Tunis");
ui->ville->addItem("Ariana");
ui->ville->addItem("Monastir");
ui->ville->addItem("Sousse");
ui->ville->addItem("Sfax");
ui->ville->addItem("Nabeul");
ui->ville->addItem("Bizerte");
ui->ville->addItem("Kairaouen");
ui->ville->addItem("Ben Arous");
ui->ville->addItem("Gabes");
ui->ville->addItem("Gafsa");

ui->ville_2->addItem("Tunis");
ui->ville_2->addItem("Ariana");
ui->ville_2->addItem("Monastir");
ui->ville_2->addItem("Sousse");
ui->ville_2->addItem("Sfax");
ui->ville_2->addItem("Nabeul");
ui->ville_2->addItem("Bizerte");
ui->ville_2->addItem("Kairaouen");
ui->ville_2->addItem("Ben Arous");
ui->ville_2->addItem("Gabes");
ui->ville_2->addItem("Gafsa");

ui->ville_3->addItem("Tunis");
ui->ville_3->addItem("Ariana");
ui->ville_3->addItem("Monastir");
ui->ville_3->addItem("Sousse");
ui->ville_3->addItem("Sfax");
ui->ville_3->addItem("Nabeul");
ui->ville_3->addItem("Bizerte");
ui->ville_3->addItem("Kairaouen");
ui->ville_3->addItem("Ben Arous");
ui->ville_3->addItem("Gabes");
ui->ville_3->addItem("Gafsa");







//requette sql qui va excuter a  partir du qt ;

//executer

















}

WindowCentres::~WindowCentres()
{
    delete ui;
}






void WindowCentres::on_c_pb_ajouter_clicked()
{




  int tel=ui->c_telephone->text().toInt();
  int nbr=ui->c_nomrecruteurs->text().toInt();
       QString nom=ui->c_nom->text();
       QString email=ui->c_email->text();
       QString adresse=ui->c_adresse->text();
QString ville=ui->ville->currentText();
       centre c(nom,tel,email,adresse,nbr,ville);

 if(email.contains("@") && tel!=0 && adresse!="" && nbr!=0 && nom!="" )  // @ obligatoire
       {   bool test=c.ajouter();




          if(test)
      {
              QMessageBox::information(nullptr, QObject::tr("OK"),
                          QObject::tr("Ajout effectue\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}
          else
              { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                          QObject::tr("Ajout non effectue.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

      }

}
 else
     { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                 QObject::tr("Ajout non effectue.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}


}









void WindowCentres::on_c_pushButton_clicked()           //AFFICHER
{
    QSqlQueryModel* model= new QSqlQueryModel();

QSqlQuery query;
    query.prepare("SELECT NOM_C FROM CENTRE ");//preparer la model qui va selecter le nom de centre de table centre ;
          query.exec();//executer
          model->setQuery(query);







    centre c;
        ui->tab_centre->setModel(c.afficher());
  ui->c_comboBox->setModel(model);     // ACTUALISER MODIFIER
  ui->c_comboBox_2->setModel(model);   // ACTUALISER SUPPRIMER
  ui->c_comboBox_3->setModel(model);   // ACTUALISER CHERCHER
  ui->c_mailing->setModel(model);       // actualiser c_mailing
        //            reclamation













}





void WindowCentres::on_c_pushButton_2_clicked()   //supprimer
{
     QString nom=ui->c_comboBox->currentText();
     if(nom!="Centre Rec Pro" )
     {

        bool test=c.Supprimer(nom);
    if(test)
   {
           QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("Suppression effectue\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);




   }
       else
           QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                       QObject::tr("Suppression non effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}
     else
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                     QObject::tr("Suppression non effectue.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


}

void WindowCentres::on_c_pushButton_4_clicked()  // modifier
{
QString nom=ui->c_comboBox_2->currentText();
    QString email=ui->c_emailupdated->text();
 int tel=ui->c_telupdated->text().toInt();
  QString adresse=ui->c_adresseupdated->text();
  int nbr=ui->c_nbupdated->text().toInt();
QString ville=ui->ville_2->currentText();

if(nom!="Centre Rec Pro" &&tel !=0 && email!="" && adresse!="" && nbr!=0 && email.contains("@"))
{          centre c(nom,tel,email,adresse,nbr,ville);
        bool  test=c.update(nom);


          if(test)
          {
                  QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("update effectue\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);




          }
              else
                  QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("update non effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("update non effectue.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void WindowCentres::on_c_pushButton_3_clicked()  //statistique
{
    ui->tab_r->setModel(c.nb_rec());
}

void WindowCentres::on_c_pb_chercher_clicked()  // chercher
{



QString nom=ui->c_comboBox_3->currentText();  // AFFICHER LES NOM DU TAB
ui->tab_rech->setModel(c.recherche(nom));   // CHERCHER ET AFFICHER LES DONNEES



}

void WindowCentres::on_c_chercher2_clicked()
{
QString ville=ui->ville_3->currentText();
    ui->tab_ville->setModel(c.recherche_ville(ville));
}


void WindowCentres::on_p_envoyer_5_clicked()  //c_mailing
{

QString des=ui->c_mailing->currentText();
QString objet=ui->c_ob->text();
QString desription=ui->c_des->text();


if(objet!="" && desription!="")
{mail m(des,objet,desription);
    bool test=m.envoyer();

if(test)
{
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("mail envoyé\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("mail non envoyé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("mail non envoyé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}








void WindowCentres::on_c_pb_reclamation_5_clicked()  // réclamation
{


 ui->label_18->setText("reclamation en cours"); // si les données reçues de arduino via la liaison série sont égales à 1


}



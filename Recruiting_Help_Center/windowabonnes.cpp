#include "windowabonnes.h"
#include "ui_windowabonnes.h"
#include<QFileInfo>
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QTextDocument>
#include <QPageSize>


WindowAbonnes::WindowAbonnes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowAbonnes)
{
    ui->setupUi(this);
    ui->lineEdit_CIN->setValidator(new QIntValidator(0 , 99999999 , this)) ;
    ui->lineEdit_TEL->setValidator(new QIntValidator(0 , 99999999 , this)) ;
    ui->lineEdit_AGE->setValidator(new QIntValidator(0 , 99 , this)) ;
    ui->tab_Abonnes->setModel(A.Afficher()) ;
   #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegularExpression rxNom(NOM_RX);
    QRegularExpressionValidator *valiNom= new QRegularExpressionValidator(rxNom,this);
    ui->lineEdit_NOM->setValidator(valiNom);
    ui->lineEdit_PRENOM->setValidator(valiNom);
    ui->lineEdit_SEXE->setValidator(valiNom);
    ui->lineEdit_ADRESSE->setValidator(valiNom);
    #define NOM_RX2 "^([0-9]+[,.]?[ ]?|[0-9]+['-]?)+$"
    QRegularExpression rxNom2(NOM_RX2);
    QRegularExpressionValidator *valiNum= new QRegularExpressionValidator(rxNom2,this);
    ui->lineEdit_CIN->setValidator(valiNum) ;
    ui->lineEdit_CIN_Suprrimer->setValidator(valiNum) ;
    ui->lineEdit_CIN_update->setValidator(valiNum) ;


   // ui->lineEdit_NIVEAUETUDE->setValidator(valiNom);


}

WindowAbonnes::~WindowAbonnes()
{
    delete ui;
}


void WindowAbonnes::on_pushButton_Ajouter_clicked()
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
     QMessageBox msgbox ;
       if(CIN!=0 && TEL!=0 && AGE!=0 && NOM.size()>0 && PRENOM.size()>0 && EMAIL.size()>0 && SEXE.size()>0 && ADRESSE.size()>0 && NIVEAU_ETUDE.size()>0)
    {
           if((SEXE=="homme")||(SEXE=="femme"))
            {
               if(EMAIL.contains("@gmail.com")||EMAIL.contains("@yahoo.fr")||EMAIL.contains("@hotmail.com")||EMAIL.contains("@hotmail.fr"))
       {
                   bool test=A.Ajouter() ;
    if(test)
    {
        msgbox.setText("Ajout avec succes") ;
        ui->tab_Abonnes->setModel(A.Afficher()) ;
        ui->lineEdit_CIN->setText("");
        ui->lineEdit_TEL->setText("") ;
        ui->lineEdit_AGE->setText("") ;
        ui->lineEdit_NOM->setText("");
        ui->lineEdit_PRENOM->setText("") ;
        ui->lineEdit_EMAIL->setText("") ;
        ui->lineEdit_SEXE->setText("");
        ui->lineEdit_ADRESSE->setText("") ;
        ui->lineEdit_NIVEAUETUDE->setText("") ;

    }
    else {msgbox.setText("echec d'ajout : CIN EXISTE !!") ;}
         msgbox.exec() ;
        }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                QObject::tr("EMAIL INVALIDE.\n" "Click Cancel to exit."), QMessageBox::Cancel);
        }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                QObject::tr("SEXE INVALIDE (homme/femme).\n" "Click Cancel to exit."), QMessageBox::Cancel);
       }

    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                         QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);

}


void WindowAbonnes::on_pushButton_Supprimer_clicked()
{

    Abonne A1 ;
    QSqlQuery query ;
    A1.setCIN(ui->lineEdit_CIN_Suprrimer->text().toInt()) ;
    query.prepare("Select * from ABONNE WHERE CIN=:CIN ");
    query.bindValue(":CIN",A1.getCIN()) ;
    query.exec() ;
    bool alreadyExist = false;
        alreadyExist = query.next();
        if(alreadyExist)
        {

            bool test=A1.Supprimer(A1.getCIN()) ;
            QMessageBox msgbox ;
            if(test)
            {

                msgbox.setText("Suppresion avec succes") ;
                ui->tab_Abonnes->setModel(A.Afficher()) ;
                ui->lineEdit_CIN_Suprrimer->setText("");

            }
            else msgbox.setText("echec du suppression !!") ;
            msgbox.exec() ;

        }
      else
                     {
                         QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                         QObject::tr("CIN INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                     }

}

void WindowAbonnes::on_pushButton_Modifier_clicked()
{

    int CIN=ui->lineEdit_CIN_update->text().toInt() ;
    int TEL=ui->lineEdit_TEL_update->text().toInt() ;
    int AGE=ui->lineEdit_AGE_updtae->text().toInt() ;
    QString NOM=ui->lineEdit_NOM_update->text() ;
    QString PRENOM=ui->lineEdit_PRENOM_update->text() ;
    QString EMAIL=ui->lineEdit_EMAIL_update->text() ;
    QString SEXE=ui->lineEdit_SEXE_update->text() ;
    QString ADRESSE=ui->lineEdit_ADRESSE_update->text() ;
    QString NIVEAU_ETUDE=ui->lineEdit_NIVEAUETUDE_update->text() ;
    Abonne A(CIN,NOM,PRENOM,EMAIL,AGE,SEXE,ADRESSE,NIVEAU_ETUDE,TEL) ;
    QMessageBox msgbox ;
    if(CIN!=0 && TEL!=0 && AGE!=0 && NOM.size()>0 && PRENOM.size()>0 && EMAIL.size()>0 && SEXE.size()>0 && ADRESSE.size()>0 && NIVEAU_ETUDE.size()>0)
    {
        if((SEXE=="homme")||(SEXE=="femme")||(SEXE==""))
   {
            if(EMAIL.contains("@gmail.com")||EMAIL.contains("@yahoo.fr")||EMAIL.contains("@hotmail.com")||EMAIL.contains("@hotmail.fr"))
       {
                bool test=A.Modifier() ;
    if(test)
    {
        msgbox.setText("Modification avec succes") ;
        ui->tab_Abonnes->setModel(A.Afficher()) ;
        ui->lineEdit_CIN_update->setText("");
        ui->lineEdit_TEL_update->setText("") ;
        ui->lineEdit_AGE_updtae->setText("") ;
        ui->lineEdit_NOM_update->setText("");
        ui->lineEdit_PRENOM_update->setText("") ;
        ui->lineEdit_EMAIL_update->setText("") ;
        ui->lineEdit_SEXE_update->setText("");
        ui->lineEdit_ADRESSE_update->setText("") ;
        ui->lineEdit_NIVEAUETUDE_update->setText("") ;
    }
    else msgbox.setText("echec de modification !!") ;
    msgbox.exec() ;
    }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                QObject::tr("EMAIL INVALIDE.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                QObject::tr("SEXE INVALIDE (homme/femme).\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                      QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void WindowAbonnes::on_pushButton_Entrer_clicked()
{
    QSqlQuery query ;
    QString CIN=ui->lineEdit_CIN_update->text() ;
    query.prepare("Select * from ABONNE WHERE CIN=:CIN ");
    query.bindValue(":CIN",CIN) ;
    if(query.exec())
    {
        bool alreadyExist = false;
            alreadyExist = query.next();
            if(alreadyExist)
            {


   ui->lineEdit_NOM_update->setText(query.value(1).toString());
   ui->lineEdit_PRENOM_update->setText(query.value(2).toString());
   ui->lineEdit_EMAIL_update->setText(query.value(3).toString());
   ui->lineEdit_SEXE_update->setText(query.value(5).toString());
   ui->lineEdit_AGE_updtae->setText(query.value(4).toString());
   ui->lineEdit_ADRESSE_update->setText(query.value(6).toString());
   ui->lineEdit_NIVEAUETUDE_update->setText(query.value(7).toString());
   ui->lineEdit_TEL_update->setText(query.value(8).toString());

            }
          else
                         {
                             QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                             QObject::tr("CIN INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                         }

}

}


void WindowAbonnes::on_pushButton_changerPoste_clicked()
{
    ChoixAgent* ch=new ChoixAgent() ;
    ch->show() ;
}


void WindowAbonnes::on_pushButton_AnullerAjout_clicked()
{
    ui->lineEdit_CIN->setText("");
    ui->lineEdit_TEL->setText("") ;
    ui->lineEdit_AGE->setText("") ;
    ui->lineEdit_NOM->setText("");
    ui->lineEdit_PRENOM->setText("") ;
    ui->lineEdit_EMAIL->setText("") ;
    ui->lineEdit_SEXE->setText("");
    ui->lineEdit_ADRESSE->setText("") ;
    ui->lineEdit_NIVEAUETUDE->setText("") ;
}


void WindowAbonnes::on_pushButton_AnnulerSupp_clicked()
{
     ui->lineEdit_CIN_Suprrimer->setText("");
}


void WindowAbonnes::on_pushButton_AnnulerModifier_clicked()
{
    ui->lineEdit_CIN_update->setText("");
    ui->lineEdit_TEL_update->setText("") ;
    ui->lineEdit_AGE_updtae->setText("") ;
    ui->lineEdit_NOM_update->setText("");
    ui->lineEdit_PRENOM_update->setText("") ;
    ui->lineEdit_EMAIL_update->setText("") ;
    ui->lineEdit_SEXE_update->setText("");
    ui->lineEdit_ADRESSE_update->setText("") ;
    ui->lineEdit_NIVEAUETUDE_update->setText("") ;
}


void WindowAbonnes::on_pushButton_IMPRIME_clicked()
{
    QString strStream;
               QTextStream out(&strStream);

               const int rowCount = ui->tab_Abonnes->model()->rowCount();
               const int columnCount = ui->tab_Abonnes->model()->columnCount();

               out <<  "<html>\n"
                   "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   <<  QString("<title>%1</title>\n").arg("strTitle")
                   <<  "</head>\n"
                   "<body bgcolor=#ffffff link=#5000A0>\n"

                   //     "<align='right'> " << datefich << "</align>"
                   "<center> <H1>Liste Des ABONNES </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

               // headers
               out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
               for (int column = 0; column < columnCount; column++)
                   if (!ui->tab_Abonnes->isColumnHidden(column))
                       out << QString("<th>%1</th>").arg(ui->tab_Abonnes->model()->headerData(column, Qt::Horizontal).toString());
               out << "</tr></thead>\n";

               // data table
               for (int row = 0; row < rowCount; row++)
               {
                   out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                   for (int column = 0; column < columnCount; column++)
                   {
                       if (!ui->tab_Abonnes->isColumnHidden(column))
                       {
                           QString data = ui->tab_Abonnes->model()->data(ui->tab_Abonnes->model()->index(row, column)).toString().simplified();
                           out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                       }
                   }
                   out << "</tr>\n";
               }
               out <<  "</table> </center>\n"
                   "</body>\n"
                   "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
               if (QFileInfo(fileName).suffix().isEmpty())
               {
                   fileName.append(".pdf");
               }

               QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
}



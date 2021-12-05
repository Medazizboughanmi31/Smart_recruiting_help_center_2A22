#include "windowoffres.h"
#include "ui_windowoffres.h"
#include <qcombobox.h>
#include"offre.h"
#include<QDebug>
#include<QMessageBox>
#include <QTextEdit>
#include<QString>
#include<QFileDialog>
#include <QtGui>
#include <QtCore>
#include<QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QUrl>

WindowOffres::WindowOffres(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowOffres)
{
    ui->setupUi(this);
    ui->o_calendarWidget->showToday();
  ui->niveau->addItem("");
    ui->niveau->addItem("CAP","CAP");
    ui->niveau->addItem("BTP","BTP");
    ui->niveau->addItem("BTS","BTS");
    ui->niveau->addItem("BAC","BAC");
    QString ch;
    for(int i=1;i<6;i++){
        ch="BAC+"+QString::number(i);
        ui->niveau->addItem(ch,ch);
    }
 ui->experience->addItem("aucune expérience n'est requise",0);
  ui->experience->addItem("1 an",1);
   for(int i=2;i<6;i++) ui->experience->addItem(QString::number(i)+" ans",i);
   ui->niveau2->addItem("");
     ui->niveau2->addItem("CAP","CAP");
     ui->niveau2->addItem("BTP","BTP");
     ui->niveau2->addItem("BTS","BTS");
     ui->niveau2->addItem("BAC","BAC");
     for(int i=1;i<6;i++){
         ch="BAC+"+QString::number(i);
         ui->niveau2->addItem(ch,ch);
     }
  ui->experience2->addItem("aucune expérience n'est requise",0);
   ui->experience2->addItem("1 an",1);
    for(int i=2;i<6;i++) ui->experience2->addItem(QString::number(i)+" ans",i);
 offre o;
  ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),"domaine"));
      ui->o_comboBox->addItem("","");
   ui->o_comboBox_7->addItems(o.recherche_id());
ui->o_pushButton_6->setDisabled(true);
ui->expire->setDisabled(true);
   ui->o_comboBox->addItems(o.recherche_id());
   ui->o_comboBox_2->addItems(o.find_societe());
  // QString select ="SELECT login from acount where login ='"+ui->lineEdit_2->text()+"'and password='"+ui->lineEdit_2->text()+"'";
ui->critere->addItem("domaine d'activite","domaine");
ui->critere->addItem("niveau d'etude","niveau");
o_stat();
}

WindowOffres::~WindowOffres()
{
    delete ui;
}
void WindowOffres::o_stat(){
    QSqlQuery q,q1;
    q.prepare("select count(id) , niveau from offre group by niveau;");
    q1.prepare("select count(id) from offre;");

    ui->o_progressBar_1->setValue(0);
    ui->o_progressBar_2->setValue(0);
    ui->o_progressBar_3->setValue(0);
    ui->o_progressBar_4->setValue(0);
    ui->o_progressBar_5->setValue(0);
    ui->o_progressBar_6->setValue(0);
    ui->o_progressBar_7->setValue(0);
    ui->o_progressBar_8->setValue(0);
    ui->o_progressBar_9->setValue(0);
    int total;
    if(q.exec())
    if(q1.exec()){
    q1.next();
    total=q1.value(0).toInt();
    while (q.next()) {
      if( q.value(1).toString().compare("CAP")==0)ui->o_progressBar_1->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BTP")==0)ui->o_progressBar_2->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BTS")==0)ui->o_progressBar_3->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BAC")==0)ui->o_progressBar_4->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BAC+1")==0)ui->o_progressBar_5->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BAC+2")==0)ui->o_progressBar_6->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BAC+3")==0)ui->o_progressBar_7->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BAC+4")==0)ui->o_progressBar_8->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("BAC+5")==0)ui->o_progressBar_9->setValue(q.value(0).toInt()*100/total);
        }}
}
void WindowOffres::on_o_pushButton_6_clicked()
{
   QMessageBox::StandardButton test=QMessageBox::question(this,"suppresion","esque vous ete sure de supprimer cette offre ?");
if (test== QMessageBox::Yes ){
offre o;
if(ui->o_comboBox->currentText()!=""){
bool test=o.supprimer(ui->o_comboBox->currentText().toInt());
if(test)
{
QMessageBox::information(nullptr,QObject::tr("OK"),
                         QObject::tr("suppression effectué \n click cancel to exit"),QMessageBox::Cancel) ;

  ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));
  ui->o_comboBox_7->clear();
  ui->o_comboBox_7->addItems(o.recherche_id());

  ui->o_comboBox->clear();
  ui->o_comboBox->addItem("","");
  ui->o_comboBox->addItems(o.recherche_id());
  o_stat();
}
else   QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("suppression non effectué \n click cancel to exit"),QMessageBox::Cancel) ;

}else{
    QMessageBox::warning(this,"suppresion","imposible de supprimer");

}
}


}
void WindowOffres::on_submit_clicked()
{
    QSqlQuery q;
    q.prepare("select id_s from societe where nom_s='"+ui->o_comboBox_2->currentText()+"';");
    q.exec();
    q.next();
    int s1=q.value(0).toInt();
    societes=QString::number(s1);
      QString domaine=ui->domaine->text();
      QString competance=ui->competance->toPlainText();
      QString niveau=ui->niveau->itemData(ui->niveau->currentIndex()).toString();
int id=0;

      QDate date =ui->dat->date();
          int experience =ui->experience->itemData(ui->experience->currentIndex()).toInt() ;
         int nheurs=ui->njconge->value();
         char sexe;
      if(ui->o_radioButton->isChecked()){
        sexe='o';
      }
      if(ui->o_radioButton_2->isChecked()){
        sexe='f';
      }
      if(ui->o_radioButton_3->isChecked()){
            sexe='h';
      }
      int age=ui->age->value();
    int salaire=ui->salaire->value();
    int njconge=ui->o_spinBox->value();
    offre o(id,date,domaine,competance,niveau,experience,nheurs,sexe,age,salaire,njconge,'o');
    bool test=true;
    test=o.ajouter(societes) ;

          if(test)
          {
          QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("ajout effectué \n click cancel to exit"),QMessageBox::Cancel) ;

            ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));
            ui->o_comboBox_7->clear();
            ui->o_comboBox_7->addItems(o.recherche_id());
            ui->o_comboBox->clear();
            ui->o_comboBox->addItem("","");
            ui->o_comboBox->addItems(o.recherche_id());
            ui->domaine->setText("");
            ui->o_comboBox_2->clear();
            ui->o_comboBox_2->addItems(o.find_societe());
            o_stat();
         //     ui->tab_Abonnes->setModel(A.Afficher()) ;


          }
          else   QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                          QObject::tr("Echec d'ajout \n click cancel to exit"),QMessageBox::Cancel) ;

}



void WindowOffres::on_o_comboBox_7_currentIndexChanged(const QString &arg1)
{
    offre o(ui->o_comboBox_7->currentText().toInt());
    QSqlQuery query;
query.prepare("Select * from offre WHERE ID=?;");
    query.addBindValue(o.get_id());
    if(query.exec()){
        while (query.next()) {
            ui->domaine2->setText(query.value(2).toString());
            ui->competance2->setPlainText(query.value(3).toString());
            ui->niveau2->setCurrentText(query.value(4).toString());
            ui->experience2->setCurrentIndex(query.value(5).toInt());
            ui->nheures2->setValue(query.value(6).toInt());
            ui->age2->setValue(query.value(8).toInt());
            ui->salaire2->setValue(query.value(9).toInt());
            ui->njconge2->setValue(query.value(10).toInt());
        }
    }
    }


void WindowOffres::on_o_pushButton_3_clicked()
{
    offre o;
    o.set_id(ui->o_comboBox_7->currentText().toInt());
    o.set_domaine(ui->domaine2->text());
    o.set_competance(ui->competance2->toPlainText());

    o.set_niveau(ui->niveau2->itemData(ui->niveau2->currentIndex()).toString());
    o.set_experience(ui->experience2->itemData(ui->experience2->currentIndex()).toInt() );
    o.set_NHeures(ui->nheures2->value());
    o.set_age_max(ui->age2->value());
    o.set_salaire(ui->salaire2->value());
    o.set_NJconge(ui->njconge2->value());
    if(ui->o_radioButton_7->isChecked()){
      o.set_sexe('o');
    }
    if(ui->o_radioButton_6->isChecked()){
      o.set_sexe('f');
    }
    if(ui->o_radioButton_5->isChecked()){
        o.set_sexe('h');
    }
    bool test=o.modifier();
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("mise a jour effectué \n click cancel to exit"),QMessageBox::Cancel) ;

      ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));
o_stat();
    }
    else   QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                    QObject::tr("mise a jour non effectué \n click cancel to exit"),QMessageBox::Cancel) ;

}


void WindowOffres::on_recherche_cursorPositionChanged(int arg1, int arg2)
{offre o;
     ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));
}


void WindowOffres::on_o_checkBox_clicked()
{ offre o;
    ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));

}

void WindowOffres::on_expire_clicked()
{
    offre o;
    if(ui->o_comboBox->currentText()!=""){
    bool test=o.expirer(ui->o_comboBox->currentText().toInt());
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("relancement effectué\n click cancel to exit"),QMessageBox::Cancel) ;

      ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));
      ui->o_comboBox_7->clear();
      ui->o_comboBox_7->addItems(o.recherche_id());
      ui->o_comboBox->clear();
      ui->o_comboBox->addItem("","");
      ui->o_comboBox->addItems(o.recherche_id());
      ui->o_comboBox_2->clear();
      ui->o_comboBox_2->addItems(o.find_societe());
      o_stat();
    }
    else{   QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("expiration effectué\n click cancel to exit"),QMessageBox::Cancel) ;

        ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));
        ui->o_comboBox_7->clear();
        ui->o_comboBox_7->addItems(o.recherche_id());
        ui->o_comboBox->clear();
        ui->o_comboBox->addItem("","");
        ui->o_comboBox->addItems(o.recherche_id());
        ui->o_comboBox_2->clear();
        ui->o_comboBox_2->addItems(o.find_societe());
        o_stat();

    }
    }else{
        QMessageBox::warning(this,"suppresion","imposible de supprimer");

    }
    }


void WindowOffres::on_o_comboBox_currentIndexChanged(int index)
{
    if (index !=0){
        ui->o_pushButton_6->setEnabled(true);
        ui->expire->setEnabled(true);
}else
    {

        ui->o_pushButton_6->setDisabled(true);
        ui->expire->setDisabled(true);
    }
}

void WindowOffres::on_recherche_c_clicked()
{
  QString  domaine=ui->conseil_le->text();
  QSqlQuery q;//,salaire*(24-nheures)+(salaire*njconge)/30   //domaine,ID_ENTREPRISE,COMPETANCE,niveau,salaire,njconge,sexe
  if(domaine.length()==0)
      q.prepare("select offre.domaine,societe.NOM_S,offre.COMPETANCE,offre.niveau,offre.salaire,offre.njconge,offre.nheures,offre.sexe,offre.salaire*(24-offre.nheures)+(offre.salaire*offre.njconge)/30 as k from offre, societe where offre.etat = 'o' and offre.ID_ENTREPRISE=societe.id_s order by k desc;");
  else
      q.prepare("select offre.domaine,societe.NOM_S,offre.COMPETANCE,offre.niveau,offre.salaire,offre.njconge,offre.nheures,offre.sexe,offre.salaire*(24-offre.nheures)+(offre.salaire*offre.njconge)/30 as k from offre, societe where offre.etat = 'o' and offre.domaine like '%"+domaine+"%'and offre.ID_ENTREPRISE=societe.id_s order by k desc;");
//q.prepare("Select * from offre where domaine like '%"+domaine+"%';");
  if(q.exec()){
 if( q.size()!=0){
q.next();
 ui->conseil_le->setText(q.value(0).toString());
 ui->c1->setText(q.value(1).toString());
 ui->c2->setText(q.value(2).toString());
 ui->c3->setText(q.value(3).toString());
 ui->c4->setText(q.value(4).toString());
 ui->c5->setText(q.value(5).toString());
 ui->c6->setText(q.value(6).toString());

 if (q.value(7).toString()=="o")
 ui->c7->setText("n'inport quelle sexe");
 else if(q.value(7).toString()=="f")

     ui->c7->setText("femme");
 else
  ui->c7->setText("homme");
 }
}else QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                            QObject::tr("fermer\n click cancel to exit"),QMessageBox::Cancel) ;

}

void WindowOffres::on_o_comboBox_2_currentTextChanged(const QString &arg1)
{


}

void WindowOffres::on_critere_currentIndexChanged(const QString &arg1)
{ offre o;
    ui->o_tableView->setModel(o.afficher(ui->recherche->text(),ui->o_checkBox->isChecked(),ui->critere->currentData().toString()));

}

void WindowOffres::on_o_pushButton_clicked()

    {
    QString strStream;
                   QTextStream out(&strStream);

                   const int rowCount = ui->o_tableView->model()->rowCount();
                   const int columnCount = ui->o_tableView->model()->columnCount();

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
                       if (!ui->o_tableView->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->o_tableView->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   // data table
                   for (int row = 0; row < rowCount; row++)
                   {
                       out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                       for (int column = 0; column < columnCount; column++)
                       {
                           if (!ui->o_tableView->isColumnHidden(column))
                           {
                               QString data = ui->o_tableView->model()->data(ui->o_tableView->model()->index(row, column)).toString().simplified();
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


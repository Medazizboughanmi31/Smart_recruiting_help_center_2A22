#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_connnect.h"
#include <QSystemTrayIcon>
#include <QtDebug>
#include <QObject>
#include<QMessageBox>
#include<QtPrintSupport/QPrinter>
#include<QFileDialog>
#include<QTextDocument>
#include<QIntValidator>
#include<QValidator>
#include<QPdfWriter>
#include<QPainter>
#include <QTextEdit>
#include<QPrinter>
#include<QPrintDialog>
#include<entreprise.h>
#include<excel.h>
#include<notification.h>
#include <QDesktopServices>

#include <QUrl>
#include <src/src/SmtpMime>
#include <QtNetwork>
#include <QFile>
#include<QCompleter>
#include <mailsmtp.h>
//#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
   ui->lineEdit->setValidator(valiNom); // A CHANGER 5TR LZMU YKOUN ENTIER MOCH STRING
    ui->lineEdit_2->setValidator(valiNom);
    ui->lineEdit_3->setValidator(valiNom);
    ui->lineEdit_4->setValidator(valiNom); // A CHANGER BCH YWALI STYLE MAIL
    ui->lineEdit_5->setValidator(valiNom);*/


    ui->tableView->setModel(tempentreprise.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    {    notification n;


        QString  id=ui->lineEdit->text();
        QString nom=ui->lineEdit_2->text();
        QString adresse=ui->lineEdit_3->text();
        QString mail=ui->lineEdit_4->text();
        QString tel=ui->lineEdit_5->text();
        QString fax=ui->lineEdit_6->text();

        entreprise f(id,nom,adresse,mail,tel,fax);

        bool test=f.ajouter();
        if(test)
        {
            n.setPopupText("entreprise a été ajouté");
                    n.show();


            ui->tableView->setModel(tempentreprise.afficher());
            QMessageBox::information(nullptr,QObject::tr("Ajout"),
                                     QObject::tr("Ajout avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);

      }
        else
        {

           QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                     QObject::tr("Ajout echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{    notification n;

    QString  id=ui->lineEdit->text();
       QString nom=ui->lineEdit_2->text();
       QString adresse=ui->lineEdit_3->text();
       QString mail=ui->lineEdit_4->text();
       QString tel=ui->lineEdit_5->text();
       QString fax=ui->lineEdit_6->text();

       entreprise f(id,nom,adresse,mail,tel,fax);

bool test=f.modifier(id);
    if(test)
    {
        n.setPopupText("entreprise a été modif");
                n.show();


        ui->tableView->setModel(tempentreprise.afficher());
        QMessageBox::information(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);



  }
    else
        QMessageBox::critical(nullptr,QObject::tr("modifier"),
                                 QObject::tr("modifier echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
}




void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from entreprise where id LIKE '"+id+"%' or nom LIKE '"+id+"%'  or adresse LIKE '"+id+"%' or mail LIKE '"+id+"%' or tel LIKE '"+id+"%'or fax LIKE '"+id+"%'");
          if(query.exec())
          {
            while(query.next())
            {
                ui->lineEdit->setText(query.value(0).toString());
                ui->lineEdit_2->setText(query.value(1).toString());
                ui->lineEdit_3->setText(query.value(2).toString());
                ui->lineEdit_4->setText(query.value(3).toString());
                ui->lineEdit_5->setText(query.value(4).toString());
                ui->lineEdit_6->setText(query.value(4).toString());


            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}


void MainWindow::on_pushButton_3_clicked()
{notification n;
    QString id=ui->lineEdit->text();
    bool test=tempentreprise.supprimer(id);
    if(test){

        n.setPopupText("entreprise a été suppr");
                n.show();
        ui->tableView->setModel(tempentreprise.afficher());
        QMessageBox::information(nullptr,QObject::tr("suppression"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                 QObject::tr("suppression echoue.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(tempentreprise.trier());

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView->setModel(tempentreprise.trierdec());

}

void MainWindow::on_pushButton_6_clicked()
{
    QString id =ui->lineEdit_7->text();
       ui->tableView->setModel(tempentreprise.recherche(id));
}

void MainWindow::on_pushButton_7_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
       QDesktopServices::openUrl(link);
}


/* void MainWindow::on_pushButton_9_clicked()
{
    QString strStream;
                  QTextStream out(&strStream);

                  const int rowCount = ui->table_produit->model()->rowCount();
                  const int columnCount = ui->table_produit->model()->columnCount();

                  out <<  "<html>\n"
                      "<head>\n"
                      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      <<  QString("<title>%1</title>\n").arg("strTitle")
                      <<  "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"

                     //     "<align='right'> " << datefich << "</align>"
                      "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                  // headers
                  out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->table_produit->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->table_produit->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->table_produit->isColumnHidden(column)) {
                              QString data = ui->table_produit->model()->data(ui->table_produit->model()->index(row, column)).toString().simplified();
                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                      }
                      out << "</tr>\n";
                  }
                  out <<  "</table> </center>\n"
                      "</body>\n"
                      "</html>\n";

            QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
              if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

             QPrinter printer (QPrinter::PrinterResolution);
              printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);

             QTextDocument doc;
              doc.setHtml(strStream);
              doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
              doc.print(&printer);
}

void MainWindow:: on_pushButton_10_clicked()
{

    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->text(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->text());
}


void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


*/

void MainWindow::on_pushButton_11_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                               tr("Excel Files (*.xls)"));
               if (fileName.isEmpty())
                   return;

               ExportExcelObject obj(fileName, "mydata", ui->tableView);

               obj.addField(0, "colum1", "char(20)");
               obj.addField(1, "colum2", "char(20)");
               obj.addField(2, "colum3", "char(20)");
               obj.addField(3, "colum4", "char(20)");
               obj.addField(4, "colum5", "char(20)");
               obj.addField(5, "colum6", "char(20)");


               int retVal = obj.export2Excel();

               if( retVal > 0)
               {
                   QMessageBox::information(this, tr("Done"),
                                            QString(tr("cin exported!")).arg(retVal)
                                            );
               }
}

void MainWindow::on_pushButton_12_clicked()
{
    QPdfWriter pdf("C:/Users/Rim Dammak/Documents/rimproject/pdfdocumentcin.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::darkGray);
                          painter.setFont(QFont("Roboto", 25));
                          painter.drawText(950,1100,"Liste Des entreprises");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 20));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"id");
                          painter.drawText(1200,3300,"nom");
                          painter.drawText(2600,3300,"adresse");
                          painter.drawText(4000,3300,"mail");
                          painter.drawText(5400,3300,"tel");
                          painter.drawText(7000,3300,"fax");

                          QSqlQuery query;
                          query.prepare("select * from entreprise");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2600,i,query.value(2).toString());
                              painter.drawText(3900,i,query.value(3).toString());
                              painter.drawText(5500,i,query.value(4).toString());
                              painter.drawText(6900,i,query.value(5).toString());





                             i = i + 500;
                          }
}

void MainWindow::on_pushButton_10_clicked()
{
    QPrinter rd;
       QPrintDialog d(&rd,this);
       d.setWindowTitle("imprimer entreprise");
       d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
       if(d.exec()!=QDialog::Accepted)
           return;

}

void MainWindow::on_pushButton_13_clicked()
{

}

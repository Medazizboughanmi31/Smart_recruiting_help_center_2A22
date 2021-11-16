#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include "loggingin.h"
#include <QMessageBox>
#include "choixagent.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;


    bool test=c.createconnect();
    //MainWindow w;
   // w.show();
    //LoggingIN L ;
  //  L.show();
    ChoixAgent ch ;
    ch.show() ;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}

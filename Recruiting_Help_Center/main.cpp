#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include "loggingin.h"
#include <QMessageBox>
#include "choixagent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {
         w.show();
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


<<<<<<< HEAD:main.cpp
    e.notifcation();

    
   return a.exec();
}
=======
>>>>>>> d3dc43c6ce113ff5d61d94d07e1b01b1a4f581d4:Recruiting_Help_Center/main.cpp

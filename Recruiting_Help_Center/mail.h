#ifndef MAIL_H
#define MAIL_H

#include<QString>
#include<QSqlQueryModel>

class mail
{
public:
    mail();
mail(QString a,QString b,QString d);
bool envoyer();


private :
    QString des;
    QString ob;
    QString description;



};

#endif // MAIL_H

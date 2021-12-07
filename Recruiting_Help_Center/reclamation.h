#ifndef RECLAMATION_H
#define RECLAMATION_H

#include<QSqlQueryModel>
#include<QString>
class reclamation
{
public:
    reclamation();
    reclamation(QString a,QString b);
    bool envoyer_rec();





private:
    QString centre_des;
    QString rec_des;
};

#endif // RECLAMATION_H

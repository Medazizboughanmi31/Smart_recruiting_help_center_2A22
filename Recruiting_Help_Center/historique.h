#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class historique
{
private:
    QString operation;

public:
    historique();
    historique(QString);
    void Ajouter();
    QSqlQueryModel * Afficher( );

};

#endif // HISTORIQUE_H

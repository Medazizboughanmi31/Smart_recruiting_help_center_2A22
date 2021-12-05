#ifndef GESTION_H
#define GESTION_H

#include <QDialog>
#include<QIntValidator>
#include<QString>
#include<QMessageBox>
#include <QRegularExpressionValidator>
#include "abonne.h"
#include "choixagent.h"

namespace Ui {
class Gestion;
}

class Gestion : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion(QWidget *parent = nullptr);
    ~Gestion();

private slots:


    void on_pushButton_changePoste_clicked();

    void on_pushButton_changeCompte_clicked();




    void on_lineEdit_Preference_textChanged(const QString &arg1);

    void on_radioButton_AGEASC_clicked();

    void on_radioButton_AGEDESC_clicked();

    void on_radioButton_ETUDEASC_clicked();

    void on_radioButton_ETUDEDESC_clicked();

    void on_radioButton_Nom_clicked();


    void on_pushButton_EnvoyerReclamation_clicked();

    void on_pushButton_AnnulerRec_clicked();






private:
    Ui::Gestion *ui;
};

#endif // GESTION_H

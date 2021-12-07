#ifndef WINDOWPUBLICATIONS_H
#define WINDOWPUBLICATIONS_H

#include <QDialog>
#include "publication.h"



namespace Ui {
class WindowPublications;
}

class WindowPublications : public QDialog
{
    Q_OBJECT

public:
    explicit WindowPublications(QWidget *parent = nullptr);
    ~WindowPublications();

private slots:



    void on_pub_pb_supprimer_clicked();

    void on_pub_pb_modifier_clicked();

    void on_pub_pushButton_2_clicked();


    //void on_publier_clicked();

    //void on_envoyer_mail_clicked();

    void on_pub_Ajouter_clicked();


    void on_pub_envoyer_mail_2_clicked();

    void on_trier_pub_clicked();

private:
    Ui::WindowPublications *ui;
    publication p;


};

#endif // WindowPublications_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "publication.h"
#include "arduino.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void update_label();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_2_clicked();


    //void on_publier_clicked();

    //void on_envoyer_mail_clicked();

    void on_Ajouter_clicked();


    void on_envoyer_mail_2_clicked();

    void on_trier_pub_clicked();

    //void on_Ajouter_pub_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    publication p;
    QByteArray data; // variable contenant les données reçues
      arduino A; // objet temporaire

};

#endif // MAINWINDOW_H

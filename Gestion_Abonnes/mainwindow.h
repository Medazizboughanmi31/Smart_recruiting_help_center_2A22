#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QIntValidator>
#include<QString>
#include<QMessageBox>
#include <QRegularExpressionValidator>
#include "abonne.h"
#include "choixagent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_Modifier_clicked();



    void on_pushButton_Entrer_clicked();

    void on_pushButton_changerPoste_clicked();

    void on_pushButton_AnullerAjout_clicked();

    void on_pushButton_AnnulerSupp_clicked();

    void on_pushButton_AnnulerModifier_clicked();

    void on_pushButton_IMPRIME_clicked();

private:
    Ui::MainWindow *ui;
    Abonne A ;
};
#endif // MAINWINDOW_H

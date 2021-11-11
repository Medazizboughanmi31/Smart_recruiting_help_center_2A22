#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include "entretien.h"
#include <QMainWindow>
#include <QMessageBox>


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


    void on_ajouter_clicked();


    void on_offre_A_textChanged(const QString &arg1);

    void on_num_A_textChanged(const QString &arg1);

    void on_Supprimer_clicked();


    void on_num_r_clicked();

    void on_modifier_clicked();

private:
    Ui::MainWindow *ui;
    entretien E;
};
#endif // MAINWINDOW_H

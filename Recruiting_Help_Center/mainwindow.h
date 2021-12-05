#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "choixagent.h"
#include "windowoffres.h"
#include "windowentretiens.h"
#include "windowcentres.h"
#include "windowpublications.h"
#include "windowentreprises.h"

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
    void on_pushButton_GestionAbonnes_clicked();

    void on_pushButton_GestionOffres_clicked();

    void on_pushButton_GestionEntretiens_clicked();

    void on_pushButton_GestionCentres_clicked();

    void on_pushButton_GestionPublications_clicked();

    void on_pushButton_GestionEntreprises_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

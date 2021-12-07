#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include "entretien.h"
#include "historique.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include"arduino.h"
#include <QPainter>

QT_CHARTS_USE_NAMESPACE
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

    void on_ent_ajouter_clicked();


    void on_ent_offre_A_textChanged(const QString &arg1);

    void on_ent_num_A_textChanged(const QString &arg2);

    void on_ent_Supprimer_clicked();


    void on_ent_num_r_clicked();

    void on_ent_modifier_clicked();
    void stat();

    void on_ent_email_clicked();

private:
    Ui::MainWindow *ui;
    entretien E;
    historique H;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H

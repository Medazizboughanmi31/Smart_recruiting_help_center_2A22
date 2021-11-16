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


    void on_ajouter_clicked();


    void on_offre_A_textChanged(const QString &arg1);

    void on_num_A_textChanged(const QString &arg2);

    void on_Supprimer_clicked();


    void on_num_r_clicked();

    void on_modifier_clicked();
    void stat();




    void on_comboBoxStat_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    entretien E;
    historique H;
};
#endif // MAINWINDOW_H

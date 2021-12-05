#ifndef WINDOWABONNES_H
#define WINDOWABONNES_H
#include <QDialog>
#include<QIntValidator>
#include<QString>
#include<QMessageBox>
#include <QRegularExpressionValidator>
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
#include "abonne.h"
#include "choixagent.h"



QT_BEGIN_NAMESPACE
namespace Ui { class WindowAbonnes; }
QT_END_NAMESPACE

class WindowAbonnes : public QDialog
{
    Q_OBJECT

public:
    WindowAbonnes(QWidget *parent = nullptr);
    ~WindowAbonnes();

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
    Ui::WindowAbonnes *ui;

    Abonne A ;
};
#endif // WindowAbonnes_H


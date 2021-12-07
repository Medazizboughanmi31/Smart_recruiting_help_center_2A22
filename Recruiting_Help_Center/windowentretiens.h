#ifndef WINDOWENTRETIENS_H
#define WINDOWENTRETIENS_H

#include <QDialog>
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
#include "entretien.h"
#include "historique.h"

QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class WindowEntretiens; }
QT_END_NAMESPACE

class WindowEntretiens : public QDialog
{
    Q_OBJECT

public:
    WindowEntretiens(QWidget *parent = nullptr);
    ~WindowEntretiens();

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
    Ui::WindowEntretiens *ui;
    entretien E;
    historique H;

};
#endif // WindowEntretiens_H

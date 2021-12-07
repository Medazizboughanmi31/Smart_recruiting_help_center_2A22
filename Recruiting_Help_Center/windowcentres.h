#ifndef WINDOWCENTRES_H
#define WINDOWCENTRES_H

#include <QDialog>

#include"centre.h"
#include"reclamation.h"
#include <QVariant>
QT_BEGIN_NAMESPACE
namespace Ui { class WindowCentres; }
QT_END_NAMESPACE

class WindowCentres : public QDialog
{
    Q_OBJECT

public:
    WindowCentres(QWidget *parent = nullptr);
    ~WindowCentres();

private:
    Ui::WindowCentres *ui;
signals:
    void setCenter(QVariant, QVariant);

private slots:
    void on_c_pb_ajouter_clicked();
    void on_c_pushButton_clicked();
    void on_c_pushButton_2_clicked();

    void on_c_pushButton_4_clicked();

    void on_c_pushButton_3_clicked();

    void on_c_pb_chercher_clicked();

    void on_p_envoyer_5_clicked();

    void on_c_pb_reclamation_5_clicked();

    void on_c_chercher2_clicked();

private:
    centre c;
    reclamation r;

};

#endif // WINDOWCENTRES_H

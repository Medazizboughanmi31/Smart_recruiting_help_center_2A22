#ifndef WINDOWOFFRES_H
#define WINDOWOFFRES_H

#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class WindowOffres; }
QT_END_NAMESPACE

class WindowOffres : public QDialog
{
    Q_OBJECT

public:
    WindowOffres(QWidget *parent = nullptr);
    ~WindowOffres();

 QString societes;
private slots:


    void on_o_pushButton_clicked();

    void on_o_pushButton_6_clicked();

    void on_submit_clicked();


    void on_o_comboBox_7_currentIndexChanged(const QString &arg1);

    void on_o_pushButton_3_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_o_checkBox_clicked();

    void on_expire_clicked();

    void on_o_comboBox_currentIndexChanged(int index);

    void on_recherche_c_clicked();


    void on_o_comboBox_2_currentTextChanged(const QString &arg1);
    void o_stat();
    void on_critere_currentIndexChanged(const QString &arg1);

private:
    Ui::WindowOffres *ui;


};
#endif // WindowOffres_H

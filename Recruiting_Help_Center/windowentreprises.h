#ifndef WINDOWENTREPRISES_H
#define WINDOWENTREPRISES_H

#include <QDialog>
#include "entreprise.h"
#include<QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowEntreprises; }
QT_END_NAMESPACE

class WindowEntreprises : public QDialog
{
    Q_OBJECT

public:
    WindowEntreprises(QWidget *parent = nullptr);
    ~WindowEntreprises();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();




private:
    Ui::WindowEntreprises *ui;
    entreprise tempentreprise;
};
#endif // WindowEntreprises_H

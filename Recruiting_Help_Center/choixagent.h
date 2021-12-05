#ifndef CHOIXAGENT_H
#define CHOIXAGENT_H

#include <QDialog>
#include "windowabonnes.h"
#include "loggingin.h"
#include "gestion.h"

namespace Ui {
class ChoixAgent;
}

class ChoixAgent : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixAgent(QWidget *parent = nullptr);
    ~ChoixAgent();

private slots:
    void on_pushButton_A_acceuil_clicked();

    void on_pushButton_Admin_clicked();

private:
    Ui::ChoixAgent *ui;
};

#endif // CHOIXAGENT_H

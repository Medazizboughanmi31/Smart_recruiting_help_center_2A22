#ifndef LOGGINGIN_H
#define LOGGINGIN_H


#include <QDialog>
#include<QSqlQuery>
#include<QMessageBox>
#include <QRegularExpressionValidator>

namespace Ui {
class LoggingIN;
}

class LoggingIN : public QDialog
{
    Q_OBJECT

public:
    explicit LoggingIN(QWidget *parent = nullptr);
    ~LoggingIN();

private slots:
    void on_pushButton_SeConnecter_clicked();

private:
    Ui::LoggingIN *ui;
};

#endif // LOGGINGIN_H

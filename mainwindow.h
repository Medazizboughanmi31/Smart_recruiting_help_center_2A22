#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<entreprise.h>
#include <QMainWindow>
#include<QPixmap>
#include <QMainWindow>


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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

   void on_pushButton_10_clicked();

   void sendMail();
   void mailSent(QString);
   void browse();

   void readyRead();

   // This function gets called when the socket tells us it's connected.
   void connected();


   void on_pushButton_11_clicked();

   void on_pushButton_12_clicked();

   void on_pushButton_13_clicked();

private:
    Ui::MainWindow *ui;
    entreprise tempentreprise;
};
#endif // MAINWINDOW_H

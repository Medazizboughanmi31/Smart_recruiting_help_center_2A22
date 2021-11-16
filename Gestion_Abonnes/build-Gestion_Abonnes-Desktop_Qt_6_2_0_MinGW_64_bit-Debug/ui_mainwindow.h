/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *CRUD;
    QTabWidget *tabWidget_2;
    QWidget *Ajout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_Ajouter;
    QLineEdit *lineEdit_NOM;
    QLineEdit *lineEdit_PRENOM;
    QLineEdit *lineEdit_CIN;
    QLineEdit *lineEdit_EMAIL;
    QLineEdit *lineEdit_AGE;
    QLineEdit *lineEdit_SEXE;
    QLineEdit *lineEdit_ADRESSE;
    QLineEdit *lineEdit_NIVEAUETUDE;
    QLineEdit *lineEdit_TEL;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *Affichage;
    QTableView *tab_Abonnes;
    QWidget *Suppression;
    QLineEdit *lineEdit_CIN_Suprrimer;
    QLabel *label_17;
    QPushButton *pushButton_Supprimer;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *widget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *Preference;
    QLabel *label_3;
    QComboBox *comboBox;
    QTableView *tab_preference;
    QWidget *Classification;
    QLabel *label_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QTableView *tab_classification;
    QWidget *Reclamation;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QTextEdit *textEdit;
    QWidget *Stastiques;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(50, 40, 691, 491));
        tabWidget->setMaximumSize(QSize(701, 491));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(100, 100));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        CRUD = new QWidget();
        CRUD->setObjectName(QString::fromUtf8("CRUD"));
        tabWidget_2 = new QTabWidget(CRUD);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 30, 681, 421));
        Ajout = new QWidget();
        Ajout->setObjectName(QString::fromUtf8("Ajout"));
        pushButton_5 = new QPushButton(Ajout);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(510, 320, 93, 28));
        pushButton_Ajouter = new QPushButton(Ajout);
        pushButton_Ajouter->setObjectName(QString::fromUtf8("pushButton_Ajouter"));
        pushButton_Ajouter->setGeometry(QRect(380, 320, 93, 28));
        lineEdit_NOM = new QLineEdit(Ajout);
        lineEdit_NOM->setObjectName(QString::fromUtf8("lineEdit_NOM"));
        lineEdit_NOM->setGeometry(QRect(70, 70, 113, 22));
        lineEdit_PRENOM = new QLineEdit(Ajout);
        lineEdit_PRENOM->setObjectName(QString::fromUtf8("lineEdit_PRENOM"));
        lineEdit_PRENOM->setGeometry(QRect(250, 70, 113, 22));
        lineEdit_CIN = new QLineEdit(Ajout);
        lineEdit_CIN->setObjectName(QString::fromUtf8("lineEdit_CIN"));
        lineEdit_CIN->setGeometry(QRect(420, 70, 113, 22));
        lineEdit_CIN->setMaxLength(8);
        lineEdit_EMAIL = new QLineEdit(Ajout);
        lineEdit_EMAIL->setObjectName(QString::fromUtf8("lineEdit_EMAIL"));
        lineEdit_EMAIL->setGeometry(QRect(70, 150, 113, 22));
        lineEdit_AGE = new QLineEdit(Ajout);
        lineEdit_AGE->setObjectName(QString::fromUtf8("lineEdit_AGE"));
        lineEdit_AGE->setGeometry(QRect(250, 150, 113, 22));
        lineEdit_SEXE = new QLineEdit(Ajout);
        lineEdit_SEXE->setObjectName(QString::fromUtf8("lineEdit_SEXE"));
        lineEdit_SEXE->setGeometry(QRect(420, 150, 113, 22));
        lineEdit_ADRESSE = new QLineEdit(Ajout);
        lineEdit_ADRESSE->setObjectName(QString::fromUtf8("lineEdit_ADRESSE"));
        lineEdit_ADRESSE->setGeometry(QRect(70, 230, 113, 22));
        lineEdit_NIVEAUETUDE = new QLineEdit(Ajout);
        lineEdit_NIVEAUETUDE->setObjectName(QString::fromUtf8("lineEdit_NIVEAUETUDE"));
        lineEdit_NIVEAUETUDE->setGeometry(QRect(250, 230, 113, 22));
        lineEdit_TEL = new QLineEdit(Ajout);
        lineEdit_TEL->setObjectName(QString::fromUtf8("lineEdit_TEL"));
        lineEdit_TEL->setGeometry(QRect(420, 230, 113, 22));
        label_8 = new QLabel(Ajout);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 40, 55, 16));
        label_9 = new QLabel(Ajout);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(250, 40, 55, 16));
        label_10 = new QLabel(Ajout);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(420, 40, 55, 16));
        label_11 = new QLabel(Ajout);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(70, 120, 55, 16));
        label_12 = new QLabel(Ajout);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(250, 120, 55, 16));
        label_13 = new QLabel(Ajout);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(420, 120, 55, 16));
        label_14 = new QLabel(Ajout);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(70, 200, 55, 16));
        label_15 = new QLabel(Ajout);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(260, 200, 101, 16));
        label_16 = new QLabel(Ajout);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(420, 200, 55, 16));
        tabWidget_2->addTab(Ajout, QString());
        Affichage = new QWidget();
        Affichage->setObjectName(QString::fromUtf8("Affichage"));
        tab_Abonnes = new QTableView(Affichage);
        tab_Abonnes->setObjectName(QString::fromUtf8("tab_Abonnes"));
        tab_Abonnes->setGeometry(QRect(20, 40, 621, 251));
        tabWidget_2->addTab(Affichage, QString());
        Suppression = new QWidget();
        Suppression->setObjectName(QString::fromUtf8("Suppression"));
        lineEdit_CIN_Suprrimer = new QLineEdit(Suppression);
        lineEdit_CIN_Suprrimer->setObjectName(QString::fromUtf8("lineEdit_CIN_Suprrimer"));
        lineEdit_CIN_Suprrimer->setGeometry(QRect(30, 90, 321, 41));
        label_17 = new QLabel(Suppression);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 40, 171, 41));
        label_17->setFrameShape(QFrame::NoFrame);
        label_17->setTextFormat(Qt::RichText);
        pushButton_Supprimer = new QPushButton(Suppression);
        pushButton_Supprimer->setObjectName(QString::fromUtf8("pushButton_Supprimer"));
        pushButton_Supprimer->setGeometry(QRect(410, 250, 93, 28));
        pushButton_9 = new QPushButton(Suppression);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(540, 250, 93, 28));
        pushButton_10 = new QPushButton(Suppression);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(20, 340, 91, 28));
        tabWidget_2->addTab(Suppression, QString());
        tabWidget->addTab(CRUD, QString());
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 150, 321, 41));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 260, 321, 41));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 215, 91, 31));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 95, 171, 41));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setTextFormat(Qt::RichText);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 330, 121, 28));
        tabWidget->addTab(widget, QString());
        Preference = new QWidget();
        Preference->setObjectName(QString::fromUtf8("Preference"));
        label_3 = new QLabel(Preference);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 30, 171, 41));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setTextFormat(Qt::RichText);
        comboBox = new QComboBox(Preference);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 70, 281, 31));
        tab_preference = new QTableView(Preference);
        tab_preference->setObjectName(QString::fromUtf8("tab_preference"));
        tab_preference->setGeometry(QRect(40, 180, 621, 251));
        tabWidget->addTab(Preference, QString());
        Classification = new QWidget();
        Classification->setObjectName(QString::fromUtf8("Classification"));
        label_5 = new QLabel(Classification);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 40, 171, 41));
        label_5->setFrameShape(QFrame::NoFrame);
        label_5->setTextFormat(Qt::RichText);
        radioButton = new QRadioButton(Classification);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(150, 50, 251, 21));
        radioButton_2 = new QRadioButton(Classification);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(150, 90, 261, 21));
        radioButton_3 = new QRadioButton(Classification);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(150, 130, 191, 21));
        tab_classification = new QTableView(Classification);
        tab_classification->setObjectName(QString::fromUtf8("tab_classification"));
        tab_classification->setGeometry(QRect(30, 180, 621, 251));
        tabWidget->addTab(Classification, QString());
        Reclamation = new QWidget();
        Reclamation->setObjectName(QString::fromUtf8("Reclamation"));
        pushButton_2 = new QPushButton(Reclamation);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 380, 121, 28));
        pushButton_3 = new QPushButton(Reclamation);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 380, 121, 28));
        label_4 = new QLabel(Reclamation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 50, 201, 41));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setTextFormat(Qt::RichText);
        textEdit = new QTextEdit(Reclamation);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 116, 601, 231));
        tabWidget->addTab(Reclamation, QString());
        Stastiques = new QWidget();
        Stastiques->setObjectName(QString::fromUtf8("Stastiques"));
        progressBar = new QProgressBar(Stastiques);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(80, 120, 231, 31));
        progressBar->setValue(24);
        progressBar_2 = new QProgressBar(Stastiques);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(80, 260, 231, 31));
        progressBar_2->setValue(24);
        label_6 = new QLabel(Stastiques);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 60, 171, 41));
        label_6->setFrameShape(QFrame::NoFrame);
        label_6->setTextFormat(Qt::RichText);
        label_7 = new QLabel(Stastiques);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(80, 200, 171, 41));
        label_7->setFrameShape(QFrame::NoFrame);
        label_7->setTextFormat(Qt::RichText);
        pushButton_4 = new QPushButton(Stastiques);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 387, 151, 31));
        tabWidget->addTab(Stastiques, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion Des abonn\303\251s", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_Ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "PRENOM", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "AGE", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "SEXE", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "ADRESSE", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "NIVEAU D'ETUDE", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "TEL", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Ajout), QCoreApplication::translate("MainWindow", "Ajout", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Affichage), QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "CIN ", nullptr));
        pushButton_Supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Mettre a jour", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Suppression), QCoreApplication::translate("MainWindow", "Suppression", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CRUD), QCoreApplication::translate("MainWindow", "CRUD", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom d'utilisateur", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Se connecter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "Logging In", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Crit\303\250re de recherche", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Age", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Sexe", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Niveau d'etude", nullptr));

        comboBox->setCurrentText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Preference), QCoreApplication::translate("MainWindow", "Preference", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Classer Selon : ", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Ordre Alphabitique croissant des noms", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Ordre Alphabitique d\303\251croissant des noms", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Date d'ajout", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Classification), QCoreApplication::translate("MainWindow", "Classification", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ecrire la reclamation ci-desous", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Reclamation), QCoreApplication::translate("MainWindow", "Reclamation", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Abonn\303\251s Admis :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Abonn\303\251s Rejet\303\251s :", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Mettre \303\240 jour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Stastiques), QCoreApplication::translate("MainWindow", "Stastiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

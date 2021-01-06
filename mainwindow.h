#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "string"
#include <QMainWindow>
#include "classe_personnel.h"
#include"class_services.h"
#include "materiels.h"
#include "entretien.h"
#include "patient.h"
#include "rendezvous.h"
#include <stock.h>
#include <fournisseur.h>
#include <QSound>
#include<QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include<QWidget>
#include<dialog.h>
#include<dialog2.h>
#include<dialog3.h>
#include "string"
#include<stat_ressource.h>
#include<scanner.h>
#include<ressource.h>
#include<QSound>
#include<QWidget>
#include<fournisseur1.h>
#include<capture.h>
#include<image.h>
#include<notification.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setid(QString);
    void setmdp(QString);
    QString getid();
    QString getmdp();
    void init_scan();
    void init_fournisseur();
    void init_ressource();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_66_clicked();

    void on_pushButton_68_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_71_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_54_clicked();

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_Materiels_Rechercher_clicked();

    void on_pushButton_Materiels_Trier_clicked();

    void on_pushButton_Materiels_Afficher_clicked();

    void on_pushButton_Materiels_PDF_clicked();

    void on_pushButton_Entretien_Ajouter_clicked();

    void on_pushButton_Entretien_Supprimer_clicked();

    void on_pushButton_Entretien_Modifier_clicked();

    void on_pushButton_Entretien_Rechercher_clicked();

    void on_pushButton_Entretien_Afficher_clicked();

    void on_pushButton_Entretien_PDF_clicked();

    void on_pushButton_Entretien_Trier_clicked();

    void on_pushButton_LoadList_Materiels_clicked();

    void on_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_Ajouter2_clicked();

    void on_pushButton_Supprimer2_clicked();

    void on_pushButton_Chercher2_clicked();

    void on_pushButton_Modifier2_clicked();

    void on_pushButton_41_clicked();
    int getselectedpatient();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_58_clicked();



     void on_pushButton_870_clicked();

     void on_pushButton_750_clicked();

     void on_pushButton_880_clicked();

     void on_pushButton_pdf_2_clicked();



     void on_pushButton_246_clicked();
     void on_pushButton_79_clicked();

     void on_pushButton_82_clicked();

     void on_pushButton_76_clicked();

     void on_pushButton_109_clicked();

     void on_pushButton_111_clicked();

     void on_pushButton_110_clicked();

     void on_pushButton_83_clicked();

     void on_pushButton_81_clicked();

     //void on_pushButton_80_clicked();

     //void on_pushButton_89_clicked();

     void on_radioButton_11_clicked();

     void on_radioButton_13_clicked();

     void on_radioButton_12_clicked();

     void on_radioButton_14_clicked();

     void on_pushButton_84_clicked();

     void on_afficher_ressource_3_activated(const QModelIndex &index);

     void on_pushButton_77_clicked();



     void on_lineEdit_39_textEdited(const QString &arg1);

     void on_afficher_ressource_activated(const QModelIndex &index);

     void on_afficher_scanner_activated(const QModelIndex &index);

     void on_lineEdit_39_windowIconTextChanged(const QString &iconText);

     void on_lineEdit_36_textEdited(const QString &arg1);

     void on_radioButton_clicked();

     void on_radioButton_2_clicked();

     void on_radioButton_3_clicked();

     void on_radioButton_4_clicked();

     void on_pushButton_91_clicked();

     void on_pushButton_92_clicked();


     void on_pushButton_88_clicked();

     void on_pushButton_87_clicked();

     void on_pushButton_90_clicked();

     void on_pushButton_102_clicked();

     void on_pushButton_103_clicked();

     void on_pushButton_95_clicked();

     void on_pushButton_101_clicked();

     void on_afficher_fournisseur_activated(const QModelIndex &index);

     void on_pushButton_97_clicked();

     void on_pushButton_96_clicked();

     void on_lineEdit_46_textEdited(const QString &arg1);

     void on_radioButton_15_clicked();

     void on_radioButton_16_clicked();

     void on_radioButton_5_clicked();

     void on_radioButton_6_clicked();

     void on_radioButton_7_clicked();

     void on_radioButton_8_clicked();

     void on_pushButton_104_clicked();

     void on_pushButton_105_clicked();

     void on_pushButton_99_clicked();

     void on_pushButton_100_clicked();

     void on_radioButton_9_clicked();

     void on_radioButton_10_clicked();

     void on_radioButton_17_clicked();

     void on_radioButton_18_clicked();

     void on_pushButton_106_clicked();

     void on_pushButton_108_clicked();

     void on_pushButton_107_clicked();

     void on_pushButton_114_clicked();

     void on_pushButton_112_clicked();

     void on_pushButton_113_clicked();


     void on_label_110_linkActivated(const QString &link);

     void on_label_111_linkActivated(const QString &link);

     void on_pushButton_24_clicked();

private:
    Ui::MainWindow *ui;
  QString id,mdp,value;
  classe_personnel tmpemployee;
  class_services tserv;
 Materiels tempmateriels;
   Entretien tempentretien;
   patient tmppatient;
   rendezvous tmprendezvous;
   fournisseur fournisseurtemp;
   stock  stocktemp;
   QSound *son;
   QSound *son1;
   QPropertyAnimation *animation;
   QPropertyAnimation *animation1;
   QPropertyAnimation *animation2;
   QPropertyAnimation *animation3;
   QSequentialAnimationGroup * animgrp;
   Dialog d;
   Dialog2 d2;
   Dialog3 d3;
   scanner tempscanner;
   ressource tempressource;
   stat_ressource *sre;
   fournisseur1 tmpf;
   capture *c;
   image p;

};
#endif // MAINWINDOW_H

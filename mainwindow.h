#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "string"
#include<stat_ressource.h>
#include<scanner.h>
#include<ressource.h>
#include<QSound>
#include<QWidget>
#include<fournisseur.h>
#include<capture.h>
#include<image.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow
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

    // void on_pushButton_clicked();

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

private:
    Ui::MainWindow *ui;
    scanner tempscanner;
    ressource tempressource;
    stat_ressource *sre;
    fournisseur tmpf;
    capture *c;
    QString id,mdp,value;
    image p;
};


#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "string"
#include<stat_ressource.h>
#include <QMainWindow>
#include<scanner.h>
#include<ressource.h>
#include<QSound>
#include<QWidget>

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

    void on_pushButton_79_clicked();

    void on_pushButton_82_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_81_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_89_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_12_clicked();

    void on_radioButton_14_clicked();

     void on_pushButton_84_clicked();

     void on_afficher_ressource_3_activated(const QModelIndex &index);

     void on_pushButton_77_clicked();

     void on_pushButton_78_clicked();

     void on_lineEdit_39_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    scanner tempscanner;
    ressource tempressource;
    stat_ressource *sre;

  QString id,mdp,value;
};


#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "string"
#include <QMainWindow>
#include "patient.h"
#include <QDialog>
#include <QtDebug>
#include <QtSql>
#include <QSqlQueryModel>
#include <QStackedWidget>
#include <QWidget>
#include <QPushButton>

#include <QDialogButtonBox>
#include "rendezvous.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QModelIndexList>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTextTableFormat>
#include <QFileDialog>
#include <QTextTableCell>
#include <QTableWidget>
#include <QModelIndex>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QModelIndexList>
//#include <QPrinter>
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


      void on_ajouter_clicked();







      void on_pushButton_supprimer_clicked();


      void on_pushButton_modifier_clicked();





      void on_pushButton_chercher_clicked();

      void on_pushButton_Ajouter2_clicked();

      void on_pushButton_Supprimer2_clicked();

      void on_pushButton_Chercher2_clicked();

      void on_pushButton_Modifier2_clicked();

      void on_pushButton_pdf_clicked();

      void on_pushButton_49_clicked();

      //void on_pushButton_mail_clicked();

      //void on_pushButton_envoyer_clicked();

      void on_pushButton_39_clicked();

private:
    Ui::MainWindow *ui;
  QString id,mdp;
  patient tmppatient;
  rendezvous tmprendezvous;
};
#endif // MAINWINDOW_H

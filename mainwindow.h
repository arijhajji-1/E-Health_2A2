#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "string"
#include <QMainWindow>
#include "materiels.h"
#include "entretien.h"
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

    void on_pushButton_Materiels_Ajouter_clicked();

    void on_pushButton_Materiels_Supprimer_clicked();

    void on_pushButton_Materiels_Afficher_clicked();

    void on_lineEdit_Entretien_ID_textEdited(const QString &arg1);

    void on_pushButton_Entretien_Ajouter_clicked();

    void on_pushButton_Entretien_Afficher_clicked();

    void on_pushButton_Entretien_Supprimer_clicked();

    void on_pushButton_Entretien_Modifier_clicked();

    void on_pushButton_Materiels_Modifier_clicked();

    void on_pushButton_Materiels_Rechercher_clicked();

    void on_pushButton_11_clicked();


    void on_pushButton_Materiels_Trier_clicked();

    void on_dateEdit_Entertien_userDateChanged(const QDate &date);

    void on_pushButton_Entretien_Rechercher_clicked();

    void on_pushButton_Entretien_Trier_clicked();

    void on_pushButton_Materiels_PDF_clicked();

    void on_pushButton_91_clicked();

    void on_pushButton_Entretien_PDF_clicked();

    void on_pushButton_LoadList_Materiels_clicked();

private:
    Ui::MainWindow *ui;
  QString id,mdp;
  Materiels tempmateriels;
  Entretien tempentretien;
};
#endif // MAINWINDOW_H

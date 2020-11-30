#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <scanner.h>
#include<ressource.h>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include<QFileDialog>
#include <QTextDocument>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_78_clicked();
    ui->afficher_ressource_3->setModel(tempressource.afficher_ressource());
    ui->afficher_scanner_2->setModel(tempscanner.afficher_scanner());

    ui->lineEdit_40->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_32->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_32->setEnabled(1);
    ui->lineEdit_32->clear();
    ui->lineEdit_37->clear();
    ui->lineEdit_38->clear();
    ui->dateEdit_11->setCalendarPopup(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setid(QString s){id=s;}
void MainWindow::setmdp(QString s){mdp=s;}
QString MainWindow::getid(){return id;}
QString MainWindow::getmdp(){return mdp;}

void MainWindow::on_pushButton_clicked()
{
    MainWindow C;
    C.setid(ui->lineEdit->text());
    C.setmdp(ui->lineEdit_2->text());
    ui->lineEdit->setText(C.getid());
    ui->lineEdit_2->setText(C.getmdp());
    if((C.getid()=="1"&&C.getmdp()=="1")||(C.getid()=="2"&&C.getmdp()=="2")||(C.getid()=="3"&&C.getmdp()=="3")||(C.getid()=="4"&&C.getmdp()=="4")){
   ui->stackedWidget->setCurrentIndex(1);
    }
    else
        QMessageBox::information(this,"conecter","id ou mdp incorrect");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_23_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_22_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

void MainWindow::on_pushButton_29_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_33_clicked()
{
   ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_pushButton_34_clicked()
{
     ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::on_pushButton_19_clicked()
{
     ui->stackedWidget_5->setCurrentIndex(2);
}

void MainWindow::on_pushButton_35_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(1);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::on_pushButton_37_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::on_pushButton_79_clicked() // ajout scanner
{
  //  int cin=ui->stackedWidget_6->lineEdit_40->text().toInt();
    int cin =ui->lineEdit_40->text().toInt();
    QString nom=ui->lineEdit_31->text();
    QString prenom=ui->lineEdit_33->text();
    QString date_n=ui->dateEdit_9->date().toString();
    int telephone=ui->lineEdit_34->text().toInt();
    QString analyse=ui->lineEdit_35->text();
    QString date = ui->dateEdit_8->date().toString();


    scanner c(cin,nom,prenom,date_n,telephone,analyse,date);
    bool test=c.ajouter_scanner();
    if (test)
    {
        ui->afficher_scanner_2->setModel(tempscanner.afficher_scanner());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout avec succée"), QMessageBox::Ok);
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }

}

void MainWindow::on_pushButton_82_clicked() //supprimer scanner
{
    int id=ui->lineEdit_40->text().toUInt();
    bool test=tempscanner.supprimer_scanner(id);
    if(test)
    {
        ui->afficher_scanner_2->setModel(tempscanner.afficher_scanner());
        QMessageBox::information(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression avec succée"), QMessageBox::Ok);
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }
}


void MainWindow::on_pushButton_76_clicked() //modifier scanner
{
    int cin =ui->lineEdit_40->text().toInt();
    int telephone=ui->lineEdit_34->text().toInt();
    QString nom=ui->lineEdit_31->text();
    QString prenom=ui->lineEdit_33->text();
    QString date_n=ui->dateEdit_9->date().toString();
    QString analyse=ui->lineEdit_35->text();
    QString date = ui->dateEdit_8->date().toString();


    scanner c(cin,nom,prenom,date_n,telephone,analyse,date);
      bool test=c.modifier_scanner(cin);
      if(test)
    {

          ui->afficher_scanner_2->setModel(tempscanner.afficher_scanner());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Modification avec succees.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_109_clicked() //ajout ressource
{
    int ref =ui->lineEdit_32->text().toInt();
    int stock=ui->lineEdit_37->text().toInt();
    QString date = ui->dateEdit_11->date().toString();
    QString remarque=ui->lineEdit_38->text();



    ressource c(ref,stock,date,remarque);
    bool test=c.ajouter_ressource();
    if (test)
    {
        ui->afficher_ressource_3->setModel(tempressource.afficher_ressource());
        ui->lineEdit_32->setEnabled(1);
        ui->lineEdit_32->clear();
        ui->lineEdit_37->clear();
        ui->lineEdit_38->clear();
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout avec succée"), QMessageBox::Ok);
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }

}




void MainWindow::on_pushButton_111_clicked() //supprimer ressource
{
    int ref=ui->lineEdit_32->text().toUInt();
    bool test=tempressource.supprimer_ressource(ref);
    if(test)
    {
        ui->afficher_ressource_3->setModel(tempressource.afficher_ressource());
        ui->lineEdit_32->setEnabled(1);
        ui->lineEdit_32->clear();
        ui->lineEdit_37->clear();
        ui->lineEdit_38->clear();
        QMessageBox::information(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression avec succée"), QMessageBox::Ok);
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }
}



void MainWindow::on_pushButton_110_clicked() //modifer ressource
{
    int ref =ui->lineEdit_32->text().toInt();
    int stock=ui->lineEdit_37->text().toInt();
    QString date = ui->dateEdit_11->date().toString();
    QString remarque=ui->lineEdit_38->text();



    ressource c(ref,stock,date,remarque);
    bool test=c.modifier_ressource(c);
      if(test)
    {

          ui->afficher_ressource_3->setModel(tempressource.afficher_ressource());
          ui->lineEdit_32->setEnabled(1);
          ui->lineEdit_32->clear();
          ui->lineEdit_37->clear();
          ui->lineEdit_38->clear();
    QMessageBox::information(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Modification avec succees.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_83_clicked() //imprimer ressource
{
    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void MainWindow::on_pushButton_81_clicked() //imprimer scanner
{
    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void MainWindow::on_pushButton_80_clicked() //recherche scanner
{
    QString cin =ui->lineEdit_36->text();
    ui->afficher_scanner_2->setModel(tempscanner.Recherche(cin));
}

void MainWindow::on_pushButton_89_clicked() //recherche ressource
{
    QString ref =ui->lineEdit_39->text();
    ui->afficher_ressource_3->setModel(tempressource.Rechercher(ref));


}


void MainWindow::on_radioButton_11_clicked() //trie ressource
{
    ui->afficher_ressource_3->setModel(tempressource.trierA1());
}

void MainWindow::on_radioButton_13_clicked() //trie
{
    ui->afficher_ressource_3->setModel(tempressource.trierB2());
}



void MainWindow::on_radioButton_12_clicked()//trie scanner
{
    ui->afficher_scanner_2->setModel(tempscanner.trierA());
}

void MainWindow::on_radioButton_14_clicked()
{
    ui->afficher_scanner_2->setModel(tempscanner.trierB());
}

void MainWindow::on_pushButton_84_clicked()// PDF

{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM RESSOURCE ");
        q.exec();
        QString pdf="<br> <h1  style='color:blue'>Ressource Labo  <br></h1>\n <br> <table>  <tr>  <th>SR </th>  <th>Date  </th> <th>Ref  </th>  <th>Remarque </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(1).toString()+" " + q.value(2).toString() +"</td>   <td>" +q.value(0).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(6).toString()+" " " "  " " "</td>   <td>"+q.value(4).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);

}

void MainWindow::on_afficher_ressource_3_activated(const QModelIndex &index)
{
    //boutonradiocm();

    QString val=ui->afficher_ressource_3->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tempressource.tableclicked(val);

    if (qry.exec())
    {
        while (qry.next())
        {
            ui->lineEdit_32->setDisabled(1);
            ui->lineEdit_32->setText(qry.value(0).toString());
            ui->lineEdit_37->setText(qry.value(1).toString());
           ui->dateEdit_11->setDate(qry.value(2).toDate());

            ui->lineEdit_38->setText(qry.value(3).toString());


        }
    }
}

void MainWindow::on_pushButton_77_clicked()
{
    sre=new stat_ressource (this);
    sre->show();
}

void MainWindow::on_pushButton_78_clicked()
{
    ui->afficher_ressource_3->setModel(tempressource.afficher_ressource());
}

void MainWindow::on_lineEdit_39_textEdited(const QString &arg1)
{

   value=arg1;
   ui->afficher_ressource_3->setModel(tempressource.Rechercher(value)) ;
}

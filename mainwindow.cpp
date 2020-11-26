#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiels.h"
#include "entretien.h"
#include <QDateTime>
#include <QDialog>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_Materiels->setModel(tempmateriels.afficher());
    ui->tableView_Entretien->setModel(tempentretien.afficher());

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
void MainWindow::on_pushButton_Materiels_Ajouter_clicked()
{
    QString id= ui->lineEdit_Materiels_ID->text();
    QString nom= ui->lineEdit_Materiels_Nom->text();
    QString dt1= ui->dateEdit_Materiels->text();

    Materiels m(id,nom,dt1);

    bool test=m.ajouter();
    if(test)
    {
        ui->tableView_Materiels->setModel(tempmateriels.afficher());
            QMessageBox::information(nullptr, QObject::tr("ajout"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
       else
      //  qDebug() <<"connection failed";
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                        QObject::tr("ajout failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_Materiels_Supprimer_clicked()
{
    QString id=ui->lineEdit_Materiels_ID->text();
    bool test=tempmateriels.supprimer(id);
    if(test)
    {
        ui->tableView_Materiels->setModel(tempmateriels.afficher());
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
       else
      //  qDebug() <<"connection failed";
        QMessageBox::critical(nullptr, QObject::tr("Suppression"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_Entretien_Ajouter_clicked()
{
    QString id= ui->lineEdit_Entretien_ID->text();
    int num= ui->lineEdit_Entretien_Num->text().toInt();
    QString dt2= ui->dateEdit_Entertien->text();
    QString idem= ui->comboBox_3_Materiels->currentText();
    QString dsc= ui->lineEdit_Entretien_Description->text();

    Entretien e(id,idem,num,dsc,dt2);

    bool test=e.ajouter();
    if(test)
    {
        ui->tableView_Entretien->setModel(tempentretien.afficher());
            QMessageBox::information(nullptr, QObject::tr("ajout"),
                        QObject::tr("ajout successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
       else
      //  qDebug() <<"connection failed";
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                        QObject::tr("ajout failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_Entretien_Supprimer_clicked()
{
    QString id=ui->lineEdit_Entretien_ID->text();
    bool test=tempentretien.supprimer(id);
    if(test)
    {
        ui->tableView_Entretien->setModel(tempentretien.afficher());
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
       else
      //  qDebug() <<"connection failed";
        QMessageBox::critical(nullptr, QObject::tr("Suppression"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_Materiels_Modifier_clicked()
{

    QString id= ui->lineEdit_Materiels_ID->text();
    QString nom= ui->lineEdit_Materiels_Nom->text();
    QString dt1= ui->dateEdit_Materiels->text();

    Materiels m(id,nom,dt1);

    bool test=m.modifier();
        if(test)
        {

            ui->tableView_Materiels->setModel(tempmateriels.afficher());

            QMessageBox::information(nullptr, QObject::tr("Modifier"),
                        QObject::tr("Modification avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier "),
                        QObject::tr("Modification echoue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_Entretien_Modifier_clicked()
{
    QString id= ui->lineEdit_Entretien_ID->text();
    QString idem= ui->comboBox_3_Materiels->currentText();
    int num= ui->lineEdit_Entretien_Num->text().toInt();
    QString dsc= ui->lineEdit_Entretien_Description->text();
    QString dt2= ui->dateEdit_Entertien->text();


    Entretien e(id,idem,num,dsc,dt2);

    bool test=e.modifier();
        if(test)
        {

            ui->tableView_Entretien->setModel(tempentretien.afficher());

            QMessageBox::information(nullptr, QObject::tr("Modifier"),
                        QObject::tr("Modification avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier "),
                        QObject::tr("Modification echoue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_Materiels_Afficher_clicked()
{
    ui->tableView_Materiels->setModel(tempmateriels.afficher());
}



void MainWindow::on_pushButton_Entretien_Afficher_clicked()
{
     ui->tableView_Entretien->setModel(tempentretien.afficher());
}







void MainWindow::on_pushButton_Materiels_Rechercher_clicked()
{
    QString id = ui->lineEdit_Materiels_ID->text();
    QString nom = ui->lineEdit_Materiels_Nom->text();
    QString dt1 = ui->dateEdit_Materiels->text();

        ui->tableView_Materiels->setModel(tempmateriels.rechercher(id,nom,dt1));

}


void MainWindow::on_pushButton_Materiels_Trier_clicked()
{
QString a=ui->comboBox_2_Materiels->currentText();
    QString choice=ui->comboBox_Materiels->currentText();
     ui->tableView_Materiels->setModel(tempmateriels.trier(choice,a));
}



void MainWindow::on_pushButton_Entretien_Rechercher_clicked()
{
    QString id= ui->lineEdit_Entretien_ID->text();
    QString idem= ui->comboBox_3_Materiels->currentText();
    int numero= ui->lineEdit_Entretien_Num->text().toInt();
    QString dsc= ui->lineEdit_Entretien_Description->text();
    QString dt2= ui->dateEdit_Entertien->text();
  QString num=QString::number(numero);

        ui->tableView_Entretien->setModel(tempentretien.rechercher(id,idem,num,dsc,dt2));
}


void MainWindow::on_pushButton_Entretien_Trier_clicked()
{
    QString a=ui->comboBox_2_Entretien->currentText();
        QString choice=ui->comboBox_Entretien->currentText();
         ui->tableView_Entretien->setModel(tempentretien.trier(choice,a));
}

void MainWindow::on_pushButton_Materiels_PDF_clicked()
{
    QSqlDatabase db;
                QTableView tableView_Materiels;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM MATERIELS ");
                 qry.exec();
                 Modal->setQuery(qry);
                 tableView_Materiels.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = tableView_Materiels.model()->rowCount();
                 const int columnCount =  tableView_Materiels.model()->columnCount();

                 QString date = QDateTime::currentDateTime().toString();
                 out <<date;


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #000080; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Matériels Operationnels")
                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                 out << "<thead><tr bgcolor=#B5D3E7>";
                 for (int column = 0; column < columnCount; column++)
                     if (!tableView_Materiels.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(tableView_Materiels.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!tableView_Materiels.isColumnHidden(column)) {
                             QString data = tableView_Materiels.model()->data(tableView_Materiels.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"

                         "<p align='center'> <img src='D:/care++.png' alt='care++logo'></p>"

                      <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2 >\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table >\n"

                     "</body>\n"

                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                    /* QLabel lab;
                      QPixmap pixmap("D:/care++.png");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     QPrinter printer(QPrinter::PrinterResolution);

*/
                     document->print(&printer);

                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/materiels.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;

}



void MainWindow::on_pushButton_Entretien_PDF_clicked()
{
    QSqlDatabase db;
                QTableView tableView_Entretien;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM ENTRETIEN ");
                 qry.exec();
                 Modal->setQuery(qry);
                 tableView_Entretien.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = tableView_Entretien.model()->rowCount();
                 const int columnCount =  tableView_Entretien.model()->columnCount();

                 QString date = QDateTime::currentDateTime().toString();
                 out <<date;


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #FFD700; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Entretiens")

                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                 out << "<thead><tr bgcolor=#F5EA74>";
                 for (int column = 0; column < columnCount; column++)
                     if (!tableView_Entretien.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(tableView_Entretien.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!tableView_Entretien.isColumnHidden(column)) {
                             QString data = tableView_Entretien.model()->data(tableView_Entretien.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"

                         "<p align='center'> <img src='D:/care++.png' alt='care++logo'></p>"

                      <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2 >\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table >\n"

                     "</body>\n"

                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                    /* QLabel lab;
                      QPixmap pixmap("D:/care++.png");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     QPrinter printer(QPrinter::PrinterResolution);

*/
                     document->print(&printer);

                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/entretien.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;
}


void MainWindow::on_pushButton_LoadList_Materiels_clicked()
{
    QSqlDatabase db;

                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery query;
                query.prepare("select ID from Materiels");
                query.exec();
                Modal->setQuery(query);
                ui->comboBox_3_Materiels->setModel(Modal);

}


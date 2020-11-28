#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <stock.h>
#include <fournisseur.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QDialog>
#include <QFile>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
 ui->setupUi(this);
 ui->lineEdit_supp->setValidator(new QIntValidator(0,99999999,this));
 ui->lineEdit_16->setValidator(new QIntValidator(0,99999999,this));
 ui->lineEdit_20->setValidator(new QIntValidator(0,99999999,this));

ui->tableView_stock->setModel(stocktemp.afficher());

ui->tableView_fournisseur->setModel(fournisseurtemp.afficher());


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

void MainWindow::on_pushButton_50_clicked()
{
    int ref=ui->lineEdit_supp->text().toInt();
    QString nom=ui->lineEdit_15->text();
    int qtt=ui->lineEdit_16->text().toInt();
    QString idf=ui->lineEdit_28->text();

    stock e(ref,nom,qtt,idf);
    bool test=e.ajouter();
    if (test)

    {    ui->tableView_stock->setModel(stocktemp.afficher());

        QMessageBox::information(nullptr, QObject::tr("ajout"),
                              QObject::tr("ajout avec succés.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_51_clicked()
{
    int ref=ui->lineEdit_supp->text().toInt();
    bool test=stocktemp.supprimer(ref);
    if (test)
    { ui->tableView_stock->setModel(stocktemp.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression"),
                              QObject::tr("suppression avec succés.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("suppression"),
                    QObject::tr("suppression impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_56_clicked()
{
    QString nomf=ui->lineEdit_17->text();
    QString adrf=ui->lineEdit_18->text();
    QString idf=ui->lineEdit_19->text();
    int numf=ui->lineEdit_20->text().toInt();
    fournisseur e(nomf,adrf,idf,numf);
    bool test=e.ajouter();
    if (test)

    {        ui->tableView_fournisseur->setModel(fournisseurtemp.afficher());


        QMessageBox::information(nullptr, QObject::tr("ajout"),
                              QObject::tr("ajout avec succés.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_57_clicked()
{
    int numf=ui->lineEdit_20->text().toInt();
    bool test=fournisseurtemp.supprimer(numf);
    if (test)
    { ui->tableView_fournisseur->setModel(fournisseurtemp.afficher());

        QMessageBox::information(nullptr, QObject::tr("suppression"),
                              QObject::tr("suppression avec succés.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("suppression"),
                    QObject::tr("suppression impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_54_clicked()
{

}

void MainWindow::on_pushButton_60_clicked()
{
    QSqlDatabase db;
                QTableView table_stock;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM stock ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_stock.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = table_stock.model()->rowCount();
                 const int columnCount =  table_stock.model()->columnCount();


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des rendez vous")
                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_stock.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_stock.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_stock.isColumnHidden(column)) {
                             QString data = table_stock.model()->data(table_stock.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     QLabel lab;
                      QPixmap pixmap(":/img/aze.png");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     //QPrinter printer(QPrinter::PrinterResolution);

                     //pixmap.load("aze.png");
                     //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                     //painter.drawPixmap(10,10,50,50, pixmap);

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/rendezvous.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;
}

void MainWindow::on_pushButton_86_clicked()
{
    ui->tableView_stock->setModel(stocktemp.tri());
}

void MainWindow::on_pushButton_53_clicked()
{
    int ref = ui->lineEdit_supp->text().toInt();
        QString nom  = ui->lineEdit_15->text();
        int qtt=ui->lineEdit_16->text().toInt();
            if(ref==0&&nom==""){
            QString txt=ui->lineEdit_supp->text();
            ui->tableView_stock->setModel(stocktemp.recherche(txt));
            }
            else    if(ref==0&&qtt==0){
                QString txt=ui->lineEdit_15->text();
               ui->tableView_stock->setModel(stocktemp.recherche(txt));}
            else    if(qtt==0&&nom==""){
                QString txt=ui->lineEdit_16->text();
              ui->tableView_stock->setModel(stocktemp.recherche(txt));}

}

void MainWindow::on_pushButton_52_clicked()
{


    int ref = ui->lineEdit_supp->text().toInt();
      int qtt = ui->lineEdit_16->text().toInt();

      QString nom = ui->lineEdit_15->text();
      QString idf = ui->lineEdit_28->text();

      stock e(ref,nom,qtt,idf);
      bool test = e.modifier();
      if(test)
      {
          ui->tableView_stock->setModel(stocktemp.afficher());

      QMessageBox::information(nullptr,QObject::tr("modifier stock"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);
      }
     ui->lineEdit_supp->clear();
      ui->lineEdit_16->clear();
      ui->lineEdit_15->clear();
      ui->lineEdit_28->clear();


}

void MainWindow::on_pushButton_61_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this, tr("choose"), "",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename, QString()) !=0)
    {
        QImage image;
        bool valid=image.load(filename);
        if (valid)
        {

            image = image.scaledToWidth(ui->label_39->width(), Qt::SmoothTransformation);
            ui->label_39->setPixmap(QPixmap::fromImage(image));
        }

    }
}

void MainWindow::on_pushButton_58_clicked()
{

      int numf = ui->lineEdit_20->text().toInt();

      QString idf = ui->lineEdit_19->text();
      QString adrf = ui->lineEdit_18->text();
      QString nomf = ui->lineEdit_17->text();

      fournisseur e(idf,adrf,nomf,numf);
      bool test = e.modifier();
      if(test)
      {
          ui->tableView_fournisseur->setModel(fournisseurtemp.afficher());

      QMessageBox::information(nullptr,QObject::tr("modifier fournisseur"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);
      }
     ui->lineEdit_19->clear();
      ui->lineEdit_18->clear();
      ui->lineEdit_17->clear();
      ui->lineEdit_20->clear();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QListView>
#include <QSqlTableModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QDialog>
#include <QFile>
#include <QPainter>
#include <QMessageBox>
#include <QTextStream>
#include "rendezvous.h"
#include "patient.h"
#include "mail.h"
#include <QSortFilterProxyModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_rdv->setModel(tmprendezvous.afficher());
    ui->tableView_patient->setModel(tmppatient.afficher());

    //connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    //connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
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
        QMessageBox::information(this,"connecter","id ou mdp incorrect");
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


void MainWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int numtel = ui->lineEdit_numtel->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString maladie = ui->lineEdit_maladie->text();
    patient e(id,nom,prenom,adresse,numtel,maladie);
    bool test = e.ajouter();
    if(test)
    {
        ui->tableView_patient->setModel(tmppatient.afficher());

    QMessageBox::information(nullptr,QObject::tr("ajouter un patient"),QObject::tr("patient ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
    }
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_numtel->clear();
    ui->lineEdit_maladie->clear();

}




void MainWindow::on_pushButton_supprimer_clicked()
{
int id= ui->lineEdit_id->text().toInt();
bool test=tmppatient.supprimer(id);
if(test)
{
    ui->tableView_patient->setModel(tmppatient.afficher());

QMessageBox::information(nullptr,QObject::tr("supprimer un patient"),QObject::tr("patient supprimé. \n ""click cancel to exit."),QMessageBox::Cancel);
}
  ui->lineEdit_id->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int numtel = ui->lineEdit_numtel->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString maladie = ui->lineEdit_maladie->text();
    patient e(id,nom,prenom,adresse,numtel,maladie);
    bool test = e.modifier();
    if(test)
    {
        ui->tableView_patient->setModel(tmppatient.afficher());

    QMessageBox::information(nullptr,QObject::tr("modifier un patient"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);
    }
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_numtel->clear();
    ui->lineEdit_maladie->clear();
}




void MainWindow::on_pushButton_chercher_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int numtel = ui->lineEdit_numtel->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString maladie = ui->lineEdit_maladie->text();
        if(nom==""&&prenom==""){
        QString txt=ui->lineEdit_id->text();
        ui->tableView_patient->setModel(tmppatient.recherche_id_patient(txt));
        }
        else    if(id==0&&prenom==""){
            QString txt=ui->lineEdit_nom->text();
           ui->tableView_patient->setModel(tmppatient.recherche_nom_patient(txt));}
        else    if(id==0&&nom==""){
            QString txt=ui->lineEdit_prenom->text();
          ui->tableView_patient->setModel(tmppatient.recherche_prenom_patient(txt));}
        else    if(id==0&&numtel==0){
            QString txt=ui->lineEdit_numtel->text();
          ui->tableView_patient->setModel(tmppatient.recherche_num_patient(txt));}


}

void MainWindow::on_pushButton_Ajouter2_clicked()
{
    int id = ui->lineEdit_idpatient->text().toInt();
    int idm = ui->lineEdit_idmed->text().toInt();

    QString descr = ui->plainTextEdit_desc->toPlainText();
    QString dater = ui->dateTimeEdit->text();
    rendezvous e(id,dater,descr,idm);
    bool test = e.ajouter();
    if(test)
    {
        ui->tableView_rdv->setModel(tmprendezvous.afficher());

    QMessageBox::information(nullptr,QObject::tr("ajouter un rendezvous"),QObject::tr("rendezvous ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
    }
    ui->lineEdit_idpatient->clear();
    ui->lineEdit_idmed->clear();

    ui->plainTextEdit_desc->clear();
    ui->dateTimeEdit->clear();
}

void MainWindow::on_pushButton_Supprimer2_clicked()
{
    int id= ui->lineEdit_idpatient->text().toInt();
    bool test=tmprendezvous.supprimer(id);
    if(test)
    {
        ui->tableView_rdv->setModel(tmprendezvous.afficher());

    QMessageBox::information(nullptr,QObject::tr("supprimer un rendez vous"),QObject::tr("rendez vous supprimé. \n ""click cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("rendez vous n'existe pas"),QObject::tr("click cancel to exit."),QMessageBox::Cancel);
    }
      ui->lineEdit_idpatient->clear();
}

void MainWindow::on_pushButton_Chercher2_clicked()
{
   QString  id = ui->lineEdit_idpatient->text();
    QString idm = ui->lineEdit_idmed->text();
        if(idm==""){
        QString txt=ui->lineEdit_idpatient->text();
        ui->tableView_rdv->setModel(tmprendezvous.recherche_idp_patient(txt));
        }
        else    if(id==""){
            QString txt=ui->lineEdit_idmed->text();
           ui->tableView_rdv->setModel(tmprendezvous.recherche_idm_medecin(txt));}

}

void MainWindow::on_pushButton_Modifier2_clicked()
{
    int id = ui->lineEdit_idpatient->text().toInt();
    int idm = ui->lineEdit_idmed->text().toInt();

    QString descr = ui->plainTextEdit_desc->toPlainText();
    QString dater = ui->dateTimeEdit->text();
    rendezvous e(id,dater,descr,idm);
    bool test = e.modifier();
    if(test)
    {
        ui->tableView_rdv->setModel(tmprendezvous.afficher());

    QMessageBox::information(nullptr,QObject::tr("modifier un rendez vous"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);
    }
    ui->lineEdit_idpatient->clear();
    ui->lineEdit_idmed->clear();

    ui->plainTextEdit_desc->clear();
}

void MainWindow::on_pushButton_pdf_clicked()
{


    QSqlDatabase db;
            QTableView table_patient;
            QSqlQueryModel * Modal=new  QSqlQueryModel();

            QSqlQuery qry;
            QString  id = ui->lineEdit_idpatient->text();

             qry.prepare("SELECT * FROM patient where id=:id ");
             qry.exec();
             Modal->setQuery(qry);
             table_patient.setModel(Modal);



             db.close();


             QString strStream;
             QTextStream out(&strStream);

             const int rowCount = table_patient.model()->rowCount();
             const int columnCount =  table_patient.model()->columnCount();


             const QString strTitle ="Document";


             out <<  "<html>\n"
                 "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                 <<  QString("<title>%1</title>\n").arg(strTitle)
                 <<  "</head>\n"
                 "<body bgcolor=#ffffff link=#5000A0>\n"
                << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des patients")
                <<"<br>"
                 <<"<table border=1 cellspacing=0 cellpadding=2>\n";

             out << "<thead><tr bgcolor=#f0f0f0>";
             for (int column = 0; column < columnCount; column++)
                 if (!table_patient.isColumnHidden(column))
                     out << QString("<th>%1</th>").arg(table_patient.model()->headerData(column, Qt::Horizontal).toString());
             out << "</tr></thead>\n";

             for (int row = 0; row < rowCount; row++) {
                 out << "<tr>";
                 for (int column = 0; column < columnCount; column++) {
                     if (!table_patient.isColumnHidden(column)) {
                         QString data = table_patient.model()->data(table_patient.model()->index(row, column)).toString().simplified();
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
             printer.setOutputFileName("/tmp/patient.pdf");
             printer.setPageMargins(QMarginsF(15, 15, 15, 15));



             delete document;

}

void MainWindow::on_pushButton_49_clicked()
{
    QSqlDatabase db;
            QTableView table_rendezvous;
            QSqlQueryModel * Modal=new  QSqlQueryModel();

            QSqlQuery qry;
            QString  id = ui->lineEdit_idpatient->text();

             qry.prepare("SELECT * FROM rendezvous where id=:id ");
             qry.exec();
             Modal->setQuery(qry);
             table_rendezvous.setModel(Modal);



             db.close();


             QString strStream;
             QTextStream out(&strStream);

             const int rowCount = table_rendezvous.model()->rowCount();
             const int columnCount =  table_rendezvous.model()->columnCount();


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
                 if (!table_rendezvous.isColumnHidden(column))
                     out << QString("<th>%1</th>").arg(table_rendezvous.model()->headerData(column, Qt::Horizontal).toString());
             out << "</tr></thead>\n";

             for (int row = 0; row < rowCount; row++) {
                 out << "<tr>";
                 for (int column = 0; column < columnCount; column++) {
                     if (!table_rendezvous.isColumnHidden(column)) {
                         QString data = table_rendezvous.model()->data(table_rendezvous.model()->index(row, column)).toString().simplified();
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

/*void MainWindow::on_pushButton_mail_clicked()
{

    ui->stackedWidget_2->setCurrentIndex(1);


}*/

/*void MainWindow::on_pushButton_envoyer_clicked()
{
    mail* smtp = new mail(ui->lineEdit_sender->text()," 22861274", "smtp.gmail.com", 465);

           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


         smtp->sendMail(ui->lineEdit_sender->text(), ui->lineEdit_recepiant->text() , ui->lineEdit_subject->text(),ui->plainTextEdit_body->toPlainText());

}
*/

void MainWindow::on_pushButton_39_clicked()
{
    QString tri=ui->comboBox->currentText();

        if(tri=="id")
      ui->tableView_patient->setModel(tmppatient.ordre_id_patient());
        else if(tri=="nom")
            ui->tableView_patient->setModel(tmppatient.ordre_nom_patient());
        else if(tri=="prenom")
 ui->tableView_patient->setModel(tmppatient.ordre_prenom_patient());}

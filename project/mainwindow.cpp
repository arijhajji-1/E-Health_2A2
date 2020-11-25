#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "classe_personnel.h"
#include"class_services.h"
#include<QDebug>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QPrintDialog>
#include<QPrinter>
#include<QTextDocument>
#include<QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_21->setValidator(new QIntValidator(0,9999,this));
    ui->lineEdit_26->setValidator(new QIntValidator(0,9999,this));
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
    QString id = ui->lineEdit->text();
       QString mdp = ui->lineEdit_2->text();
       QSqlQuery query;
       if (query.exec("SELECT *from connexion WHERE id like '"+id+"' and mdp like '"+mdp+"'"))
       {
           int count=0;
           while(query.next())
           {
               count++;
           }
           if(count==1)
           {

                qDebug() << "is logged in";
                if(id=="1")
           ui->stackedWidget->setCurrentIndex(2);
                if(id=="2")
           ui->stackedWidget->setCurrentIndex(3);
                if(id=="3")
           ui->stackedWidget->setCurrentIndex(4);
                if(id=="4")
           ui->stackedWidget->setCurrentIndex(5);
                if(id=="5")
           ui->stackedWidget->setCurrentIndex(6);
                if(id=="0")
                    ui->stackedWidget->setCurrentIndex(1);
           }
           else
           {
              QMessageBox::information(this,"conecter","id ou mdp incorrect");
           }
       }

    //   ui->lineEdit->setText(query.value(0).toString());
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
    QString id = ui->lineEdit->text();
    if(id=="1")
    ui->stackedWidget->setCurrentIndex(0);
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);
   ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_14_clicked()
{
    QString id = ui->lineEdit->text();
    if(id=="2")
    ui->stackedWidget->setCurrentIndex(0);
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit->clear();
     ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
    QString id = ui->lineEdit->text();
    if(id=="4")
    ui->stackedWidget->setCurrentIndex(0);
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit->clear();
     ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_17_clicked()
{
    QString id = ui->lineEdit->text();
    if(id=="5")
    ui->stackedWidget->setCurrentIndex(0);
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit->clear();
     ui->lineEdit_2->clear();
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
     ui->tableView_6->setModel(tmpemployee.afficher_employe());
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->tableView_5->setModel(tserv.afficher_service());
     ui->comboBox_3->setModel(tmpemployee.afficher_employe());
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
    QString id = ui->lineEdit->text();
    if(id=="3")
    ui->stackedWidget->setCurrentIndex(0);
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit->clear();
     ui->lineEdit_2->clear();
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

void MainWindow::on_pushButton_62_clicked()
{
    QString idp=ui->lineEdit_21->text();
       int ntel=ui->lineEdit_24->text().toInt();
    QString nom=ui->lineEdit_22->text();
    QString prenom=ui->lineEdit_23->text();
    QString specialite=ui->lineEdit_25->text();

    classe_personnel p(idp,ntel,nom,prenom,specialite);
    bool test=p.ajouter_employe();
    if(test)
    {
         ui->tableView_6->setModel(tmpemployee.afficher_employe());
        QMessageBox::information(nullptr, QObject::tr("ajouter un employee"),
                    QObject::tr("employee ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->lineEdit_24->clear();
    ui->lineEdit_25->clear();
}
void MainWindow::on_pushButton_63_clicked()
{
    QString idp=ui->lineEdit_21->text();
      int ntel=ui->lineEdit_24->text().toInt();
    QString nom=ui->lineEdit_22->text();
    QString prenom=ui->lineEdit_23->text();
    QString specialite=ui->lineEdit_25->text();

    classe_personnel p(idp,ntel,nom,prenom,specialite);
    bool test=p.modifier_employe(idp);
    if(test)
    {
         ui->tableView_6->setModel(tmpemployee.afficher_employe());
        QMessageBox::information(nullptr, QObject::tr("modifier un employee"),
                    QObject::tr("employee modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->lineEdit_24->clear();
    ui->lineEdit_25->clear();
}

void MainWindow::on_pushButton_64_clicked()
{
    QString idp=ui->lineEdit_21->text();
    bool test=tmpemployee.supprimer_employe(idp);
    if(test)
    {
         ui->tableView_6->setModel(tmpemployee.afficher_employe());
        QMessageBox::information(nullptr, QObject::tr("supprimer un employee"),
                    QObject::tr("employee a ete supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
ui->lineEdit_21->clear();

}

void MainWindow::on_pushButton_65_clicked()
{
    QString idp=ui->lineEdit_21->text();
     QString nom=ui->lineEdit_22->text();
     QString prenom=ui->lineEdit_23->text();
    if(nom==""&&prenom==""){
    QString txt=ui->lineEdit_21->text();
   ui->tableView_6->setModel(tmpemployee.recherche_id_employe(txt));
    }
    else    if(idp==0&&prenom==""){
        QString txt=ui->lineEdit_22->text();
       ui->tableView_6->setModel(tmpemployee.recherche_nom_employe(txt));}
    else    if(idp==0&&nom==""){
        QString txt=ui->lineEdit_23->text();
       ui->tableView_6->setModel(tmpemployee.recherche_prenom_employe(txt));}
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
}

void MainWindow::on_pushButton_66_clicked()
{

}

void MainWindow::on_pushButton_68_clicked()
{
    QString tri=ui->comboBox_2->currentText();

    if(tri=="id")
   ui->tableView_6->setModel(tmpemployee.ordre_id_employe());
    else if(tri=="nom")
        ui->tableView_6->setModel(tmpemployee.ordre_nom_employe());
    else if(tri=="prenom")
        ui->tableView_6->setModel(tmpemployee.ordre_prenom_employe());
}

void MainWindow::on_pushButton_67_clicked()
{
             QString strStream;
             QTextStream out(&strStream);
             const int rowCount1 = ui->tableView_6->model()->rowCount();
             const int columnCoun1t =  ui->tableView_6->model()->columnCount();
             const QString strTitle ="Document";
             out <<  "<html>\n"
                     "   <img src='C:/Users/HP/Desktop/Nouveau dossier/project/img.png' height='257' width='573'/>"
                 "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                  "<img src='img.png'>"
                 <<  QString("<title>%1</title>\n").arg(strTitle)
                 <<  "</head>\n"
                 "<body bgcolor=#ffffff link=#5000A0>\n"
                << QString("<h3 style=\" font-size: 90px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des employées")
                <<"<br>"
                 <<"<table border=1 cellspacing=0 cellpadding=40 >\n";

             out << "<thead><tr bgcolor=#f0f0f0>";
             for (int column = 0; column < columnCoun1t; column++)
                 if (!ui->tableView_6->isColumnHidden(column))
                     out << QString("<th>%1</th>").arg(ui->tableView_6->model()->headerData(column, Qt::Horizontal).toString());
             out << "</tr></thead>\n";

             for (int row = 0; row < rowCount1; row++) {
                 out << "<tr>";
                 for (int column = 0; column < columnCoun1t; column++) {
                     if (!ui->tableView_6->isColumnHidden(column)) {
                         QString data =ui->tableView_6->model()->data(ui->tableView_6->model()->index(row, column)).toString().simplified();
                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                     }
                 }
                 out << "</tr>\n";
             }
             out <<  "</table>\n"
                     "<br><br>"
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
                 QPrinter printer(QPrinter::PrinterResolution);
                 document->print(&printer);
             }

             printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setPaperSize(QPrinter::A4);
             printer.setOutputFileName("/tmp/employee.pdf");
             printer.setPageMargins(QMarginsF(15, 15, 15, 15));
             delete document;
}

void MainWindow::on_pushButton_72_clicked()
{
    QString ids=ui->lineEdit_26->text();
    QString nom=ui->lineEdit_27->text();
    QString date=ui->dateEdit_3->text();
    QString heure_debut=ui->timeEdit->text();
    QString heure_fin=ui->timeEdit_2->text();

    class_services p(ids,nom,date,heure_debut,heure_fin);
    bool test=p.ajouter_service();
    if(test)
    {
         ui->tableView_5->setModel(tserv.afficher_service());
        QMessageBox::information(nullptr, QObject::tr("ajouter un service"),
                    QObject::tr("service ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();
}

void MainWindow::on_pushButton_71_clicked()
{
    QString ids=ui->lineEdit_26->text();
    bool test=tserv.supprimer_service(ids);
    if(test)
    {
         ui->tableView_5->setModel(tserv.afficher_service());
        QMessageBox::information(nullptr, QObject::tr("supprimer un service"),
                    QObject::tr("service a ete supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
ui->lineEdit_26->clear();
}

void MainWindow::on_pushButton_69_clicked()
{
    QString ids=ui->lineEdit_26->text();
    QString nom=ui->lineEdit_27->text();
    QString date=ui->dateEdit_3->text();
   QString heure_debut=ui->timeEdit->text();
    QString heure_fin=ui->timeEdit_2->text();

    class_services p(ids,nom,date,heure_debut,heure_fin);
    bool test=p.modifier_service(ids,nom);
    if(test)
    {
        ui->tableView_5->setModel(tserv.afficher_service());
        QMessageBox::information(nullptr, QObject::tr("modifier un service"),
                    QObject::tr("service modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();

}

void MainWindow::on_pushButton_74_clicked()
{

   QString tri=ui->comboBox->currentText();
    if(tri=="id")
   ui->tableView_5->setModel(tserv.ordre_id_service());
    else if(tri=="nom")
        ui->tableView_5->setModel(tserv.ordre_nom_service());
    else if(tri=="date")
        ui->tableView_5->setModel(tserv.ordre_date_service());
}

void MainWindow::on_pushButton_73_clicked()
{
    QString ids=ui->lineEdit_26->text();
    QString nom=ui->lineEdit_27->text();
    QString date=ui->dateEdit_3->text();
   if(ids!=""){
   QString txt=ui->lineEdit_26->text();
  ui->tableView_5->setModel(tserv.recherche_id_service(txt));
   }
   else    if(nom!=""){
       QString txt=ui->lineEdit_27->text();
      ui->tableView_5->setModel(tserv.recherche_nom_service(txt));}
   else    if(ids==0&&nom==""){
       QString txt=ui->dateEdit_3->text();
      ui->tableView_5->setModel(tserv.recherche_date_service(txt));}
   ui->lineEdit_26->clear();
   ui->lineEdit_27->clear();
}

void MainWindow::on_pushButton_54_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount1 = ui->tableView_5->model()->rowCount();
    const int columnCoun1t =  ui->tableView_5->model()->columnCount();
    const QString strTitle ="Document";
    out <<  "<html>\n"
            "   <img src='C:/Users/HP/Desktop/Nouveau dossier/project/img.png' height='257' width='573'/>"
        "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         "<img src='img.png'>"
        <<  QString("<title>%1</title>\n").arg(strTitle)
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
       << QString("<h3 style=\" font-size: 90px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des services")
       <<"<br>"
        <<"<table border=1 cellspacing=0 cellpadding=40 >\n";

    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCoun1t; column++)
        if (!ui->tableView_5->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_5->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    for (int row = 0; row < rowCount1; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCoun1t; column++) {
            if (!ui->tableView_5->isColumnHidden(column)) {
                QString data =ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
            "<br><br>"
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
        QPrinter printer(QPrinter::PrinterResolution);
        document->print(&printer);
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("/tmp/employee.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    delete document;
}

void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    QString txt=arg1;
      ui->lineEdit_26->setText(txt);
      qDebug()<<txt;
     ui->comboBox_4->setModel(tmpemployee.afficher_employe1(txt));
     ui->lineEdit_27->setText(ui->comboBox_4->currentText());
}

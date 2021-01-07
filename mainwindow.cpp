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
#include <scanner.h>
#include<ressource.h>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include<QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_21->setValidator(new QIntValidator(0,9999,this));
    ui->lineEdit_26->setValidator(new QIntValidator(0,9999,this));
     son=new QSound("C:/Users/HP/Desktop/55/of.wav");
      son1=new QSound("C:/Users/HP/Desktop/55/on.wav");
    animation =new QPropertyAnimation(ui->label,"geometry");
     animation->setDuration(1000);

     animation->setStartValue(ui->label->geometry());
     animation->setEndValue(QRect(70,170,91,16));
     animation2 =new QPropertyAnimation(ui->label_2,"geometry");
     animation2->setDuration(1000);

     animation2->setStartValue(ui->label_2->geometry());
        animation2->setEndValue(QRect(70,280,101,16));
      animation1 =new QPropertyAnimation(ui->lineEdit,"geometry");
     animation1->setDuration(1000);
     animation1->setStartValue(ui->lineEdit->geometry());
     animation1->setEndValue(QRect(250,170,181,20));
     animation3 =new QPropertyAnimation(ui->lineEdit_2,"geometry");
         animation3->setDuration(1000);
       animation3->setStartValue(ui->lineEdit_2->geometry());
     animation3->setEndValue(QRect(250,280,181,20));
    animgrp= new QSequentialAnimationGroup;
    animgrp->addAnimation(animation);
     animgrp->addAnimation(animation2);
      animgrp->addAnimation(animation1);
       animgrp->addAnimation(animation3);
      // animgrp->setLoopCount(2);
       animgrp->start();
       ui->afficher_ressource->setModel(tempressource.afficher_ressource());
       ui->afficher_scanner->setModel(tempscanner.afficher_scanner());
       ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());

       ui->lineEdit_40->setValidator(new QIntValidator(0,99999999,this));
       ui->Ref_R->setValidator(new QIntValidator(0,99999999,this));
       ui->Ref_R->setEnabled(1);
       ui->lineEdit_40->setEnabled(1);
       ui->Cin_F->setEnabled(1);
       ui->Ref_R->clear();
       ui->stock->setValue(0);
       ui->remarque->clear();
       //ui->dateEdit_11->setCalendarPopup(true);
       ui->dateEdit_9->setCalendarPopup(true);
       //combobox
         ui->comboBox_fournisseur->setModel(tmpf.afficher_Flist());

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
           son->play();
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
    if(id=="1"){
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();}
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_14_clicked()
{
    QString id = ui->lineEdit->text();
    if(id=="2")
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();}
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_15_clicked()
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

void MainWindow::on_pushButton_16_clicked()
{
    QString id = ui->lineEdit->text();
    if(id=="4")
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();}
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_17_clicked()
{
    QString id = ui->lineEdit->text();
    if(id=="5")
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();}
    if(id=="0")
     ui->stackedWidget->setCurrentIndex(1);

}
void MainWindow::on_pushButton_7_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(1);
     ui->tableView_patient->setModel(tmppatient.afficher());
}

void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(2);
     ui->tableView_rdv->setModel(tmprendezvous.afficher());
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
     ui->tableView_stock->setModel(stocktemp.afficher());
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
    ui->tableView_fournisseur->setModel(fournisseurtemp.afficher());
}

void MainWindow::on_pushButton_29_clicked()
{
    QString id = ui->lineEdit->text();
    if(id=="3")
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();}
    if(id=="0")
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
      ui->tableView_Materiels->setModel(tempmateriels.afficher());
}

void MainWindow::on_pushButton_19_clicked()
{
     ui->stackedWidget_5->setCurrentIndex(2);
      ui->tableView_Entretien->setModel(tempentretien.afficher());
}

void MainWindow::on_pushButton_35_clicked()
{
      son1->play();
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit->clear();
     ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(1);
    //ui->afficher_scanner_2->setModel(tempscanner.afficher_scanner());
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
   // ui->afficher_ressource_3->setModel(tempressource.afficher_ressource());
}

void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::on_pushButton_37_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
}
void MainWindow::on_pushButton_90_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
}
void MainWindow::on_pushButton_24_clicked()
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

void MainWindow::on_pushButton_11_clicked()
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

void MainWindow::on_pushButton_12_clicked()
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

void MainWindow::on_pushButton_Materiels_Afficher_clicked()
{
    ui->tableView_Materiels->setModel(tempmateriels.afficher());
}

void MainWindow::on_pushButton_Materiels_PDF_clicked()
{
    QSqlDatabase db;

                QTableView tableView_Materiels;

                tableView_Materiels.setModel(tempmateriels.exporterPDF());

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

void MainWindow::on_pushButton_Entretien_Afficher_clicked()
{
     ui->tableView_Entretien->setModel(tempentretien.afficher());
}

void MainWindow::on_pushButton_Entretien_PDF_clicked()
{
    QSqlDatabase db;

                 QTableView tableView_Entretien;

                 tableView_Entretien.setModel(tempentretien.exporterPDF());

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
                    << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #D4AF37; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Entretiens")

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

void MainWindow::on_pushButton_Entretien_Trier_clicked()
{
    QString a=ui->comboBox_2_Entretien->currentText();
        QString choice=ui->comboBox_Entretien->currentText();
         ui->tableView_Entretien->setModel(tempentretien.trier(choice,a));
}
void MainWindow::on_pushButton_LoadList_Materiels_clicked()
{

                ui->comboBox_3_Materiels->setModel(tempentretien.listMateriels());

}


void MainWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int numtel = ui->lineEdit_numtel->text().toInt();
    ui->lineEdit_numtel->setValidator(new QIntValidator(00000000,99999999,this));
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    ui->lineEdit_numtel->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    QString nom=ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString maladie = ui->lineEdit_maladie->text();
 ui->lineEdit_id->setMaxLength(8);

    patient e(id,nom,prenom,adresse,numtel,maladie);
    bool test = e.ajouter();
    if(test)
    {
        ui->tableView_patient->setModel(tmppatient.afficher());

    QMessageBox::information(nullptr,QObject::tr("ajouter un patient"),QObject::tr("patient ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajouter un patient"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

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
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    ui->lineEdit_numtel->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
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
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

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
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    ui->lineEdit_numtel->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    QString id = ui->lineEdit_id->text();
    QString numtel = ui->lineEdit_numtel->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString maladie = ui->lineEdit_maladie->text();

        if(id!=""){
        QString txt=ui->lineEdit_id->text();
        ui->tableView_patient->setModel(tmppatient.recherche_id_patient(txt));
        }
        else    if(nom!=""){
            QString txt=ui->lineEdit_nom->text();
           ui->tableView_patient->setModel(tmppatient.recherche_nom_patient(txt));}
        else    if(prenom!=""){
            QString txt=ui->lineEdit_prenom->text();
          ui->tableView_patient->setModel(tmppatient.recherche_prenom_patient(txt));}
            else if(numtel!="") {
            qDebug()<<numtel;
            QString txt=ui->lineEdit_numtel->text();
          ui->tableView_patient->setModel(tmppatient.recherche_num_patient(txt));}


}

void MainWindow::on_pushButton_Ajouter2_clicked()
{
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    ui->lineEdit_numtel->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    int id = ui->lineEdit_idpatient->text().toInt();
    QString idm = ui->lineEdit_idmed->text();
    QString nomm=ui->lineEdit_idmed_2->text();
    QString descr = ui->plainTextEdit_desc->toPlainText();
    QString dater = ui->dateTimeEdit->text();
    rendezvous e(id,dater,descr,idm,nomm);
    bool test = e.ajouter();
    if(test)
    {
        ui->tableView_rdv->setModel(tmprendezvous.afficher());

    QMessageBox::information(nullptr,QObject::tr("ajouter un rendezvous"),QObject::tr("rendezvous ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajouter un rendezvous"),
                    QObject::tr("erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->lineEdit_idpatient->clear();
    ui->lineEdit_idmed->clear();
     ui->lineEdit_idmed_2->clear();
    ui->plainTextEdit_desc->clear();
    ui->dateTimeEdit->clear();
    notification nf;
            nf.notificationC();
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
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    ui->lineEdit_numtel->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
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
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    ui->lineEdit_numtel->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    int id = ui->lineEdit_idpatient->text().toInt();
    QString idm = ui->lineEdit_idmed->text();
    QString nomm=ui->lineEdit_idmed_2->text();
    QString descr = ui->plainTextEdit_desc->toPlainText();
    QString dater = ui->dateTimeEdit->text();
    rendezvous e(id,dater,descr,idm,nomm);
    bool test = e.modifier();
    if(test)
    {
        ui->tableView_rdv->setModel(tmprendezvous.afficher());

    QMessageBox::information(nullptr,QObject::tr("modifier un rendez vous"),QObject::tr("success. \n ""click cancel to exit."),QMessageBox::Cancel);
    }
    ui->lineEdit_idpatient->clear();
    ui->lineEdit_idmed->clear();
     ui->lineEdit_idmed_2->clear();
    ui->plainTextEdit_desc->clear();
}

void MainWindow::on_pushButton_pdf_clicked()
{


    QString strStream;
        QTextStream out(&strStream);
        const int rowCount1 = ui->tableView_patient->model()->rowCount();
        const int columnCoun1t =  ui->tableView_patient->model()->columnCount();
        const QString strTitle ="Document";
        out <<  "<html>\n"
                "   <img src='C:/Users/arouj/OneDrive/Desktop/2A/projet/e-care.png' height='257' width='573'/>"
            "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             "<img src='e-care.png'>"
            <<  QString("<title>%1</title>\n").arg(strTitle)
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
           << QString("<h3 style=\" font-size: 90px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des patients")
           <<"<br>"
            <<"<table border=1 cellspacing=0 cellpadding=40 >\n";

        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCoun1t; column++)
            if (!ui->tableView_patient->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_patient->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        for (int row = 0; row < rowCount1; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCoun1t; column++) {
                if (!ui->tableView_patient->isColumnHidden(column)) {
                    QString data =ui->tableView_patient->model()->data(ui->tableView_patient->model()->index(row, column)).toString().simplified();
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
        printer.setOutputFileName("/tmp/patient.pdf");
        printer.setPageMargins(QMarginsF(15, 15, 15, 15));
        delete document;
}

void MainWindow::on_pushButton_49_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount1 = ui->tableView_rdv->model()->rowCount();
        const int columnCoun1t =  ui->tableView_rdv->model()->columnCount();
        const QString strTitle ="Document";
        out <<  "<html>\n"
                "   <img src='C:/Users/arouj/OneDrive/Desktop/2A/projet/e-care.png' height='257' width='573'/>"
            "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             "<img src='e-care.png'>"
            <<  QString("<title>%1</title>\n").arg(strTitle)
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
           << QString("<h3 style=\" font-size: 90px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des rendez vous")
           <<"<br>"
            <<"<table border=1 cellspacing=0 cellpadding=40 >\n";

        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCoun1t; column++)
            if (!ui->tableView_rdv->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_rdv->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        for (int row = 0; row < rowCount1; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCoun1t; column++) {
                if (!ui->tableView_rdv->isColumnHidden(column)) {
                    QString data =ui->tableView_rdv->model()->data(ui->tableView_rdv->model()->index(row, column)).toString().simplified();
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
        printer.setOutputFileName("/tmp/patient.pdf");
        printer.setPageMargins(QMarginsF(15, 15, 15, 15));
        delete document;
}


int MainWindow::getselectedpatient()
{
int s=ui->tableView_patient->selectionModel()->currentIndex().row();
QModelIndex index =ui->tableView_patient->model()->index(s, 0,QModelIndex());
int aff=ui->tableView_patient->model()->data(index).toString().toInt();
return aff;
}
void MainWindow::on_pushButton_39_clicked()
{
    QString tri=ui->comboBox_5->currentText();

        if(tri=="id"){
      ui->tableView_patient->setModel(tmppatient.ordre_id_patient());}
        else if(tri=="nom"){
            ui->tableView_patient->setModel(tmppatient.ordre_nom_patient());}
        else if(tri=="prenom"){
 ui->tableView_patient->setModel(tmppatient.ordre_prenom_patient());}}

void MainWindow::on_pushButton_40_clicked()
{
    ui->tableView_patient->setModel(tmppatient.afficher());

}

void MainWindow::on_pushButton_41_clicked()
{
    ui->tableView_rdv->setModel(tmprendezvous.afficher());

}
/*
 4
4
44
4
4
4
44
4
*/
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
/*********************************************************************/


void MainWindow::on_pushButton_870_clicked()
{
    ui->tableView_5->setModel(tserv.afficher_service());
}

void MainWindow::on_pushButton_750_clicked()
{
    ui->tableView_6->setModel(tmpemployee.afficher_employe());
}

void MainWindow::on_pushButton_880_clicked()
{
d.exec();
}



void MainWindow::on_pushButton_pdf_2_clicked()
{
    d2.exec();
}


void MainWindow::on_pushButton_246_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(3);

}
/*************************************************************************************************************/
/********************SCANNER*************************/

//fonction init
void MainWindow::init_scan()
{
    ui->lineEdit_40->setEnabled(1);
    ui->lineEdit_40->clear();
    ui->lineEdit_31->clear();
    ui->lineEdit_33->clear();
    ui->lineEdit_34->clear();

    ui->lineEdit_28->clear();
}
//click affichage
void MainWindow::on_afficher_scanner_activated(const QModelIndex &index)
{
    QString val=ui->afficher_scanner->model()->data(index).toString();
    QSqlQuery qry ;


    qry=tempscanner.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->lineEdit_40->setDisabled(1);
            ui->lineEdit_40->setText(qry.value(0).toString());
            ui->lineEdit_31->setText(qry.value(1).toString());
            ui->lineEdit_33->setText(qry.value(2).toString());
            ui->dateEdit_9->setDate(qry.value(3).toDate());
            ui->lineEdit_34->setText(qry.value(4).toString());
            if (qry.value(5).toString()=="Analyse")
            {ui->traitement_Analyse->setChecked(true);}
            if (qry.value(5).toString()=="Scanner")
            {ui->traitement_Scanner->setChecked(true);}

            ui->lineEdit_28->setText(qry.value(6).toString());
        }
    }
}
// ajout scanner
void MainWindow::on_pushButton_79_clicked()
{
    //  int cin=ui->stackedWidget_6->lineEdit_40->text().toInt();
    int cin =ui->lineEdit_40->text().toInt();
    QString nom=ui->lineEdit_31->text();
    QString prenom=ui->lineEdit_33->text();
    QString date_n=ui->dateEdit_9->date().toString();
    int telephone=ui->lineEdit_34->text().toInt();
    QString traitement;
    if (ui->traitement_Analyse->isChecked())
    {traitement="Analyse";}
    if (ui->traitement_Scanner->isChecked())
    { traitement="Scanner";}
    QString email = ui->lineEdit_28->text();


    scanner c(cin,nom,prenom,date_n,telephone,traitement,email);
    bool test=c.ajouter_scanner();
    if (test)
    {

        QFile file("C:/Users/HP/Desktop/Histori/HistoriqueClientScanner.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
            return;
        //converti int -> string
        QString res2= QString::number(cin);
        QString res= QString::number(telephone);
        QTextStream cout(&file);
        QString message2="\nClient Scanner a été ajoutée sous :\n cin :"+res2+"\nnom : "+nom+" \ntel:"+res+"";
        cout << message2;
       /* if (traitement=="Analyse")
        {
            int ref,stock;
            QString remarque , cin, nom;
            ressource R (ref,stock,remarque, cin, nom);
            tempscanner.Modifier_Stock(R);
        }*/
        ui->afficher_scanner->setModel(tempscanner.afficher_scanner());
        init_scan();
        //on_pushButton_91_clicked();
        // QMessageBox::information(nullptr, QObject::tr("Ajout"),
        //QObject::tr("Ajout avec succée"), QMessageBox::Ok);
        // hide();
    }
    /* else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }*/

}
//supprimer scanner
void MainWindow::on_pushButton_82_clicked()
{
    int id=ui->lineEdit_40->text().toUInt();
    bool test=tempscanner.supprimer_scanner(id);
    if(test)
    {
        ui->afficher_scanner->setModel(tempscanner.afficher_scanner());
        init_scan();
        // QMessageBox::information(nullptr, QObject::tr("Supprimer"),
        // QObject::tr("Suppression avec succée"), QMessageBox::Ok);
        // hide();
    }
    /*  else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }*/
}

//modifier scanner
void MainWindow::on_pushButton_76_clicked()
{
    int cin =ui->lineEdit_40->text().toInt();
    QString nom=ui->lineEdit_31->text();
    QString prenom=ui->lineEdit_33->text();
    QString date_n=ui->dateEdit_9->date().toString();
    int telephone=ui->lineEdit_34->text().toInt();
    QString traitement;
    if (ui->traitement_Analyse->isChecked())
    {traitement="Analyse";}
    if (ui->traitement_Scanner->isChecked())
    { traitement="Scanner";}
    QString email = ui->lineEdit_28->text();


    scanner c(cin,nom,prenom,date_n,telephone,traitement,email);
    bool test=c.modifier_scanner(c);
    if(test)
    {

        ui->afficher_scanner->setModel(tempscanner.afficher_scanner());//refresh
        init_scan();

        /* QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                 QObject::tr("Modification avec succees.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);*/

    }
    /* else
        QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);*/
}
//imprimer scanner
void MainWindow::on_pushButton_81_clicked()
{
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("Print Livre");
    d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (d.exec() != QDialog::Accepted)
        return ;
}
//recherche scanner
void MainWindow::on_lineEdit_36_textEdited(const QString &arg1)
{
    value=arg1;
    ui->afficher_scanner->setModel(tempscanner.Recherche(value)) ;
}
//trie cin decroissant
void MainWindow::on_radioButton_12_clicked()
{
    ui->afficher_scanner->setModel(tempscanner.trier_cin_decroi());

}
//trien cin croissant
void MainWindow::on_radioButton_14_clicked()
{
    ui->afficher_scanner->setModel(tempscanner.trier_cin_croi());
}
//trier nom decroissant
void MainWindow::on_radioButton_clicked()
{
    ui->afficher_scanner->setModel(tempscanner.trier_nom_decroi());
}
//trier nom croissant
void MainWindow::on_radioButton_2_clicked()
{
    ui->afficher_scanner->setModel(tempscanner.trier_nom_croi());
}
//trier email decroissant
void MainWindow::on_radioButton_3_clicked()
{
    ui->afficher_scanner->setModel(tempscanner.trier_email_decroi());
}
//trier email croissant
void MainWindow::on_radioButton_4_clicked()
{
    ui->afficher_scanner->setModel(tempscanner.trier_email_croi());
}
//historique.txt
void MainWindow::on_pushButton_91_clicked()
{
    QFile file ("C:/Users/HP/Desktop/Histori/HistoriqueClientScanner.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->historique_client_ressource->setText(in.readAll());
}
//recherche historique
void MainWindow::on_pushButton_92_clicked()
{
    QString searchString = ui->lineEdit_29->text();
    QTextDocument *document = ui->historique_client_ressource->document();
    on_pushButton_91_clicked();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}
//refech
void MainWindow::on_pushButton_88_clicked()
{
    ui->afficher_scanner->setModel(tempscanner.afficher_scanner());//refresh
    init_scan();
}

/********************RESSOURCE*************************/
//init ressource
void MainWindow::init_ressource()
{
      ui->Ref_R->setEnabled(1);
    ui->Ref_R->clear();
     ui->stock->setValue(0);
    ui->lineEdit_30->clear();
    ui->remarque->clear();

}

//ajout ressource

void MainWindow::on_pushButton_109_clicked()
{
    int ref =ui->Ref_R->text().toInt();
    int stock=ui->stock->text().toInt();
    //QString date = ui->dateEdit_11->date().toString();
    QString remarque=ui->remarque->toPlainText();

    QAbstractItemModel * model = ui->comboBox_fournisseur->model();
    QString cinfk = model->data(model->index(ui->comboBox_fournisseur->currentIndex(),1)).toString();
    QString nomstock=ui->lineEdit_30->text();
    ressource c(ref,stock,remarque,cinfk,nomstock);
    qDebug() << cinfk ;
    bool test=c.ajouter_ressource();
    if (test)
    {
        QFile file("C:/Users/HP/Desktop/Histori/HistoriqueRessource.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
            return;
        //converti int -> string
        QString res2= QString::number(ref);
        QString res= QString::number(stock);
        QTextStream cout(&file);
        QString message2="\nRessource Traitemnt a été ajoutée sous :\n ref :"+res2+"\nstock : "+res+" \nremarque:"+remarque+"";
        cout << message2;
        ui->afficher_ressource->setModel(tempressource.afficher_ressource());
        init_ressource();
       /* QMessageBox::information(nullptr, QObject::tr("Ajout"),
                                 QObject::tr("Ajout avec succée"), QMessageBox::Ok);
        // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                              QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }*/

}
}


//supprimer ressource

void MainWindow::on_pushButton_111_clicked()
{
    int ref=ui->Ref_R->text().toUInt();
    bool test=tempressource.supprimer_ressource(ref);
    if(test)
    {
        ui->afficher_ressource->setModel(tempressource.afficher_ressource());
        init_ressource();
       /* QMessageBox::information(nullptr, QObject::tr("Supprimer"),
                                 QObject::tr("Suppression avec succée"), QMessageBox::Ok);
        // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
                              QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }*/
    }
}


//modifier ressource

void MainWindow::on_pushButton_110_clicked()
{
    int ref =ui->Ref_R->text().toInt();
    int stock=ui->stock->text().toInt();
   // QString date = ui->dateEdit_11->date().toString();
    QString remarque=ui->remarque->toPlainText();
    QAbstractItemModel * model = ui->comboBox_fournisseur->model();
    QString cinf = model->data(model->index(ui->comboBox_fournisseur->currentIndex(),1)).toString();
    QString nomstock = ui->lineEdit_30->text();

    ressource c(ref,stock,remarque,cinf,nomstock);
    bool test=c.modifier_ressource(c);
    if(test)
    {

        ui->afficher_ressource->setModel(tempressource.afficher_ressource());
       init_ressource();
      /*  QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                 QObject::tr("Modification avec succees.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);*/
    }
}

//table clicked ressource
void MainWindow::on_afficher_ressource_activated(const QModelIndex &index)
{

    QString val=ui->afficher_ressource->model()->data(index).toString();
    QSqlQuery qry ;


    qry=tempressource.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->Ref_R->setDisabled(1);
            ui->Ref_R->setText(qry.value(0).toString());
            ui->stock->setValue(qry.value(1).toInt());
            //ui->dateEdit_11->setDate(qry.value(2).toDate());
            ui->remarque->setText(qry.value(2).toString());
            ui->comboBox_fournisseur->setCurrentText(qry.value(3).toString());
            ui->lineEdit_30->setText(qry.value(4).toString());
        }
    }

}
//recherche
void MainWindow::on_lineEdit_39_textEdited(const QString &arg1)
{
    value=arg1;
    ui->afficher_ressource->setModel(tempressource.Rechercher(value)) ;
}
//tri ref decroissant

void MainWindow::on_radioButton_11_clicked() //trie ressource
{
    ui->afficher_ressource->setModel(tempressource.trier_ref_Stock_decroi());
}
//tri ref croissant
void MainWindow::on_radioButton_13_clicked()
{
    ui->afficher_ressource->setModel(tempressource.trier_ref_Stock_croi());
}
//nom stock decroissant
void MainWindow::on_radioButton_9_clicked()
{

    ui->afficher_ressource->setModel(tempressource.trier_nom_Stock_decroi());
}
//nom stock croissant
void MainWindow::on_radioButton_10_clicked()
{

    ui->afficher_ressource->setModel(tempressource.trier_nom_Stock_croi());
}
//stock decroissant
void MainWindow::on_radioButton_17_clicked()
{

    ui->afficher_ressource->setModel(tempressource.trier_Stock_decroi());
}
//stock croissant
void MainWindow::on_radioButton_18_clicked()
{

    ui->afficher_ressource->setModel(tempressource.trier_Stock_croi());
}
//afficher ressource
void MainWindow::on_pushButton_106_clicked()
{
     ui->afficher_ressource->setModel(tempressource.afficher_ressource());
     init_ressource();
}
//affiche historique ressource
void MainWindow::on_pushButton_108_clicked()
{
    QFile file ("C:/Users/HP/Desktop/Histori/HistoriqueRessource.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->historique_ressource->setText(in.readAll());
}
//recherche historique ressource
void MainWindow::on_pushButton_107_clicked()
{
    QString searchString = ui->lineEdit_49->text();
    QTextDocument *document = ui->historique_ressource->document();

    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}
/****************impression****************/

void MainWindow::on_pushButton_83_clicked()
{
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("Print Livre");
    d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (d.exec() != QDialog::Accepted)
        return ;
}









/****************pdf****************/

void MainWindow::on_pushButton_84_clicked()

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

    QString val=ui->afficher_ressource->model()->data(index).toString();
    QSqlQuery qry ;

    qry=tempressource.tableclicked(val);

    if (qry.exec())
    {
        while (qry.next())
        {
            ui->Ref_R->setDisabled(1);
            ui->Ref_R->setText(qry.value(0).toString());
            ui->stock->setValue(qry.value(1).toInt());
            //ui->dateEdit_11->setDate(qry.value(2).toDate());

            ui->remarque->setText(qry.value(2).toString());
            ui->lineEdit_30->setText(qry.value(3).toString());


        }
    }
}

void MainWindow::on_pushButton_77_clicked()
{
    sre=new stat_ressource (this);
    sre->show();
}




//0

//****************************fournisseur*****************************
//init fournisseur
void MainWindow::init_fournisseur()
{
    ui->Cin_F->setEnabled(1);
    ui->Cin_F->clear();
    ui->Nom_F->clear();
    ui->Prenom_F->clear();
    ui->age->setValue(0);
    ui->N_Tel_F->clear();
    ui->Adresse_F->clear();
    ui->photo->clear();
    ui->chemin_photo->clear();
}
//ajouter image

void MainWindow::on_pushButton_102_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_photo->setText(filename);
            image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
            ui->photo->setPixmap(QPixmap::fromImage(image));
        }
    }
}
//capture image

void MainWindow::on_pushButton_103_clicked()
{
    c=new capture(this);
    c->show();
}
//ajouter fournisseur
void MainWindow::on_pushButton_95_clicked()
{
    QString cinf =ui->Cin_F->text();
    QString nomf=ui->Nom_F->text();
    QString prenomf=ui->Prenom_F->text();
    int agef=ui->age->text().toInt();
    int telf=ui->N_Tel_F->text().toInt();
    QString adressef=ui->Adresse_F->text();
    QString photof = ui->chemin_photo->text();


    fournisseur1 c(cinf,nomf,prenomf,agef,telf,adressef,photof);
    bool test=c.ajouter_fournisseur();
    if (test)
    {

        QFile file("C:/Users/HP/Desktop/Histori/Historiquefournisseur.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
            return;
        //converti int -> string
        /*QString res2= QString::number(cin);*/
        QString res= QString::number(telf);
        QTextStream cout(&file);
        QString message2="\nFournisseur a été ajoutée sous :\n cin :"+cinf+"\nnom : "+nomf+" \ntel:"+res+"";
        cout << message2;

        ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());
         ui->comboBox_fournisseur->setModel(tmpf.afficher_Flist());
        init_fournisseur();
    }
}
//afficher fourrnisseur
void MainWindow::on_pushButton_101_clicked()
{
    ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());
    init_fournisseur();
}
//table clicked
void MainWindow::on_afficher_fournisseur_activated(const QModelIndex &index)
{

    QString val=ui->afficher_fournisseur->model()->data(index).toString();
    QSqlQuery qry ;


    qry=tmpf.tableclicked(val);
    if (qry.exec())
    {
        while (qry.next())
        {

            ui->Cin_F->setDisabled(1);
            ui->Cin_F->setText(qry.value(0).toString());
            ui->Nom_F->setText(qry.value(1).toString());
            ui->Prenom_F->setText(qry.value(2).toString());

            ui->age->setValue(qry.value(3).toInt());
            ui->N_Tel_F->setText(qry.value(4).toString());
            ui->Adresse_F->setText(qry.value(5).toString());
            ui->chemin_photo->setText(qry.value(6).toString());
            QPixmap pix(ui->chemin_photo->text());
            int w =ui->photo->width();
            int h =ui->photo->height();
            ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
}
//supp fournisseur
void MainWindow::on_pushButton_97_clicked()
{
    int id=ui->Cin_F->text().toUInt();
    bool test=tmpf.supprimer_fournisseur(id);
    if(test)
    {
        ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());
         ui->comboBox_fournisseur->setModel(tmpf.afficher_Flist());
        init_fournisseur();
    }
}
//modif fournisseur
void MainWindow::on_pushButton_96_clicked()
{
    QString cinf =ui->Cin_F->text();
    QString nomf=ui->Nom_F->text();
    QString prenomf=ui->Prenom_F->text();
    int agef=ui->age->text().toInt();
    int telf=ui->N_Tel_F->text().toInt();
    QString adressef=ui->Adresse_F->text();
    QString photof = ui->chemin_photo->text();


    fournisseur1 c(cinf,nomf,prenomf,agef,telf,adressef,photof);
    bool test=c.modifier_fournisseur(c);
    if(test)
    {

        ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());//refresh
         ui->comboBox_fournisseur->setModel(tmpf.afficher_Flist());
        init_fournisseur();
    }
}

//RECHERCH
void MainWindow::on_lineEdit_46_textEdited(const QString &arg1)
{
    value=arg1;
    ui->afficher_fournisseur->setModel(tmpf.Recherche(value)) ;
}
//cin decroi
void MainWindow::on_radioButton_15_clicked()
{
 ui->afficher_fournisseur->setModel(tmpf.trier_cin_decroi());
}
//cin croi
void MainWindow::on_radioButton_16_clicked()
{
 ui->afficher_fournisseur->setModel(tmpf.trier_cin_croi());
}
//nom dec
void MainWindow::on_radioButton_5_clicked()
{
 ui->afficher_fournisseur->setModel(tmpf.trier_nom_decroi());
}
//nom croi
void MainWindow::on_radioButton_6_clicked()
{
 ui->afficher_fournisseur->setModel(tmpf.trier_nom_croi());
}
//age dec
void MainWindow::on_radioButton_7_clicked()
{
 ui->afficher_fournisseur->setModel(tmpf.trier_age_decroi());
}
//age crois
void MainWindow::on_radioButton_8_clicked()
{
 ui->afficher_fournisseur->setModel(tmpf.trier_age_croi());
}
//modif image
void MainWindow::on_pushButton_104_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin_photo->setText(filename);
            image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
            ui->photo->setPixmap(QPixmap::fromImage(image));
        }
    }
}
//image rotation convertion zoom
void MainWindow::on_pushButton_105_clicked()
{
    image p;
    p.setchemin(ui->chemin_photo->text());
    p.exec();
}
//historique fournisseur
void MainWindow::on_pushButton_99_clicked()
{
    QFile file ("C:/Users/HP/Desktop/Histori/Historiquefournisseur.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in (&file);
    ui->historique_fournisseur_ressource->setText(in.readAll());
}
//recherche historique fournisseur
void MainWindow::on_pushButton_100_clicked()
{
    QString searchString = ui->lineEdit_47->text();
    QTextDocument *document = ui->historique_fournisseur_ressource->document();
    on_pushButton_99_clicked();
    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();


        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);

            }
        }


        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}


void MainWindow::on_pushButton_114_clicked()
{
     ui->stackedWidget_6->setCurrentIndex(3);
}

void MainWindow::on_pushButton_112_clicked()
{
    d3.exec();
    /*** ui->stackedWidget_6->setCurrentIndex(1);*/
}

void MainWindow::on_pushButton_113_clicked()
{
      ui->stackedWidget_6->setCurrentIndex(2);
}



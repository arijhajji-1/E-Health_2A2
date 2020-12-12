#include "MainWindow.h"
#include "ui_mainwindow.h"
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
    //on_pushButton_78_clicked();
    ui->afficher_ressource->setModel(tempressource.afficher_ressource());
    ui->afficher_scanner->setModel(tempscanner.afficher_scanner());
    ui->afficher_fournisseur->setModel(tmpf.afficher_fournisseur());

    ui->lineEdit_40->setValidator(new QIntValidator(0,99999999,this));
    ui->Ref_R->setValidator(new QIntValidator(0,99999999,this));
    ui->Ref_R->setEnabled(1);
    ui->lineEdit_40->setEnabled(1);
    ui->lineEdit_45->setEnabled(1);
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
void MainWindow::on_pushButton_87_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(3);
}

void MainWindow::on_pushButton_90_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
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

        QFile file("C:\\Users\\dell\\Desktop\\project 1.2\\historique\\HistoriqueClientScanner.txt");
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
    QFile file ("C:\\Users\\dell\\Desktop\\project 1.2\\historique\\HistoriqueClientScanner.txt");
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
        QFile file("C:\\Users\\dell\\Desktop\\project 1.2\\historique\\HistoriqueRessource.txt");
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
    QFile file ("C:\\Users\\dell\\Desktop\\project 1.2\\historique\\HistoriqueRessource.txt");
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
void MainWindow::on_lineEdit_39_windowIconTextChanged(const QString &iconText)
{

}

//****************************fournisseur*****************************
//init fournisseur
void MainWindow::init_fournisseur()
{
    ui->lineEdit_45->setEnabled(1);
    ui->lineEdit_45->clear();
    ui->lineEdit_41->clear();
    ui->lineEdit_42->clear();
    ui->age->setValue(0);
    ui->lineEdit_43->clear();
    ui->lineEdit_44->clear();
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
    QString cinf =ui->lineEdit_45->text();
    QString nomf=ui->lineEdit_41->text();
    QString prenomf=ui->lineEdit_42->text();
    int agef=ui->age->text().toInt();
    int telf=ui->lineEdit_43->text().toInt();
    QString adressef=ui->lineEdit_43->text();
    QString photof = ui->chemin_photo->text();


    fournisseur c(cinf,nomf,prenomf,agef,telf,adressef,photof);
    bool test=c.ajouter_fournisseur();
    if (test)
    {

        QFile file("C:\\Users\\dell\\Desktop\\project 1.2\\historique\\HistoriqueFournisseur.txt");
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

            ui->lineEdit_45->setDisabled(1);
            ui->lineEdit_45->setText(qry.value(0).toString());
            ui->lineEdit_41->setText(qry.value(1).toString());
            ui->lineEdit_42->setText(qry.value(2).toString());

            ui->age->setValue(qry.value(3).toInt());
            ui->lineEdit_43->setText(qry.value(4).toString());
            ui->lineEdit_44->setText(qry.value(5).toString());
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
    int id=ui->lineEdit_45->text().toUInt();
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
    QString cinf =ui->lineEdit_45->text();
    QString nomf=ui->lineEdit_41->text();
    QString prenomf=ui->lineEdit_42->text();
    int agef=ui->age->text().toInt();
    int telf=ui->lineEdit_43->text().toInt();
    QString adressef=ui->lineEdit_43->text();
    QString photof = ui->chemin_photo->text();


    fournisseur c(cinf,nomf,prenomf,agef,telf,adressef,photof);
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
    QFile file ("C:\\Users\\dell\\Desktop\\project 1.2\\historique\\HistoriqueFournisseur.txt");
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
     ui->stackedWidget_6->setCurrentIndex(1);
}

void MainWindow::on_pushButton_113_clicked()
{
      ui->stackedWidget_6->setCurrentIndex(2);
}





void MainWindow::on_label_110_linkActivated(const QString &link)
{

}

void MainWindow::on_label_111_linkActivated(const QString &link)
{

}

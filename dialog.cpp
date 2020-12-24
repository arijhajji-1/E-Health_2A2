#include "dialog.h"
#include "ui_dialog.h"
#include<QDebug>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QtSerialPort>
Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
   return serial;
}
int Arduino::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int Arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


QString Arduino::read_from_arduino()
{
    if(buffer.contains("\r\n")) buffer="";
    if(serial->isReadable()){

        serialdata=serial->readAll(); //récupérer les données reçues

        buffer=buffer+QString::fromStdString(serialdata.toStdString());

    return buffer;
    }
     serialdata.clear();

    return buffer;
 }


void Arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    son=new QSound("C:/Users/HP/Desktop/55/of.wav");
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::update_label()
{
    QString data=A.read_from_arduino();
      qDebug() <<data;
      ui->lineEdit->setText(data);
       QSqlQuery query;
      if (query.exec("SELECT *from ard WHERE id like '"+ui->lineEdit->text()+"'"))
      {
          int count=0;
          while(query.next())
          {
              count++;
          }
          if(count==1)
          {
          son->play();
            A.write_to_arduino("0"); //envoyer 1 à arduino
               qDebug() << "is logged in";
                ui->label_3->setText("authorise");
                ui->lineEdit->clear();
          }
          else
          {
            // QMessageBox::information(this,"conecter","id ou mdp incorrect");
             A.write_to_arduino("1");
          //  ui->label_3->setText(data);
             ui->lineEdit->clear();
          }
      }
}

void Dialog::on_pushButton_clicked()   // implémentation du slot bouton on
{
    QString id = ui->lineEdit->text();
       QSqlQuery query;
       if (query.exec("SELECT *from ard WHERE id like '"+id+"'"))
       {
           int count=0;
           while(query.next())
           {
               count++;
           }
           if(count==1)
           {
           son->play();
             A.write_to_arduino("0"); //envoyer 1 à arduino
              ui->label_3->setText("authorise");
                qDebug() << "is logged in";
           }
           else
           {
              QMessageBox::information(this,"conecter","id  incorrect");
              ui->label_3->setText("pas authorise");
                qDebug() << "is not logged in";
           }
       }

}

void Dialog::on_pushButton_2_clicked()  // implémentation du slot bouton off
{

     A.write_to_arduino("1");  //envoyer 0 à arduino
     ui->label_3->setText("authorise");
       qDebug() << "is nottttttlogged in";
}

void Dialog::on_pushButton_3_clicked()
{
      qDebug() << "is nottttttlogged in";
}




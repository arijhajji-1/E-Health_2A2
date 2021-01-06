#include "dialog3.h"
#include "ui_dialog3.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);  ui->setupUi(this);
    ui->temp_lcdNumber->display("-------");
     arduino = new QSerialPort(this);

     parsed_data = "";
    temperature_value = 0.0;

     /*
      *  Testing code, prints the description, vendor id, and product id of all ports.
      *  Used it to determine the values for the arduino uno.
      *
      *
     qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
     foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
         qDebug() << "Description: " << serialPortInfo.description() << "\n";
         qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
         qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
         qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
         qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
     }
     */


     /*
      *   Identify the port the arduino uno is on.
      */
     bool arduino_is_available = false;
     QString arduino_uno_port_name;
     //
     //  For each available serial port
     foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
         //  check if the serialport has both a product identifier and a vendor identifier
         if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
             //  check if the product ID and the vendor ID match those of the arduino uno
             if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                     && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                 arduino_is_available = true; //    arduino uno is available on this port
                 arduino_uno_port_name = serialPortInfo.portName();
             }
         }
     }


     if(arduino_is_available){
         qDebug() << "Found the arduino port...\n";
         arduino->setPortName(arduino_uno_port_name);
         arduino->open(QSerialPort::ReadOnly);
         arduino->setBaudRate(QSerialPort::Baud9600);
         arduino->setDataBits(QSerialPort::Data8);
         arduino->setFlowControl(QSerialPort::NoFlowControl);
         arduino->setParity(QSerialPort::NoParity);
         arduino->setStopBits(QSerialPort::OneStop);
         QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
     }else{
        /* qDebug() << "Couldn't find the correct port for the arduino.\n";
         QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");*/
     }
}

Dialog3::~Dialog3()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}
void Dialog3::readSerial()
{


        serialData = arduino->readAll();
       parsed_data= QString::fromStdString(serialData.toStdString());
temperature_value = parsed_data.toFloat() * (5.0 / 1023.0 * 100.0);
        qDebug() << "Temperature: " << temperature_value ;

Dialog3::updateTemperature(parsed_data);



}

void Dialog3::updateTemperature(QString sensor_reading)
{
    bool test=0;
QString m;


    m=sensor_reading;
    temperature_value = m.toFloat() * (5.0 / 1023.0 * 100.0);
    ui->temp_lcdNumber->display(temperature_value);

    if(temperature_value > 10.00)
        test=1;

            if(test)
            {

                /*QMessageBox::information(nullptr, QObject::tr("Warning"),
                            QObject::tr("Activer la Ventilation.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/

         }

}

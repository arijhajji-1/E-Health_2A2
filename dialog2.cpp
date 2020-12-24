#include "dialog2.h"
#include "ui_dialog2.h"
arduino::arduino()
{
data="";
arduino_port_name="";
arduino_is_available=false;
serial=new QSerialPort;
}
QString arduino::getarduino_port_name()
{return arduino_port_name;}
QSerialPort* arduino::getserial()
{return  serial;}
int arduino::connect_arduino()
{
    foreach(const QSerialPortInfo& serial_port_info,QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier()&&serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_product_id)
            {
                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();
            }
        }

    }
   qDebug()<<"arduino port name:"<<arduino_port_name;
   if (arduino_is_available)
   {
       serial->setPortName(arduino_port_name);
       if (serial->open(QSerialPort::ReadWrite))
       {
           serial->setBaudRate(QSerialPort::Baud9600);
           serial->setDataBits(QSerialPort::Data8);
           serial->setParity(QSerialPort::NoParity);
           serial->setStopBits(QSerialPort::OneStop);
           serial->setFlowControl(QSerialPort::NoFlowControl);
           return  0;
       }
       return  1;

   }
   return -1;
}
int arduino::close_arduino()
{
    if (serial->isOpen())
    {
        serial->close();
        return  0;
    }
    return  1;
}
void arduino::write_to_arduino(QByteArray d)
{
    if(serial->isWritable())
    {
        serial->write(d);
    }
    else {
        qDebug()<<"error en ecreture";
    }
}
QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable())
    {
        data=serial->readAll();
        return  data;
    }
return data;}
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
    switch (ret)
    {
    case(0):
        qDebug()<<"arduino is available and connected to:"<<A.getarduino_port_name();
        break;
    case(1):
        qDebug()<<"arduino is available but not connected to:"<<A.getarduino_port_name();
        break;
    case(-1):
        qDebug()<<"arduino is not available";


    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

Dialog2::~Dialog2()
{
    delete ui;
}
void Dialog2::on_pushButton_clicked()
{
    A.write_to_arduino("1");
}

void Dialog2::on_pushButton_2_clicked()
{
    A.write_to_arduino("0");
}
void Dialog2::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
    ui->label_3->setText("ON");
    else if (data=="0")
        ui->label_3->setText("OFF");


}


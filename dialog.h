#ifndef DIALOG_H
#define DIALOG_H
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

#include<QSound>
#include <QDialog>
class Arduino
{
public:     //méthodes de la classe Arduino
    Arduino();
    int connect_arduino(); // permet de connecter le PC à Arduino
    int close_arduino(); // permet de femer la connexion
    void write_to_arduino( QByteArray ); // envoyer des données vers arduino
    QString read_from_arduino();  //recevoir des données de la carte Arduino
    QSerialPort* getserial();   // accesseur
    QString getarduino_port_name();
    void set_buffer(){buffer="";}
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray  serialdata;
QString buffer;
QString data;
// contenant les données lues à partir d'Arduino
};
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_clicked();   // bouton ON

    void on_pushButton_2_clicked(); // bouton OFF

   // void on_label_2_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    QByteArray data; // variable contenant les données reçues

   Arduino A; // objet temporaire
      QSound *son;
};

#endif // DIALOG_H

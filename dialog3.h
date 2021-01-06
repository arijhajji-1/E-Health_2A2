#ifndef DIALOG3_H
#define DIALOG3_H


#include <QDialog>
#include <QSerialPort>
#include <QByteArray>


namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();
private slots:
    void readSerial();
    void updateTemperature(QString);
private:
    Ui::Dialog3 *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    float temperature_value;
};

#endif // DIALOG3_H

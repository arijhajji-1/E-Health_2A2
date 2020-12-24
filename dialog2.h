#ifndef DIALOG2_H
#define DIALOG2_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QDialog>


class arduino
{
public:
    arduino();
    int connect_arduino();
    int close_arduino();
    void write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();
private:
    QSerialPort* serial;
    static const quint16 arduino_uno_vendor_id=9025 ;
    static const quint16 arduino_uno_product_id=67 ;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;

};
/*QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void update_label();

private:
    Ui::MainWindow *ui;
    arduino A;
    QByteArray data;
};
*/


namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void update_label();
private:
    Ui::Dialog2 *ui;
    arduino A;
    QByteArray data;
};

#endif // DIALOG2_H

#ifndef STATI_H
#define STATI_H
#include <QDialog>
#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
namespace Ui {

class Stati;
}

class Stati : public QDialog
{
    Q_OBJECT

public:
    explicit Stati(QWidget *parent = nullptr);
    ~Stati();
    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;

    void paintEvent(QPaintEvent *) ;



private slots:
    void on_widget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Stati *ui;
};

#endif // STATI_H

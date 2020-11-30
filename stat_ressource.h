#ifndef STAT_RESSOURCE_H
#define STAT_RESSOURCE_H

#include <QMainWindow>
#include <QSqlQuery>
#include <iostream>
#include <QApplication>
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
class stat_ressource;
}

class stat_ressource : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat_ressource(QWidget *parent = nullptr);
    ~stat_ressource();

    int Statistique_partie2();
    int Statistique_partie3();
    int Statistique_partie4();
    void paintEvent(QPaintEvent *);
private:
    Ui::stat_ressource *ui;
};

#endif // STAT_RESSOURCE_H

#ifndef MATERIELS_H
#define MATERIELS_H
#include <QString>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Materiels
{
QString id,nom,dt1;

public:
    Materiels();
    Materiels(QString, QString, QString);
    QString getID(){return id;};
    QString getNom(){return nom;};
    QString getdt1(){return dt1;};

    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString &, QString &,QString &);
    QSqlQueryModel * trier(QString&,QString&);
    QSqlQueryModel * exporterPDF();
};

#endif // MATERIELS_H

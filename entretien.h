#ifndef ENTRETIEN_H
#define ENTRETIEN_H


#include <QString>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Entretien
{
QString id,dt2,dsc,idem;
int num;

public:
    Entretien();
    Entretien(QString,QString, int,QString,QString);
    QString getID(){return id;};
    int getNom(){return num;};
    QString getdt2(){return dt2;};
    QString getidem(){return idem;};
    QString getDsc(){return dsc;};


    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString &, QString &,QString &,QString &,QString &);
    QSqlQueryModel * trier(QString&,QString&);
    QSqlQueryModel * exporterPDF();
    QSqlQueryModel * listMateriels();
};
#endif // ENTRETIEN_H

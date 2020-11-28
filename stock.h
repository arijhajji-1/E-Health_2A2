#ifndef STOCK_H
#define STOCK_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class stock
{

public:
    stock();
    stock(int,QString,int,QString);
    QString getNom(){return nom;}
    int getRef(){return ref;}
    int getQtt(){return qtt;}
    QString getIdf(){return idf;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel *tri();
    QSqlQueryModel *recherche(QString);
    bool modifier();


private:
    int ref;
    QString nom;
    int qtt;
    QString idf;

};

#endif // STOCK_H

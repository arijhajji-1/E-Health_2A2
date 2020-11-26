#ifndef RESSOURCE_H
#define RESSOURCE_H
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ressource
{
public:
    ressource();
    ressource(int,int,QString,QString);

    bool ajouter_ressource();
    QSqlQueryModel * afficher_ressource();
    bool supprimer_ressource(int);
    bool modifier_ressource(int);
    QSqlQueryModel* Rechercher(QString);
    QSqlQueryModel * trierA1();
    QSqlQueryModel * trierB2();

private:
    int ref,stock;
    QString date,remarque;
};

#endif // RESSOURCE_H

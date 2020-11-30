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
    bool modifier_ressource(ressource);
    QSqlQueryModel* Rechercher(QString);
    QSqlQueryModel * trierA1();
    QSqlQueryModel * trierB2();
    QSqlQuery tableclicked(QString);


    int get_ref();
    int get_stock();
    QString get_date();
    QString get_remarque();
private:
    int ref,stock;
    QString date,remarque;
};

#endif // RESSOURCE_H

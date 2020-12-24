#ifndef RESSOURCE_H
#define RESSOURCE_H
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ressource
{
public:
    ressource();
    ressource(int,int,QString,QString,QString);

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
    QString get_cinfk();
    void set_ref(int ref);
    void set_stock(int stock);
    void set_date(int date);
    void set_remarque(int remarque);
    void set_cinfk(int cinfk);
    QSqlQueryModel *afficher_Rlist();
    ressource(int r, int s, QString re, QString cinfk);
    QString get_nomstock();
    void set_nomstock(QString nomstock);
    QSqlQueryModel *trier_ref_Stock();
    QSqlQueryModel *trier_ref_Stock_croi();
    QSqlQueryModel *trier_ref_Stock_decroi();
    QSqlQueryModel *trier_nom_Stock_decroi();
    QSqlQueryModel *trier_nom_Stock_croi();
    QSqlQueryModel *trier_Stock_croi();
    QSqlQueryModel *trier_Stock_decroi();
    bool Modifier_Stock(ressource R);
    bool Modifier_Stock();
private:
    int ref,stock;
    QString date,remarque,cinfk,nomstock;
};

#endif // RESSOURCE_H

#ifndef SCANNER_H
#define SCANNER_H
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"ressource.h"
class scanner
{
public:
    scanner();
    scanner(int,QString,QString,QString,int,QString,QString);

    bool ajouter_scanner();
    QSqlQueryModel * afficher_scanner();
    bool supprimer_scanner(int);
    bool modifier_scanner(int);
    QSqlQueryModel* Recherche(QString);
    QSqlQueryModel * trierA();
    QSqlQueryModel * trierB();

    QString get_fiscale();
    QString get_secteur_activite();

    QSqlQuery tableclicked(QString a);
    int get_cin();
    int get_tel();
    QString get_nom();
    QString get_prenom();
    QString get_dateN();
    QString get_traitement();
    QString get_email();
    void set_cin(int cin);
    void set_tel(int tel);
    void set_nom(QString nom);
    void set_prenom(QString prenom);
    void set_date(QString date);
    void set_traitement(QString traitement);
    void set_email(QString email);
    bool modifier_scanner(scanner s);
    QSqlQueryModel *trier_cin_decroi();
    QSqlQueryModel *trier_cin_croi();
    QSqlQueryModel *trier_nom_decroi();
    QSqlQueryModel *trier_nom_croi();
    QSqlQueryModel *trier_email_decroi();
    QSqlQueryModel *trier_email_croi();
    bool Modifier_Stock(ressource R);
    bool Modifier_Stock();
private:
    int cin,num_tlphn;
    QString nom,prenom,dateNaissance,email,traitement;
};

#endif // SCANNER_H

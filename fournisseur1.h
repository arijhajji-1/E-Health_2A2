#ifndef FOURNISSEUR1_H
#define FOURNISSEUR1_H
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QString>
class fournisseur1
{
public:
    fournisseur1();
    fournisseur1(QString cinf, QString nomf, QString prenomf, int agef, int telf, QString adressef, QString photof);
    int get_agef();
    int get_telf();
    QString get_cinf();
    QString get_nomf();
    QString get_prenomf();
    QString get_adressef();
    QString get_photof();
    void set_agef(int agef);
    void set_nomf(QString nomf);
    void set_prenomf(QString prenomf);
    void set_adressef(QString adressef);
    void set_cinf(QString cin);
    void set_telf(int telf);
    void set_photof(QString photof);
    bool ajouter_fournisseur();
    QSqlQueryModel *afficher_fournisseur();
    QSqlQuery tableclicked(QString a);
    bool supprimer_fournisseur(int idd);
    bool modifier_fournisseur(fournisseur1 s);
    QSqlQueryModel *Recherche(QString a);
    QSqlQueryModel *trier_cin_decroi();
    QSqlQueryModel *trier_cin_croi();
    QSqlQueryModel *trier_nom_croi();
    QSqlQueryModel *trier_nom_decroi();
    QSqlQueryModel *trier_age_croi();
    QSqlQueryModel *trier_age_decroi();
    QSqlQueryModel *afficher_Flist();
private:
    QString cinf,nomf,prenomf,adressef,photof;
    int agef,telf;
};

#endif // FOURNISSEUR1_H

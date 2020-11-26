#ifndef SCANNER_H
#define SCANNER_H
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

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

private:
    int cin,num_tlphn;
    QString nom,prenom,dateNaissance,date,analyse;
};

#endif // SCANNER_H

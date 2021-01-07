#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QFileDialog>



class fournisseur
{
public:
    fournisseur();
    fournisseur(QString,QString,QString,int);
    QString getNomf(){return nomf;}
    QString getAdrf(){return adrf;}
    QString getIdf(){return idf;}
    int getNumf(){return numf;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

private:
    QString nomf;
    QString adrf;
    QString idf;
    int numf;
};

#endif // FOURNISSEUR_H

#ifndef CLASSE_PERSONNEL_H
#define CLASSE_PERSONNEL_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class classe_personnel
{
public:
    classe_personnel();
    classe_personnel(QString,int,QString,QString,QString);
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_adress(){return specialite;}
    QString get_idp(){return idp;}
    int get_ntel(){return ntel;}
    bool ajouter_employe();
    bool supprimer_employe(QString);
    bool modifier_employe(QString);
    QSqlQueryModel *afficher_employe();
     QSqlQueryModel *afficher_employe1(QString);
    QSqlQueryModel *recherche_id_employe(QString);
     QSqlQueryModel *recherche_nom_employe(QString);
      QSqlQueryModel *recherche_prenom_employe(QString);
      QSqlQueryModel *ordre_id_employe();
      QSqlQueryModel *ordre_nom_employe();
      QSqlQueryModel *ordre_prenom_employe();
private:
    QString idp,nom,prenom,specialite;
    int ntel;
};

#endif // CLASSE_PERSONNEL_H

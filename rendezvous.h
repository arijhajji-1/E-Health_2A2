#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class rendezvous
{
public:

    rendezvous();
rendezvous(int,QString,QString,QString,QString);
QString get_date(){return dater;};
QString get_desc(){return descr;};
int get_id(){return id;};
QString get_idm(){return idm;};
bool ajouter();
bool modifier();
bool supprimer(int);
QSqlQueryModel * afficher();
QSqlQueryModel *recherche_idm_medecin(QString);
QSqlQueryModel *recherche_idp_patient(QString );
private:
QString dater,descr,nomm,idm;
int id;
};
#endif // RENDEZVOUS_H

#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class patient
{
public:

    patient();
patient(int,QString,QString,QString,int,QString);
QString get_nom(){return nom;};
QString get_prenom(){return prenom;};
QString get_adresse(){return adresse;};
QString get_maladie(){return maladie;};
int get_id(){return id;};
int get_numtel(){return numtel;};
bool ajouter();
bool modifier();
bool supprimer(int);
QSqlQueryModel * afficher();
QSqlQueryModel * recherche_id_patient(QString);
QSqlQueryModel *recherche_nom_patient(QString);
QSqlQueryModel * recherche_prenom_patient(QString);
 QSqlQueryModel  * recherche_num_patient(QString);
 QSqlQueryModel *ordre_id_patient();
  QSqlQueryModel *ordre_nom_patient();
   QSqlQueryModel *ordre_prenom_patient();
private:
QString nom,prenom,adresse,maladie;
int id,numtel;
};

#endif // PATIENT_H

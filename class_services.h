#ifndef CLASS_SERVICES_H
#define CLASS_SERVICES_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class class_services
{
public:
    class_services();
    class_services(QString,QString,QString,QString,QString);
    QString get_nom(){return nom;}
    QString get_date(){return date;}
    QString get_heured(){return heure_debut;}
    QString get_heuref(){return heure_fin;}
    QString get_idp(){return ids;}
    bool ajouter_service();
    bool supprimer_service(QString);
    bool modifier_service(QString,QString);
    QSqlQueryModel *afficher_service();
    QSqlQueryModel *recherche_id_service(QString);
     QSqlQueryModel *recherche_nom_service(QString);
      QSqlQueryModel *recherche_date_service(QString);
      QSqlQueryModel *ordre_id_service();
      QSqlQueryModel *ordre_nom_service();
      QSqlQueryModel *ordre_date_service();
private:
    QString ids,nom,date,heure_debut,heure_fin;
};

#endif // CLASS_SERVICES_H

#include "class_services.h"

class_services::class_services()
{
    ids="";
    nom="";
    date="";
    heure_debut="";
    heure_fin="";

}
class_services::class_services(QString id,QString nom1,QString date1,QString heured,QString heuref)
{
    ids=id;
    nom=nom1;
    date=date1;
    heure_debut=heured;
    heure_fin=heuref;
}
bool class_services::ajouter_service()
{
    QSqlQuery query;
    query.prepare("INSERT INTO services(ID,NOM,DATES,HEURE_DEBUT,HEURE_FIN)VALUES(:ids,:nom1,:date1,:heured,:heuref)");
    query.bindValue(":ids",ids);
    query.bindValue(":nom1",nom);
    query.bindValue(":date1",date);
    query.bindValue(":heured",heure_debut);
    query.bindValue(":heuref",heure_fin);

    return query.exec();
}
bool class_services::supprimer_service(QString id)
{
    QSqlQuery query;
     query.prepare("Delete from services where id= :ids");
     query.bindValue(":ids",id);
     return query.exec();
}
bool class_services::modifier_service(QString id ,QString nom)
{
    QSqlQuery query;
     query.prepare("Update services set dates=:date,heure_debut=:heured,heure_fin=:heuref where id=:ids and nom=:nom");
     query.bindValue(":ids",id);
     query.bindValue(":nom",nom);
     query.bindValue(":date",date);
     query.bindValue(":heured",heure_debut);
     query.bindValue(":heuref",heure_fin);
     return query.exec();
}
QSqlQueryModel* class_services::afficher_service()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from services");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_debut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_fin"));
    return model;
}
QSqlQueryModel *class_services::recherche_id_service(QString txt)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from services where id LIKE '"+txt+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_debut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_fin"));
    return model;
}
 QSqlQueryModel *class_services:: recherche_nom_service(QString txt)
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from services where nom LIKE '"+txt+"'" );
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_debut"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_fin"));
     return model;
 }
QSqlQueryModel * class_services::recherche_date_service(QString txt)
 {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from services where dates LIKE '"+txt+"'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_debut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_fin"));
    return model;
 }
 QSqlQueryModel *class_services::ordre_id_service()
  {
       QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from services  order by id" );
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_debut"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_fin"));
       return model;
  }
 QSqlQueryModel *class_services::ordre_nom_service()
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from services  order by nom" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_debut"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_fin"));
      return model;
  }
 QSqlQueryModel *class_services:: ordre_date_service()
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from services  order by dates" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_debut"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_fin"));
      return model;
  }

#include "classe_personnel.h"

classe_personnel::classe_personnel()
{
   idp="";
 ntel=0;
   nom="";
   prenom="";
   specialite="";

}
 classe_personnel:: classe_personnel(QString id,int w,QString n,QString p,QString ads)
{
    idp=id;
     ntel=w;
     nom=n;
     prenom=p;
     specialite=ads;

}
 bool classe_personnel::ajouter_employe()
 {
     QSqlQuery query;

     QString res1=QString::number(ntel);
     query.prepare("INSERT INTO staff(ID,NOM,PRENOM,NTEL,SPECIALIE)VALUES(:idp,:nom,:prenom,:ntel,:specialie)");
     query.bindValue(":idp",idp);
     query.bindValue(":ntel",res1);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":specialie",specialite);

     return query.exec();
 }
 bool classe_personnel::supprimer_employe(QString id)
 {
    QSqlQuery query;
     query.prepare("Delete from staff where id= :idp");
     query.bindValue(":idp",id);
     return query.exec();
 }
  bool classe_personnel::modifier_employe(QString id)
  {
     QSqlQuery query;
      QString res1=QString::number(ntel);
      // QString idp=QString::number(id);
      query.prepare("Update staff set nom=:nom,prenom=:prenom,specialie=:specialie,ntel=:ntel where id=:idp");
      query.bindValue(":idp",id);
       query.bindValue(":ntel",res1);
      query.bindValue(":nom",nom);
      query.bindValue(":prenom",prenom);
      query.bindValue(":specialie",specialite);


      return query.exec();
  }
  QSqlQueryModel *classe_personnel::afficher_employe()
  {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from staff");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("ntel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialie"));
      return model;
  }
  QSqlQueryModel *classe_personnel::afficher_employe1(QString txt)
  {
      QSqlQueryModel *model=new QSqlQueryModel();
           model->setQuery("select nom  from staff where id LIKE '"+txt+"'");
           return model;
  }
  QSqlQueryModel *classe_personnel::recherche_id_employe(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from staff where id LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("ntel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialie"));
      return model;
  }
  QSqlQueryModel *classe_personnel::recherche_nom_employe(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from staff where nom LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("ntel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialie"));
      return model;
  }
  QSqlQueryModel *classe_personnel::recherche_prenom_employe(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from staff where prenom LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("ntel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialie"));
      return model;
  }
   QSqlQueryModel *classe_personnel::ordre_id_employe()
   {
       QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from staff  order by id" );
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("ntel"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialie"));
       return model;
   }
   QSqlQueryModel *classe_personnel::ordre_nom_employe()
   {
       QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from staff  order by nom" );
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("ntel"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialie"));
       return model;
   }
   QSqlQueryModel *classe_personnel::ordre_prenom_employe()
   {
       QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("select * from staff  order by prenom" );
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("ntel"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialie"));
       return model;
   }

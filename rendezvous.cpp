#include "rendezvous.h"

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
rendezvous::rendezvous()
{
id=0;
dater="";
descr="";
idm="";
nomm="";

}
rendezvous::rendezvous(int id,QString dater,QString descr,QString idm,QString nomm)
{
    this->id=id;
    this->idm=idm;
            this->dater=dater;
    this->descr=descr;
   this->nomm=nomm;

}
bool rendezvous::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("insert into rendezvous (id,dater,descr,idm,nomm) values (:id,:dater,:descr,:idm,:nomm)");

query.bindValue(":id",res);
query.bindValue(":dater",dater);
query.bindValue(":descr",descr);
query.bindValue(":idm",idm);
query.bindValue(":nomm",nomm);
return query.exec();
}
QSqlQueryModel * rendezvous::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model ->setQuery("select * from rendezvous");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("dater"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("descr"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("idmed"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nomm"));
    return model;
}
bool rendezvous::supprimer(int iddd)
{
    QSqlQuery query;
    QString res=QString::number(iddd);
    query.prepare("Delete from rendezvous where id =:id");
    query.bindValue(":id",res);
    return query.exec();
}
bool rendezvous::modifier()
{
    QSqlQuery query;
    QString res=QString::number(id);


    query.prepare("UPDATE  rendezvous set dater=:dater,descr=:descr where id=:idr and idm=:idm and nomm=:nomm");
query.bindValue(":idr",res);
query.bindValue(":dater",dater);
query.bindValue(":descr",descr);
query.bindValue(":idm",idm);
query.bindValue(":nomm",nomm);
return query.exec();
}
QSqlQueryModel *rendezvous::recherche_idp_patient(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from rendezvous where id LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("dater"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("descr"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("idmed"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("nomm"));

      return model;
  }
  QSqlQueryModel *rendezvous::recherche_idm_medecin(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from rendezvous where idm LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("dater"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("descr"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("idmed"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("nomm"));

      return model;
  }

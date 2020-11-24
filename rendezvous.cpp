#include "rendezvous.h"

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
rendezvous::rendezvous()
{
id=0;
dater="";
descr="";
idm=0;

}
rendezvous::rendezvous(int id,QString dater,QString descr,int idm )
{
    this->id=id;
    this->idm=idm;
            this->dater=dater;
    this->descr=descr;


}
bool rendezvous::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString ress=QString::number(idm);
    query.prepare("insert into rendezvous (id,dater,descr,idm) values (seq_username.nextval,:id,:dater,:descr,:idm)");

query.bindValue(":id",res);
query.bindValue(":dater",dater);
query.bindValue(":descr",descr);
query.bindValue(":idm",ress);
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
    QString ress=QString::number(idm);

    query.prepare("UPDATE  rendezvous set dater=:dater,descr=:descr where id=:idr and idm=:idm");
query.bindValue(":idr",res);
query.bindValue(":dater",dater);
query.bindValue(":descr",descr);
query.bindValue(":idm",ress);
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

      return model;
  }

#include "materiels.h"
#include <QtCore>

Materiels::Materiels()
{
  id="";;
  nom="";
  dt1="";

}

Materiels::Materiels(QString i, QString n, QString d)
{
  id=i;
  nom=n;
  dt1=d;

}




bool Materiels::ajouter()
{
  QSqlQuery query;
 query.prepare("INSERT INTO MATERIELS (ID,NOM,DATE_AJOUT)"
               "VALUES(:id,:nom,:dt1)");


  query.bindValue(":id",id);
  query.bindValue(":nom",nom);
  query.bindValue(":dt1",dt1);

return query.exec();

}

QSqlQueryModel *Materiels::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from Materiels");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date d'ajout"));
   return model;
}

bool Materiels::supprimer(QString idm)
{
    QSqlQuery query;
    QString id=QString(idm);
    query.prepare("Delete from materiels where ID=:id");
    query.bindValue(":id",idm);
    return query.exec();


}

bool Materiels::modifier()
{
    QSqlQuery query;
    QString idm=QString(id);
   query.prepare("UPDATE materiels SET NOM=:nom,DATE_AJOUT=:dt1 where ID=:idm");
    query.bindValue(":idm",idm);
    query.bindValue(":nom",nom);
    query.bindValue(":dt1",dt1);
    return query.exec();
}

QSqlQueryModel *Materiels::rechercher(QString &a,QString &b,QString &c)
{
    QSqlQueryModel *model=new QSqlQueryModel();

   model->setQuery("select * from materiels where(ID LIKE '"+a+"%') AND (NOM LIKE '"+b+"%') AND (DATE_AJOUT LIKE '"+c+"%') ");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date d'ajout"));
    return model;
}

QSqlQueryModel * Materiels::trier(QString& choice,QString& a)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if ((choice=="ID")and(a=="decroissant"))
        model->setQuery("SELECT * FROM MATERIELS ORDER BY id Desc ");

        else if ((choice=="Nom")and(a=="decroissant"))
          model->setQuery("SELECT * FROM MATERIELS ORDER BY nom Desc ");


    if ((choice=="ID")and(a=="croissant"))
        model->setQuery("SELECT * FROM MATERIELS ORDER BY id ASC ");

        else if ((choice=="Nom")and(a=="croissant"))
    {
          model->setQuery("SELECT * FROM MATERIELS ORDER BY nom ASC ");
    }


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date d'ajout"));
    return model;
}

QSqlQueryModel * Materiels::exporterPDF()
{

    QSqlQueryModel * Model=new  QSqlQueryModel();

    QSqlQuery qry;
     qry.prepare("SELECT * FROM MATERIELS ");
     qry.exec();
     Model->setQuery(qry);

     return Model;
}

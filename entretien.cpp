#include "entretien.h"

Entretien::Entretien()
{
  id="";
  idem="";
  num=0;
  dsc="";
  dt2="";


}

Entretien::Entretien(QString i,QString im, int n,QString d, QString dt)
{
  id=i;
  idem=im;
  num=n;
  dsc=d;
  dt2=dt;


}




bool Entretien::ajouter()
{
  QSqlQuery query;
  QString numero=QString::number(num);
 query.prepare("INSERT INTO ENTRETIEN (ID,IDM,NUM,DESCRIPTION,DATE_ENVOI)"
               "VALUES(:id,:idem,:num,:dsc,:dt2)");


  query.bindValue(":id",id);
  query.bindValue(":idem",idem);
  query.bindValue(":num",numero);
  query.bindValue(":dsc",dsc);
  query.bindValue(":dt2",dt2);


return query.exec();

}

QSqlQueryModel *Entretien::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from Entretien");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant entretien"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Identifiant materiel"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Num"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("description"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date d'envoi"));


   return model;
}

bool Entretien::supprimer(QString ide)
{
    QSqlQuery query;
    QString id=QString(ide);
    query.prepare("Delete from entretien where ID=:id");
    query.bindValue(":id",ide);
    return query.exec();


}

bool Entretien::modifier()
{
    QSqlQuery query;
    QString numero=QString::number(num);
    QString ide=QString(id);
   query.prepare("UPDATE entretien SET IDM=:idem,NUM=:num,DESCRIPTION=:dsc,DATE_ENVOI=:dt2 where ID=:ide");
    query.bindValue(":ide",ide);
    query.bindValue(":idem",idem);
    query.bindValue(":num",numero);
    query.bindValue(":dsc",dsc);
    query.bindValue(":dt2",dt2);

    return query.exec();
}

QSqlQueryModel *Entretien::rechercher(QString &a,QString &b,QString &c,QString &d,QString &e)
{
    QSqlQueryModel *model=new QSqlQueryModel();

   model->setQuery("select * from entretien where(ID LIKE '"+a+"%') AND (IDM LIKE '"+b+"%') AND (NUM LIKE '"+c+"%') AND (DESCRIPTION LIKE '"+d+"%') AND (DATE_ENVOI LIKE '"+e+"%') ");

   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant entretien"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Identifiant materiel"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Num"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("description"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date d'envoi"));
    return model;
}

QSqlQueryModel * Entretien::trier(QString& choice,QString& a)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if ((choice=="ID entretien")and(a=="decroissant"))
        model->setQuery("SELECT * FROM ENTRETIEN ORDER BY id Desc ");

        else if ((choice=="Num")and(a=="decroissant"))
          model->setQuery("SELECT * FROM ENTRETIEN ORDER BY num Desc ");

    else if ((choice=="ID materiel")and(a=="decroissant"))
      model->setQuery("SELECT * FROM ENTRETIEN ORDER BY idm Desc ");

    if ((choice=="ID entretien")and(a=="croissant"))
        model->setQuery("SELECT * FROM ENTRETIEN ORDER BY id ASC ");

        else if ((choice=="Num")and(a=="croissant"))

          model->setQuery("SELECT * FROM ENTRETIEN ORDER BY num ASC ");
    else if ((choice=="ID materiel")and(a=="croissant"))

      model->setQuery("SELECT * FROM ENTRETIEN ORDER BY idm ASC ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant entretien"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Identifiant materiel"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Num"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date d'envoi"));
      return model;

}

QSqlQueryModel * Entretien::listMateriels()
{
    QSqlQueryModel * Model=new  QSqlQueryModel();

    QSqlQuery query;
    query.prepare("select ID from Materiels");
    query.exec();
    Model->setQuery(query);
    return Model;
}

QSqlQueryModel * Entretien::exporterPDF()
{
    QSqlQueryModel * Model=new  QSqlQueryModel();

    QSqlQuery qry;
     qry.prepare("SELECT * FROM ENTRETIEN ");
     qry.exec();
     Model->setQuery(qry);
     return Model;
}

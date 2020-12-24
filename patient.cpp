#include "patient.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
patient::patient()
{
id=0;
nom="";
prenom="";
adresse="";
maladie="";
numtel=0;
}
patient::patient(int id,QString nom,QString prenom,QString adresse, int numtel,QString maladie )
{
    this->id=id;
            this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->maladie=maladie;
    this->numtel=numtel;
}
bool patient::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString ress=QString::number(numtel);
    query.prepare("INSERT INTO patient (id,nom,prenom,adresse,numtel,maladie) "
                  "VALUES(:id,:nom,:prenom,:adresse,:numtel,:maladie)");

query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse",adresse);
query.bindValue(":numtel",ress);
query.bindValue(":maladie",maladie);
return query.exec();
}
QSqlQueryModel * patient::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model ->setQuery("select * from patient");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("numtel"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));
    return model;
}
bool patient::supprimer(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from patient where id =:id");
    query.bindValue(":id",res);
    return query.exec();
}
bool patient::modifier()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString ress=QString::number(numtel);
    query.prepare("UPDATE  patient set nom=:nom,prenom=:prenom,adresse=:adresse,numtel=:numtel,maladie=:maladie where id=:id");
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse",adresse);
query.bindValue(":numtel",ress);
query.bindValue(":maladie",maladie);
return query.exec();
}
QSqlQueryModel *patient::recherche_id_patient(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from patient where id LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("numtel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));

      return model;
  }
  QSqlQueryModel *patient::recherche_nom_patient(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from patient where nom LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("numtel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));
      return model;
  }
  QSqlQueryModel *patient::recherche_prenom_patient(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from patient where prenom LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("numtel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));
      return model;
  }
  QSqlQueryModel *patient::recherche_num_patient(QString txt)
  {

      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from patient where numtel LIKE '"+txt+"'" );
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("numtel"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));
      return model;
  }
  QSqlQueryModel *patient::ordre_id_patient()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from patient  order by id" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("numtel"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));

         return model;
     }
  QSqlQueryModel *patient::ordre_nom_patient()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from patient  order by nom" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("numtel"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));

         return model;
     }
  QSqlQueryModel *patient::ordre_prenom_patient()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from patient  order by prenom" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("numtel"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("maladie"));

         return model;
     }

#include "fournisseur.h"
#include <QString>
#include <QSqlQuery>

fournisseur::fournisseur()
{

     nomf="";
     adrf="";
     idf="";
     numf=0;
}
fournisseur::fournisseur(QString n ,QString a,QString i,int x){

    nomf=n;
    adrf=a;
    idf=i;
    numf=x;
}
bool fournisseur::ajouter(){
    QSqlQuery query;
    QString numfs=QString::number(numf);
    query.prepare("INSERT INTO fournisseur (IDF,ADRF,NOMF,NUMF)"
                  "VALUES(:idf, :adrf, :nomf, :numf)");
    query.bindValue(":idf",idf);
    query.bindValue(":adrf",adrf);
    query.bindValue(":nomf",nomf);
    query.bindValue(":numf",numfs);

    return query.exec();


}
QSqlQueryModel * fournisseur:: afficher(){

    QSqlQueryModel * model=new QSqlQueryModel ();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Adresse du fournisseur"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Nom du fournisseur"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("n téléphone"));
    return  model;
}

bool fournisseur::supprimer(int numf){
    QSqlQuery query;
    QString numfs=QString::number(numf);
    query.prepare("Delete from fournisseur where numf = :numf");
query.bindValue(":numf",numfs);
    return query.exec();
}
bool fournisseur::modifier()
{
    QSqlQuery query;
    QString res=QString::number(numf);
    query.prepare("UPDATE  fournisseur set idf=:idf,adrf=:adrf,nomf=:nomf,numf=:numf where numf=:numf");
query.bindValue(":idf",idf);
query.bindValue(":adrf",adrf);
query.bindValue(":nomf",nomf);
query.bindValue(":numf",res);

return query.exec();
}

#include "stock.h"
#include <QString>
#include <QSqlQuery>

stock::stock()
{
    ref=0;
    nom="";
    qtt=0;
    idf="";
}
stock::stock(int r,QString n,int q,QString i){
    ref=r;
    nom=n;
    qtt=q;
    idf=i;
}
bool stock::ajouter(){
    QSqlQuery query;
    QString refs=QString::number(ref);
    QString qtts=QString::number(qtt);
    query.prepare("INSERT INTO stock (ref,nom,qtt,idf)"
                  "VALUES(:ref, :nom, :qtt, :idf)");

    query.bindValue(":ref",refs);
    query.bindValue(":nom",nom);
    query.bindValue(":qtt",qtts);
    query.bindValue(":idf",idf);
    return query.exec();


}
QSqlQueryModel * stock:: afficher(){

    QSqlQueryModel * model=new QSqlQueryModel ();
    model->setQuery("select * from stock");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Références"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom du médicament"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("identifiant"));

    return  model;
}
bool stock::supprimer(int ref){
    QSqlQuery query;
    QString refs=QString::number(ref);
    query.prepare("Delete from stock where ref = :ref");
query.bindValue(":ref",refs);
    return query.exec();


}
QSqlQueryModel *stock::tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from stock order by nom ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("qtt"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("idf"));
    return model;
}
QSqlQueryModel *stock::recherche(QString txt)
{

    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from stock where nom LIKE '"+txt+"'" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("qtt"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("idf"));

         return model;}


bool stock::modifier()
{
    QSqlQuery query;
    QString res=QString::number(ref);
    QString ress=QString::number(qtt);
    query.prepare("UPDATE  stock set ref=:ref,nom=:nom,qtt=:qtt,idf=:idf where ref=:ref");
query.bindValue(":ref",res);
query.bindValue(":nom",nom);
query.bindValue(":qtt",ress);
query.bindValue(":idf",idf);
return query.exec();
}

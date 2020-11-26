#include "ressource.h"

ressource::ressource()
{
    ref=0;
    stock=0;
    date=" ";
    remarque=" ";
}

ressource::ressource(int r,int s,QString d,QString re)
{
    this->ref=r;
    this->stock=s;
    this->date=d;
    this->remarque=re;
}

bool ressource ::ajouter_ressource()
{
    QSqlQuery query;
    QString CINS= QString::number(ref);
    query.prepare("INSERT INTO RESSOURCE(REF,STOCKRESTANT,DATER,REMARQUE) "
                  "VALUES (:ref, :stockrestant,:date,:remarque)");
    query.bindValue(":ref", CINS);
    query.bindValue(":stockrestant", stock);
    query.bindValue(":date", date);
    query.bindValue(":remarque", remarque);

    return    query.exec();
}

QSqlQueryModel * ressource ::afficher_ressource()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ressource");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCK_RESTANT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REMARQUE"));

    return model;
}


bool ressource :: supprimer_ressource(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from ressource where REF = :ref");
    query.bindValue(":ref",res);
    return query.exec();

}

bool ressource::modifier_ressource(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Update ressource set REF = :ref , STOCKRESTANT = :stockrestant , DATER = :date , REMARQUE = :remarque   where REF = :ref ");
query.bindValue(":id", res);
query.bindValue(":ref", ref);
query.bindValue(":stockrestant", stock);
query.bindValue(":date", date);
query.bindValue(":remarque", remarque);


return    query.exec();
}

QSqlQueryModel* ressource::Rechercher(QString cin)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from ressource where ref LIKE '"+cin+"%' or stockrestant LIKE '"+cin+"%' or date LIKE '"+cin+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));

 return model;
}

QSqlQueryModel *ressource::trierA1() // m sghir lel kbir
{

           QSqlQueryModel * model = new  QSqlQueryModel ();
           model->setQuery("SELECT * FROM ressource order by stockrestant");


           model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));

           return model;

}

QSqlQueryModel *ressource::trierB2() // m sghir lel kbir
{

    QSqlQueryModel * model = new  QSqlQueryModel ();
    model->setQuery("SELECT * FROM ressource order by stockrestant desc");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));

    return model;
}


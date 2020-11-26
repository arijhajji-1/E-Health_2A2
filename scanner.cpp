#include "scanner.h"

scanner::scanner()
{
    cin=0;
    num_tlphn=0;
    nom=" ";
    prenom=" ";
    dateNaissance=" ";
    date=" ";
    analyse=" ";
}

scanner::scanner(int c,QString n,QString p,QString dt,int num,QString a,QString d)
{
    this->cin=c;
    this->nom=n;
    this->prenom=p;
    this->dateNaissance=dt;
     this->num_tlphn=num;
    this->analyse=a;
    this->date=d;
}

bool scanner ::ajouter_scanner()
{
    QSqlQuery query;
    QString CINS= QString::number(cin);
    query.prepare("INSERT INTO SCANNER(CIN,NOM,PRENOM,DATENAISSANCE,TELEPHONE,ANALYSE,DATEE) "
                  "VALUES (:cin, :nom,:prenom,:date_naissance,:telephone,:analyse,:date)");
    query.bindValue(":cin", CINS);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naissance", dateNaissance);
    query.bindValue(":telephone", num_tlphn);
    query.bindValue(":analyse", analyse);
    query.bindValue(":date", date);

    return    query.exec();
}

QSqlQueryModel * scanner ::afficher_scanner()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from scanner");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ANALYSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE"));

    return model;
}


bool scanner :: supprimer_scanner(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from scanner where CIN = :id");
    query.bindValue(":id",res);
    return query.exec();

}

bool scanner::modifier_scanner(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Update scanner set CIN = :cin , NOM = :nom , PRENOM = :prenom , DATENAISSANCE = :date_naissance, TELEPHONE = :telephone , ANALYSE = :analyse, DATEE = :date   where CIN = :cin ");
query.bindValue(":id", res);
query.bindValue(":cin", cin);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":date_naissance", dateNaissance);
query.bindValue(":telephone", num_tlphn);
query.bindValue(":analyse", analyse);
query.bindValue(":date", date);

return    query.exec();
}

QSqlQueryModel* scanner::Recherche(QString cin)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from scanner where cin LIKE '"+cin+"%' or nom LIKE '"+cin+"%' or prenom LIKE '"+cin+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

 return model;
}

QSqlQueryModel *scanner::trierA() // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM scanner order by cin ASC");
           q->exec();
           model->setQuery(*q);
           return model;

}

QSqlQueryModel *scanner::trierB() // m sghir lel kbir
{
           QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM scanner order by cin DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;
}

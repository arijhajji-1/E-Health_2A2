#include "ressource.h"


ressource::ressource()
{
    ref=0;
    stock=0;
    date=" ";
    remarque=" ";

}

ressource::ressource(int r,int s,QString re,QString cinfk,QString nomstock)
{
    this->ref=r;
    this->stock=s;
    //this->date=d;
    this->remarque=re;
    this->cinfk=cinfk;
    this->nomstock=nomstock;
}
//les get
int ressource::get_ref(){return ref ;}
int ressource::get_stock(){return  stock;}
QString ressource::get_date(){return date;}
QString ressource::get_remarque(){return remarque;}
QString ressource::get_cinfk(){return cinfk;}
QString ressource::get_nomstock(){return nomstock;}
//les set
void ressource::set_ref (int  ref){this->ref=ref;}
void ressource::set_stock(int stock){this->stock=stock;}
void ressource::set_date(int date){this->date=date;}
void ressource::set_remarque(int remarque){this->remarque=remarque;}
void ressource::set_cinfk(int cinfk){this->cinfk=cinfk;}
void ressource::set_nomstock(QString nomstock){this->nomstock=nomstock;}

//ajouter ressource
bool ressource ::ajouter_ressource()
{
    QSqlQuery query;

    query.prepare("INSERT INTO RESSOURCE_TRAITEMENT( REF_T , STOCK_T , REMARQUE_T , CIN_F_FK , NOM_STOCK) "
                  "VALUES (:ref, :stock, :remarque , :cinfk , :nomstock)");

    //***************************************bindvalue a->>>>>>>>>>>>>>z

    query.bindValue(":ref", ref);
    query.bindValue(":stock", stock);
    //query.bindValue(":date", date);
    query.bindValue(":remarque", remarque);
    query.bindValue(":cinfk", cinfk);
    query.bindValue(":nomstock",nomstock);

    return    query.exec();
}
//afficher ressource
QSqlQueryModel * ressource ::afficher_ressource()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from RESSOURCE_TRAITEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCK_RESTANT"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin f"));
    return model;
}

//supprimer ressource
bool ressource :: supprimer_ressource(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from RESSOURCE_TRAITEMENT where REF_T = :ref");
    query.bindValue(":ref",res);
    return query.exec();

}
//modifier ressource
bool ressource::modifier_ressource(ressource R)
{
QSqlQuery query;
query.prepare("Update RESSOURCE_TRAITEMENT set REF_T = :ref , STOCK_T= :stockrestant , REMARQUE_T = :remarque ,CIN_F_FK = :cinf, NOM_STOCK = :nomstock  where REF_T = :ref ");

query.bindValue(":ref", R.get_ref());
query.bindValue(":stockrestant", R.get_stock());
//query.bindValue(":date",R.get_date());
query.bindValue(":remarque",R.get_remarque());
query.bindValue(":cinf",R.get_cinfk());
query.bindValue(":nomstock",R.get_nomstock());
return    query.exec();
}
//recherche ressource
QSqlQueryModel* ressource::Rechercher(QString a)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from RESSOURCE_TRAITEMENT where REF_T LIKE '"+a+"%' or STOCK_T LIKE '"+a+"%' or REMARQUE_T LIKE '"+a+"%' or NOM_STOCK LIKE '"+a+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
    // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN F"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));

 return model;
}
//trie ref stock croissant
QSqlQueryModel *ressource::trier_ref_Stock_croi() // m sghir lel kbir
{

           QSqlQueryModel * model = new  QSqlQueryModel ();
           model->setQuery("SELECT * FROM RESSOURCE_TRAITEMENT order by REF_T");



           model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
          // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN F"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));

           return model;

}
//trie ref stock decroissant
QSqlQueryModel *ressource::trier_ref_Stock_decroi()
{

    QSqlQueryModel * model = new  QSqlQueryModel ();
    model->setQuery("SELECT * FROM RESSOURCE_TRAITEMENT order by REF_T DESC");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN F"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));

    return model;
}
//trie nom stock croissant
QSqlQueryModel *ressource::trier_nom_Stock_croi()
{

    QSqlQueryModel * model = new  QSqlQueryModel ();
    model->setQuery("SELECT * FROM RESSOURCE_TRAITEMENT order by NOM_STOCK ");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN F"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));

    return model;
}
//trie nom stock decroissant
QSqlQueryModel *ressource::trier_nom_Stock_decroi()
{

    QSqlQueryModel * model = new  QSqlQueryModel ();
    model->setQuery("SELECT * FROM RESSOURCE_TRAITEMENT order by NOM_STOCK desc");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN F"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));

    return model;
}
//trie stock croissant
QSqlQueryModel *ressource::trier_Stock_croi()
{

    QSqlQueryModel * model = new  QSqlQueryModel ();
    model->setQuery("SELECT * FROM RESSOURCE_TRAITEMENT order by STOCK_T ");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN F"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));

    return model;
}
//trie stock decroissant
QSqlQueryModel *ressource::trier_Stock_decroi()
{

    QSqlQueryModel * model = new  QSqlQueryModel ();
    model->setQuery("SELECT * FROM RESSOURCE_TRAITEMENT order by STOCK_T desc");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STOCKRESTANT"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMARQUE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN F"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));

    return model;
}
//table clicked
QSqlQuery  ressource::tableclicked(QString a)
{

    QSqlQuery qry ;

     qry.prepare("Select * from RESSOURCE_TRAITEMENT where REF_T ='"+a+"' ");
    return qry;
}
bool ressource::Modifier_Stock()
{QSqlQuery query;
    query.prepare("UPDATE RESSOURCE_TRAITEMENT SET STOCK_T = STOCK_T - 1 ");


    query.bindValue(":ref", get_ref());
    query.bindValue(":stockrestant", get_stock());
    query.bindValue(":remarque",get_remarque());
    query.bindValue(":cinf",get_cinfk());
    query.bindValue(":nomstock",get_nomstock());



    return    query.exec();

}

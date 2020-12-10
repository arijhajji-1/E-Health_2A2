#include "scanner.h"
#include"ressource.h"

scanner::scanner()
{
    cin=0;
    num_tlphn=0;
    nom=" ";
    prenom=" ";
    dateNaissance=" ";
    email=" ";
    traitement=" ";
}

scanner::scanner(int c,QString n,QString p,QString dt,int num,QString a,QString d)
{
    this->cin=c;
    this->nom=n;
    this->prenom=p;
    this->dateNaissance=dt;
    this->num_tlphn=num;
    this->traitement=a;
    this->email=d;
}
//les get
int scanner::get_cin(){return  cin;}
int scanner::get_tel(){return  num_tlphn;}
QString scanner::get_nom(){return  nom;}
QString scanner::get_prenom(){return  prenom;}
QString scanner::get_dateN(){return  dateNaissance;}
QString scanner::get_traitement(){return  traitement;}
QString scanner::get_email(){return  email;}

//les set
void scanner::set_cin (int cin){this->cin=cin;}
void scanner::set_tel (int  tel){this->num_tlphn=tel;}
void scanner::set_nom(QString nom){this->nom=nom;}
void scanner::set_prenom(QString prenom){this->prenom=prenom;}
void scanner::set_date(QString date){this->dateNaissance=date;}
void scanner::set_traitement(QString traitement){this->traitement=traitement;}
void scanner::set_email(QString email){this->email=email;}

//ajout scanner
bool scanner ::ajouter_scanner()
{
    QSqlQuery query;
    QString CINS= QString::number(cin);
    query.prepare("INSERT INTO CLIENTSCAN(CIN_C,NOM_C,PRENOM_C,DATE_N,TEL_C,TRAITEMENT_C,EMAIL_C) "
                  "VALUES (:cin, :nom,:prenom,:date_naissance,:telephone,:traitement,:email)");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naissance", dateNaissance);
    query.bindValue(":telephone", num_tlphn);
    query.bindValue(":traitement", traitement);
    query.bindValue(":email", email);

    return    query.exec();
}
// affichage
QSqlQueryModel * scanner ::afficher_scanner()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENTSCAN");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TRAITEMENT"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}

//supp
bool scanner :: supprimer_scanner(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from CLIENTSCAN where CIN_C = :cin");
    query.bindValue(":cin",res);
    return query.exec();

}
//modif
bool scanner::modifier_scanner(scanner s)
{
    QSqlQuery query;
    query.prepare("Update CLIENTSCAN set CIN_C = :cin , NOM_C = :nom , PRENOM_C = :prenom , DATE_N = :date_naissance, TEL_C = :telephone , TRAITEMENT_C = :traitement, EMAIL_C = :email   where CIN_C = :cin ");

    query.bindValue(":cin",s.get_cin());
    query.bindValue(":nom",s.get_nom());
    query.bindValue(":prenom",s.get_prenom());
    query.bindValue(":date_naissance",s.get_dateN());
    query.bindValue(":telephone",s.get_tel());
    query.bindValue(":traitement",s.get_traitement());
    query.bindValue(":email",s.get_email());
    return    query.exec();
}
//recherche
QSqlQueryModel* scanner::Recherche(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENTSCAN where CIN_C LIKE '"+a+"%' or NOM_C LIKE '"+a+"%' or PRENOM_C LIKE '"+a+"%' or TEL_C LIKE '"+a+"%' or TRAITEMENT_C LIKE '"+a+"%' or EMAIL_C LIKE '"+a+"%'");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TRAITEMENT"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}
//cin decroissant
QSqlQueryModel *scanner::trier_cin_decroi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM CLIENTSCAN order by CIN_C DESC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//cin croissant
QSqlQueryModel *scanner::trier_cin_croi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM CLIENTSCAN order by CIN_C ASC");
    q->exec();
    model->setQuery(*q);
    return model;
}
//nom decroissant
QSqlQueryModel *scanner::trier_nom_decroi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM CLIENTSCAN order by NOM_C DESC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//nom croissant
QSqlQueryModel *scanner::trier_nom_croi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM CLIENTSCAN order by NOM_C ASC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//email decroissant
QSqlQueryModel *scanner::trier_email_decroi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM CLIENTSCAN order by EMAIL_C DESC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//email croissant
QSqlQueryModel *scanner::trier_email_croi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM CLIENTSCAN order by EMAIL_C ASC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//table clicked
QSqlQuery  scanner::tableclicked(QString a)
{
    QSqlQuery qry ;
    qry.prepare("Select * from CLIENTSCAN where CIN_C ='"+a+"' ");
    return qry;
}
bool scanner::Modifier_Stock(ressource R)
{QSqlQuery query;
    query.prepare("UPDATE RESSOURCE_TRAITEMENT SET STOCK_T = STOCK_T - 1  ");


    query.bindValue(":ref", R.get_ref());
    query.bindValue(":stockrestant", R.get_stock());
    query.bindValue(":remarque",R.get_remarque());
    query.bindValue(":cinf",R.get_cinfk());
    query.bindValue(":nomstock",R.get_nomstock());



    return    query.exec();

}

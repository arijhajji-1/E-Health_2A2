#include "fournisseur.h"

fournisseur::fournisseur()
{
    cinf="";
    nomf="";
    prenomf="";
    agef=0;
    telf=0;
    adressef="";
    photof="";
}
fournisseur::fournisseur(QString cinf,QString nomf, QString prenomf,int agef,int telf, QString adressef, QString photof)
{
    this->cinf=cinf;
    this->nomf=nomf;
    this->prenomf=prenomf;
    this->agef=agef;
    this->telf=telf;
    this->adressef=adressef;
    this->photof=photof;
}
//les get
int fournisseur::get_agef(){return agef ;}
int fournisseur::get_telf(){return  telf;}
QString fournisseur::get_cinf(){return cinf;}
QString fournisseur::get_nomf(){return nomf;}
QString fournisseur::get_prenomf(){return prenomf;}
QString fournisseur::get_adressef(){return adressef;}
QString fournisseur::get_photof(){return photof;}
//les set
void fournisseur::set_agef (int  agef){this->agef=agef;}
void fournisseur::set_nomf(QString nomf){this->nomf=nomf;}
void fournisseur::set_prenomf(QString prenomf){this->prenomf=prenomf;}
void fournisseur::set_adressef(QString adressef){this->adressef=adressef;}
void fournisseur::set_cinf(QString cin){this->cinf=cinf;}
void fournisseur::set_telf(int telf){this->telf=telf;}
void fournisseur::set_photof(QString photof){this->photof=photof;}
//ajout
bool fournisseur ::ajouter_fournisseur()
{
    QSqlQuery query;

    query.prepare("INSERT INTO FOURNISSEUR_RESSOURCE(CIN_F,NOM_F,PRENOM_F,AGE_F,TEL_F,ADRESSE_F,PHOTO_F) "
                  "VALUES (:cin, :nom,:prenom,:age,:tel,:adresse,:photo)");
    query.bindValue(":cin", cinf);
    query.bindValue(":nom", nomf);
    query.bindValue(":prenom", prenomf);
    query.bindValue(":age", agef);
    query.bindValue(":tel", telf);
    query.bindValue(":adresse", adressef);
    query.bindValue(":photo", photof);

    return    query.exec();
}
// affichage
QSqlQueryModel * fournisseur ::afficher_fournisseur()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR_RESSOURCE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMF"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMF"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGEF"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CHEMIN"));

    return model;
}
//supp
bool fournisseur :: supprimer_fournisseur(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from FOURNISSEUR_RESSOURCE where CIN_F = :cin");
    query.bindValue(":cin",res);
    return query.exec();

}
//modif
bool fournisseur::modifier_fournisseur(fournisseur s)
{
    QSqlQuery query;
    query.prepare("Update FOURNISSEUR_RESSOURCE set CIN_F = :cinf , NOM_F = :nomf , PRENOM_F = :prenomf , AGE_F = :agef, TEL_F = :telf, ADRESSE_F = :adressef, PHOTO_F = :photof   where CIN_F = :cinf ");

    query.bindValue(":cinf",s.get_cinf());
    query.bindValue(":nomf",s.get_nomf());
    query.bindValue(":prenomf",s.get_prenomf());
    query.bindValue(":agef",s.get_agef());
    query.bindValue(":telf",s.get_telf());
    query.bindValue(":adressef",s.get_adressef());
    query.bindValue(":photof",s.get_photof());
    return    query.exec();
}
//recherche
QSqlQueryModel* fournisseur::Recherche(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR_RESSOURCE where CIN_F LIKE '"+a+"%' or NOM_F LIKE '"+a+"%' or PRENOM_F LIKE '"+a+"%' or TEL_F LIKE '"+a+"%' or AGE_F LIKE '"+a+"%' or ADRESSE_F LIKE '"+a+"%'");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PHOTO"));

    return model;
}
//trie cin decroi
QSqlQueryModel *fournisseur::trier_cin_decroi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM FOURNISSEUR_RESSOURCE order by CIN_F DESC");
    q->exec();
    model->setQuery(*q);
    return model;

}


//trie cin croi
QSqlQueryModel *fournisseur::trier_cin_croi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM FOURNISSEUR_RESSOURCE order by CIN_F ASC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//trie nom decroi
QSqlQueryModel *fournisseur::trier_nom_decroi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM FOURNISSEUR_RESSOURCE order by NOM_F DESC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//trie nom croi
QSqlQueryModel *fournisseur::trier_nom_croi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM FOURNISSEUR_RESSOURCE order by NOM_F ASC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//trie Age croi
QSqlQueryModel *fournisseur::trier_age_croi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM FOURNISSEUR_RESSOURCE order by AGE_F ASC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//trie Age DEcroi
QSqlQueryModel *fournisseur::trier_age_decroi()
{
    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM FOURNISSEUR_RESSOURCE order by AGE_F DESC");
    q->exec();
    model->setQuery(*q);
    return model;

}
//table clicked
QSqlQuery  fournisseur::tableclicked(QString a)
{
    QSqlQuery qry ;
    qry.prepare("Select * from FOURNISSEUR_RESSOURCE where CIN_F ='"+a+"' ");
    return qry;
}
//fournisseur
QSqlQueryModel * fournisseur::afficher_Flist()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NOM_F , CIN_F from FOURNISSEUR_RESSOURCE ");
    return model;
}

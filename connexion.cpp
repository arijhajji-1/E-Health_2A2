#include "connexion.h"

connexion::connexion()
{

}

bool connexion::ouvrirconnexion()
{
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test1");//inserer le nom de la source de données ODBC
    db.setUserName("Ouma");//inserer nom de l'utilisateur
    db.setPassword("Ouma1");//inserer mot de passe de cet utilisateur

    if (db.open())
     test=true;

    return  test;
}

void connexion :: fermerconnexion()
{
    db.close();
}

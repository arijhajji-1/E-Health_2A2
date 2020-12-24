#include "connexion.h"
#include"QSqlDatabase"
#include <QtDebug>
connexion::connexion()
{

}
bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2a");
db.setUserName("zarrouk");//inserer nom de l'utilisateur
db.setPassword("4503");//inserer mot de passe de cet utilisateur

if (db.open())
  {test=true;}
return  test;

}

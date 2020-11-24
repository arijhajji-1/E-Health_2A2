#include "connection.h"


Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2");
db.setUserName("arijj");//inserer nom de l'utilisateur
db.setPassword("22861274");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

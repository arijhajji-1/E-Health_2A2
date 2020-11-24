#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");//inserer le nom de la source de données ODBC
db.setUserName("oussama");//inserer nom de l'utilisateur
db.setPassword("oussama");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

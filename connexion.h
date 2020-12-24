#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{
public:
    connexion();
     bool createconnect();

};

#endif // CONNEXION_H

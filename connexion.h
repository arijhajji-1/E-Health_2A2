#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connexion
{
public:
    connexion();
    bool ouvrirconnexion();
    void fermerconnexion();

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H

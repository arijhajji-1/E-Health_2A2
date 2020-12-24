#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class admin
{
public:
    admin();
    admin(QString,QString);
    QString get_id(){return id;}
    //QString login(QString,QString);
private:
    QString id,mdp;
};

#endif // ADMIN_H

#include "admin.h"
#include <QtDebug>
#include <QMessageBox>
#include "mainwindow.h"
admin::admin()
{
id="";
mdp="";
}
admin::admin(QString i,QString m)
{
this->id=i;
this->mdp=m;
}
/*QString login(QString id,QString mdp)
{


    QSqlQuery query;
    if (query.exec("SELECT *from connexion WHERE id like '"+id+"' and mdp like '"+mdp+"'"))
    {
        int count=0;
        while(query.next())
        {
            count++;
        }
        if(count==1)
        {

             qDebug() << "is logged in";
          if(id=="1")
        ui->stackedWidget->setCurrentIndex(2);
             if(id=="2")
        ui->stackedWidget->setCurrentIndex(3);
             if(id=="3")
        ui->stackedWidget->setCurrentIndex(4);
             if(id=="4")
        ui->stackedWidget->setCurrentIndex(5);
             if(id=="5")
        ui->stackedWidget->setCurrentIndex(6);
             if(id=="0")
                 ui->stackedWidget->setCurrentIndex(1);
        }
      else
        {
           QMessageBox::information(this,"conecter","id ou mdp incorrect");
        }
    }



    return id;
}*/

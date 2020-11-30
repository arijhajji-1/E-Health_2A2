#include "stati.h"
#include "ui_stati.h"

Stati::Stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stati)
{
    ui->setupUi(this);
}

Stati::~Stati()
{
    delete ui;
}
int Stati::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from FONCTIONS where SALAIRE BETWEEN '1' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Stati::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from FONCTIONS where SALAIRE BETWEEN '50' AND '200'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Stati::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from RESSOURCE where STOCKRESTANT BETWEEN '200' AND '500'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void Stati::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    //cout<<b<<endl ;
    int c=Statistique_partie3();
   // cout<<c<<endl ;
    int d=Statistique_partie4();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::green);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("1-50") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("51-100") ;
    painter.setBrush(Qt::blue);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("201-500") ;

}


 void Stati::on_widget_customContextMenuRequested(const QPoint &pos)
{

}

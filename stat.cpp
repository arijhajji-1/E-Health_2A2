#include "stat.h"

#include <QPainter>

stat::stat(QWidget *parent) :
    QWidget(parent)
{

}

void stat::PaintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size =QRectF (10,10, this->width ()-10 );
    painter.setBrush(Qt::red);
    painter.drawstat()
}

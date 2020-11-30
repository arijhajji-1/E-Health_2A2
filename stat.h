#ifndef STAT_H
#define STAT_H

#include <QWidget>

class stat : public QWidget
{
   Q_OBJECT
 public :
    explicit stat(QWidget *parent = 0 );

protected:

    void PaintEvent (QPaintEvent *);

signals:

};

#endif // STAT_H

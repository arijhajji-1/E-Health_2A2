#ifndef STAT_RESSOURCE_TRAITEMENT_H
#define STAT_RESSOURCE_TRAITEMENT_H

#include <QMainWindow>

namespace Ui {
class Stat_Ressource_Traitement;
}

class Stat_Ressource_Traitement : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stat_Ressource_Traitement(QWidget *parent = nullptr);
    ~Stat_Ressource_Traitement();

private:
    Ui::Stat_Ressource_Traitement *ui;
};

#endif // STAT_RESSOURCE_TRAITEMENT_H

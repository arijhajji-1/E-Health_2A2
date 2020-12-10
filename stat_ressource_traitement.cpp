#include "stat_ressource_traitement.h"
#include "ui_stat_ressource_traitement.h"

Stat_Ressource_Traitement::Stat_Ressource_Traitement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stat_Ressource_Traitement)
{
    ui->setupUi(this);
}

Stat_Ressource_Traitement::~Stat_Ressource_Traitement()
{
    delete ui;
}

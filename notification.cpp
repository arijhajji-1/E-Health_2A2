#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notificationC()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/USER/Desktop/notif"));

    notifyIcon->show();
    notifyIcon->showMessage("Reminder ","N'oubliez pas de vérifier les rendez-vous d'aujourd'hui",QSystemTrayIcon::Information,15000);
}

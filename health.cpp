#include "health.h"
#include <QString>
#include <QFont>

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
health=100;
setPlainText("health: " + QString::number(health));
setDefaultTextColor(Qt::red);
setFont(QFont("times",16));
}

void Health::decrease()
{
   health-=25;
   setPlainText("health: " + QString::number(health));

}

int Health::getHealth()
{
    return health;
}


#include"bullet.h"
#include <QTimer>
#include <QDebug>
#include "enemy.h"
#include <QGraphicsScene>
#include <QTypeInfo>
#include <typeinfo>
#include "player.h"
#include "game.h"
#include <QList>

extern Game *game;


Bullet::Bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/bullet.png"));



QTimer *timer= new QTimer();
connect(timer,SIGNAL(timeout()),this,SLOT(move()));
timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *>colliding_items=collidingItems();
    for(int x=0;x<colliding_items.size();x++)
    {
        if(typeid(*(colliding_items[x]))==typeid(Enemy))
        {
            game->score->increase();
            scene()->removeItem(colliding_items[x]);

            qDebug()<<"enemy dissapeared(shooted) XD";


            scene()->removeItem(this);
            delete colliding_items[x];
            delete this;
            return;
        }

    }

    setPos(x(),y()-10);
    if(pos().y()<0)
    {
        scene()->removeItem(this);
        delete this;
   qDebug()<<"bullet removed";
    }
}

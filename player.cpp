#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include "game.h"
#include <QTimer>

extern Game *game;

Player::Player()
{
    setPixmap(QPixmap(":/images/player.png"));
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(touch()));
    timer->start(1000);
}



void Player::keyEvent(QKeyEvent *event)
{
if(event->key()==Qt::Key_Left)
{
    if(pos().x()>0)
    setPos(x()-100,y());
}
if(event->key()==Qt::Key_Right)
{
    if(pos().x()+100<800)
    setPos(x()+100,y());
}


if(event->key()==Qt::Key_Space)
{
    Bullet *bullet= new Bullet();
    bullet->setPos(x()+40,y());
  scene()->addItem(bullet);
}
}


void Player::spawn()
{
    Enemy *enemy=new Enemy();
    scene()->addItem(enemy);

}

void Player::touch()
{
    QList<QGraphicsItem *>ci=collidingItems();
    for(int st1=0;st1<ci.size();st1++)
    {
        if(typeid(*(ci[st1]))==typeid(Enemy))
        {
            game->health->decrease();
            scene()->removeItem(ci[st1]);
            delete ci[st1];
        }
    }
}

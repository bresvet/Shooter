#include"enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"
#include <cstdlib>
#include <time.h>

extern Game *game;

Enemy::Enemy()
{
    srand(time(NULL));
    int random_number=rand()%700;
    setPos(random_number,0);
setPixmap(QPixmap(":/images/enemy.png"));
QTimer *timer= new QTimer();
connect(timer,SIGNAL(timeout()),this,SLOT(move()));
timer->start(rand()%25+15);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() +pixmap().height()>600)
    {
        game->score->decrease();
        scene()->removeItem(this);
        delete this;
   qDebug()<<"enemy dissapeared(by reaching maximux y-axis limit XD";
    }
}

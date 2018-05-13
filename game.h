#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"

#ifndef GAME_H

#define GAME_H
class Game:public QGraphicsView
{
public:
    Game();
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;

};

#endif // GAME_H

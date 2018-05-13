#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Player:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Player();
    void keyEvent(QKeyEvent *event);

public slots:
    void spawn();
    void touch();
};

#endif // MYRECT_H



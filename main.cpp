#include <QApplication>
#include "game.h"
#include <thread>
#include <QDebug>
Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<std::thread::hardware_concurrency();


    game= new Game();
    game->show();



return a.exec();
}

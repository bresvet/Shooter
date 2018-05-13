#include "score.h"
#include <QString>
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
score=0;
setPlainText("score: " + QString::number(score));
setDefaultTextColor(Qt::blue);
setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText("score: " + QString::number(score));

}

void Score::decrease()
{
    score--;
    setPlainText("score: " + QString::number(score));

}

int Score::getScore()
{
    return score;
}

#include "score.h"

#include <QObject>

Score::Score(QObject *parent, unsigned int s) : QObject(parent), score(s)
{
    setPlainText("Score: " + QString::number(score));
    show();
}

void Score::addPoints(int points)
{
    score += points;
    setPlainText("Score: " + QString::number(score));
    show();
}


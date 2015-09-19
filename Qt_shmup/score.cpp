#include "score.h"

#include <QObject>

Score::Score(unsigned int s) : score(s)
{
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(QColor(255,255,255));
    setPos(x()+4, y());
    setZValue(4);
    show();
}

void Score::addPoints(int points)
{
    if(static_cast<int>(score) + points >= 0) score += points;
    setPlainText("Score: " + QString::number(score));
    show();
}
unsigned int Score::getScore() const
{
    return score;
}

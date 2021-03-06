#include "health.h"

#include <QObject>

Health::Health(unsigned int h) : health(h)
{
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(QColor(255,255,255));
    setPos(x()+4, 25);
    setZValue(4);
    show();
}

void Health::decHealth(int points)
{
    if(static_cast<int>(health) - points >= 0)
    {
        health -= points;
        setPlainText("Health: " + QString::number(health));
    }
    else
    {
        setPlainText("Health: DEAD!");
    }
    show();
}


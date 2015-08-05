#include "health.h"

#include <QObject>

Health::Health(QObject *parent, unsigned int h) : QObject(parent), health(h)
{
    setPlainText("Health: " + QString::number(health));
    setPos(x(), 15);
    show();
}

void Health::decHealth(int points)
{
    if(static_cast<int>(health) + points >= 0)
    {
        health += points;
        setPlainText("Health: " + QString::number(health));
    }
    else
    {
        setPlainText("Health: DEAD!");
    }
    show();
}


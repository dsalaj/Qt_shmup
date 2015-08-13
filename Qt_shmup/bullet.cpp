#include "bullet.h"

#include <QTimer>

Bullet::Bullet(QObject *parent, unsigned int damage) : QObject(parent), dmg(damage)
{
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

unsigned int Bullet::damage()
{
    return dmg;
}

void Bullet::remove()
{
    delete this;
 }


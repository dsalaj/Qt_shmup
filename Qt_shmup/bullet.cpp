#include "bullet.h"

#include <QTimer>

Bullet::Bullet(QObject *parent, unsigned int damage) : QObject(parent), dmg(damage)
{
    setZValue(3);
}

Bullet::~Bullet()
{

}

unsigned int Bullet::damage()
{
    return dmg;
}

void Bullet::remove()
{
    delete this;
 }


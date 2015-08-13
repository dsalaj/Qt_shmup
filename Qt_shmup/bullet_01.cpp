#include "bullet_01.h"
#include "bullet.h"


Bullet_01::Bullet_01(QObject *parent) : Bullet(parent, 1)
{
    setPixmap(QPixmap(":/images/bullet_01.png"));
}

void Bullet_01::move()
{
    setPos(x(), y()-4);
}

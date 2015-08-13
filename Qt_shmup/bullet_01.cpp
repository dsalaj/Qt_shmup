#include "bullet_01.h"

Bullet_01::Bullet_01(QObject *parent) : Bullet_player(parent, 1)
{
    setPixmap(QPixmap(":/images/bullet_01.png"));
}

void Bullet_01::move()
{
    setPos(x(), y()-4);
}

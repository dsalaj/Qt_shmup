#include "bullet_e01.h"

Bullet_e01::Bullet_e01(QObject *parent) : Bullet_enemy(parent, 1)
{
    setPixmap(QPixmap(":/images/bullet_e01.png"));
}

void Bullet_e01::move()
{
    setPos(x(), y()+2);
}

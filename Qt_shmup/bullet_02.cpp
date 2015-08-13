#include "bullet_02.h"
#include "bullet.h"

Bullet_02::Bullet_02(QObject *parent) : Bullet(parent, 4)
{
    setPixmap(QPixmap(":/images/bullet_02.png"));
}

void Bullet_02::move()
{
    setPos(x(), y()-2);
}

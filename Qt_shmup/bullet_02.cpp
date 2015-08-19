#include "bullet_02.h"

Bullet_02::Bullet_02(QObject *parent) : Bullet_player(parent, 4)
{
    setPixmap(QPixmap(":/images/bullet_02.png"));
}

void Bullet_02::advance(int phase)
{
    if(!phase) return;
    setPos(x(), y()-bullet_speed_02);
}

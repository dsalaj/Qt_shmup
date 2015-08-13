#ifndef BULLET_ENEMY_H
#define BULLET_ENEMY_H

#include "bullet.h"

class Bullet_enemy : public Bullet
{
public:
    explicit Bullet_enemy(QObject *parent, unsigned int damage);
};

#endif // BULLET_ENEMY_H

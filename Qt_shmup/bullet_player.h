#ifndef BULLET_PLAYER_H
#define BULLET_PLAYER_H

#include "bullet.h"

class Bullet_player : public Bullet
{
public:
    explicit Bullet_player(QObject *parent, unsigned int damage);
    virtual ~Bullet_player();
};

#endif // BULLET_PLAYER_H

#ifndef ENEMY_01_H
#define ENEMY_01_H

#include "enemy.h"

class Enemy_01 : public Enemy
{
public:
    explicit Enemy_01(QObject *parent, QGraphicsScene *scene);
protected:
    void advance(int phase);
};

#endif // ENEMY_01_H

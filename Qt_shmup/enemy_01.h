#ifndef ENEMY_01_H
#define ENEMY_01_H

#include "enemy.h"

class Enemy_01 : public Enemy
{
public:
    explicit Enemy_01(QObject *parent, QGraphicsScene *scene);
public slots:
    void move();
};

#endif // ENEMY_01_H

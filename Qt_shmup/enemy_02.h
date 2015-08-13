#ifndef ENEMY_02_H
#define ENEMY_02_H

#include "enemy.h"



class Enemy_02 : public Enemy
{
public:
    explicit Enemy_02(QObject *parent, QGraphicsScene *scene);
public slots:
    void shoot();
};

#endif // ENEMY_02_H

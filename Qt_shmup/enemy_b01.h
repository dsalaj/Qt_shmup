#ifndef ENEMY_B01_H
#define ENEMY_B01_H

#include "enemy.h"

class Enemy_b01 : public Enemy
{
public:
    explicit Enemy_b01(QObject *parent, QGraphicsScene *scene);
private:
    unsigned int state;
    unsigned int y_state;
public slots:
    virtual void move();
    virtual void shoot();
};

#endif // ENEMY_B01_H

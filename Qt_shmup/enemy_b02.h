#ifndef ENEMY_B02_H
#define ENEMY_B02_H

#include "enemy.h"

class Enemy_b02 : public Enemy
{
public:
    explicit Enemy_b02(QObject *parent, QGraphicsScene *scene, int x_offset);
private:
    unsigned int state;
    unsigned int y_state;
    int x_offset;
public slots:
    virtual void shoot();
protected:
    void advance(int phase);
};

#endif // ENEMY_B02_H

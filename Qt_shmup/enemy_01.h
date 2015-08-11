#ifndef ENEMY_01_H
#define ENEMY_01_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "enemy.h"

class Enemy_01 : public Enemy
{
public:
    explicit Enemy_01(QObject *parent, QGraphicsScene *scene);
};

#endif // ENEMY_01_H

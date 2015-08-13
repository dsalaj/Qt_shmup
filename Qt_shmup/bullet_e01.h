#ifndef BULLET_E01_H
#define BULLET_E01_H

#include "bullet_enemy.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet_e01 : public Bullet_enemy
{
    Q_OBJECT
public:
    explicit Bullet_e01(QObject *parent);
public slots:
    void move();
};

#endif // BULLET_E01_H

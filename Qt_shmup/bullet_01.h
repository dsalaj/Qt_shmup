#ifndef BULLET_01_H
#define BULLET_01_H

#include "bullet_player.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet_01 : public Bullet_player
{
    Q_OBJECT
public:
    explicit Bullet_01(QObject *parent);
public slots:
    void move();
};

#endif // BULLET_01_H

#ifndef BULLET_02_H
#define BULLET_02_H

#include "bullet_player.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet_02 : public Bullet_player
{
    Q_OBJECT
public:
    explicit Bullet_02(QObject *parent);
public slots:
    void move();
};

#endif // BULLET_02_H

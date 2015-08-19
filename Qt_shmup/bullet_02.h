#ifndef BULLET_02_H
#define BULLET_02_H

#include "bullet_player.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet_02 : public Bullet_player
{
public:
    explicit Bullet_02(QObject *parent);
protected:
    void advance(int phase);
};

#endif // BULLET_02_H

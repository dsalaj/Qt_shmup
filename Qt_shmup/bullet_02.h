#ifndef BULLET_02_H
#define BULLET_02_H

#include "bullet.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet_02 : public Bullet
{
    Q_OBJECT
public:
    explicit Bullet_02(QObject *parent);
public slots:
    void move();
};

#endif // BULLET_02_H

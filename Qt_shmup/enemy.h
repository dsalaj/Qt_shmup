#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "game.h"

extern Game* game;

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent, unsigned int speed, int health, unsigned int score);
protected:
    unsigned int speed;
    int health;
    unsigned int score;

signals:

public slots:
    virtual void move();
    virtual void shoot();
};

#endif // ENEMY_H

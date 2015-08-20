#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "game.h"
#include "constants.h"

extern Game* game;

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent, unsigned int speed, int health, unsigned int score);
    virtual ~Enemy();
    bool getBoss_body() const;
    void setBoss_body(bool value);

protected:
    bool boss_body;
    void damage(unsigned int amount);
    unsigned int speed;
    int health;
    unsigned int score;
    virtual void check();
    QPixmap pix;
public slots:
    virtual void shoot();
};

#endif // ENEMY_H

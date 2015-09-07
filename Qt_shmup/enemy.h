#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "game.h"
#include "constants.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent, unsigned int speed, int health, unsigned int score);
    virtual ~Enemy();
    bool getBoss_body() const;
    void setBoss_body(bool value);

protected:
    void damage(unsigned int amount);
    unsigned int speed;
    int health;
    unsigned int score;
    bool boss_body;
    virtual void check();
    QPixmap pix;
public slots:
    virtual void shoot();
};

#endif // ENEMY_H

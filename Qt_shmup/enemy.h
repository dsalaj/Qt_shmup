#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent, QGraphicsScene *scene, unsigned int speed, unsigned int health, unsigned int score);
protected:
    unsigned int speed;
    unsigned int health;
    unsigned int score;

signals:

public slots:
    virtual void move();
};

#endif // ENEMY_H

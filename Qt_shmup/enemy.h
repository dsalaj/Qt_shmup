#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent, QGraphicsScene *scene, unsigned int speed, unsigned int health);
protected:
    unsigned int speed;
    unsigned int health;

signals:

public slots:
    virtual void move();
};

#endif // ENEMY_H

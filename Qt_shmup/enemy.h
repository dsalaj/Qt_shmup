#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent, QGraphicsScene *scene);
private:
    unsigned int speed;

signals:

public slots:
    void move();
};

#endif // ENEMY_H

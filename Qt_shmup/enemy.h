#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>

class Enemy : public QObject, public QGraphicsEllipseItem
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

#ifndef ENEMY_BOSS01_H
#define ENEMY_BOSS01_H

#include "enemy.h"

#include <QGraphicsItemGroup>

class Enemy_boss01 : public QObject, public QGraphicsItemGroup
{
public:
    explicit Enemy_boss01(QObject *parent, QGraphicsScene *scene);
private:
    Q_OBJECT
    QList<Enemy*> parts;
    unsigned int state;
    unsigned int y_state;
    unsigned int speed;
    unsigned int width;
protected:
    void advance(int phase);
};

#endif // ENEMY_BOSS01_H

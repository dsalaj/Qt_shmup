#include "enemy_b01.h"
#include "enemy_b02.h"
#include "enemy_boss01.h"

#include <QTimer>

Enemy_boss01::Enemy_boss01(QObject *parent, QGraphicsScene *scene) : QObject(parent), state(0), y_state(1), speed(speed_eb01), width(100)
{
    setPos(scene->width()/2 - width/2, -50);
    Enemy_b02* leftw = new Enemy_b02(this, scene, -42);
    addToGroup(leftw);
    Enemy_b02* rightw = new Enemy_b02(this, scene, 40);
    addToGroup(rightw);
    Enemy_b01* core = new Enemy_b01(this, scene);
    addToGroup(core);
}

void Enemy_boss01::advance(int phase)
{
    if(!phase) return;

    if(state == 0)
    {
        setPos(x(), y()+speed);
        if(y() >= 50*y_state) {
            state = 1;
            y_state++;
        }
    }
    else if(state == 1 && x() > 0)
    {
        setPos(x()-speed, y());
        if(x() <= 0) state = 2;
    }
    else if(state == 2 && x() < scene()->width()-width)
    {
        setPos(x()+speed, y());
        if(x() >= scene()->width()-width) state = 3;
    }
    else if(state == 3 && x() > scene()->width()/2-width/2)
    {
        setPos(x()-speed, y());
        if(x() <= scene()->width()/2-width/2) state = 0;
    }
}

#include "bullet_e01.h"
#include "bullet_player.h"
#include "enemy_b01.h"

#include <QTimer>
#include <QDebug>

Enemy_b01::Enemy_b01(QObject *parent, QGraphicsScene *scene) : Enemy(parent, 2, 20, 20), state(0), y_state(1)
{
    setPixmap(QPixmap(":/images/boss1.png"));
    setPos(scene->width()/2 - pixmap().width()/2, - pixmap().height());

    QTimer* move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

    QTimer* shoot_timer = new QTimer(this);
    connect(shoot_timer,SIGNAL(timeout()),this,SLOT(shoot()));
    shoot_timer->start(2000);
}

void Enemy_b01::shoot()
{
    Bullet_e01* bullet = new Bullet_e01(scene());
    bullet->setPos(x()+pixmap().width()/2-bullet->pixmap().width()/2, y()+pixmap().height());
    scene()->addItem(bullet);
}

void Enemy_b01::advance(int phase)
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
    else if(state == 2 && x() < scene()->width()-pixmap().width())
    {
        setPos(x()+speed, y());
        if(x() >= scene()->width()-pixmap().width()) state = 3;
    }
    else if(state == 3 && x() > scene()->width()/2-pixmap().width()/2)
    {
        setPos(x()-speed, y());
        if(x() <= scene()->width()/2-pixmap().width()/2) state = 0;
    }

    check();
}

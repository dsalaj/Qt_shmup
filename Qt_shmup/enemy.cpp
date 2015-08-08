#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <typeinfo>
#include "bullet.h"
#include "game.h"

extern Game* game;

Enemy::Enemy(QObject *parent, QGraphicsScene *scene) : QObject(parent), speed(3)
{
    setPixmap(QPixmap(":/images/enemy1.png"));
    setPos((qrand() % static_cast<int>(scene->width() - 70)) + 35, - pixmap().height());

    speed = 2 + (qrand() % 3);
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+speed);
    if(collidingItems().size() != 0)
    {
        for(QGraphicsItem* i : collidingItems())
        {
            if(typeid(*i) == typeid(Bullet))
            {
                Bullet* b = dynamic_cast<Bullet*>(i);
                if(b!=NULL) b->remove();
                game->addPoints(1);
                delete this;
            }
        }
    }
    else if(y() > scene()->height())
    {
        game->decHealth(-1);
        delete this;
    }
}


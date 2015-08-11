#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <typeinfo>
#include "bullet.h"
#include "game.h"

extern Game* game;

Enemy::Enemy(QObject *parent, QGraphicsScene *scene, unsigned int speed, unsigned int health) : QObject(parent), speed(speed), health(health)
{
    setPos((qrand() % static_cast<int>(scene->width() - 70)) + 35, - pixmap().height());

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
                health--;
                if(health <= 0)
                {
                    game->addPoints(1);
                    delete this;
                }
            }
        }
    }
    else if(y() > scene()->height())
    {
        game->decHealth(-1);
        delete this;
    }
}


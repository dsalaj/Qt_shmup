#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <typeinfo>
#include "bullet.h"
#include "game.h"

extern Game* game;

Enemy::Enemy(QObject *parent, unsigned int speed, int health, unsigned int score) :
             QObject(parent), speed(speed), health(health), score(score)
{

}

void Enemy::move()
{
    setPos(x(), y()+speed);
    if(collidingItems().size() != 0)
    {
        for(QGraphicsItem* i : collidingItems())
        {
            if(dynamic_cast<Bullet*>(i))
            {
                Bullet* b = dynamic_cast<Bullet*>(i);
                if(b!=NULL)
                {
                    b->remove();
                }
                health -= b->damage();
                if(health <= 0)
                {
                    Game::getInstance().addPoints(score);
                    delete this;
                }
            }
        }
    }
    else if(y() > scene()->height())
    {
        Game::getInstance().decHealth(-1);
        delete this;
    }
}


#include "bullet.h"
#include "game.h"
#include "bullet_player.h"
#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QBitmap>


extern Game* game;

Enemy::Enemy(QObject *parent, unsigned int speed, int health, unsigned int score) :
             QObject(parent), speed(speed), health(health), score(score)
{

}

Enemy::~Enemy()
{

}

void Enemy::check()
{
    setPixmap(pix);
    if(collidingItems().size() != 0)
    {
        for(QGraphicsItem* i : collidingItems())
        {
            if(dynamic_cast<Bullet_player*>(i))
            {
                Bullet_player* b = dynamic_cast<Bullet_player*>(i);
                if(b!=NULL)
                {
                    health -= b->damage();
                    b->remove();
                    QPixmap p = pixmap();
                    p.fill(Qt::white);
                    p.setMask(pix.mask());
                    this->setPixmap(p);
                }
                if(health <= 0)
                {
                    Game::getInstance().addPoints(score);
                    delete this;
                }
            }
        }
    }
    else
    {
        if(y() > scene()->height())
        {
            Game::getInstance().decHealth(1);
            delete this;
        }
    }
}

void Enemy::shoot()
{
}


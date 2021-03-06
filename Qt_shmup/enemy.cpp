#include "bullet.h"
#include "game.h"
#include "bullet_player.h"
#include "enemy.h"
#include "enemy_boss01.h"
#include "enemy_b01.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QBitmap>


extern Game* game;

Enemy::Enemy(QObject *parent, unsigned int speed, int health, unsigned int score) :
             QObject(parent), speed(speed), health(health), score(score), boss_body(false)
{
    setZValue(2);
}

Enemy::~Enemy()
{

}
bool Enemy::getBoss_body() const
{
    return boss_body;
}

void Enemy::setBoss_body(bool value)
{
    boss_body = value;
}


void Enemy::damage(unsigned int amount)
{
    if(!boss_body) health -= amount; // FIXME: invalid read of size X error
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
                    damage(b->damage());
                    b->remove();
                    QPixmap p = pixmap(); // FIXME: invalid read of size X error
                    p.fill(Qt::white); // FIXME: invalid read of size X error
                    p.setMask(pix.mask());
                    this->setPixmap(p);
                }
                if(health <= 0)
                {
                    Game::getInstance().addPoints(score);
                    if(dynamic_cast<Enemy_b01*>(this))
                    {
                        Game::getInstance().levelFinished();
                    }
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


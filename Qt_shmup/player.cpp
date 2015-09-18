#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "constants.h"
#include "enemy_01.h"
#include "enemy_02.h"
#include "bullet_01.h"
#include "bullet_02.h"
#include "enemy_b01.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Player::Player(QObject *parent) :
    QObject(parent),
    bullet_type(1),
    direction(0),
    center(0),
    mouse_x(0),
    mouse_y(0),
    shoot(false),
    in_shop(false),
    fly_away(false),
    fly_away_speed(0.1)
{
    setPixmap(QPixmap(":/images/spaceship.png"));
    setZValue(1);
    shooter = new QTimer(this);
    connect(shooter, SIGNAL(timeout()), this, SLOT(shoot_shop()));

//    bulletSound = new QMediaPlayer(this);
//    bulletSound->setMedia(QUrl("qrc:/sounds/bullet2.wav"));
}

bool Player::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseMove && !in_shop)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(e != NULL)
        {
            mouse_x = e->pos().x();
            mouse_y = e->pos().y();
            setDirection();
        }
    }
    else if(event->type() == QEvent::MouseButtonPress && !in_shop)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(e->button() == Qt::LeftButton)
        {
            shoot = true; // TODO: ASK FABIAN: crashes when Bullet directly constructed
        }

    } else {
        // pass the event on to the parent class
        //return QMainWindow::eventFilter(obj, event);
        //FIXME: not needed?
        return Game::getInstance().eventFilter(obj, event);
    }
    return false;
}

void Player::setInShop(bool value, bool shoot)
{
    in_shop = value;
    if(in_shop && shoot)
    {
        shooter->start(300);
    }
    else if(in_shop && !shoot)
    {
        shooter->stop();
        fly_away = true;
    }
    else
    {
        shooter->stop();
    }

}

void Player::advance(int phase)
{
    if(!phase) return;
    setDirection();
    if(direction > 0 && !in_shop)
    {
        setPos(x()+player_speed, y());
    }
    else if(direction < 0 && !in_shop)
    {
        setPos(x()-player_speed, y());
    }
    if(shoot == true)
    {
        shoot = false;
        Bullet_player* bullet = NULL;
        switch(bullet_type)
        {
        case 1:
            bullet = new Bullet_01(this);
            break;
        case 2:
            bullet = new Bullet_02(this);
            break;
        }
        bullet->setPos(x()+pixmap().width()/2-bullet->pixmap().width()/2, y());
        scene()->addItem(bullet);
    }
    if(fly_away)
    {
        setPos(x(),y()-fly_away_speed);
        fly_away_speed += fly_away_speed / 5*(fly_away_speed-0.9*fly_away_speed);
    }
}

void Player::setDirection()
{
    center = this->x() + pixmap().width()/2;
    if(mouse_x < center-player_pos_tolerance)
    {
        direction = -1;
    }
    else if(mouse_x > center+player_pos_tolerance)
    {
        direction = 1;
    }
    else
    {
        direction = 0;
    }
}

void Player::shoot_shop()
{
    shoot = true;
}

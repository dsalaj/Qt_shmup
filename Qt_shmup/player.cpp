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

Player::Player(QObject *parent) : QObject(parent), direction(0), center(0), mouse_x(0), mouse_y(0)
{
    setPixmap(QPixmap(":/images/spaceship.png"));

//    bulletSound = new QMediaPlayer(this);
//    bulletSound->setMedia(QUrl("qrc:/sounds/bullet2.wav"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Down) {
        setPos(x(), y()+player_speed);
    }
    else if(event->key() == Qt::Key_Up) {
        setPos(x(), y()-player_speed);
    }
    else if(event->key() == Qt::Key_Right &&
            x() < scene()->width() - this->pixmap().width()) {
        setPos(x()+player_speed, y());
    }
    else if(event->key() == Qt::Key_Left &&
            x() > 0) {
        setPos(x()-player_speed, y());
    }
    else if(event->key() == Qt::Key_Space) {
        Bullet_01* bullet = new Bullet_01(this);
        bullet->setPos(x()+pixmap().width()/2-bullet->pixmap().width()/2, y());
        scene()->addItem(bullet);

//        qDebug() << "bulletSound media status = " << QString::number(bulletSound->mediaStatus());
//        if(bulletSound->state() == QMediaPlayer::PlayingState || bulletSound->mediaStatus() == QMediaPlayer::EndOfMedia)
//        {
//            bulletSound->setPosition(0);
//            qDebug() << "bullet->setPosition(0)";
//        }
//        else if(bulletSound->state() == QMediaPlayer::StoppedState)
//        {
//            bulletSound->play();
//            qDebug() << "bullet->play()";
//        }
    }
    else if(event->key() == Qt::Key_G) {
        Game::getInstance().gen();
    }
}

void Player::advance(int phase)
{
    if(!phase) return;
    setDirection();
    if(direction > 0)
    {
        setPos(x()+player_speed, y());
    }
    else if(direction < 0)
    {
        setPos(x()-player_speed, y());
    }
}

void Player::setDirection()
{
    center = this->x() + pixmap().width()/2;
    if(mouse_x < center-1)
    {
        direction = -1;
    }
    else if(mouse_x > center+1)
    {
        direction = 1;
    }
    else
    {
        direction = 0;
    }
}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void Player::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    mouse_x = event->scenePos().x();
    mouse_y = event->scenePos().y();

    setDirection();

    //qDebug() << "Player: mouse moved! dir = " << QString::number(direction);
}

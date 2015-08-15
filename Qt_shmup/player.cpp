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

Player::Player(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/images/spaceship.png"));

    bulletSound = new QMediaPlayer(this);
//    bulletSound->setMedia(QUrl("qrc:/sounds/bullet2.wav"));

//    QTimer* timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(gen()));
//    timer->start(enemy_spawn_timeout);
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
        Bullet_02* bullet = new Bullet_02(this);
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
    else if(event->key() == Qt::Key_B) {
        gen();
    }
}

void Player::gen() {
    Enemy_b01* enemy = new Enemy_b01(this, scene());
    scene()->addItem(enemy);
//    if(qrand() % 2 == 0)
//    {
//        Enemy_01* enemy = new Enemy_01(this, scene());
//        scene()->addItem(enemy);
//    }
//    else
//    {
//        Enemy_02* enemy = new Enemy_02(this, scene());
//        scene()->addItem(enemy);
//    }
}



#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include "constants.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

MyRect::MyRect(QObject *parent) : QObject(parent)
{
    bulletSound = new QMediaPlayer(this);
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(gen()));
    timer->start(enemy_spawn_timeout);
}

void MyRect::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Down) {
        setPos(x(), y()+player_speed);
    }
    else if(event->key() == Qt::Key_Up) {
        setPos(x(), y()-player_speed);
    }
    else if(event->key() == Qt::Key_Right &&
            x() < scene()->width() - this->rect().width()) {
        setPos(x()+player_speed, y());
    }
    else if(event->key() == Qt::Key_Left &&
            x() > 0) {
        setPos(x()-player_speed, y());
    }
    else if(event->key() == Qt::Key_Space) {
        Bullet* bullet = new Bullet(this);
        bullet->setPos(x()+50, y());
        scene()->addItem(bullet);


//        qDebug() << "bulletSound media status = " << QString::number(bulletSound->mediaStatus());
//        if(bulletSound->state() == QMediaPlayer::PlayingState)
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
}

void MyRect::gen() {
    Enemy* enemy = new Enemy(this, scene());
    scene()->addItem(enemy);
}



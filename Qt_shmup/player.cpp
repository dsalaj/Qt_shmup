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

Player::Player(QObject *parent) : QObject(parent), direction(0), center(0), mouse_x(0), mouse_y(0), shoot(false)
{
    setPixmap(QPixmap(":/images/spaceship.png"));
    bulletSound = new QMediaPlayer(this);
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
    }
    else if(event->key() == Qt::Key_G) {
        Game::getInstance().gen();
    }
}

bool Player::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseMove)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(e != NULL)
        {
            mouse_x = e->pos().x();
            mouse_y = e->pos().y();
            setDirection();
        }
    }
    else if(event->type() == QEvent::MouseButtonPress)
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
    if(shoot == true)
    {
        shoot = false;
        Bullet_01* bullet = new Bullet_01(this);
        bullet->setPos(x()+pixmap().width()/2-bullet->pixmap().width()/2, y());
        scene()->addItem(bullet);
//        //qDebug() << "bulletSound media status = " << QString::number(bulletSound->mediaStatus());
//        if(bulletSound->state() == QMediaPlayer::PlayingState ||
//           bulletSound->mediaStatus() == QMediaPlayer::EndOfMedia ||
//           bulletSound->state() == QMediaPlayer::StoppedState)
//        {
//            bulletSound->setMedia(QUrl("qrc:/sounds/bullet2.wav"));
//            bulletSound->setPosition(0);
//            bulletSound->play();
//            //qDebug() << "bullet->setPosition(0)";
//        }
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

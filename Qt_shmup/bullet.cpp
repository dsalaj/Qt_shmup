#include "bullet.h"

#include <QTimer>

Bullet::Bullet(QObject *parent) : QObject(parent)
{
    //setRect(x(), y(), 4, 10);
    setPixmap(QPixmap(":/images/bullet.png"));
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Bullet::move()
{
    setPos(x(), y()-4);
}

void Bullet::remove()
{
    delete this;
 }


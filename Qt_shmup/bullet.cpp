#include "bullet.h"

#include <QTimer>

Bullet::Bullet(QObject *parent) : QObject(parent)
{
    setRect(x(), y(), 4, 10);
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    setPos(x(), y()-20);
}

void Bullet::remove()
{
    delete this;
 }


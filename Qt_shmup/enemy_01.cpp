#include "enemy_01.h"

#include <QTimer>

Enemy_01::Enemy_01(QObject *parent, QGraphicsScene *scene) : Enemy(parent, scene, (2 + (qrand() % 3)), 1)
{
    setPixmap(QPixmap(":/images/enemy1.png"));

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

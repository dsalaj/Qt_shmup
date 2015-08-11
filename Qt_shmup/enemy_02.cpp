#include "enemy_02.h"

#include <QTimer>

Enemy_02::Enemy_02(QObject *parent, QGraphicsScene *scene) : Enemy(parent, scene, (1 + (qrand() % 2)), 4)
{
    setPixmap(QPixmap(":/images/enemy2.png"));

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}


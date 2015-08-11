#include "enemy_02.h"

#include <QTimer>

Enemy_02::Enemy_02(QObject *parent, QGraphicsScene *scene) : Enemy(parent, scene, (1 + (qrand() % 2)), 4, 5)
{
    setPixmap(QPixmap(":/images/enemy2.png"));
    setPos(game->random_xpos(static_cast<int>(scene->width()), pixmap().width()), - pixmap().height());

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}


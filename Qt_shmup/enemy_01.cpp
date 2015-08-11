#include "enemy_01.h"

#include <QTimer>

Enemy_01::Enemy_01(QObject *parent, QGraphicsScene *scene) : Enemy(parent, scene, (2 + (qrand() % 3)), 1, 2)
{
    setPixmap(QPixmap(":/images/enemy1.png"));
    setPos((qrand() % static_cast<int>(scene->width() - pixmap().width())), - pixmap().height());
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
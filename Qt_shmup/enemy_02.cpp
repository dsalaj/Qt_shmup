#include "enemy_02.h"

#include <QTimer>

Enemy_02::Enemy_02(QObject *parent, QGraphicsScene *scene) : Enemy(parent, (1 + (qrand() % 2)), 4, 5)
{
    setPixmap(QPixmap(":/images/enemy2.png"));
    setPos(Game::getInstance().random_xpos(static_cast<int>(scene->width()), pixmap().width()), - pixmap().height());

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}


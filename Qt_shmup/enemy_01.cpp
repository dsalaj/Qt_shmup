#include "enemy_01.h"

#include <QTimer>

Enemy_01::Enemy_01(QObject *parent, QGraphicsScene *scene) : Enemy(parent, (2 + (qrand() % 3)), 1, 2)
{
    setPixmap(QPixmap(":/images/enemy1.png"));
    setPos(Game::getInstance().random_xpos(static_cast<int>(scene->width()), pixmap().width()), - pixmap().height());
}

void Enemy_01::advance(int phase)
{
    if(!phase) return;
    setPos(x(), y()+speed);
    check();
}

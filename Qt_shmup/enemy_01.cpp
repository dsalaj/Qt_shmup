#include "enemy_01.h"

#include <QTimer>

Enemy_01::Enemy_01(QObject *parent, QGraphicsScene *scene) : Enemy(parent, (speed_e01 + (qrand() % 3)), health_e01, score_e01)
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

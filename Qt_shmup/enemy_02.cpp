#include "bullet_e01.h"
#include "enemy_02.h"

#include <QTimer>

Enemy_02::Enemy_02(QObject *parent, QGraphicsScene *scene) : Enemy(parent, (1 + (qrand() % 2)), 4, 5)
{
    setPixmap(QPixmap(":/images/enemy2.png"));
    setPos(Game::getInstance().random_xpos(static_cast<int>(scene->width()), pixmap().width()), - pixmap().height());

    QTimer* move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

    QTimer* shoot_timer = new QTimer(this);
    connect(shoot_timer,SIGNAL(timeout()),this,SLOT(shoot()));
    shoot_timer->start(2000);
}

void Enemy_02::move()
{
    setPos(x(), y()+speed);
    check();
}

void Enemy_02::shoot()
{
    Bullet_e01* bullet = new Bullet_e01(scene());
    bullet->setPos(x()+pixmap().width()/2-bullet->pixmap().width()/2, y()+pixmap().height());
    scene()->addItem(bullet);
}

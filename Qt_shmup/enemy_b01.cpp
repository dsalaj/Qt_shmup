#include "bullet_e01.h"
#include "enemy_b01.h"
#include "enemy_boss01.h"

#include <QTimer>
#include <QDebug>

Enemy_b01::Enemy_b01(QObject *parent, QGraphicsScene *scene)
         : Enemy(parent, speed_eb01, health_eb01, score_eb01), state(0), y_state(1)
{
    setBoss_body(true);
    pix = QPixmap(":/images/boss1.png");
    setPixmap(pix);
    setPos(mapToScene(scene->width()/2 - pixmap().width()/2, - pixmap().height()));

    QTimer* shoot_timer = new QTimer(this);
    connect(shoot_timer,SIGNAL(timeout()),this,SLOT(shoot()));
    shoot_timer->start(2000);
}

void Enemy_b01::shoot()
{
    Bullet_e01* bullet = new Bullet_e01(scene());
    bullet->setPos(mapToScene(x()+pixmap().width()/2-bullet->pixmap().width()/2, y()+pixmap().height()));
    scene()->addItem(bullet);
}

void Enemy_b01::advance(int phase)
{
    if(!phase) return;
    if(dynamic_cast<Enemy_boss01*>(parent())->childItems().size() == 1) setBoss_body(false);
    check();
}

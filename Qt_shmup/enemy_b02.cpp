#include "bullet_e01.h"
#include "enemy_b02.h"

#include <QTimer>
#include <QDebug>

Enemy_b02::Enemy_b02(QObject *parent, QGraphicsScene *scene, int x_offset)
         : Enemy(parent, speed_eb01, health_eb01, score_eb01), state(0), y_state(1), x_offset(x_offset)
{
    QImage image = QImage(":/images/boss1a.png");
    if(x_offset > 0)
        image = image.mirrored(true,false);
    pix = QPixmap::fromImage(image);
    setPixmap(pix);
    setPos(mapToScene(scene->width()/2 - pixmap().width()/2 + x_offset, - pixmap().height() + 30));

    QTimer* shoot_timer = new QTimer(this);
    connect(shoot_timer,SIGNAL(timeout()),this,SLOT(shoot()));
    shoot_timer->start(2000);
}

void Enemy_b02::shoot()
{
    Bullet_e01* bullet = new Bullet_e01(scene());
    bullet->setPos(mapToScene(x(), y()));
    scene()->addItem(bullet);
}

void Enemy_b02::advance(int phase)
{
    if(!phase) return;
    check();
}

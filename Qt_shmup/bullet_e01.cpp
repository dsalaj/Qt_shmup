#include "bullet_e01.h"
#include "player.h"
#include "game.h"

Bullet_e01::Bullet_e01(QObject *parent) : Bullet_enemy(parent, 1)
{
    setPixmap(QPixmap(":/images/bullet_e01.png"));
}

void Bullet_e01::advance(int phase)
{
    if(!phase) return;
    setPos(x(), y()+2);
    if(collidingItems().size() != 0)
    {
        for(QGraphicsItem* i : collidingItems())
        {
            Player* p = dynamic_cast<Player*>(i);
            if(p!=NULL)
            {
                Game::getInstance().decHealth(this->damage());
                this->remove();
            }
        }
    }
}

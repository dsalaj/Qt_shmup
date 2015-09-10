#include "button_w2.h"
#include "game.h"

Button_w2::Button_w2(QObject *parent) : Button(parent)
{
    setPixmap(QPixmap(":/images/enemy1.png"));

}

void Button_w2::clicked()
{
    if(Game::getInstance().getPoints() >= 20)
    {
        Game::getInstance().addPoints(-20);
        Game::getInstance().getPlayer()->bullet_type = 2;
    }
}

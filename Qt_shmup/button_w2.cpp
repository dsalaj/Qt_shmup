#include "button_w2.h"
#include "game.h"
#include "utility.h"

Button_w2::Button_w2(QObject *parent) : Button(parent)
{
    setPixmap(QPixmap(":/images/enemy1.png"));

}

void Button_w2::clicked()
{
    if(Game::getInstance().getPoints() +
       Utility::priceOfWeapon(Game::getInstance().getPlayer()->bullet_type) >=
       Utility::priceOfWeapon(2))
    {
        Game::getInstance().addPoints(
                    Utility::priceOfWeapon(Game::getInstance().getPlayer()->bullet_type) -
                    Utility::priceOfWeapon(2));
        Game::getInstance().getPlayer()->bullet_type = 2;
    }
}

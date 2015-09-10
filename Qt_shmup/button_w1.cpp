#include "button_w1.h"

Button_w1::Button_w1(QObject *parent) : Button(parent)
{
    setPixmap(QPixmap(":/images/shop_w1.png"));

}

void Button_w1::clicked()
{
    if(Game::getInstance().getPoints() +
       Utility::priceOfWeapon(Game::getInstance().getPlayer()->bullet_type) >=
       Utility::priceOfWeapon(1))
    {
        Game::getInstance().addPoints(
                    Utility::priceOfWeapon(Game::getInstance().getPlayer()->bullet_type) -
                    Utility::priceOfWeapon(1));
        Game::getInstance().getPlayer()->bullet_type = 1;
    }
}

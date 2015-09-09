#include "button_w2.h"
#include "game.h"

Button_w2::Button_w2(QObject *parent) : Button(parent)
{
    setPixmap(QPixmap(":/images/enemy1.png"));

}

void Button_w2::clicked()
{
    Game::getInstance().addPoints(-1);
}

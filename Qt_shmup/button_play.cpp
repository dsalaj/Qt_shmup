#include "button_play.h"
#include "game.h"

Button_play::Button_play(QObject *parent) : QObject(parent)
{

}

Button_play::~Button_play()
{
    Game::getInstance().getPlayer()->setInShop(false, false);
}

void Button_play::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    // check if cursor not moved since click beginning
    if ((m_mouseClick) && (e->pos() == m_lastPoint))
    {
        // do something: for example emit Click signal
        emit clicked();
    }
}

void Button_play::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    // store click position
    m_lastPoint = e->pos();
    // set the flag meaning "click begin"
    m_mouseClick = true;
}


void Button_play::clicked()
{
    Game::getInstance().play();
    delete this;
}

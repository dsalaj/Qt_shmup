#include "button.h"
#include "game.h"

Button::Button(QObject *parent) : QObject(parent)
{

}

void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    // check if cursor not moved since click beginning
    if ((m_mouseClick) && (e->pos() == m_lastPoint))
    {
        // do something: for example emit Click signal
        emit clicked();
    }
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    // store click position
    m_lastPoint = e->pos();
    // set the flag meaning "click begin"
    m_mouseClick = true;
}

void Button::clicked()
{
}


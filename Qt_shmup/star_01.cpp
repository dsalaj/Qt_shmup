#include "star_01.h"

Star_01::Star_01(QObject *parent, QGraphicsScene *scene) : QObject(parent)
{
    QPixmap pix = QPixmap(":/images/star1.png");
    setPixmap(pix);
    setPos(Game::getInstance().random_xpos(static_cast<int>(scene->width()), pixmap().width()), - pixmap().height());
    speed = 0.1 + 0.1*(qrand()%10);
    if(speed < 0.7)
    {
        setScale(0.1 + 0.1*(qrand()%4));
    }
    else
    {
        setScale(0.1 + 0.1*(qrand()%10));
    }
}

void Star_01::advance(int phase)
{
    if(!phase) return;
    setPos(x(), y()+speed);
}

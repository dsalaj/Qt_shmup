#ifndef STAR_01_H
#define STAR_01_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "game.h"

class Star_01 : public QObject, public QGraphicsPixmapItem
{
public:
    Star_01(QObject *parent, QGraphicsScene *scene);
protected:
    void advance(int phase);
private:
    qreal speed;
};

#endif // STAR_01_H

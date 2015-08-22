#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
public:
    explicit Player(QObject *parent = 0);
    void keyPressEvent(QKeyEvent *event);    
    bool eventFilter(QObject *obj, QEvent *event);
private:
    QMediaPlayer* bulletSound;
    int direction;
    void advance(int phase);
    qreal center;
    qreal mouse_x, mouse_y;
    void setDirection();
    bool shoot;
};

#endif // PLAYER_H

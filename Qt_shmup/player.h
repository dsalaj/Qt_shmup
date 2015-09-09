#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    bool eventFilter(QObject *obj, QEvent *event);
    void setInShop(bool value);
private:
    QMediaPlayer* bulletSound;
    int direction;
    void advance(int phase);
    qreal center;
    qreal mouse_x, mouse_y;
    void setDirection();
    bool shoot;
    bool in_shop;
    QTimer* shooter;
public slots:
    void shoot_shop();
};

#endif // PLAYER_H

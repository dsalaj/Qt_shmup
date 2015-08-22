#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
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
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYRECT_H

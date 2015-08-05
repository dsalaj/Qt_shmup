#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsRectItem>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = 0);

signals:

public slots:
    void move();
    void remove();
};

#endif // BULLET_H

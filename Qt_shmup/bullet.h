#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent, unsigned int damage);
    unsigned int damage();
private:
    unsigned int dmg;
public slots:
    virtual void move() = 0;
    void remove();
};

#endif // BULLET_H

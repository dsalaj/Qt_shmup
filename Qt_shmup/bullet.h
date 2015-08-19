#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
public:
    explicit Bullet(QObject *parent, unsigned int damage);
    virtual ~Bullet();
    unsigned int damage();
    void remove();
private:
    unsigned int dmg;
    QTimer* timer;
};

#endif // BULLET_H

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem, public QObject
{
public:
    explicit Health(QObject *parent, unsigned int h);
    void decHealth(int points);
private:
    unsigned int health;
};

#endif // HEALTH_H

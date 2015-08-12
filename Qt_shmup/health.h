#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    explicit Health(unsigned int h);
    void decHealth(int points);
private:
    unsigned int health;
};

#endif // HEALTH_H

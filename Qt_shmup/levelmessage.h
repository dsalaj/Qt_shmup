#ifndef LEVELMESSAGE_H
#define LEVELMESSAGE_H

#include <QGraphicsTextItem>

class LevelMessage : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit LevelMessage(QString message, int time);
public slots:
    void clear();
};

#endif // LEVELMESSAGE_H

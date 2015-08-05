#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem, public QObject
{
public:
    explicit Score(QObject *parent, unsigned int s);
    void addPoints(int points);
private:
    unsigned int score;
};

#endif // SCORE_H

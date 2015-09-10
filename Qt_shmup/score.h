#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    explicit Score(unsigned int s);
    void addPoints(int points);
    unsigned int getScore() const;
private:
    unsigned int score;
};

#endif // SCORE_H

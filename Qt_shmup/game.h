#ifndef GAME_H
#define GAME_H

#include "health.h"
#include "score.h"

#include <QObject>



class Game : public QObject
{
public:
    Game();
    void play();
    void addPoints(int points);
    void decHealth(int points);
private:
    Score* score;
    Health* health;

};

#endif // GAME_H

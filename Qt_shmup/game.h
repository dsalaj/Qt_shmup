#ifndef GAME_H
#define GAME_H

#include "health.h"
#include "score.h"

#include <QObject>



class Game : public QObject
{
    Q_OBJECT
public:
    static Game& getInstance();
    void play();
    void addPoints(int points);
    void decHealth(int points);
    int random_xpos(int sw, int pw);
private:
    static Game* instance;
    Game();
    Game(Game const&) = delete;
    void operator=(Game const&) = delete;

    Score* score;
    Health* health;
    QGraphicsScene* scene;
    QPixmap* background;
    unsigned int bg_pos;
public slots:
    void moveBackground();
};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H

#include "health.h"
#include "player.h"
#include "score.h"

#include <QGraphicsView>
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    ~Game();
    static Game& getInstance();
    void init();
    void play();
    void play(QString new_level);
    void showMessage(QString message, int time);
    void addPoints(int points);
    void decHealth(int points);
    int random_xpos(int sw, int pw);
    Player *getPlayer() const;
    void menuShow();
    void menuRemove();

private:
    static Game* instance;
    Game();
    Game(Game const&) = delete;
    void operator=(Game const&) = delete;

    Player* player;
    Score* score;
    Health* health;
    QGraphicsScene* scene;
    QPixmap* background;
    unsigned int bg_pos;
    QTimer* enemy_spawn;
    QString level;
    QTimer* main_tick;
    QGraphicsView* view;
    unsigned int level_number;
    QVector<QObject*>* menu;

public slots:
    void move_bg();
    void gen();
};

#endif // GAME_H

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
    void play(QFile* new_level);
    void showMessage(QString message, int time);
    void addPoints(int points);
    int getPoints();
    void decHealth(int points);
    int random_xpos(int sw, int pw);
    Player *getPlayer() const;
    void menuShow();
    void levelFinished();

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
    QFile* level_file;
    QTextStream* level_stream;
    QTimer* main_tick;
    QGraphicsView* view;
    unsigned int level_number;
    bool last_level;

public slots:
    void move_bg();
    void gen();
};

#endif // GAME_H

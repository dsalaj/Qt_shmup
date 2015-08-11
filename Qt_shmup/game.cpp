#include "game.h"
#include "player.h"
#include "score.h"
#include "health.h"

#include <QGraphicsScene>
#include <QGraphicsView>

Game::Game()
{

}

void Game::play()
{
    QGraphicsScene* scene = new QGraphicsScene(0,0,800,600);

    Player* player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    QGraphicsView* view = new QGraphicsView(scene);
    view->show();
    view->setFixedSize(800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    score = new Score(scene, 0);
    scene->addItem(score);

    health = new Health(scene, 6);
    scene->addItem(health);

    player->setPos(350,500);
}

void Game::addPoints(int points)
{
    score->addPoints(points);
}

void Game::decHealth(int points)
{
    health->decHealth(points);
}


int Game::random_xpos(int sw, int pw)
{
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0,sw - pw);
    return distribution(generator);
}

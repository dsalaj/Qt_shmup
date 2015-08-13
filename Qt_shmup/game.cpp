#include "game.h"
#include "player.h"
#include "score.h"
#include "health.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QTimer>

Game::Game()
{

}

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

void Game::play()
{
    scene = new QGraphicsScene(0,0,800,600);
    bg_pos = 0;
    background = new QPixmap(":/images/bg.png");
    scene->setBackgroundBrush(QBrush(*background));

    Player* player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    QGraphicsView* view = new QGraphicsView(scene);
    view->show();
    view->setFixedSize(scene->width(),scene->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    score = new Score(0);
    scene->addItem(score);

    health = new Health(6);
    scene->addItem(health);

    player->setPos(scene->width()/2 - player->pixmap().width()/2, scene->height() - player->pixmap().height());

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBackground()));
    timer->start(50);
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

void Game::moveBackground()
{
    // FIXXME: moving background wihtout tearing
//    background = new QPixmap(":/images/bg.png");
//    background->scroll(0, bg_pos++, 0, 0, scene->width(), scene->height());
//    if(bg_pos % background->height() == 0) bg_pos = 0;
//    scene->setBackgroundBrush(QBrush(*background));
}

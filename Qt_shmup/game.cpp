#include "game.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include "constants.h"
#include "enemy_01.h"
#include "enemy_02.h"
#include "enemy_b01.h"
#include "enemy_boss01.h"
#include "levelmessage.h"
#include "star_01.h"
#include "button.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QTimer>

Game::Game() : background(NULL), level_number(0)
{
}

void Game::move_bg()
{
    // FIXXME: moving background wihtout tearing
//    delete background;
//    background = new QPixmap(":/images/bg.png");
//    background->scroll(0, bg_pos++, 0, 0, scene->width(), scene->height());
//    //if(bg_pos % background->height() == 0) bg_pos = 0;
//    //scene->setBackgroundBrush(QBrush(Qt::black));
//    scene->setBackgroundBrush(QBrush(*background));
    if(qrand()%100 < 10)
    {
        Star_01* s = new Star_01(this, scene);
        scene->addItem(s);
    }
}

Player *Game::getPlayer() const
{
    return player;
}

void Game::menu()
{
    showMessage("..:: QT SHMUP ::..", 15000);
    Button* b = new Button(this);
    b->setPixmap(QPixmap(":/images/spaceship.png"));
    b->setPos(350, 340);
    scene->addItem(b);
    //connect(b, SIGNAL(), b, SLOT(clicked());
}


Game::~Game()
{
    // FIXME: is cleanup necessary for members without set parent?
}

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

void Game::init()
{
    scene = new QGraphicsScene(0,0,800,600);
    bg_pos = 0;
    background = new QPixmap(":/images/bg.png");
    //scene->setBackgroundBrush(QBrush(*background));
    scene->setBackgroundBrush(Qt::black);
    scene->setItemIndexMethod(QGraphicsScene::BspTreeIndex); // TODO: compare the two index methods
    //scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    player = new Player(this);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    view = new QGraphicsView(scene);
    view->show();
    view->setFixedSize(scene->width(),scene->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setRenderHint(QPainter::Antialiasing); // TODO: see if it makes difference
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate); // TODO: test the performance with different policies

    score = new Score(0);
    health = new Health(6);

    main_tick = new QTimer(scene);
    connect(main_tick, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(main_tick, SIGNAL(timeout()), &Game::getInstance(), SLOT(move_bg()));
    main_tick->start(1000 / 33);

    enemy_spawn = new QTimer();
    connect(enemy_spawn,SIGNAL(timeout()),this,SLOT(gen()));
}

void Game::play()
{
    level = "..:..:.:..:.::.._b_________________er";
    play(level);
}

void Game::play(QString new_level)
{
    scene->addItem(player);
    player->setPos(scene->width()/2 - player->pixmap().width()/2, scene->height() - player->pixmap().height());
    level = new_level;
    enemy_spawn->start(enemy_spawn_timeout);
    scene->addItem(health);
    scene->addItem(score);
}

void Game::showMessage(QString message, int time)
{
    LevelMessage* m = new LevelMessage(message, time);
    m->setPos(scene->width()/2 - (m->boundingRect().width()/2)*5, scene->height()/2-m->boundingRect().height()*5);
    scene->addItem(m);
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

void Game::gen() {

    if(!level.isEmpty())
    {
        QChar instruction = level.at(0);
        level.remove(0,1);
        if(instruction == '.')
        {
            Enemy_01* enemy = new Enemy_01(this, scene);
            scene->addItem(enemy);
        }
        else if(instruction == ':')
        {
            Enemy_02* enemy = new Enemy_02(this, scene);
            scene->addItem(enemy);
        }
        else if(instruction == '_')
        {
            // rest
        }
        else if(instruction == 'b')
        {
            Enemy_boss01* enemy = new Enemy_boss01(this, scene);
            scene->addItem(enemy);
        }
        else if(instruction == 'r')
        {
            play();
        }
        else if(instruction == 'e')
        {
            //exit(0);
            showMessage("Level " + QString::number(++level_number), 2000);
        }
    }
}

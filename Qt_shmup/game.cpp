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
#include "button_play.h"
#include "button_w2.h"
#include "button_w1.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QTimer>

Game::Game() : background(NULL), level_number(0), last_level(false)
{
}

void Game::move_bg()
{
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

void Game::menuShow()
{
    Button_play* bp = new Button_play(this);
    bp->setPixmap(QPixmap(":/images/menu_play.png"));
    bp->setPos(100, 500);
    bp->setZValue(4);
    scene->addItem(bp);

    Button* splash = new Button(bp);
    splash->setPixmap(QPixmap(":/images/logo_scale.png"));
    splash->setZValue(4);
    scene->addItem(splash);
}

void Game::levelFinished()
{
    if(!last_level)
    {
        //Show shop here!
        Button_play* bp = new Button_play(this);
        bp->setPixmap(QPixmap(":/images/menu_play.png"));
        bp->setPos(600, 500);
        bp->setZValue(4);
        scene->addItem(bp);

        Button_w1* b = new Button_w1(bp);
        b->setZValue(4);
        b->setPos(400,300);
        scene->addItem(b);

        Button_w2* b2 = new Button_w2(bp);
        b2->setZValue(4);
        b2->setPos(400,400);
        scene->addItem(b2);

        player->setInShop(true, true);
        player->setPos(100,player->y());
    }
    else
    {
        player->setInShop(true, false);
        player->setPos(scene->width()/2-player->pixmap().width()/2, player->y());
        // player->fly_away...
        showMessage("Game Complete...\nCredits", 15000);
    }
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
    if(level_file == NULL)
    {
        play(new QFile(":/levels/level1.txt"));
    }
    else if(level_file->fileName() == ":/levels/level1.txt")
    {
        last_level = true;
        play(new QFile(":/levels/level2.txt"));
    }
    else
    {
        qDebug() << "Error: Unknown level_file state!";
        exit(2);
    }
}

void Game::play(QFile* new_level)
{
    qDebug() << new_level->fileName();
    scene->addItem(player);
    player->setPos(scene->width()/2 - player->pixmap().width()/2, scene->height() - player->pixmap().height());
    scene->addItem(health);
    scene->addItem(score);

    level_file = new_level;
    if(level_file->open(QIODevice::ReadOnly))
    {
        level_stream = new QTextStream(level_file);
        enemy_spawn->start(enemy_spawn_timeout);
    }
    else
    {
        qDebug() << "Could not open level file";
        exit(1);
    }
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

int Game::getPoints()
{
    return score->getScore();
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

    level = level_stream->readLine();
    if(!level.isEmpty())
    {
        for(int index = 0; index < 19; index++)
        {
            if(level.length() <= index) break;
            QChar instruction = level.at(index);

            if(instruction == '1')
            {
                Enemy_01* enemy = new Enemy_01(this, scene);
                enemy->setPos(static_cast<qreal>(index)*(scene->width()*0.05), enemy->y());
                scene->addItem(enemy);
            }
            else if(instruction == '2')
            {
                Enemy_02* enemy = new Enemy_02(this, scene);
                enemy->setPos(index*(scene->width()*0.05), enemy->y());
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
}

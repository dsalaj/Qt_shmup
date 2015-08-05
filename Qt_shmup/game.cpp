#include "game.h"
#include "myrect.h"
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

    MyRect* rect = new MyRect();
    rect->setRect(0,0,100,100);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    scene->addItem(rect);

    QGraphicsView* view = new QGraphicsView(scene);
    view->show();
    view->setFixedSize(800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    score = new Score(scene, 0);
    scene->addItem(score);

    health = new Health(scene, 6);
    scene->addItem(health);

    rect->setPos(350,500);

//    QMediaPlayer* m = new QMediaPlayer(this);
//    m->setMedia(QUrl("qrc:/sounds/bullet.mp3"));
//    qDebug() << "m media status = " << QString::number(m->mediaStatus());
//    m->play();
}

void Game::addPoints(int points)
{
    score->addPoints(points);
}

void Game::decHealth(int points)
{
    health->decHealth(points);
}


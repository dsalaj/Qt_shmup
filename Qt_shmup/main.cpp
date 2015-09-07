#include "dialog.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game::getInstance().init();
    //Game::getInstance().play();
    Game::getInstance().menu();
    a.installEventFilter(Game::getInstance().getPlayer());

    return a.exec();
}

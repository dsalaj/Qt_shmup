#include "dialog.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include "myrect.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->play();

    return a.exec();
}

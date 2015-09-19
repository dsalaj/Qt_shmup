#include "dialog.h"
#include <QApplication>
#include <QFontDatabase>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/font/vermin_vibes_1989.ttf");
    a.setFont(QFont("Vermin Vibes 1989,",22));
    Game::getInstance().init();
    Game::getInstance().menuShow();
    a.installEventFilter(Game::getInstance().getPlayer());

    return a.exec();
}

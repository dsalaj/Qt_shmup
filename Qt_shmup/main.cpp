#include "dialog.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include "mainwindow.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    //w.showFullScreen();

//    Game::getInstance().init();
//    Game::getInstance().play();
    a.installEventFilter(&w);

    return a.exec();
}

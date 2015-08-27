#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,800,600);
    background = new QPixmap(":/images/bg.png");
    scene->setBackgroundBrush(QBrush(*background));
    //view = new QGraphicsView(scene);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Game::getInstance().init(scene);
    Game::getInstance().play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

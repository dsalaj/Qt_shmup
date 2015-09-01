#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene = new QGraphicsScene(0,0,800,600);
    scene = new QGraphicsScene(0,0,ui->graphicsView->width(), ui->graphicsView->height());
    background = new QPixmap(":/images/bg.png");
    scene->setBackgroundBrush(QBrush(*background));
    //view = new QGraphicsView(scene);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QPushButton* b1 = new QPushButton("Start", this);
    ui->verticalLayout->addWidget(b1);
    connect(b1,SIGNAL(pressed()),this,SLOT(start()));

    //Game::getInstance().init(scene);
    //Game::getInstance().play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    Game::getInstance().init(scene);
    Game::getInstance().play();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseMove)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(e != NULL)
        {
            if(Game::getInstance().getPlayer())
                Game::getInstance().getPlayer()->move(e->pos()); //FIXME: delay with bool member just like shoot
        }
    }
    else if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(e->button() == Qt::LeftButton)
        {
            if(Game::getInstance().getPlayer())
                Game::getInstance().getPlayer()->setShoot(true);
        }

    } else {
        // pass the event on to the parent class
        //return QMainWindow::eventFilter(obj, event);
        //FIXME: not needed?
        return Game::getInstance().eventFilter(obj, event);
    }
    return false;
}

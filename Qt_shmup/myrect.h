#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class MyRect : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit MyRect(QObject *parent = 0);
    void keyPressEvent(QKeyEvent *event);
private:
    QMediaPlayer* bulletSound;
signals:

public slots:
    void gen();
};

#endif // MYRECT_H

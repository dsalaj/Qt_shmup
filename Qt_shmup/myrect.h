#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class MyRect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit MyRect(QObject *parent = 0);
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:

    void gen();
};

#endif // MYRECT_H

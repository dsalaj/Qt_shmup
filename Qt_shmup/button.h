#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class Button : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Button(QObject *parent = 0);
protected:
    bool m_mouseClick;
    QPointF m_lastPoint;
    // re-implement processing of mouse events
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
public slots:
    virtual void clicked();
};

#endif // BUTTON_H

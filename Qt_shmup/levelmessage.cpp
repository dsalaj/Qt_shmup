#include "levelmessage.h"

#include <QTimer>
#include <QGraphicsScene>

LevelMessage::LevelMessage(QString message, int time)
{
    setPlainText(message);
    setDefaultTextColor(QColor(255,255,255));
    setScale(2);

    show();

    QTimer* remove_message = new QTimer(this);
    remove_message->setSingleShot(true);
    connect(remove_message,SIGNAL(timeout()),this,SLOT(clear()));
    remove_message->start(time);
}

void LevelMessage::clear()
{
    setPlainText("");
}

#include "levelmessage.h"

#include <QTimer>

LevelMessage::LevelMessage(QString message, int time)
{
    setPlainText(message);
    setDefaultTextColor(QColor(200,200,255));
    setScale(5);

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

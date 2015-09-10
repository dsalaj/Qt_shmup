#ifndef BUTTON_W1_H
#define BUTTON_W1_H

#include "button.h"
#include "game.h"
#include "utility.h"
#include <QObject>

class Button_w1 : public Button
{
    Q_OBJECT
public:
    Button_w1(QObject *parent = 0);
public slots:
    virtual void clicked();
};

#endif // BUTTON_W1_H

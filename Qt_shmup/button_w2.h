#ifndef BUTTON_W2_H
#define BUTTON_W2_H

#include "button.h"

#include <QObject>

class Button_w2 : public Button
{
    Q_OBJECT
public:
    Button_w2(QObject *parent = 0);
public slots:
    virtual void clicked();
};

#endif // BUTTON_W2_H

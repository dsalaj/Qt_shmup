#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T22:25:40
#
#-------------------------------------------------

QT       += core gui multimedia
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_shmup
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    player.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    constants.h \
    game.h \
    score.h \
    health.h \
    player.h

FORMS    += dialog.ui

RESOURCES += \
    res.qrc

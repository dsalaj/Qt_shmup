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
    player.cpp \
    enemy_01.cpp \
    enemy_02.cpp \
    bullet_01.cpp \
    bullet_02.cpp \
    bullet_player.cpp \
    bullet_enemy.cpp \
    bullet_e01.cpp \
    enemy_b01.cpp \
    enemy_boss01.cpp \
    enemy_b02.cpp \
    levelmessage.cpp \
    star_01.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    constants.h \
    game.h \
    score.h \
    health.h \
    player.h \
    enemy_01.h \
    enemy_02.h \
    bullet_01.h \
    bullet_02.h \
    bullet_player.h \
    bullet_enemy.h \
    bullet_e01.h \
    enemy_b01.h \
    enemy_boss01.h \
    enemy_b02.h \
    levelmessage.h \
    star_01.h

FORMS    += dialog.ui

RESOURCES += \
    res.qrc

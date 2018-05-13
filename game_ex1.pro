#-------------------------------------------------
#
# Project created by QtCreator 2017-09-05T19:12:45
#
#-------------------------------------------------

QT       += core gui \
           multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_ex1
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    game.cpp \
    health.cpp \
    player.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    score.h \
    game.h \
    health.h \
    player.h

FORMS    +=

RESOURCES += \
    res.qrc

DISTFILES +=

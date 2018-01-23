#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QObject>
#include <QMediaPlayer>
#include <QPointer>

#include "cannon.h"
#include "health.h"
#include "score.h"

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    int win_height;
    int win_width;

    Game(QWidget *parent = 0);

    QGraphicsScene *scene;

    Cannon *cannon;
    Health *health;
    Score *score;

    QPointer<QMediaPlayer> bgMusic;

    void startMenu();
    void gameOver();
    void checkUpdate();

public slots:
    void run();
};

#endif // GAME_H

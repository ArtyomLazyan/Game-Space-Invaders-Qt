#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QPointer>

class Cannon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    int color;

    Cannon(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void shoot();
    void changeColor();
    int getColor();

public slots:
    void createEnemy();

private:
    QPointer<QMediaPlayer> bulletSound;

    QSet<int> keyPressed;
    bool firstRelease;
};

#endif // CANNON_H

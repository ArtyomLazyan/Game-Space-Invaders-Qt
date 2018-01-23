#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int color;
    Bullet(int color, QGraphicsItem *parent = 0);
public slots:
    void move();
    int getColor() const;
};

#endif // BULLET_H

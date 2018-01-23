#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QString>
#include <stdlib.h>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int color;
    Enemy(QGraphicsItem *parent = 0);
    virtual int getColor() = 0;

public slots:
    virtual void move() = 0;
};

class BlueEnemy : public Enemy
{
    Q_OBJECT
public:
    BlueEnemy(QGraphicsItem *parent = 0);
    int getColor() override;
public slots:
    void move() override;
};

class RedEnemy : public Enemy
{
    Q_OBJECT
public:
    RedEnemy(QGraphicsItem *parent = 0);
    int getColor() override;
public slots:
    void move() override;
};

class PinkEnemy : public Enemy
{
    Q_OBJECT
public:
    PinkEnemy(QGraphicsItem *parent = 0);
    int getColor() override;
public slots:
    void move() override;
};

#endif // ENEMY_H

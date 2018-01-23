#include "enemy.h"
#include "game.h"
#include <QBitmap>

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {}

/* BLUE ENEMY */
BlueEnemy::BlueEnemy(QGraphicsItem *parent) : Enemy(parent)
{
    color = 2; // BLUE

    int random_number = rand() % 1700;
    setPos(random_number, 0);

    QPixmap pixmap(":/images/BlueInvader.png");
    QPixmap newPixmap = pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio);
    setPixmap(newPixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void BlueEnemy::move()
{
    setPos(x(), y() + 5);

    if (pos().y() > game->win_height - 50)
    {
        // decrease healt
        game->health->decrease();

        QPointer<QMediaPlayer> dontHit = new QMediaPlayer();
        dontHit->setMedia(QUrl("qrc:/sounds/dontHit.wav"));
        dontHit->play();

        scene()->removeItem(this);
        delete this;
    }

    if (game->health->getHealth() < 0)
    {
        // game over
        game->gameOver();
    }

    // check collision with cannon
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (auto &item : colliding_items)
    {
        if (dynamic_cast<Cannon *>(item))
        {
            game->gameOver();
        }
    }
}

int BlueEnemy::getColor()
{
    return color;
}

/* RED ENEMY */
RedEnemy::RedEnemy(QGraphicsItem *parent) : Enemy(parent)
{
    color = 0; // RED

    int random_number = rand() % 1700;
    setPos(random_number, 0);

    QPixmap pixmap(":/images/RedInvader.png");
    QPixmap newPixmap = pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio);
    setPixmap(newPixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(40);
}

void RedEnemy::move()
{
    setPos(x(), y() + 5);

    if (pos().y() > game->win_height - 50)
    {
        // decrease healt
        game->health->decrease();

        QPointer<QMediaPlayer> dontHit = new QMediaPlayer();
        dontHit->setMedia(QUrl("qrc:/sounds/dontHit.wav"));
        dontHit->play();

        scene()->removeItem(this);
        delete this;
    }

    if (game->health->getHealth() < 0)
    {
        // game over
        game->gameOver();
    }

    // check collision with cannon
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (auto &item : colliding_items)
    {
        if (dynamic_cast<Cannon *>(item))
        {
            game->gameOver();
        }
    }
}

int RedEnemy::getColor()
{
    return color;
}

/* PINK ENEMY */
PinkEnemy::PinkEnemy(QGraphicsItem *parent) : Enemy(parent)
{
    color = 1; // PINK

    int random_number = rand() % 1700;
    setPos(random_number, 0);

    QPixmap pixmap(":/images/PinkInvader.png");
    QPixmap newPixmap = pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio);
    setPixmap(newPixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(60);
}

void PinkEnemy::move()
{
    setPos(x(), y() + 5);

    if (pos().y() > game->win_height - 50)
    {
        // decrease healt
        game->health->decrease();

        QPointer<QMediaPlayer> dontHit = new QMediaPlayer();
        dontHit->setMedia(QUrl("qrc:/sounds/dontHit.wav"));
        dontHit->play();

        scene()->removeItem(this);
        delete this;
    }

    if (game->health->getHealth() < 0)
    {
        // game over
        game->gameOver();
    }

    // check collision with cannon
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (auto &item : colliding_items)
    {
        if (dynamic_cast<Cannon *>(item))
        {
            game->gameOver();
        }
    }
}

int PinkEnemy::getColor()
{
    return color;
}

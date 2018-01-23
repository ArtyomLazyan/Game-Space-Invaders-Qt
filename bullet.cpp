#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include <QPointer>

extern Game *game; // there is an external global object called game

Bullet::Bullet(int col, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    color = col;

    switch (color)
    {
        // 0 - Red
        case 0:
        {
            QPixmap pixmap(":/images/redShoot.png");
            QPixmap newPixmap = pixmap.scaled(QSize(40, 40), Qt::KeepAspectRatio);
            setPixmap(newPixmap);
        }
        break;

        // 1 - Pink
        case 1:
        {
            QPixmap pixmap(":/images/pinkShoot.png");
            QPixmap newPixmap = pixmap.scaled(QSize(40, 40), Qt::KeepAspectRatio);
            setPixmap(newPixmap);
        }
        break;

        // 2 - Blue
        case 2:
        {
            QPixmap pixmap(":/images/blueShoot.png");
            QPixmap newPixmap = pixmap.scaled(QSize(40, 40), Qt::KeepAspectRatio);
            setPixmap(newPixmap);
        }
        break;
    }

    // move bullet timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

void Bullet::move()
{
    /* check collision with enemies */

    // list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    Enemy *enemy;

    for (auto &item : colliding_items)
    {
      // if one of the colliding items is an Enemy then delete both the bullet and the enemy
        if ( (enemy = dynamic_cast<Enemy *>(item)) )
        {
            if ( (enemy->getColor()) == (this->getColor()) )
            {
                game->score->increase();
                scene()->removeItem(item);
                scene()->removeItem(this);

                QPointer<QMediaPlayer> explosion = new QMediaPlayer();
                explosion->setMedia(QUrl("qrc:/sounds/explosion.wav"));
                explosion->play();

                delete item;
                delete this;
            }
            else
            {
                // if enemy but coloros are different
                game->score->decrease();
                scene()->removeItem(this);

                QPointer<QMediaPlayer> dontHit = new QMediaPlayer();
                dontHit->setMedia(QUrl("qrc:/sounds/dontHit.wav"));
                dontHit->play();

                delete this;
            }

            // check health and score
            game->checkUpdate();
            return;
        }
    }

    /* move bullet */
    setPos(x(), y() - 10);

    // if the bullet is off the screen, destroy it
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

int Bullet::getColor() const
{
    return color;
}

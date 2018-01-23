#include "cannon.h"
#include "bullet.h"
#include "enemy.h"

Cannon::Cannon(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    changeColor();
    srand(time(NULL));
    bulletSound = new QMediaPlayer(this);
    bulletSound->setMedia(QUrl("qrc:/sounds/shoot.wav"));
}

void Cannon::shoot()
{
    Bullet *bullet = new Bullet(color);
    bullet->setPos(x() + 27, y());
    scene()->addItem(bullet);
}

void Cannon::changeColor()
{
    static int num = 0;

    // set graphic
    switch (num)
    {
        // 0 - Red
        case 0:
        {
            QPixmap pixmap(":/images/redCannon.png");
            QPixmap newPixmap = pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio);
            setPixmap(newPixmap);
            color = 0;
        }
        break;

        // 1 - Pink
        case 1:
        {
            QPixmap pixmap(":/images/pinkCannon.png");
            QPixmap newPixmap = pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio);
            setPixmap(newPixmap);
            color = 1;
        }
        break;

        // 2 - Blue
        case 2:
        {
            QPixmap pixmap(":/images/blueCannon.png");
            QPixmap newPixmap = pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio);
            setPixmap(newPixmap);
            color = 2;
        }
        break;
    }

    num++;
    if (num == 3)
        num = 0;
}

int Cannon::getColor()
{
    return color;
}

void Cannon::createEnemy()
{
    int num = rand() % 3;
    Enemy *enemy;

    switch (num)
    {
        case 0:
            enemy = new BlueEnemy();
        break;

        case 1:
            enemy = new RedEnemy();
        break;

        case 2:
            enemy = new PinkEnemy();
        break;

        default:
            enemy = new PinkEnemy();
    }

    scene()->addItem(enemy);
}

void Cannon::keyPressEvent(QKeyEvent *event)
{
   switch (event->key())
    {
        case Qt::Key_Left:
            // check out of range
            if(pos().x() > 0)
                setPos(x() - 20, y());
        break;

        case Qt::Key_Right:
            // check out of range
            if(pos().x() + 100 < 1820)
                setPos(x() + 20, y());
        break;

        case Qt::Key_Z:
        {
            // change cannon collor
            changeColor();
            QPointer<QMediaPlayer> cannonSound = new QMediaPlayer();
            cannonSound->setMedia(QUrl("qrc:/sounds/changeCannonColor.wav"));
            cannonSound->play();
        }
        break;

        case Qt::Key_Space:

            shoot();

            // play bullet sound
            if (bulletSound->state() == QMediaPlayer::PlayingState)
            {
                bulletSound->setPosition(0);
            }
            else if (bulletSound->state() == QMediaPlayer::StoppedState)
            {
                bulletSound->play();
            }

        break;
    }
}

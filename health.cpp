#include "health.h"
#include <QFont>

int Health::health = 3;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //draw the text
    setPlainText(QString("Health : ") + QString::number(health)); // health 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 24));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health : ") + QString::number(health)); // health - 1
}

void Health::resetHealth()
{
    health = 3;
    setPlainText(QString("Health : ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}


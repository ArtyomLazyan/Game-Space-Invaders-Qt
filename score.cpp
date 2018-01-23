#include "score.h"
#include <QFont>

int Score::score = 0;

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    // type text
    setPlainText(QString("Score : ") + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 24));
}

void Score::increase()
{
    score += 10;
    setPlainText(QString("Score : ") + QString::number(score));
}

void Score::decrease()
{
    score -= 10;
    setPlainText(QString("Score : ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::reset()
{
   score = 0;
    setPlainText(QString("Score : ") + QString::number(score));
}

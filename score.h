#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent = 0);
    void increase();
    void decrease();
    int getScore();
    void reset();
private:
    static int score;
};

#endif // SCORE_H

#include "game.h"
#include "enemy.h"
#include "button.h"
#include <QDebug>
#include <QPixmap>
#include <QFont>
#include <QPointer>
#include <QGraphicsTextItem>

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    win_height = 1075;
    win_width = 1820;

    // set scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, win_width, win_height);

    // game is inherited from QGraphicsView Widget
    setBackgroundBrush(QBrush(QImage(":/images/SpaceInvadersBg.jpg")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCursor(Qt::PointingHandCursor);
    setStyleSheet("border-style:none");

}

void Game::checkUpdate()
{
  if ((score->getScore()) < 0)
  {
      score->reset();
      gameOver();
  }

  if ((health->getHealth()) < 0)
      gameOver();
}

void Game::run()
{
    scene->clear();
    setCursor(Qt::BlankCursor);

     // create cannon
    cannon = new Cannon();
    cannon->setPos(win_width / 2, win_height - 110);
    cannon->setFlag(QGraphicsItem::ItemIsFocusable);
    cannon->setFocus();
    scene->addItem(cannon);

    // create score & health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 40);
    health->resetHealth();
    scene->addItem(health);
    score->reset();


    // create enemies
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), cannon, SLOT(createEnemy()));
    timer->start(2000);


    // play background music
    bgMusic = new QMediaPlayer();
    bgMusic->setMedia(QUrl("qrc:/sounds/bgMusic.wav"));
    bgMusic->play();
}

void Game::startMenu()
{
    // Main Logo
    QPixmap pixmap(":/images/mainLogo.png");
    QGraphicsPixmapItem *mainLogo = new QGraphicsPixmapItem(pixmap);
    mainLogo->setPos(this->width() / 2 - 250, 30);
    scene->addItem(mainLogo);

    // alien logo
    QPixmap alienLogo(":/images/invader.png");
    QPixmap newAlienLogo = alienLogo.scaled(QSize(800, 800), Qt::KeepAspectRatio);
    QGraphicsPixmapItem *alien = new QGraphicsPixmapItem(newAlienLogo);
    alien->setPos(this->width(), 270);
    scene->addItem(alien);

    // create Play button
    Button *playButton = new Button(QString("Play"));
    int posXplayButton = this->width() / 2 + playButton->boundingRect().width() - 10;
    int posYplayButton = 500;
    playButton->setPos(posXplayButton, posYplayButton);

    connect(playButton, SIGNAL(clicked()), this, SLOT(run()));
    scene->addItem(playButton);

    // create quit button
    Button *quitButton = new Button(QString("Quit"));
    int posXquitButton = this->width() / 2 + quitButton->boundingRect().width() - 10;
    int posYquitButton = 620;
    quitButton->setPos(posXquitButton, posYquitButton);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

void Game::gameOver()
{
    scene->clear();
    setCursor(Qt::PointingHandCursor);
    bgMusic->stop();

    // play gameover music
    QPointer<QMediaPlayer> gameOver = new QMediaPlayer();
    gameOver->setMedia(QUrl("qrc:/sounds/gameOver.wav"));
    gameOver->play();

    // game over Logo
    QPixmap pixmap(":/images/gameOver.png");
    QGraphicsPixmapItem *mainLogo = new QGraphicsPixmapItem(pixmap);
    mainLogo->setPos(this->width() / 2 - 300, 30);
    scene->addItem(mainLogo);

    // alien logo
    QPixmap alienLogo(":/images/over.png");
    QPixmap newAlienLogo = alienLogo.scaled(QSize(400, 400), Qt::KeepAspectRatio);
    QGraphicsPixmapItem *alien = new QGraphicsPixmapItem(newAlienLogo);
    alien->setPos(this->width() - 400, this->height() - 405);
    scene->addItem(alien);

    // type Score
    int gameScore = score->getScore();
    if (gameScore < 0) gameScore = 0;
    QGraphicsTextItem *text = new QGraphicsTextItem(QString("Your score : ") + QString::number(gameScore));
    text->setFont(QFont("times", 24));
    text->setDefaultTextColor(Qt::cyan);
    text->setPos(this->width() / 2 - text->boundingRect().width() / 2 - 20, 300);
    scene->addItem(text);

    // create Play again button
    Button *playButton = new Button(QString("Play again"));
    int posXplayButton = this->width() / 2 - 130;
    int posYplayButton = 500;
    playButton->setPos(posXplayButton, posYplayButton);

    connect(playButton, SIGNAL(clicked()), this, SLOT(run()));
    scene->addItem(playButton);

    // create quit button
    Button *quitButton = new Button(QString("Quit"));
    int posXquitButton = this->width() / 2 - 130;
    int posYquitButton = 620;
    quitButton->setPos(posXquitButton, posYquitButton);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

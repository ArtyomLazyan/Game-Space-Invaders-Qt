#include <QApplication>
#include "game.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();

    // from QGraphicsView
    game->showFullScreen();
    game->startMenu();

    return a.exec();
}

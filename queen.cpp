#include "queen.h"

Queen::Queen(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightQueen.png");
    else
        icon.load("../ChessGame/images/darkQueen.png");
    icon.scaled(parent->width(), parent->height());
    this->setPixmap(icon);
}

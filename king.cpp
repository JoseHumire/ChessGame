#include "king.h"

King::King(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightKing.png");
    else
        icon.load("../ChessGame/images/darkKing.png");
    this->setPixmap(icon);
}

#include "knight.h"

Knight::Knight(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightKnight.png");
    else
        icon.load("../ChessGame/images/darkKnight.png");
    this->setPixmap(icon);
}

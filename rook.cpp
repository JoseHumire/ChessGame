#include "rook.h"

Rook::Rook(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightRook.png");
    else
        icon.load("../ChessGame/images/darkRook.png");
    this->setPixmap(icon);
}

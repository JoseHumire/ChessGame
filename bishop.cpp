#include "bishop.h"
Bishop::Bishop(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightBishop.png");
    else
        icon.load("../ChessGame/images/darkBishop.png");
    this->setPixmap(icon);
}

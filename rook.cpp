#include "rook.h"

Rook::Rook(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/lightRook.png");
    else
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/darkRook.png");
    this->setPixmap(icon);
}

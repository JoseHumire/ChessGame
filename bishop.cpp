#include "bishop.h"

Bishop::Bishop(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/lightBishop.png");
    else
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/darkBishop.png");
    this->setPixmap(icon);
}

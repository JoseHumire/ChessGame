#include "queen.h"

Queen::Queen(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/lightQueen.png");
    else
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/darkQueen.png");
    this->setPixmap(icon);
}

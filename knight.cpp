#include "knight.h"

Knight::Knight(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/lightKnight.png");
    else
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/darkKnight.png");
    this->setPixmap(icon);
}

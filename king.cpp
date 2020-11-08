#include "king.h"

King::King(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/lightKing.png");
    else
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/darkKing.png");
    this->setPixmap(icon);
}

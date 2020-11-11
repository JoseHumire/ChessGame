#include "pawn.h"

Pawn::Pawn(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightPawn.png");
    else
        icon.load("../ChessGame/images/darkPawn.png");
    this->setPixmap(icon);
}

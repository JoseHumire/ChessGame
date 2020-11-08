#include "pawn.h"

Pawn::Pawn(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/lightPawn.png");
    else
        icon.load("D:/UNSA/SEMESTRE6/TO/ChessGame/images/darkPawn.png");
    this->setPixmap(icon);
}

#include "queen.h"

Queen::Queen(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightQueen.png");
    else
        icon.load("../ChessGame/images/darkQueen.png");
    this->setPixmap(icon);
}

std::vector<QPoint> Queen::getMoves(std::unique_ptr<Piece> pieces[8][8], QPoint start){
    std::vector<QPoint> moves;
    return moves;
}
